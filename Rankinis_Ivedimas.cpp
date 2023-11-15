#include "Mano_Header.h"
//Rankinis ivedimas v0.1
//rankiniu budu pazymiu ivedimas
void pazymiai(Mokinys& student,int kiekis) {
	int temp;
	vector<int> temp_pazymiai;
	student.SetPaz_sk(kiekis);
	for (int i = 0; i < kiekis; i++) {
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
	temp_pazymiai.clear();
}

//rankiniu budu vardo ivedimas
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

