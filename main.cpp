#include <iostream>
#include <cmath>
#include <float.h>
#include "closestPair.h"
using namespace std;


int main(int argc, char* argv[]){

	numPoints = 0;
	pointsArr = new Point[MAX_ARRAY_SIZE];
	string algorithmChoice;
	// Once input is gathered
	// begin algorithm
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
	
	bool firstCoordinateOfPoint = true; 
	string line;
	string point;
	char inputChar;
	bool gotDecimal = false;
	while(getline(cin,line)){
		if(line == "EOF") return 0;
		point = "";
		for(int i = 0; i < line.length(); i++){
			inputChar = line[i];
			// If not a valid input
			// then continue and read in new input
			if(!isValidInput(inputChar) && i != line.length()-1) 
				continue;

			if(inputChar != ' ' && inputChar != '\n' && i != line.length()-1 ) {
				if(inputChar == '.'){
					if(gotDecimal) 
						continue;
					gotDecimal = true;
				}
				point += inputChar;
			}
			else if(point.length() > 0){
				
				// to get last digit of the coordinate
				if(i == line.length()-1 && inputChar >= '0' && inputChar <+ '9'){
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
					 pointsArr[numPoints].y = atof(point.c_str());
					 numPoints++;
					 firstCoordinateOfPoint = true;
					 point = "";
					 gotDecimal = false;
				}
				
			}

		}
	}
  
 
}