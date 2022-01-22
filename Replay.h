#ifndef REPLAY_H
#define REPLAY_H
#include <iostream>
#include <fstream>
#include <list>
#include <string>
#include "Exception.h"

#include <chrono>
#include <thread>


using namespace std;
class Replay {
private:
	static const int rig = 8;
	static const int col = 8;
	char replay[rig][col];

	ofstream out;	//per output su file
	ifstream file;	//per input da file

public:
	Replay();
	void stampaSchermo(string nome_file);
	void stampaSuFile(string nome_file_log, string file_output);

	void print();

	~Replay() {}
};
#endif