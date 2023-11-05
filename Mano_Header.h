#pragma once

//Deklaracijos
#include <vector>
#include <string>
#include <iostream>
#include <numeric>
#include <iomanip>
#include <algorithm>
#include <fstream>
#include <chrono>
#include <sstream>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <cstdlib>
#include <list>


using std::list;
using std::vector;
using std::cout;
using std::string;
using std::cin;
using std::endl;



class Mokinys {
	string vardas;
	string pavarde;
	vector<int> pazymiai;
	int galutinis_pazimys;
	int egzam_result;
	int pazimiu_sk;
	float pazymiu_vidurkis;

public:
	Mokinys();
	Mokinys(string name, string surname, vector<int> grades, int result);
    Mokinys& operator=(const Mokinys &mokinys);
	float pazymio_vidurkis(bool priskyrimas);
	float pazymio_medianas();
	void print_vidurkis();
	void print_medianas();
	void print_ND();





	void pazymiai_itext(std::ofstream& skaitymas);




	//seteriai
	void SetPaz_sk(int skaicius);
	void SetVardas(string name);
	void SetPavarde(string name);
	void SetPazymiai(vector<int>& vec);
	void SetEgzaminas(int skaicius);
	void SetVidurkis(float average);

	//geteriai
	int Get_pazSk() {
		return pazimiu_sk;
	}
	string Get_Vardas() {
		return vardas;
	}
	string Get_Pavarde() {
		return pavarde;
	}
	int Get_Egzaminas() {
		return egzam_result;
	}
	vector<int> Get_Pazymiai() {
		return pazymiai;
	}

	float Get_Vidurkis() {
		return pazymiu_vidurkis;
	}
	//destruktorius
	~Mokinys();


};

class Konteineriai {
public:
	int container_type;
	vector<Mokinys> Grupe;
	Mokinys mokinys;
	vector<int> skaiciai;
	int choice;
	//2 kategorijos
	vector<Mokinys>geri_mokiniai;
	vector<Mokinys>vidutiniai_mokiniai;

	//listas-------------------------
	list<Mokinys> Grupe1;
	list<Mokinys>geri_mokiniai1;
	list<Mokinys>vidutiniai_mokiniai1;
	Mokinys mokinys1;
	//deque


	void Saraso_Rikiavimas_marsrutizavimas(int pasirinkimas) {
	/*
		switch (pasirinkimas)
		{
		case 1:
			if (container_type == 1) {
			Saraso_Rikiavimas_vec(Grupe);
			}
			else if (container_type == 2) {
				Saraso_Rikiavimas_list(Grupe1);

		}
			break;
		case 2:
			if (container_type == 2) {
				Saraso_Rikiavimas_vec(geri_mokiniai);
			}
			else if (container_type == 2) {
				Saraso_Rikiavimas_list(geri_mokiniai1);

			}
			break;
		case 3:
			if (container_type == 1) {
				Saraso_Rikiavimas_vec(vidutiniai_mokiniai);
			}
			else if (container_type == 2) {
				Saraso_Rikiavimas_list(vidutiniai_mokiniai1);

			}
			break;
		default:
			break;
		}
			*/
		
	}



	void Saraso_skirstymo_marsrutizavimas() {
	/*	switch (container_type)
		{
		case 1:
		 
			Saraso_Skirstymas_vec();

			break;
		case 2:
			Saraso_Skirstymas_list();

			break;	
		default:
			break;
		}

*/



	}

	void Saraso_Skirstymas_vec() {
		//auto start = std::chrono::high_resolution_clock::now();
		//for (auto it =Grupe.begin(); it !=Grupe.end();) {
		//	//true su vidurkio priskyrimu jei false tai nepriskiria
		//	if (it->pazymio_vidurkis(true) >= 5) {
		//		geri_mokiniai.push_back(*it);
		//		it = Grupe.erase(it);

		//	}
		//	else {
		//		vidutiniai_mokiniai.push_back(*it);
		//		it = Grupe.erase(it);
		//	}



		//}
		//auto end = std::chrono::high_resolution_clock::now();
		//std::chrono::duration<double> diff = end - start;
		//cout << "////////////ATLIKIMO GREITIS////////////////////" << endl;
		//cout << "Sarasu skirstymas uztruko " << diff.count() << endl;
		//cout << "////////////////////////////////////////////////" << endl;


	}
	void Saraso_Skirstymas_list() {
		//auto start = std::chrono::high_resolution_clock::now();
		//for (auto it = Grupe1.begin(); it != Grupe1.end();) {
		//	//true su vidurkio priskyrimu jei false tai nepriskiria
		//	if (it->pazymio_vidurkis(true) >= 5) {
		//		geri_mokiniai1.push_back(*it);
		//		it = Grupe1.erase(it);

		//	}
		//	else {
		//		vidutiniai_mokiniai1.push_back(*it);
		//		it = Grupe1.erase(it);
		//	}



		//}
		//auto end = std::chrono::high_resolution_clock::now();
		//std::chrono::duration<double> diff = end - start;
		//cout << "////////////ATLIKIMO GREITIS////////////////////" << endl;
		//cout << "Sarasu skirstymas uztruko " << diff.count() << endl;
		//cout << "////////////////////////////////////////////////" << endl;


	}



