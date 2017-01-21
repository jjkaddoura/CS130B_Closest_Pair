#include <iostream>
#include <fstream>
using namespace std;



int main(int argc, char** argv){
	

  // READ INPUT FROM FILE
  string filename = "input.txt";
  ifstream file;
  file.open(filename, ifstream::in);
  string line;
  while(getline(file,line)){
    cout << line << endl;
    for(int i = 0; i < line.length(); i++){
      
    }
  }
  
  // Once input is gathered
  // begin algorithm
  string algorithmChoice = argv[1];
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
}

struct Point {
  double x;
  double y;
};		   


class ClosestPair {
  
	Point** pointsArr;

};
