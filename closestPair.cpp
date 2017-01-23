#include <iostream>
#include <fstream>
using namespace std;


struct Point {
  double x;
  double y;
};

// Point& operator=(const Point& point){
// 	this.x = point.x;
// 	this.y = point.y;
// 	return *this;
// }
bool isValidInput(char c);
void printAllPoints();
void sortPointsByXCoord();
void sortPointsByYCoord();
void swap(int index1, int index2);


static const int MAX_ARRAY_SIZE = 100;
static int numPoints = 0;
Point* pointsArr =  new Point[MAX_ARRAY_SIZE];

int main(int argc, char* argv[]){
	
	string algorithmChoice;
	bool firstCoordinateOfPoint = true; 

  // READ INPUT FROM FILE
  string filename = "input.txt";
  ifstream file;
  file.open(filename, ifstream::in);
  string line;
  string point;
  char inputChar;
  bool gotDecimal = false;
  while(getline(file,line)){
  	point = "";
    for(int i = 0; i < line.length(); i++){
    	inputChar = line[i];

    	// If not a valid input
    	// then read in new input
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
  
  // Once input is gathered
  // begin algorithm
  if(argc > 2)
  	algorithmChoice = argv[1];


  if(argc < 2){
    cout << "Please include an argument: brute, basic,"
	 << " or optimal to indicate which method to use." << endl;
    return 0;
  }
  if(algorithmChoice == "brute"){
    cout << "Initiating the brute force algrothim" << endl;
  } 
  else if(algorithmChoice == "basic") {
    cout << "Initiating the basic algorthim!" << endl;
  }
  else if(algorithmChoice == "optimal") {
    cout << "Initiating the optimal algorithm!" << endl;
    
  }
  else if(algorithmChoice == "EOF"){
    cout << "END OF FILE" << endl;
  }
  file.close();

  cout << "initial print" << endl;
  printAllPoints();
  sortPointsByXCoord();
  cout << "after sorting by X coordinate" << endl;
  printAllPoints();
  cout << "after sorting by y coordinate" << endl;
  sortPointsByYCoord();
  printAllPoints();
}

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
	bool outOfOrder = true;
	while(outOfOrder){
		outOfOrder = false;
		for(int i = 1; i < numPoints; i++){
			if(pointsArr[i-1].y > pointsArr[i].y){
				
				swap(i-1,i);
				outOfOrder = true;
				

			}

		}
	}
}

void swap(int index1, int index2){
	double tempX = pointsArr[index1].x;
	double tempY = pointsArr[index1].y;
	pointsArr[index1].x = pointsArr[index2].x;
	pointsArr[index1].y = pointsArr[index2].y;
	pointsArr[index2].x = tempX;
	pointsArr[index2].y = tempY;
}