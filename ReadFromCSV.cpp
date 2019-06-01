#include "ReadFromCSV.h"
#include <iostream>
#include <iomanip>
#include <fstream>
#include "vector"
#include <string>
#include <sstream>
using namespace std;

ReadFromCSV::ReadFromCSV()
{
	
}


ReadFromCSV::~ReadFromCSV()
{
}

void ReadFromCSV:: read_record()
{
	fstream fin;
	int ** blocksInFiles =NULL;
	int * sizes = NULL;
	// Open an existing file 
	fin.open("C:/Users/naors/Downloads/as.csv", ios::in);
	if (fin.is_open())
	{
		cout << "File opened successfully" << "\n";
	}
	else {
		cout << "Error opening file" << "\n";
	}
	string line;
	int numOfFIles;
	int numOfBLocks;
	while (getline(fin, line)) {
		if (line.find("Num files") != string::npos) {
			stringstream ss(line);
			string temp;
			int found;
			while (!ss.eof()) {
				ss >> temp;
				if (stringstream(temp) >> found)
					numOfFIles = found;
				temp = "";
			}
			blocksInFiles = (int **)malloc(numOfFIles * sizeof(int *));
		}

		if (line.find("Num blocks")!= string::npos) {
			stringstream ss(line);
			string temp;
			int found;
			while (!ss.eof()) {
				ss >> temp;
				if (stringstream(temp) >> found)
					numOfBLocks = found;
				temp = "";
			}
			for (int i = 0; i<numOfFIles; i++)
				blocksInFiles[i] = (int *)calloc(numOfBLocks ,sizeof(int));
			sizes = (int *)malloc(numOfBLocks * sizeof(int));
		}
		if (line.find("F") == 0) {
			std::vector<string> vect;
			stringstream ss(line);
			while (ss.good()) {
				string substr;
				getline(ss, substr, ',');
				vect.push_back(substr);
			}
			int fileID = std::stoi(vect[1]);
			int blocks = std::stoi(vect[4]);
			int blockID;
			int blockC = 0;
			for(int i=5;i<5+blocks;i++){
				blockID = std::stoi(vect[i]);
				blocksInFiles[fileID][blockID] = 1;
				i++;
				sizes[blockC] = std::stoi(vect[i]);
				blockC++;
			}
		}
	}
	cout << "As" << endl;
}