//PANOZZO ELISA SILENE

#include "Replay.h"
#include <iostream>
#include <fstream>
using namespace std;


int main(int argc, char* argv[]) {


	/*
	argomento v [nome_file_log]: stampa a video il replay del file di log indicato;
	argomento f [nome_file_log] [nome_file_output_replay]: scrive su file il replay del
		file di log indicato.
	
	*/

	Replay rep;

	if (argc == 2) {
		rep.stampaSchermo(argv[1]);
	}

	else if (argc == 3) {
		rep.stampaSuFile(argv[1], argv[2]);
	}

	else {
		try {
			rep.stampaSchermo("Test.txt");
		}
		catch (Exception& e) {
			cout << e.what() << endl;
		}

	}


	cout << "-----fine partita-----" << endl;
	return 0;
}

