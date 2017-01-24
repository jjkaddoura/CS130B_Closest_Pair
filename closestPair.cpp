#include <iostream>
#include <fstream>
#include <float.h>
#include <cmath>
#include "closestPair.h"
using namespace std;


void printAllPoints(){
	for(int i =0; i < numPoints; i++){
		cout << i+1 << ") x: " << pointsArr[i].x << " y: " << pointsArr[i].y << endl;
	}
}
bool isValidInput(char c){
	if((c >='0' && c <= '9' ) || 
		c == ' ' || c== '\n' || c == '.') return true;
	return false;
}

void sortPointsByXCoord(){
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

void sortPointsByYCoord(){
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

void swap(int index1, int index2){
	Point temp = pointsArr[index1];
	pointsArr[index1] = pointsArr[index2];
	pointsArr[index2] = temp;
}

double distance(Point p1, Point p2){
	return sqrt((p2.x-p1.x) * (p2.x - p1.x) + (p2.y-p1.y)*(p2.y-p1.y));
}

double bruteForce(){
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

bool checkDuplicate(Point p){
	for(int i = 0; i < numPoints; i++){
		if(pointsArr[i].x == 1) return true;
	}
}