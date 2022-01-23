//PANOZZO ELISA SILENE

#include "Replay.h"


using namespace std;
Replay::Replay() {
	for (int riga = 2; riga <= 5; riga++) {
		for (int colonna = 0; colonna < 8; colonna++) {
			replay[riga][colonna] = ' ';
		}
	}
	//parte bianca
	for (int colonna = 0; colonna < 8; colonna++) {
		replay[1][colonna] = 'p';
	}

	replay[0][0] = 't';
	replay[0][1] = 'c';
	replay[0][2] = 'a';
	replay[0][3] = 'd';
	replay[0][4] = 'r';
	replay[0][5] = 'a';
	replay[0][6] = 'c';
	replay[0][7] = 't';

	//parte nera
	for (int colonna = 0; colonna < 8; colonna++) {
		replay[6][colonna] = 'P';
	}

	replay[7][0] = 'T';
	replay[7][1] = 'C';
	replay[7][2] = 'A';
	replay[7][3] = 'D';
	replay[7][4] = 'R';
	replay[7][5] = 'A';
	replay[7][6] = 'C';
	replay[7][7] = 'T';


	//dichiarazione ofstream
	ofstream out;
	//dichiarazione ifstream
	ifstream file;
	
}

void Replay::stampaSuFile(string nome_file_log, string file_output) {
	//flusso d'ingresso
	ifstream file;
	file.open(nome_file_log, std::ifstream::in);

	//se ci sono problemi lancia l'eccezione
	if (!file.good()) {
		throw Exception("Problemi con l'apertura del flusso ifstream");
	}

	

	char temp;
	string line;

	//ofstream
	ofstream out;
	//apertura flusso
	out.open(file_output);

	//stampa su file
	for (int riga = 7; riga >= 0; riga--) {   //stampa su file 
		out << (riga + 1) << " ";
		for (int colonna = 0; colonna < 8; colonna++) {
			out << replay[riga][colonna];
		}
		out << endl;
	}
	out << "  " << "ABCDEFGH" << endl << endl;


	if (file.is_open()) {

		while (getline(file, line)) {	//lettura riga per riga

			//stringa line ha la riga


			//stampiamo un po' di spazio
			out << " ----------------------------------------" << endl << endl;


			int dati[4];

			string input_minuscolo = "";

			char c;
			int temp;

			char lettera;


			for (unsigned int i = 0; i < line.length(); i++) {
				//leggo un carattere della stringa
				c = line[i];

				//conversione
				temp = tolower(c);

				lettera = char(temp);

				//aggiunta alla stringa
				input_minuscolo += lettera;
			}


			//mettiamo gli indici ascii delle lettere in dati[4]
			//in dati ci sono i valori ascii di lettere e numeri
			dati[0] = input_minuscolo[0];	//colonna partenza
			dati[1] = input_minuscolo[1];	//riga partenza
			dati[2] = input_minuscolo[3];	//colonna arrivo
			dati[3] = input_minuscolo[4];	//riga arrivo

			//ora dobbiamo convertirli negli indici che usiamo nella scacchiera quindi
			//a --> 0 , b --> 1 , ... , h --> 7    per le colonne
			//1 --> 0 , 2 --> 1 , ... , 8 --> 7    per le righe

			//le due lettere minuscole
			dati[0] -= 97;
			dati[2] -= 97;

			//i due numeri
			dati[1] -= 49;
			dati[3] -= 49;

			//prendiamo il pezzo di partenza
			char pezzo = replay[dati[1]][dati[0]];
			//e lo spostiamo nella casella di arrivo
			replay[dati[3]][dati[2]] = pezzo;
			//e mettiamo lo spazio nella casella di partenza
			replay[dati[1]][dati[0]] = ' ';

			//stampa su file
			for (int riga = 7; riga >= 0; riga--) {   //stampa su file 
				out << (riga + 1) << " ";
				for (int colonna = 0; colonna < 8; colonna++) {
					out << replay[riga][colonna];
				}
				out << endl;
			}
			out << "  " << "ABCDEFGH" << endl << endl;
			

		}
		//fine while
		file.close();
		//chiusura ifstream


	}
	else {
	cout << "Non e' possibile aprire il file" << endl;
	}

	//chiusura ofstream
	out.close();

}



void Replay::stampaSchermo(string nome_file) {

	//flusso d'ingresso
	ifstream file;
	file.open(nome_file, std::ifstream::in);

	//se ci sono problemi lancia l'eccezione
	if (!file.good()) {
		throw Exception("Problemi con l'apertura del flusso ifstream");
	}
	

	char temp;
	string line;

	//ora stampiamo la scacchiera a schermo
	for (int riga = 7; riga >= 0; riga--) {
		cout << (riga + 1) << " ";
		for (int colonna = 0; colonna < 8; colonna++) {
			cout << replay[riga][colonna];
		}
		cout << endl;
	}
	cout << "  " << "ABCDEFGH" << endl << endl;

	
	if (file.is_open()) {

		while (getline(file, line)) {	//dovrebbe fare una lettura riga per riga

			//pausa di 1 secondo (o poco più)
			std::chrono::seconds dura(1);
			std::this_thread::sleep_for(dura);

			//stringa line ha la riga


			//stampiamo un po' di spazio
			cout << " ----------------------------------------" << endl << endl;
			out << " ----------------------------------------" << endl << endl;


			int dati[4];

			string input_minuscolo = "";

			char c;
			int temp;

			char lettera;


			for (unsigned int i = 0; i < line.length(); i++) {
				//leggo un carattere della stringa
				c = line[i];

				//conversione
				temp = tolower(c);

				lettera = char(temp);

				//aggiunta alla stringa
				input_minuscolo += lettera;
			}

			//mettiamo gli indici ascii delle lettere in dati[4]
			//in dati ci sono i valori ascii di lettere e numeri
			dati[0] = input_minuscolo[0];	//colonna partenza
			dati[1] = input_minuscolo[1];	//riga partenza
			dati[2] = input_minuscolo[3];	//colonna arrivo
			dati[3] = input_minuscolo[4];	//riga arrivo

			//ora dobbiamo convertirli negli indici che usiamo nella scacchiera quindi
			//a --> 0 , b --> 1 , ... , h --> 7    per le colonne
			//1 --> 0 , 2 --> 1 , ... , 8 --> 7    per le righe

			//le due lettere minuscole
			dati[0] -= 97;
			dati[2] -= 97;

			//i due numeri
			dati[1] -= 49;
			dati[3] -= 49;


			//prendiamo il pezzo di partenza
			char pezzo = replay[dati[1]][dati[0]];
			//e lo spostiamo nella casella di arrivo
			replay[dati[3]][dati[2]] = pezzo;
			//e mettiamo lo spazio nella casella di partenza
			replay[dati[1]][dati[0]] = ' ';


			//ora stampiamo la scacchiera a schermo
			for (int riga = 7; riga >= 0; riga--) {
				cout << (riga + 1) << " ";
				for (int colonna = 0; colonna < 8; colonna++) {
					cout << replay[riga][colonna];
				}
				cout << endl;
			}
			cout << "  " << "ABCDEFGH" << endl << endl;




		}
		//fine while
		file.close();
		//chiusura ifstream


	}
	else {
		cout << "Non e' possibile aprire il file" << endl;
	}

	//chiusura ofstream
	out.close();



}
