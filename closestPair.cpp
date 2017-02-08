#include <iostream>
#include <fstream>
#include <float.h>
#include <cmath>
#include <vector>
#include "closestPair.h"
using namespace std;


int main(int argc, char* argv[])
{
	pointsArr = new Point[MAX_ARRAY_SIZE];
	string algorithmChoice;
	
	bool firstCoordinateOfPoint = true; 
	string line;
	string point;
	char inputChar;
	bool gotNegative = false;
	bool gotDecimal = false;
	while(getline(cin,line)){
		if(line == "EOF") return 0;
		point = "";
		for(int i = 0; i < line.length(); i++)
		{
			inputChar = line[i];
			// If not a valid input
			// then continue and read in new input
			if(!isValidInput(inputChar) && i != line.length()-1) 
				continue;

			if(inputChar != ' ' && inputChar != '\n' && i != line.length()-1 ) 
			{
				if(inputChar == '.')
				{
					if(gotDecimal) 
						continue;
					gotDecimal = true;
				}
				if(inputChar == '-')
				{
					if(gotNegative) 
						continue;
					gotNegative = true;
				}
				point += inputChar;
			}
			else if(point.length() > 0 || (inputChar >= '0' && inputChar <= '9'))
			{
				
				// to get last digit of the coordinate
				if(inputChar >= '0' && inputChar <= '9')
				{
						point += inputChar;
				}

				// Set the X coordiante
				if(firstCoordinateOfPoint) {
					double coordinate = atof(point.c_str());
					pointsArr[numPoints].x = coordinate;
					firstCoordinateOfPoint = false;
					point = "";
					gotNegative = false;
					gotDecimal = false;
				}
				// Set the y coordinate
				else{
					 pointsArr[numPoints].y = atof(point.c_str());
					 firstCoordinateOfPoint = true;
					 point = "";
					 gotNegative = false;
					 gotDecimal = false;
					 if(!isDuplicate(pointsArr[numPoints])) 
					 	incrementNumPoints();

				}
				
			}

		}
		
	}

	if(argc > 1)
			algorithmChoice = argv[1];
		else {
			cout << "Please include an argument: brute, basic,"
			<< " or optimal to indicate which method to use." << endl;
		return 0;
		}

		if(algorithmChoice == "brute"){
			cout << "closest pair distance: " << findMinDistBruteForce() << endl;
			printAnswers();
		} 
		else if(algorithmChoice == "basic") {
			cout << "closest pair distance: " << findMinDistBasic() << endl;
			printAnswers();
		}
		else if(algorithmChoice == "optimal") {
			cout << "closest pair distance: " << findMinDistOptimal() << endl;
			printAnswers();
		}
  	
  	
 
}

void printAllPoints()
{
	for(int i = 0; i < numPoints; i++){
		cout << i+1 << ") x: " << pointsArr[i].x << " y: " << pointsArr[i].y << endl;
	}
}

bool isValidInput(char c)
{
	if((c >='0' && c <= '9' ) || c == '-' ||
		c == ' ' || c== '\n' || c == '.') return true;
	return false;
}


void sortPointsByXCoord()
{
	sortPointsByXCoord(0,numPoints);
}
void sortPointsByXCoord(int start, int end){
	bool outOfOrder = true;

	while(outOfOrder){
		outOfOrder = false;
		for(int i = start+1; i < end; i++){
			if(pointsArr[i-1].x > pointsArr[i].x){
				swap(i-1,i);
				outOfOrder = true;
			}
			else if(pointsArr[i-1].x == pointsArr[i].x){
				if(pointsArr[i-1].y > pointsArr[i].y){
					swap(i-1,i);
					outOfOrder = true;
				}
			}

		}
	}
}

void sortPointsByYCoord()
{
	sortPointsByYCoord(0,numPoints);
}
void sortPointsByYCoord(int start, int end){
	int i;
	bool outOfOrder = true;
	while(outOfOrder){
		outOfOrder = false;
		for(i = start+1; i < end; i++){
			if(pointsArr[i-1].y > pointsArr[i].y){
				swap(i-1,i);
				outOfOrder = true;
			}

		}
	}
}

void swap(int index1, int index2)
{
	Point temp = pointsArr[index1];
	pointsArr[index1] = pointsArr[index2];
	pointsArr[index2] = temp;
}

double distance(Point p1, Point p2)
{
	return sqrt((p2.x-p1.x) * (p2.x - p1.x) + (p2.y-p1.y)*(p2.y-p1.y));
}

