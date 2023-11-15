#include "Mano_Header.h"
//Saraso_rikiavimas_v0.1
//Marsrutizavimas-------------------------------------------------------
void Konteineriai::Saraso_Rikiavimas_marsrutizavimas(int pasirinkimas) {
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
		if (container_type == 1) {
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


}

//Rikiavimo metodai------------------------------------------
void Konteineriai::Saraso_Rikiavimas_vec(vector<Mokinys>& group) {
	system("cls");
	auto start = std::chrono::high_resolution_clock::now();
	for (auto& list : group) {
		list.pazymio_vidurkis(true);
	}

	std::sort(group.begin(), group.end(), lyginimas_pagal_vidurki);
	auto end = std::chrono::high_resolution_clock::now();
	std::chrono::duration<double> diff = end - start;
	cout << "////////////ATLIKIMO GREITIS////////////////////" << endl;
	cout << "Saraso rikiavimas uztruko " << diff.count() << endl;
	cout << "////////////////////////////////////////////////" << endl;

}

void Konteineriai::Saraso_Rikiavimas_list(list<Mokinys>& group) {
	system("cls");
	auto start = std::chrono::high_resolution_clock::now();
	for (auto& sar : group) {
		sar.pazymio_vidurkis(true);
	}

	group.sort(lyginimas_pagal_vidurki);
	auto end = std::chrono::high_resolution_clock::now();
	std::chrono::duration<double> diff = end - start;
	cout << "////////////ATLIKIMO GREITIS////////////////////" << endl;
	cout << "Saraso rikiavimas uztruko " << diff.count() << endl;
	cout << "////////////////////////////////////////////////" << endl;
}
