#include <iostream>
#include <fstream>
#include <float.h>
#include <cmath>
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
				point += inputChar;
			}
			else if(point.length() > 0)
			{
				
				// to get last digit of the coordinate
				if(i == line.length()-1 && inputChar >= '0' && inputChar <+ '9')
				{
					if(inputChar == '.'){
						if(gotDecimal) 
							continue;
						gotDecimal = true;
					}
						point += inputChar;
				}

				// Set the X coordiante
				if(firstCoordinateOfPoint) {
					double coordinate = atof(point.c_str());
					pointsArr[numPoints].x = coordinate;
					
					firstCoordinateOfPoint = false;
					point = "";
					gotDecimal = false;
				}
				// Set the y coordinate
				else{
					cout << "made it into if" << endl;

					 pointsArr[numPoints].y = atof(point.c_str());
					 firstCoordinateOfPoint = true;
					 point = "";
					 gotDecimal = false;
					 addPoint();
					 // if(!isDuplicate(pointsArr[numPoints+1])) 
					 // 	numPoints++;

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
			cout << "Initiating the brute force algrothim" << endl;
			cout << "The minimum distance between all points is: " << bruteForce() << endl;
		} 
		else if(algorithmChoice == "basic") {
			cout << "Initiating the basic algorthim!" << endl;
		}
		else if(algorithmChoice == "optimal") {
			cout << "Initiating the optimal algorithm!" << endl;
		}
  	
  	
 
}

void printAllPoints()
{
	cout << numPoints << endl;
	for(int i = 0; i < numPoints; i++){
		cout << i+1 << ") x: " << pointsArr[i].x << " y: " << pointsArr[i].y << endl;
	}
}
bool isValidInput(char c)
{
	if((c >='0' && c <= '9' ) || 
		c == ' ' || c== '\n' || c == '.') return true;
	return false;
}

void sortPointsByXCoord()
{
	bool outOfOrder = true;
	cout << "sorting the points by X" << endl;
	while(outOfOrder){
		outOfOrder = false;
		for(int i = 1; i < numPoints; i++){
			if(pointsArr[i-1].x > pointsArr[i].x){
				swap(i-1,i);
				outOfOrder = true;
			}

		}
	}
}

void sortPointsByYCoord()
{
	int i;
	bool outOfOrder = true;
	while(outOfOrder){
		outOfOrder = false;
		for(i = 1; i < numPoints; i++){
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

double bruteForce()
{
	int i,j;
	double d;
	for(i = 0; i < numPoints; i++){
		for(j = 0; j < numPoints; j++){
			if(i == j) continue;
			d = distance(pointsArr[i],pointsArr[j]);
			if(d < minDistance)
				minDistance = d;
		}
	}
	return minDistance;
}

bool isDuplicate(Point p)
{
	for(int i = 0; i < numPoints; i++){
		if(round(pointsArr[i].x) == round(p.x) && 
			round(pointsArr[i].y == round(p.y)))
			return true;
	}
	return false;
}

double round(double coordinate)
{
	long long temp = coordinate * 10000000 + 0.5; // round up
    double d = temp/10000000.0;
    return d;
}

int getNumPoints(){ return numPoints; }

void addPoint(){ numPoints++; }