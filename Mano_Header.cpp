#include "Mano_Header.h"



Mokinys::Mokinys() {




}
//pildymo konstruktorius
Mokinys::Mokinys(string name , string surname , vector<int> grades , int result) {
	vardas = name;
	pavarde = surname;
	pazymiai = grades;
	egzam_result = result;
	//cout << "Sukurtas pildymas" << endl;
	
}


//operatorius priskiriantis reiksmes
Mokinys& Mokinys::operator=(const Mokinys &mokinys) {
	if (this == &mokinys)return *this;
	vardas = mokinys.vardas;
	pavarde = mokinys.pavarde;
	pazymiai = mokinys.pazymiai;
	egzam_result = mokinys.egzam_result;
	pazymiu_vidurkis = mokinys.pazymiu_vidurkis;

	return *this;
}

//destruktorius--------
Mokinys::~Mokinys() {
	vardas.clear();
	pavarde.clear();
	pazymiai.clear();


}


	
//Metodai-------------------------------------
float Mokinys::pazymio_vidurkis(bool priskyrimas) {

	float vidurkis = std::accumulate(Mokinys::pazymiai.begin(), Mokinys::pazymiai.end(), 0);
	vidurkis /= Mokinys::pazymiai.size();
	if (priskyrimas==true)  SetVidurkis(vidurkis); 



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
	cout << std::setw(16) << pazymio_vidurkis(false) << endl;

}

void Mokinys::print_medianas() {
	cout << std::setw(12) << vardas << std::setw(12) << pavarde;
	cout << std::setw(16) << pazymio_medianas() << endl;



}

void Mokinys::print_ND() {
	cout << std::setw(12)<<vardas<< std::setw(12)<< pavarde;
	for (auto& skaicius : pazymiai) cout <<std::setw(11)<< skaicius;
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

void Mokinys::SetVidurkis(float average) {
	pazymiu_vidurkis = average;
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

void failo_skaitymas(vector<Mokinys>& group, Mokinys& student, int n) {
	auto start = std::chrono::high_resolution_clock::now();auto st = start;
	string path = "sarasas/Kursiokai" + std::to_string(n) + ".txt";
	std::ifstream skaitymas(path);
	int index = 0;
	int skaiciavimas = -1;
	int dis = 2;
	int skaic;
	std::string zodis="";
	std::string vardas;
	std::string pavarde;

	vector <int> temp_pazymiai;
	
	if (skaitymas.is_open()) {
	
		//nuskaito pirma eilute iki egz. kad suzinoti kiek namu darbu
		while (skaitymas >> zodis  ) {
			//cout << zodis << endl;
			skaiciavimas += 1;
			if (zodis == "egz.") { break; }
	

		}
		
	
		

		cout << "Faile yra " << skaiciavimas-2 <<"namu darbu"<<endl;


		cout << "---------------------------" << endl;
		//cia realizuotas duomenu perdavimas i kintamuosius----------------------------------
		while (!skaitymas.eof()) {
			//cia nuskaito pavarde
				if (index <1) { skaitymas >> zodis,pavarde=zodis, index += 1; }

				//cia varda
			if (index >=1 && index<2) { skaitymas >> zodis, vardas=zodis, index += 1; }
	
			//cia namu darbai
			if (index == 2 && dis!=skaiciavimas) { skaitymas >> skaic, temp_pazymiai.push_back(skaic), dis += 1; }

			
			//cia inicializuojame perdavima i studenta ir i vectoriu Grupe
			if (dis == skaiciavimas) { 
				skaitymas >> skaic;
				//	Mokinys studentas(vardas,pavarde,temp_pazymiai,skaic);
				student.SetVardas(vardas);
				student.SetPavarde(pavarde);
					student.SetEgzaminas(skaic),
					student.SetPazymiai(temp_pazymiai),
					student.SetPaz_sk(skaiciavimas-2),
					group.push_back(student),
					student.~Mokinys(),
					temp_pazymiai.clear();
					index = 0,
					dis = 2; }

		}
		
	
	
		/*	skaitymas >> zodis;
		cout << zodis << endl;*/

		skaitymas.close();
		auto end = std::chrono::high_resolution_clock::now();
		std::chrono::duration<double> diff = end - start;
		cout << "///////////////ATLIKIMO GREITIS//////////////////" << endl;
		cout << "nuskaityta per: " << diff.count()<<endl;
		cout << "//////////////////////////////////////////////////" << endl;

	
	}
	else {
		cout << "Failo negalima atidaryti arba jo nera" << endl;
		
	
		


	}




}


void failo_skaitymas_v2(vector<Mokinys>& group, Mokinys& student) {
	auto start = std::chrono::high_resolution_clock::now(); auto st = start;
	std::ifstream input("kursiokai.txt"); // Atidaryti failą skaitymui

	if (!input.is_open()) {
		std::cerr << "Nepavyko atidaryti failo kursiokai.txt" << std::endl;
		return; // Grįžti, jei nepavyko atidaryti failo
	}

	std::string line;

	while (std::getline(input, line)) {
		std::istringstream iss(line);
		std::string vardas, pavarde;
		iss >> vardas >> pavarde;

		std::vector<int> pazymiai;
		int pazymys;
		while (iss >> pazymys) {
			pazymiai.push_back(pazymys);
		}

		// Sukurti objektą Mokinys ir įdėti jį į vektorių
			student.SetEgzaminas(pazymiai.back()),
				pazymiai.pop_back(),
			student.SetPazymiai(pazymiai),		
			group.push_back(student),
		
		group.push_back(student);
			student.~Mokinys(),
			pazymiai.clear();	
	}

	input.close(); // Uždaryti failą
	auto end = std::chrono::high_resolution_clock::now();
	std::chrono::duration<double> diff = end - start;
	cout << "nuskaityta per " << diff.count() << endl;





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
	cout << endl;
}


void Mokinys::pazymiai_itext(std::ofstream& skaitymas) {

	skaitymas << std::setw(15) << Get_Vardas() << std::setw(15) << Get_Pavarde() << std::setw(5);

	for (int l = 0; l < pazymiai.size(); l++) {


		skaitymas << std::setw(12) << pazymiai[l];
	}

	skaitymas << std::setw(12) << egzam_result << endl;






}






//----------------------------------------
// 
//
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
				
		for (auto& duom : group) label_ND(duom.Get_pazSk()), duom.print_ND();



	}


}
void all_print_v2(vector<Mokinys>& group) {
if (group.size()==0) {
		cout << "sarasas tuscias" << endl;
		return;
	}
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
