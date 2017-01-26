#include <iostream>
using namespace std;

int main(int argc, char* argv []){

	int n;

	if(argc != 2){
		cout << "Please run program with one integer, n, as an argument "
		<< "for the amount of points to generate" << endl;
		exit(0);

	}

	n = atoi(argv[1]);

	for(int i = 0; i < n; i++){
		cout << "jacob is awesome!!!" << endl;
	}


}