double findMinDistBruteForce()
{	
	if(numPoints < 2){
		cout << "Not enough points to compare distances" << endl;
		exit(0);
	}
	double minDistance = DBL_MAX;
	int i,j;
	double d;
	for(i = 0; i < numPoints; i++){
		for(j = 0; j < numPoints; j++){
			if(i == j) continue;
			d = distance(pointsArr[i],pointsArr[j]);
			if(d < minDistance){
				minDistance = d;
				answers.clear();
				answers.push_back(pointsArr[i]);
				answers.push_back(pointsArr[j]);
			}
			else if(d == minDistance){
				if(answers.size() > 1){
					checkResults(pointsArr[i], pointsArr[j]);
				} 

			}
		}
	}

	return minDistance;
}
double findMinDistBruteForce(int start, int end){
	double minDistance = distance(pointsArr[start],pointsArr[start+1]);
	int i,j;
	double d;
	for(i = start; i < end; i++){
		for(j = start; j < end; j++){
			if(i == j) continue;
			else
				d = distance(pointsArr[i],pointsArr[j]);
			if(d < minDistance){
				minDistance = d;
				checkResults(pointsArr[i],pointsArr[j]);
			}
			else if(d == minDistance){
				
					checkResults(pointsArr[i], pointsArr[j]);
				 

			}
		}
	}

	return minDistance;

}
void checkResults(Point p1, Point p2){
	double d = distance(p1,p2);
	if(answers.size() < 1){
		answers.push_back(p1);
		answers.push_back(p2);
		return;
	}
	for(int i = 0; i < answers.size(); i += 2){
		if(d < distance(answers[i], answers[i+1])){
			answers.clear();
			answers.push_back(p1);
			answers.push_back(p2);
		}
		else if(d == distance(answers[i], answers[i+1])){
			if(!isDuplicatePair(answers[i], answers[i+1])){
				answers.push_back(p1);
				answers.push_back(p2);
			}
		}
	}
}
bool isDuplicatePair(Point p1, Point p2){
	for(int i = 0; i < answers.size(); i += 2){
		if((p1.x == answers[i].x && p1.y == answers[i].y &&
			p2.x == answers[i+1].x && p2.y == answers[i+1].y) ||
			(p1.x == answers[i+1].x && p1.y == answers[i+1].y &&
			p2.x == answers[i].x && p2.y == answers[i].y)){
			return true;
		}
	}
	return false;
}
double findMinDistBasic(){
	//sortPointsByXCoord();
	return findMinDistBasic(0,numPoints);
}


