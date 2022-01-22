#include "Replay.h"
#include <iostream>
#include <fstream>
using namespace std;


/*
	int argc: è un parametro di tipo intero. Rappresenta il
	numero degli argomenti effettivamente passati al
	programma nella linee di comando con cui si invoca la
	sua esecuzione. Anche il nome stesso del programma
	(nell'esempio, prog) è considerato un argomento,
	quindi argc vale sempre almeno 1

	---

	char **argv: è un puntatore a un puntatore a
	carattere, ovvero un array di stringhe.
	Ciascuna stringa nel vettore contiene un diverso
	argomento. Gli argomenti sono memorizzati nel vettore
	nell'ordine con cui sono dati dall'utente.
	argv[0] contiene il nome del programma stesso

*/
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
		rep.stampaSchermo("Test.txt");

	}


	cout << "-----fine partita-----" << endl;
	return 0;
}

