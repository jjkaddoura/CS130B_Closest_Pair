#include <float.h>
#include <vector>
using namespace std;
#ifndef CLOSEST_PAIR_H
#define Closest_PAIR_H


struct Point {
	double x;
	double y;

	Point& operator=(const Point& point){
		this->x = point.x;
		this->y = point.y;
		return *this;
	}


};

/////////////////////////
/// MEMBERS
/////////////////////////
int numPoints;
Point* pointsArr;
const int MAX_ARRAY_SIZE = 10000000;
vector<Point> answers;


////////////////////////
/// METHODS
////////////////////////
double findMinDistBruteForce();
double findMinDistBruteForce(int start, int end);
double findMinDistBasic();
double findMinDistBasic(int start, int end);
double findMinDistOptimal();
double findMinDistOptimal(int start, int end);
double minimum(double d, double dd);
double distance(Point p1, Point p2);
double round(double coordinate);
bool isValidInput(char c);
bool isDuplicate(Point p);
void printAllPoints();
void sortPointsByXCoord();
void sortPointsByYCoord();
void sortPointsByXCoord(int start, int end);
void sortPointsByYCoord(int start, int end);
void swap(int index1, int index2);
void incrementNumPoints();
void decrementNumPoints();
int getNumPoints();
void checkResults(Point p1, Point p2);
bool isDuplicatePair(Point p1, Point p2);
void printAnswers();


#endif
