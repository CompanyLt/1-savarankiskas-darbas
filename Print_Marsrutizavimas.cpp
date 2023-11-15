#include "Mano_Header.h"
//Print marsrutizavimas_v0.1


//Spausdinimas-------------------
void Konteineriai::all_printas_marsrutizavimas(int pasirinkimas) {
	system("cls");
	switch (container_type)
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

}

//pasirinkimas tai butent kokia darlis ar tai visas sarasas ar tai blogiukai-gerieciai
void Konteineriai::all_print_vec(int pasirinkimas) {
	int pasirinkti;
	cout << "VIdurki ar visus namu darbus? VIsi ND [ 1 ] / Vidurkis [ 2 ]  " << endl;
	cin >> pasirinkti;
	//2 visi namu darbai 
	if (pasirinkti == 1) {
		switch (pasirinkimas)
		{
		case 1:

			if (Grupe.size() == 0) {
				cout << "sarasas tuscias" << endl;
				return;
			}
			else {
				cout << "KIEKIS: " << Grupe.size() << endl;
			}

			label_ND(Grupe[0].Get_pazSk());
			for (auto& duom : Grupe) duom.print_ND();


			break;
		case 2:
			if (geri_mokiniai.size() == 0) {
				cout << "sarasas tuscias" << endl;
				return;
			}
			else {
				cout << "KIEKIS: " << geri_mokiniai.size() << endl;
			}

			label_ND(geri_mokiniai[0].Get_pazSk());
			for (auto& duom : geri_mokiniai) duom.print_ND();
			break;	
		case 3:
			if (vidutiniai_mokiniai.size() == 0) {
				cout << "sarasas tuscias" << endl;
				return;
			}
			else {
				cout << "KIEKIS: " << vidutiniai_mokiniai.size() << endl;
			}

			label_ND(vidutiniai_mokiniai[0].Get_pazSk());
			for (auto& duom : vidutiniai_mokiniai) duom.print_ND();

			break;
		default:
			break;
		}
	}
	//vidurkis---------------------------
	else {
		switch (pasirinkimas)
		{
		case 1:

			if (Grupe.size() == 0) {
				cout << "sarasas tuscias" << endl;
				return;
			}
			else {
				cout << "KIEKIS: " << Grupe.size() << endl;
			}

			label_vidurkio_vec(Grupe);



			break;
		case 2:
			if (geri_mokiniai.size() == 0) {
				cout << "sarasas tuscias" << endl;
				return;
			}
			else {
				cout << "KIEKIS: " << geri_mokiniai.size() << endl;
			}

			label_vidurkio_vec(geri_mokiniai);

			break;	
		case 3:
			if (vidutiniai_mokiniai.size() == 0) {
				cout << "sarasas tuscias" << endl;
				return;
			}
			else {
				cout << "KIEKIS: " << vidutiniai_mokiniai.size() << endl;
			}

			label_vidurkio_vec(vidutiniai_mokiniai);

			break;
		default:
			break;
		}

	}

}


void Konteineriai::all_print_list(int pasirinkimas) {
	int pasirinkti;
	cout << "VIdurki ar visus namu darbus? VIsi ND [ 1 ] / Vidurkis [ 2 ]  " << endl;
	cin >> pasirinkti;
	if (pasirinkti == 1) {
		switch (pasirinkimas)
		{
		case 1:

			if (Grupe1.size() == 0) {
				cout << "sarasas tuscias" << endl;
				return;
			}
			else {
				cout << "KIEKIS: " << Grupe1.size() << endl;
			}

			label_ND(Grupe1.front().Get_pazSk());
			for (auto& duom : Grupe1) duom.print_ND();


			break;
		case 2:
			if (geri_mokiniai1.size() == 0) {
				cout << "sarasas tuscias" << endl;
				return;
			}
			else {
				cout << "KIEKIS: " << geri_mokiniai1.size() << endl;
			}

			label_ND(geri_mokiniai1.front().Get_pazSk());
			for (auto& duom : geri_mokiniai1) duom.print_ND();
			break;
		case 3:
			if (vidutiniai_mokiniai1.size() == 0) {
				cout << "sarasas tuscias" << endl;
				return;
			}
			else {
				cout << "KIEKIS: " << vidutiniai_mokiniai1.size() << endl;
			}

			label_ND(vidutiniai_mokiniai1.front().Get_pazSk());
			for (auto& duom : vidutiniai_mokiniai1) duom.print_ND();

			break;
		default:
			break;
		}


	}
	else {
		switch (pasirinkimas)
		{
		case 1:

			if (Grupe1.size() == 0) {
				cout << "sarasas tuscias" << endl;
				return;
			}
			else {
				cout << "KIEKIS: " << Grupe1.size() << endl;
			}

			label_vidurkio_list(Grupe1);



			break;
		case 2:
			if (geri_mokiniai1.size() == 0) {
				cout << "sarasas tuscias" << endl;
				return;
			}
			else {
				cout << "KIEKIS: " << geri_mokiniai1.size() << endl;
			}

			label_vidurkio_list(geri_mokiniai1);

			break;
		case 3:
			if (vidutiniai_mokiniai1.size() == 0) {
				cout << "sarasas tuscias" << endl;
				return;
			}
			else {
				cout << "KIEKIS: " << vidutiniai_mokiniai1.size() << endl;
			}

			label_vidurkio_list(vidutiniai_mokiniai1);


			break;
		default:
			break;
		}
	}



}

//Antrasciu  ir vidurkio spausdinimasatspausdinimas-------------------
void label_vidurkio_vec(vector<Mokinys>& group) {


	cout << std::setw(12) << "Vardas" << std::setw(12) << "Pavarde";
	cout << std::setw(25) << " Galutinis vidurkis " << std::setw(25) << "Galutinis medianas " << endl;

	cout << "---------------------------------------------------------------------------" << endl;
	for (auto& duom : group) duom.print_vidurkis(), duom.print_medianas();


}
void label_vidurkio_list(list<Mokinys>& group) {


	cout << std::setw(12) << "Vardas" << std::setw(12) << "Pavarde";
	cout << std::setw(25) << " Galutinis vidurkis " << endl;
	cout << std::setw(25) << "Galutinis medianas " << endl;
	cout << "---------------------------------------------------------------------------" << endl;
	for (auto& duom : group) duom.print_vidurkis(), duom.print_medianas();


}



//Vidurkiu printinimas
void Mokinys::print_vidurkis() {
	cout << std::setw(12) << vardas << std::setw(12) << pavarde;
	cout << std::setw(16) << pazymio_vidurkis(false);

}

void Mokinys::print_medianas() {

	cout << std::setw(16) << pazymio_medianas() << endl;



}

void Mokinys::print_ND() {
	cout << std::setw(12) << vardas << std::setw(12) << pavarde;
	for (auto& skaicius : pazymiai) cout << std::setw(11) << skaicius;
	cout << std::setw(12) << egzam_result << endl;
}
