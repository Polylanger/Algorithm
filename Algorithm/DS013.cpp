#include <fstream>
#include <iostream>
#include <stdlib.h>
using namespace std;

int _main() {
	ifstream inFile;
	ofstream outFile;

	outFile.open("my.dat", ios::out);
	char univ[] = "Tsinghua", name[10];
	int course = 2401, number;
	outFile << univ << endl;
	outFile << endl << endl;
	outFile << course << endl;

	inFile.open("my.dat", ios::in | ios::_Nocreate);
	if (!inFile) {
		cerr << "Can't open my.dat" << endl;
		exit(1);
	}

	char c;
	inFile >> name >> c >> number;
	outFile << "name: " << name << endl;
	outFile << "number: " << number << endl;

	return 0;
}