	void Saraso_Rikiavimas_vec(vector<Mokinys>& group) {
		//auto start = std::chrono::high_resolution_clock::now();
		//		for (auto& list : group) {
		//			list.pazymio_vidurkis(true);
		//		}

		//	//	std::sort(group.begin(), group.end(), lyginimas_pagal_vidurki);
		//		auto end = std::chrono::high_resolution_clock::now();
		//		std::chrono::duration<double> diff = end - start;
		//		cout << "////////////ATLIKIMO GREITIS////////////////////" << endl;
		//		cout << "Saraso rikiavimas uztruko " << diff.count() << endl;
		//		cout << "////////////////////////////////////////////////" << endl;



	}

	 
	void Saraso_Rikiavimas_list(list<Mokinys>& group) {

	//	auto start = std::chrono::high_resolution_clock::now();
	//	for (auto& sar : group) {
	//		sar.pazymio_vidurkis(true);
	//	}

	////	std::sort(group.begin(), group.end(), lyginimas_pagal_vidurki);
	//	auto end = std::chrono::high_resolution_clock::now();
	//	std::chrono::duration<double> diff = end - start;
	//	cout << "////////////ATLIKIMO GREITIS////////////////////" << endl;
	//	cout << "Saraso rikiavimas uztruko " << diff.count() << endl;
	//	cout << "////////////////////////////////////////////////" << endl;
	}


	void all_printas_marsrutizavimas(int pasirinkimas) {

	/*	switch (container_type)
		{
		case 1:

			all_print_vec(pasirinkimas);

			break;
		case 2:
			all_print_list(pasirinkimas);

			break;		
		default:
			break;
		}
*/



	}


	void all_print_vec(int pasirinkimas) {

		//switch (pasirinkimas)
		//{
		//case 1:

		//	if (Grupe.size() == 0) {
		//		cout << "sarasas tuscias" << endl;
		//		return;
		//	}
		//	else {
		//		cout << "KIEKIS: " << Grupe.size() << endl;
		//	}
		//
		//	//	label_ND(Grupe[0].Get_pazSk());
		//		for (auto& duom : Grupe) duom.print_ND();


		//	break;
		//case 2:
		//	if (geri_mokiniai.size() == 0) {
		//		cout << "sarasas tuscias" << endl;
		//		return;
		//	}
		//	else {
		//		cout << "KIEKIS: " << geri_mokiniai.size() << endl;
		//	}

		////	label_ND(Grupe[0].Get_pazSk());
		//	for (auto& duom : geri_mokiniai) duom.print_ND();
		//	break;
		//case 3:
		//	if (vidutiniai_mokiniai.size() == 0) {
		//		cout << "sarasas tuscias" << endl;
		//		return;
		//	}
		//	else {
		//		cout << "KIEKIS: " << vidutiniai_mokiniai.size() << endl;
		//	}

		////	label_ND(Grupe[0].Get_pazSk());
		//	for (auto& duom : vidutiniai_mokiniai) duom.print_ND();

		//	break;
		//default:
		//	break;
		//}


	}

	void all_print_list(int pasirinkimas) {

		//switch (pasirinkimas)
		//{
		//case 1:

		//	if (Grupe1.size() == 0) {
		//		cout << "sarasas tuscias" << endl;
		//		return;
		//	}
		//	else {
		//		cout << "KIEKIS: " << Grupe1.size() << endl;
		//	}

		////	label_ND(Grupe1.front().Get_pazSk());
		//	for (auto& duom : Grupe1) duom.print_ND();


		//	break;
		//case 2:
		//	if (geri_mokiniai1.size() == 0) {
		//		cout << "sarasas tuscias" << endl;
		//		return;
		//	}
		//	else {
		//		cout << "KIEKIS: " << geri_mokiniai1.size() << endl;
		//	}

		////	label_ND(Grupe1.front().Get_pazSk());
		//	for (auto& duom : geri_mokiniai1) duom.print_ND();
		//	break;
		//case 3:
		//	if (vidutiniai_mokiniai1.size() == 0) {
		//		cout << "sarasas tuscias" << endl;
		//		return;
		//	}
		//	else {
		//		cout << "KIEKIS: " << vidutiniai_mokiniai1.size() << endl;
		//	}

		////	label_ND(Grupe1.front().Get_pazSk());
		//	for (auto& duom : vidutiniai_mokiniai1) duom.print_ND();

		//	break;
		//default:
		//	break;
		//}


	}



};
//----------------------------------------------

void failo_skaitymas(vector<Mokinys>& group,Mokinys& student, int n);
void failo_skaitymas_v3(vector<Mokinys>& group, Mokinys& student);
void failo_skaitymas_v2(vector<Mokinys>& group, Mokinys& student);
void asmens_ivestis(Mokinys& student);
void pazymiai(Mokinys& student);
void all_print(vector<Mokinys>& group);
void all_print_v2(vector<Mokinys>& group);
void label_vidurkio(vector<Mokinys>& group);
void label_ND(int group_size);



///v0.2
void failo_generavimas();//random failo generavimas
void label_itexta(std::ofstream& skaitymas, int kiekis);
void pazymiai_itexta_random(std::ofstream& skaitymas, int kiekis, int student_id);
bool lyginimas_pagal_varda( Mokinys& mokinys1, Mokinys& mokinys2);
bool lyginimas_pagal_vidurki(Mokinys& mokinys1, Mokinys& mokinys2);
void Saraso_Rikiavimas(vector<Mokinys>& group);
void Saraso_Skirstymas(vector<Mokinys>& group, vector<Mokinys>& good_students, vector<Mokinys>& bad_students);
void Saraso_Sukurimas(vector<Mokinys>& List, string file_name);
void Pagrindiniai_veiksmai(vector<Mokinys>& group, vector<Mokinys>& good_students, vector<Mokinys>& bad_students, int pasirinkimas);
void failo_skaitymas_new(Konteineriai& container, int n);
void Pagrindiniai_veiksmai_new(Konteineriai& container, int pasirinkimas);
