#pragma once
//Deklaracijos
#include <vector>
#include <string>
#include <iostream>
#include <numeric>
#include <iomanip>
#include <algorithm>

using std::vector;
using std::cout;
using std::string;
using std::cin;
using std::endl;



class Mokinys {
	string vardas;
	string pavarde;
	vector<int> pazymiai;
	int egzam_result;

public:
	Mokinys();
	float pazymio_vidurkis();
	float pazymio_medianas();
	void print_vidurkis();
	void print_medianas();
	void print_ND();

	//seteriai
	void SetVardas(string name);
	void SetPavarde(string name);
	void SetPazymiai(vector<int>& vec);
	void SetEgzaminas(int skaicius);
	//geteriai
	//destruktorius
	~Mokinys() {
		vardas.clear();
		pavarde.clear();
		pazymiai.clear();


	}


};
//funkcijos
void asmens_ivestis(Mokinys& student);
void pazymiai(Mokinys& student);
void all_print(vector<Mokinys>& group);
void label_vidurkio(vector<Mokinys>& group);
void label_ND(int group_size);

