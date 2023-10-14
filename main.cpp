// Savarankiskas darbas v0.1.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
# include "Mano_Header.h"
void all_print(vector<Mokinys>& group);
void label_vidurkio(vector<Mokinys>& group);
void label_ND(int group_size);
int main()
{
	vector<Mokinys> Grupe;
	Mokinys mokinys;
	
	for (int i = 0; i < 1; i++) {
		
		asmens_ivestis(mokinys);
		pazymiai(mokinys);

		Grupe.push_back(mokinys);
		mokinys.~Mokinys();
	}
	// analogas C# foreach(var variable in Objekt);

	//cia galim realizuoti operacijas
	//1 vidurkiai , 2 visi namu darbai su egzu;

	
	all_print(Grupe);

	



	
}
//spausdina pagrindini vidurkio-med uzrasa LENTELE---------------------
void label_vidurkio(vector<Mokinys>& group) {
	int choice;
	cout << "Vidurkis ar Medianas ? 1: 2";
	cin >> choice;


	if (choice == 1) {


	cout << std::setw(12) << "Vardas" << std::setw(12) << "Pavarde";
	cout << std::setw(25) << " Galutinis vidurkis " << endl;
		cout << "---------------------------------------------------------------------------" << endl;
		for (auto& duom : group) duom.print_vidurkis();


	}
	else {
		cout << std::setw(12) << "Vardas" << std::setw(12) << "Pavarde";
		cout << std::setw(25) <<"Galutinis medianas " << endl;
		cout << "---------------------------------------------------------------------------" << endl;
		for (auto& duom : group)duom.print_medianas();

	}

}
//------------------------------------------------------------------------
//visu namu darbu lenteles spausdinimas
void label_ND(int group_size) {
	cout << std::setw(12) << "Pavarde" << std::setw(12) << "Vardas";
	for (int i = 0; i < group_size; i++) {
		cout << std::setw(11) << "ND" << i + 1;


	}
	cout << std::setw(12) << "Egzaminas" << endl;

}
//----------------------------------------
//cia pagrindine spausdinimo funkcija kuri marsrutizuoja konkrecia uzklausa
void all_print(vector<Mokinys>& group) {
	int pasirinkimas;
	cout << "Vidurkis[ 1.] , visi namu darbai[ 2.]" <<endl ;
	cout<<"Ka isvesti: ";
	cin >> pasirinkimas;


	if (1 == pasirinkimas) {
		
		label_vidurkio(group);

		

	}else{

		label_ND(5);

	for (auto& duom : group) duom.print_ND();



	}


	}
	
