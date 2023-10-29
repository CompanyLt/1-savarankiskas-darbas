#pragma once
//Deklaracijos
#include <vector>
#include <string>
#include <iostream>
#include <numeric>
#include <iomanip>
#include <algorithm>
#include <fstream>

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

public:
	Mokinys();
	Mokinys(string name, string surname, vector<int> grades, int result);
    Mokinys& operator=(const Mokinys &mokinys);
	float pazymio_vidurkis();
	float pazymio_medianas();
	void print_vidurkis();
	void print_medianas();
	void print_ND();










	//seteriai
	void SetPaz_sk(int skaicius);
	void SetVardas(string name);
	void SetPavarde(string name);
	void SetPazymiai(vector<int>& vec);
	void SetEgzaminas(int skaicius);
	//geteriai
	int Get_pazSk() {
		return pazimiu_sk;
	}
	//destruktorius
	~Mokinys();


};


void failo_skaitymas(vector<Mokinys>& group,Mokinys& student);
void asmens_ivestis(Mokinys& student);
void pazymiai(Mokinys& student);
void all_print(vector<Mokinys>& group);
void label_vidurkio(vector<Mokinys>& group);
void label_ND(int group_size);

