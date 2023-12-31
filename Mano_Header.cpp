#include "Mano_Header.h"


Mokinys::Mokinys() {
	cout << "Sukurtas" << endl;



}
//pildymo konstruktorius
Mokinys::Mokinys(string name , string surname , vector<int> grades , int result) {
	vardas = name;
	pavarde = surname;
	pazymiai = grades;
	
}


//operatoriai
Mokinys& Mokinys::operator=(const Mokinys &mokinys) {
	if (this == &mokinys)return *this;
	vardas = mokinys.vardas;
	pavarde = mokinys.pavarde;
	pazymiai = mokinys.pazymiai;


	return *this;
}

//destruktorius--------
Mokinys::~Mokinys() {
	vardas.clear();
	pavarde.clear();
	pazymiai.clear();


}


	
//Metodai-------------------------------------
float Mokinys::pazymio_vidurkis() {

	float vidurkis = std::accumulate(Mokinys::pazymiai.begin(), Mokinys::pazymiai.end(), 0);
	vidurkis /= Mokinys::pazymiai.size();
	return vidurkis;
}

float Mokinys::pazymio_medianas() {
	float medianas;
	std::sort(pazymiai.begin(), pazymiai.end());

	if (pazymiai.size() % 2 == 1) {
		// Nelyginis skaičius elementų, medianą gauname tiesiog vidurinio elemento reikšmė
		medianas = pazymiai[pazymiai.size() / 2];
	}
	else {
		// Lyginis skaičius elementų, medianą gauname dviejų vidurinių elementų vidurkį
		int vidurinis1 = pazymiai[(pazymiai.size() - 1) / 2];
		int vidurinis2 = pazymiai[pazymiai.size() / 2];
		medianas = (vidurinis1 + vidurinis2) / 2.0; // Dėl tikslumo paversime į double
	}
	return medianas;
}

void Mokinys::print_vidurkis() {
	cout << std::setw(12) << vardas << std::setw(12) << pavarde;
	cout << std::setw(16) << pazymio_vidurkis() << endl;

}

void Mokinys::print_medianas() {
	cout << std::setw(12) << vardas << std::setw(12) << pavarde;
	cout << std::setw(16) << pazymio_medianas() << endl;



}

void Mokinys::print_ND() {
	cout << std::setw(12)<<vardas<< std::setw(12)<< pavarde <<std::setw(12);
	for (auto& skaicius : pazymiai) cout <<std::setw(12)<< skaicius;
	cout <<std::setw(12)<<egzam_result<< endl;

}

//-----------------------------------------------------------------


//seteriai
void Mokinys::SetVardas(string name) {
	vardas = name;

}
void Mokinys::SetPaz_sk(int skaicius) {
	pazimiu_sk = skaicius;


}

void Mokinys::SetPavarde(string name) {
	pavarde = name;
}

void Mokinys::SetPazymiai(vector<int>& vec) {
	pazymiai = vec;


}

void Mokinys::SetEgzaminas(int skaicius) {
	egzam_result = skaicius;


}

//-------------------------
//geteriai-------------------


//Funkcijos--------------------------------------------
void asmens_ivestis(Mokinys& student) {
	string temp;
	char temp_1;
	cout << "Iveskite varda: ";
	cin >> temp;
	student.SetVardas(temp);
	cout << "Iveskite pavarde: ";
	cin >> temp;
	student.SetPavarde(temp);

}

void pazymiai(Mokinys& student) {
	int temp;
	vector<int> temp_pazymiai;
	cout << "Iveskite pazimiu kieki?";
	cin >> temp;
	student.SetPaz_sk(temp);
	for (int i = 0; i < temp; i++) {
		short int temp2;
		cout << "Iveskite pazymi";
		cin >> temp2;
		temp_pazymiai.push_back(temp2);



	}

	cout << "Iveskite egzamino rezultata ";
	cin >> temp;
	student.SetEgzaminas(temp);
	student.SetPazymiai(temp_pazymiai);
	cout << endl;
}
//spausdina pagrindini vidurkio-med uzrasa LENTELE---------------------
void label_vidurkio(vector<Mokinys>& group) {
	int choice;
	cout << "Vidurkis[ 1.] , Medianas[ 2.] ";
	cin >> choice;


	if (choice == 1) {


		cout << std::setw(12) << "Vardas" << std::setw(12) << "Pavarde";
		cout << std::setw(25) << " Galutinis vidurkis " << endl;
		cout << "---------------------------------------------------------------------------" << endl;
		for (auto& duom : group) duom.print_vidurkis();


	}
	else {
		cout << std::setw(12) << "Vardas" << std::setw(12) << "Pavarde";
		cout << std::setw(25) << "Galutinis medianas " << endl;
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
	cout << "Vidurkis[ 1.] , visi namu darbai[ 2.]" << endl;
	cout << "Ka isvesti: ";
	cin >> pasirinkimas;


	if (1 == pasirinkimas) {

		label_vidurkio(group);



	}
	else {
		
		label_ND(group[0].Get_pazSk());
		
		for (auto& duom : group) duom.print_ND();



	}


}
