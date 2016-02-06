#include "coding.h"
#include <iostream>
#include <fstream>
#include <string>

int main(int argc, char* argv[]){
	using namespace std;
	if(argc!=2){
		cerr << "Err nbr arg" << endl;
		exit(1);
	}
	string arg = argv[1];
	ifstream input(arg+".enc");
	ofstream output(arg+".dec");
	if (!input) { 
		cerr << "Could not open: " << arg+".enc" << endl;
		exit(1);
	}
	if (!output) { 
		cerr << "Could not open: " << arg+".dec" << endl;
		exit(1);
	}
	
	while (true) {
		char c = 0;
		input.get(c);
		if(!c)
			break;
		output.put(Coding::decode(c));
	}
	cout << endl;
	input.close();
}