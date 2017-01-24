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
static const int MAX_ARRAY_SIZE = 100;
static int numPoints;
static Point* pointsArr;
static double minDistance = DBL_MAX;

////////////////////////
/// METHODS
////////////////////////
bool isValidInput(char c);
void printAllPoints();
void sortPointsByXCoord();
void sortPointsByYCoord();
void swap(int index1, int index2);
double distance(Point p1, Point p2);
double bruteForce();


#endif
