#include <iostream>
#include <fstream>
using namespace std;

struct Point {
  double x;
  double y;
};

bool isValidInput(char c);
void printAllPoints();
static const int MAX_ARRAY_SIZE = 100;
static int numPoints = 0;
Point* pointsArr = new Point[MAX_ARRAY_SIZE];


int main(int argc, char** argv){
	
	string algorithmChoice;
	// int numPoints = 0;
	bool firstCoordinateOfPoint = true; 
	
	


  // READ INPUT FROM FILE
  string filename = "input.txt";
  ifstream file;
  file.open(filename, ifstream::in);
  string line;
  char inputChar;
  while(getline(file,line)){
  	string point = "";
    for(int i = 0; i < line.length(); i++){
    	inputChar = line[i];
    	if(!isValidInput(inputChar)) 
    		continue;
    
    	if(inputChar != ' ' && inputChar != '\n' && i != line.length()-1 ) {
    		point += inputChar;
    	}
    	else if(point.length() > 0){
    		if(i == line.length()-1){
    				cout << "GOOOD" << endl;
    				point += inputChar;
    			}
    		if(firstCoordinateOfPoint) {
    			// to get last digit of the coordinate
    			
    			double coordinate = atof(point.c_str());
    			pointsArr[numPoints].x = coordinate;
    			
    			firstCoordinateOfPoint = false;
    			point = "";
    		}
    		else{
    			 pointsArr[numPoints].y = atof(point.c_str());
    			 numPoints++;
    			 firstCoordinateOfPoint = true;
    			 point = "";
    			// break;
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


  printAllPoints();
}


void printAllPoints(){
	cout << numPoints << endl;
	for(int i =0; i < numPoints; i++){
		cout << i << ". x: " << pointsArr[i].x << " y: " << pointsArr[i].y << endl;
	}
}
bool isValidInput(char c){
	if((c >='0' && c <= '9' ) || 
		c == ' ' || c== '\n' || c == '.') return true;
	return false;
}