double findMinDistBasic(int start, int end){
	sortPointsByXCoord(start,end);
	// Base cases
	// if(end - start <= 1) return DBL_MAX;
	// if(end - start <= 3){
	// 	double d1, d2, d3;
	// 	d1 = distance(pointsArr[start],pointsArr[start+1]);
	// 	d2 = distance(pointsArr[start],pointsArr[start+2]);
	// 	d3 = distance(pointsArr[start+1],pointsArr[start+2]);
	// 	if(d1 < d2){
	// 		if(d1 < d3){
	// 			checkResults(pointsArr[start], pointsArr[start+1]);

	// 			return d1;
	// 		}
	// 	}
	// 	else if(d2 < d3){
	// 		checkResults(pointsArr[start], pointsArr[start+2]);
	// 		return d2;
	// 	}
	// 	else{
	// 		checkResults(pointsArr[start+1], pointsArr[start+2]);
	// 		return d3;
	// 	}
	// }
	if(end-start < 4){
		return findMinDistBruteForce(start,end);
	}

	
	double min_left = findMinDistBasic(start, (start + end)/2 );
	double min_right = findMinDistBasic((start + end)/2, end);
	
	double d = minimum(min_left, min_right);

	double median;
	// bool evenNumOfPts = (end+start)%2 == 0;
	// if(evenNumOfPts)
	// 	median = (pointsArr[(start + end)/2].x + pointsArr[(start + end)/2 - 1].x)/2;
	// else
	median = pointsArr[(start+end)/2].x;
	vector<Point> middle;
	int j = end;
	int i;
	for(i = (start+end)/2; i >= start; i--){
		if(abs(pointsArr[i].x - median) <= (d))
			middle.push_back(pointsArr[i]);
		else 
			break;
	
	}
	for(i = (start+end)/2+1; i < end; i++){
		if(abs(pointsArr[i].x - median) <= (d))
			middle.push_back(pointsArr[i]);
		else
			break;
	}
	// for(int i = start; i < end; i++){
	// 	if(abs(pointsArr[i].x - median) < d)
	// 		middle.push_back(pointsArr[i]);
	// }
		
	
	if(middle.size() > 1){
		// sorting the middle vector by y coordinate
		bool outOfOrder = true;
		while(outOfOrder){
			outOfOrder = false;
			for(i = 1; i < middle.size(); i++){
				if(middle[i-1].y > middle[i].y){
					Point temp = middle[i-1];
					middle[i-1] = middle[i];
					middle[i] = temp;
					outOfOrder = true;
				}

			}
		}
	//	cout << "the size of the middle strip is: " << middle.size() << endl;
		for(i = 0; i < middle.size(); i++){
			for(j = i+1; j < middle.size(); j++){
				if(i == j) continue;
				if(middle[i].y - middle[j].y > d){
					break;
				}
				if(distance(middle[i], middle[j]) < d){
					checkResults(middle[i],middle[j]);
					d = distance(middle[i], middle[j]);
				}
			}
		}
	}

	return d;
}
double minimum(double d, double dd){
	if(d < dd) 
		return d;
	return dd;
}
double findMinDistOptimal(){
	sortPointsByXCoord();
	findMinDistOptimal(0, numPoints);

}
double findMinDistOptimal(int start, int end){
	// Base cases
	// if(end - start <= 1) return DBL_MAX;
	// if(end - start == 3){
	// 	if(distance(pointsArr[start],pointsArr[start+1]) < distance(pointsArr[start+1],pointsArr[end])){
	// 		if(distance(pointsArr[start],pointsArr[start+1]) < distance(pointsArr[start], pointsArr[end])){
	// 			checkResults(pointsArr[start],pointsArr[start+1]);
	// 			return distance(pointsArr[start],pointsArr[start+1]);
	// 		}
	// 		else{
	// 			checkResults(pointsArr[start],pointsArr[end]);
	// 			return distance(pointsArr[start],pointsArr[end]);
	// 		}
	// 	}
	// 	else if( distance(pointsArr[start+1],pointsArr[end]) < distance(pointsArr[start],pointsArr[end])){
	// 		checkResults(pointsArr[start+1],pointsArr[end]);
	// 		return distance(pointsArr[start+1],pointsArr[end]);
	// 	}
	// 	else{
	// 		checkResults(pointsArr[start],pointsArr[start+1]);
	// 		return distance(pointsArr[start],pointsArr[start+1]);
	// 	}
	// }
	// else if(end - start == 2) 
	// 	return distance(pointsArr[start],pointsArr[end]);
	if(end - start < 4){
		return findMinDistBruteForce(start,end);
	}


	double median;
	// bool evenNumOfPts = (start+end)%2 == 0;
	// if(evenNumOfPts)
	// 	median = (pointsArr[end/2].x + pointsArr[end/2 - 1].x)/2;
	// else
	median = pointsArr[(start+end)/2].x;

	
	double min_left = findMinDistBasic(start, (start + end)/2);
	double min_right = findMinDistBasic((start + end)/2, end);
	vector<Point> middle;
	
	
	double d = minimum(min_left, min_right);

	int j = end;
	int i;
	for(i = (start+end)/2; i > start; i--){
		if(abs(pointsArr[i].x - median) <= d)
			middle.push_back(pointsArr[i]);
	}
	for(i = (start+end)/2+1; i < end; i++){
		if(abs(pointsArr[i].x - median) <= d)
			middle.push_back(pointsArr[i]);
	}

	

	//cout << "the size of the middle strip is: " << middle.size() << endl;
	for(i = 0; i < middle.size(); i ++){
		for(j = 0; j < middle.size(); j++){
			if(i == j) continue;
			if(distance(middle[i], middle[j]) < d){
				checkResults(middle[i], middle[j]);
				d = distance(middle[i], middle[j]);
			}
		}
	}
	return d;
}

bool isDuplicate(Point p)
{
	int i;
	for(i = 0; i < numPoints; i++){
		if(round(pointsArr[i].x) == round(p.x) &&  round(pointsArr[i].y == round(p.y))){
			return true;

		}
	}
	return false;
}

double round(double coordinate)
{
	long long temp = coordinate * 10000000 + 0.5; // round up
    double d = temp/10000000.0;
    return d;
}

void incrementNumPoints(){ numPoints++; }
void decrementNumPoints(){ numPoints--; }

void printAnswers(){
	for(int i = 0; i < answers.size(); i+=2){
		cout  << "(" << answers[i].x << "," << answers[i].y << ")" << "  "
			 << "(" << answers[i+1].x << "," << answers[i+1].y << ")" << endl;
	}
}