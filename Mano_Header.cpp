#include "Mano_Header.h"

Mokinys::Mokinys() {

}
//pildymo konstruktoriai
Mokinys::Mokinys(string name , string surname , vector<int> grades , int result) {
	vardas = name;
	pavarde = surname;
	pazymiai = grades;
	egzam_result = result;
		
}

Mokinys::Mokinys(string name, string surname, vector<int> grades, int result,int paz_skaicius) {
	vardas = name;
	pavarde = surname;
	pazymiai = grades;
	egzam_result = result;
	pazimiu_sk = paz_skaicius - 2;
	pazymio_vidurkis(true);
	
}
//-------------------------------------------------------------------------------------------------

// kopijavimo operatorius priskiriantis reiksmes
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
//-----------------------------------------------------------------


//SETERIAI
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
int Mokinys::Get_pazSk() {
	return pazimiu_sk;
}
string Mokinys::Get_Vardas() {
	return vardas;
}
string Mokinys::Get_Pavarde() {
	return pavarde;
}
int Mokinys::Get_Egzaminas() {
	return egzam_result;
}
vector<int>Mokinys::Get_Pazymiai() {
	return pazymiai;
}

float Mokinys::Get_Vidurkis() {

	return pazymiu_vidurkis;
}


//METODAI-------------------------------------
//Metodas kuris gali isvesti vidurki pre priskyrimo jei false, true priskiria;
float Mokinys::pazymio_vidurkis(bool priskyrimas) {

	float vidurkis = std::accumulate(Mokinys::pazymiai.begin(), Mokinys::pazymiai.end(), 0);
	vidurkis /= Mokinys::pazymiai.size();
	if (priskyrimas == true) {
		SetVidurkis(vidurkis);
	}



	return vidurkis;
}
//mediano apskaiciavimo metodas
float Mokinys::pazymio_medianas() {
	float medianas;
	std::sort(pazymiai.begin(), pazymiai.end());

	if (pazymiai.size() % 2 == 1) {
		medianas = pazymiai[pazymiai.size() / 2];
	}
	else {

		int vidurinis1 = pazymiai[(pazymiai.size() - 1) / 2];
		int vidurinis2 = pazymiai[pazymiai.size() / 2];
		medianas = (vidurinis1 + vidurinis2) / 2.0; // 
	}
	return medianas;
}
/////////////////////////////////////////////////////////////////

//Funkcijos--------------------------------------------
//FAILO SKAITYMO FUNKCIJA-----------------------------------------------------


void failo_skaitymas_buffer(Konteineriai& container, int n, int container_type) {
	auto start = std::chrono::high_resolution_clock::now(); auto st = start;
	string path = "sarasas/Kursiokai" + std::to_string(n) + ".txt";
	std::ifstream skaitymas(path);
	int skaic;
	std::string zodis = ""; std::string vardas; std::string pavarde;
	vector <int> temp_pazymiai;
	skaitymas.seekg(0, std::ios::end);

	std::streampos dydis = skaitymas.tellg();

	skaitymas.seekg(0, std::ios::beg);

	std::vector<char> buferis(dydis);

	skaitymas.read(buferis.data(), dydis);
	skaitymas.close(); // Uždarome failą

	//std::istringstream iss(std::string(buferis.data(), dydis));
	
	//cout << buferis.data();
	std::string eilute(buferis.begin(), buferis.end());
	//cout << eilute << endl;
	std::istringstream iss(eilute);
	string eile;

int nd1=0, nd2=0, nd3=0, nd4, nd5, nd6, nd7, nd8;
	std::getline(iss, eile);

	
	while (iss >> vardas >> pavarde >> nd1 >> nd2 >> nd3 >> nd4 >> nd5 >> nd6>>nd7>>nd8) {
	//	cout << vardas << pavarde << nd1 << nd2 << nd3 << nd4 << nd5 << nd6 << nd7 << nd8 << "dsd"<<endl;
		vector <int> temp_pazymiai = { nd1, nd2, nd3, nd4, nd5,nd6, nd7 };
		Mokinys mokinys(vardas,pavarde,temp_pazymiai,nd8,6);
			
		container.Grupe.push_back(mokinys);

	}


	auto end = std::chrono::high_resolution_clock::now();
	std::chrono::duration<double> diff = end - start;
	cout << "///////////////ATLIKIMO GREITIS//////////////////" << endl;
	cout << "nuskaityta per: " << diff.count() << endl;
	cout << "//////////////////////////////////////////////////" << endl;

}
//Pag failo skaitymas-veikaintis
void failo_skaitymas_new(Konteineriai& container, int n,int container_type) {
	auto start = std::chrono::high_resolution_clock::now(); auto st = start;
	string path = "sarasas/Kursiokai" + std::to_string(n) + ".txt";
	std::ifstream skaitymas(path);
	int index = 0;
	int skaiciavimas = -1;
	int dis = 2;
	int skaic;
	std::string zodis = ""; std::string vardas; std::string pavarde;

	vector <int> temp_pazymiai;

	if (skaitymas.is_open()) {

		//nuskaito pirma eilute iki egz. kad suzinoti kiek namu darbu
		while (skaitymas >> zodis) {
			//cout << zodis << endl;
			skaiciavimas += 1;
			if (zodis == "egz.") { break; }
			//if (skaiciavimas > 20) { system("cls"), cout << "Failas neteisingas" << endl; exit; }

		}
		cout << "Faile yra " << skaiciavimas - 2 << "namu darbu" << endl;


		cout << "---------------------------" << endl;
		skaitymas.ignore();
		//cia realizuotas duomenu perdavimas i kintamuosius----------------------------------
	
		while (!skaitymas.eof()) {	
		
			//cia nuskaito pavarde
			if (index < 1) { skaitymas >> zodis, pavarde = zodis, index += 1; }
			//cia varda
			if (index >= 1 && index < 2) { skaitymas >> zodis, vardas = zodis, index += 1; }
			//cia namu darbai
			if (index == 2 && dis != skaiciavimas) { skaitymas >> skaic, temp_pazymiai.push_back(skaic), dis += 1; }

			//cia inicializuojame perdavima i studenta ir i vectoriu Grupe
			if (dis == skaiciavimas) {
				skaitymas >> skaic;
				//	Mokinys studentas(vardas,pavarde,temp_pazymiai,skaic);

			//	Mokinys mok(vardas, pavarde, temp_pazymiai, skaic, skaiciavimas);
				container.mokinys.SetVardas(vardas);
				container.mokinys.SetPavarde(pavarde);
				container.mokinys.SetPazymiai(temp_pazymiai);
				container.mokinys.SetEgzaminas(skaic);
				container.mokinys.SetPaz_sk(skaiciavimas);
				container.mokinys.pazymio_vidurkis(true);
				temp_pazymiai.clear();
				switch (container.container_type)
				{
				case 1:		

					container.Grupe.push_back(container.mokinys),
						container.mokinys.~Mokinys(),
					
					index = 0;dis = 2;				
					break;
				case 2:				
						container.Grupe1.push_back(container.mokinys),
							container.mokinys.~Mokinys(),					
						
					index = 0,dis = 2;					
					break;				
				default:
					break;
				}
				index = 0, dis = 2;				
			}

		}
		skaitymas.close();
		auto end = std::chrono::high_resolution_clock::now();
		std::chrono::duration<double> diff = end - start;
		cout << "///////////////ATLIKIMO GREITIS//////////////////" << endl;
		cout << "nuskaityta per: " << diff.count() << endl;
		cout << "//////////////////////////////////////////////////" << endl;
	}
	else {
		cout << "Failo negalima atidaryti arba jo nera" << endl;
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


