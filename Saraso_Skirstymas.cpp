#include "Mano_Header.h"
//Saraso_skirrstymas_v0.1
//skirstymo Marsrutizavimo metodas------------------------------------------
void Konteineriai::Saraso_skirstymo_marsrutizavimas() {
	switch (container_type)
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





}


void Konteineriai::Saraso_Skirstymas_vec() {
	system("cls");
	if (Grupe.size() != 0) {
		auto start = std::chrono::high_resolution_clock::now();

		for (auto& grupe : Grupe) {
			if (grupe.Get_Vidurkis() < 5) {
				vidutiniai_mokiniai.push_back(grupe);
			}
			else {
				geri_mokiniai.push_back(grupe);
			}

		}
		Grupe.clear();
		auto end = std::chrono::high_resolution_clock::now();
		std::chrono::duration<double> diff = end - start;
		cout << "////////////ATLIKIMO GREITIS////////////////////" << endl;
		cout << "Sarasu skirstymas uztruko " << diff.count() << endl;
		cout << "////////////////////////////////////////////////" << endl;

	}
	else {
		cout << "Konteineris Vector jau tuscias" << endl;
	}
}


void Konteineriai::Saraso_Skirstymas_list() {
	system("cls");
	if (Grupe1.size() != 0) {
		auto start = std::chrono::high_resolution_clock::now();
		for (auto& grupe : Grupe1) {
			if (grupe.Get_Vidurkis() < 5) {
				vidutiniai_mokiniai1.push_back(grupe);
			}
			else {
				geri_mokiniai1.push_back(grupe);
			}

		}
		Grupe1.clear();
		auto end = std::chrono::high_resolution_clock::now();
		std::chrono::duration<double> diff = end - start;
		cout << "////////////ATLIKIMO GREITIS////////////////////" << endl;
		cout << "Sarasu skirstymas uztruko " << diff.count() << endl;
		cout << "////////////////////////////////////////////////" << endl;
	}
	else {
		cout << "Konteineris List jau tuscias" << endl;
	}

}
