#include <iostream>
#include <stdlib.h>
#include <time.h>
using namespace std;

int main(int argc, char* argv []){

	int n;

	if(argc != 2){
		cout << "Please run program with one integer, n, as an argument "
		<< "for the amount of points to generate" << endl;
		exit(0);

	}


	srand(time(NULL));

	for (int i = 0; i < atoi(argv[1]); i++) {
		int max = -10000;
		int min = 10000;
		double random_one = min + (max-min)*(double)rand()/RAND_MAX;
		double random_two = min + (max-min)*(double)rand()/RAND_MAX;
		cout << random_one << " " << random_two << endl;
	}

}
