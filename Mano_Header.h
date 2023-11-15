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
#include <Windows.h>


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
	Mokinys(string name, string surname, vector<int> grades, int result, int paz_skaicius);
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
	int Get_pazSk();
	string Get_Vardas();
	string Get_Pavarde();
	int Get_Egzaminas();
	vector<int> Get_Pazymiai();
	float Get_Vidurkis();
	//destruktorius
	~Mokinys();


};
//funkcijos
void label_vidurkio_list(list<Mokinys>& group);
void label_vidurkio_vec(vector<Mokinys>& group);
void label_ND(int group_size);
bool lyginimas_pagal_vidurki(Mokinys& mokinys1, Mokinys& mokinys2);


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
	//destruktor
	~Konteineriai() {
		/*Grupe.clear();*/
		skaiciai.clear();
	/*	geri_mokiniai.clear();
		vidutiniai_mokiniai.clear();
		Grupe1.clear();
		skaiciai.clear();
		geri_mokiniai1.clear();
		vidutiniai_mokiniai1.clear();*/
	}
	
	//metodai
	void Saraso_Rikiavimas_marsrutizavimas(int pasirinkimas);
	void Saraso_skirstymo_marsrutizavimas();
	void Saraso_Skirstymas_vec();
	void Saraso_Skirstymas_list();
	void Saraso_Rikiavimas_vec(vector<Mokinys>& group);
	void Saraso_Rikiavimas_list(list<Mokinys>& group);
	void all_printas_marsrutizavimas(int pasirinkimas);
	void all_print_vec(int pasirinkimas);
	void all_print_list(int pasirinkimas);

};
//----------------------------------------------
void asmens_ivestis(Mokinys& student);
void pazymiai(Mokinys& student,int kiekis);
void label_ND(int group_size);
void label_vidurkio_vec(vector<Mokinys>& group);
void label_vidurkio_list(list<Mokinys>& group);

///v0.2
void failo_generavimas();//random failo generavimas
void label_itexta(std::ofstream& skaitymas, int kiekis);
void pazymiai_itexta_random(std::ofstream& skaitymas, int kiekis, int student_id);
bool lyginimas_pagal_varda( Mokinys& mokinys1, Mokinys& mokinys2);
bool lyginimas_pagal_vidurki(Mokinys& mokinys1, Mokinys& mokinys2);
void Saraso_Sukurimas(vector<Mokinys>& List, string file_name);
void Saraso_Sukurimas_list(list<Mokinys>& List, string file_name);
void Pagrindiniai_veiksmai_new(Konteineriai& container, int pasirinkimas);
void failo_skaitymas_new(Konteineriai& container, int n, int container_type);
void failo_skaitymas_buffer(Konteineriai& container, int n, int container_type);
