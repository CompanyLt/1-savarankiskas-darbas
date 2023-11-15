#include "Mano_Header.h"
//Saraso sukurimas v0.1

//SARASU sukurimas i txt vector------------------------------------------------
void Saraso_Sukurimas(vector<Mokinys>& List, string file_name) {
	auto start = std::chrono::high_resolution_clock::now();
	std::ofstream Sukurimas("ataskaitos/" + file_name + ".txt");
	label_itexta(Sukurimas, List.front().Get_pazSk());

	for (auto& list : List) {
		list.pazymiai_itext(Sukurimas);

	}

	Sukurimas.close();
	auto end = std::chrono::high_resolution_clock::now();
	std::chrono::duration<double> diff = end - start;
	cout << "////////////ATLIKIMO GREITIS////////////////////" << endl;
	cout << "Ataskaitos isvedimas i faila uztruko: " << diff.count() << endl;
	cout << "////////////////////////////////////////////////" << endl;


}
//SARASU sukurimas i txt list------------------------------------------------
void Saraso_Sukurimas_list(list<Mokinys>& List, string file_name) {
	
	auto start = std::chrono::high_resolution_clock::now();
	std::ofstream Sukurimas("ataskaitos/" + file_name + ".txt");
	label_itexta(Sukurimas, List.front().Get_pazSk());

	for (auto& list : List) {
		list.pazymiai_itext(Sukurimas);

	}

	Sukurimas.close();
	auto end = std::chrono::high_resolution_clock::now();
	std::chrono::duration<double> diff = end - start;
	cout << "////////////ATLIKIMO GREITIS////////////////////" << endl;
	cout << "Ataskaitos isvedimas i faila uztruko: " << diff.count() << endl;
	cout << "////////////////////////////////////////////////" << endl;


}

//Iraso pazymius i faila
void Mokinys::pazymiai_itext(std::ofstream& skaitymas) {

	skaitymas << std::setw(15) << Get_Vardas() << std::setw(15) << Get_Pavarde() << std::setw(5);

	for (int l = 0; l < pazymiai.size(); l++) {


		skaitymas << std::setw(12) << pazymiai[l];
	}

	skaitymas << std::setw(12) << egzam_result << endl;

}

//----------------------------------------








