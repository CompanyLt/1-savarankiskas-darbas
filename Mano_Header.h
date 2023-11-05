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
