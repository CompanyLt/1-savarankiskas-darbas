#include "Mano_Header.h"

void failo_generavimas() {
	int kiekis;
	cout << "Namu darbu skaicius??" << endl;
	cin >> kiekis;
	int countas = 1000;

	for (int i = 0; i < 3; i++) {
		auto start = std::chrono::high_resolution_clock::now();
		std::ofstream Sukurimas("sarasas/Kursiokai" + std::to_string(i+1)+ ".txt");
	
		//Sukurimas << "sdsds";

		label_itexta(Sukurimas,kiekis);
		for (int j = 0; j <countas; j++) {
		pazymiai_itexta_random(Sukurimas, kiekis,j);
		
		}
		countas *= 10;
		Sukurimas.close();
		auto end = std::chrono::high_resolution_clock::now();
		std::chrono::duration<double> diff = end - start;
		cout << "/////////////ATLIKIMO GREITIS/////////" << endl;
		cout << "faila sugeneravo per " << diff.count() << endl;
		cout << "////////////////////////////////////////" << endl;
	}



}











void label_itexta(std::ofstream& skaitymas,int kiekis) {

	skaitymas << std::setw(15) << "Vardas" << std::setw(15) << "Pavarde";
	for (int g = 0; g < kiekis; g++) {

		skaitymas << std::setw(11) <<"ND"<<g + 1;

	}
	skaitymas << std::setw(13) << "egz." << endl;;

}
void pazymiai_itexta_random(std::ofstream& skaitymas, int kiekis,int student_id) {
	
	int rand_skaicius;
	skaitymas<< std::setw(15) << "Vardenis" << student_id << std::setw(15) << "Pavardenis"<< student_id << std::setw(5);
	for (int l = 0; l < kiekis; l++) {
		rand_skaicius = rand() % 10 + 1;

		skaitymas << std::setw(12) << rand_skaicius;
	}
	skaitymas << std::setw(12) << rand_skaicius << endl;
	

}

void Saraso_Rikiavimas(vector<Mokinys>& group) {
	
	//Mokinys didziausias ;
	//didziausias = group[0];	
	//Mokinys temp;
	////cout << didziausias.Get_Vardas() << endl;
	//for (int i = 1; i < group.size(); i++) {
	//	//cout <<didziausias.Get_Egzaminas() << "  tempo gets " << group[i].Get_Egzaminas() << endl;
	//	if (didziausias.Get_Egzaminas() < group[i].Get_Egzaminas()) {
	//	
	//	/*	cout << temp.Get_Egzaminas() << "  tempo gets " << group[i].Get_Egzaminas()<<endl;
	//		cout << group[0].Get_Egzaminas() << "  pries " << group[i].Get_Egzaminas() << endl;*/
	//		temp = group[0];			
	//		group[0] = group[i];
	//		group[i] = temp;
	//		
	//		didziausias = group[0];

	//	}


	//}
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

bool lyginimas_pagal_varda( Mokinys& mokinys1, Mokinys& mokinys2) {

	return mokinys1.Get_Egzaminas() > mokinys2.Get_Egzaminas();

}

bool lyginimas_pagal_vidurki(Mokinys& mokinys1, Mokinys& mokinys2) {
	

	return mokinys1.Get_Vidurkis() > mokinys2.Get_Vidurkis();

}









void Saraso_Skirstymas(vector<Mokinys>& group, vector<Mokinys>& good_students, vector<Mokinys>& bad_students) {
	auto start = std::chrono::high_resolution_clock::now();
	for (auto it = group.begin(); it != group.end();) {
		//true su vidurkio priskyrimu jei false tai nepriskiria
		if (it->pazymio_vidurkis(true) >= 5) {
			good_students.push_back(*it);
			it = group.erase(it);

		}
		else {
			bad_students.push_back(*it);
			it = group.erase(it);
		}



	}
	auto end = std::chrono::high_resolution_clock::now();
	std::chrono::duration<double> diff = end - start;
	cout << "////////////ATLIKIMO GREITIS////////////////////" << endl;
	cout << "Sarasu skirstymas uztruko " << diff.count() << endl;
	cout << "////////////////////////////////////////////////" << endl;


}






void Saraso_Sukurimas(vector<Mokinys>& List, string file_name) {
	auto start = std::chrono::high_resolution_clock::now();
		std::ofstream Sukurimas("ataskaitos/" + file_name + ".txt");
		label_itexta(Sukurimas, List[0].Get_pazSk());
		int pazimiu_skaicius = List[0].Get_pazSk();
	for (auto& list : List) {
		list.pazymiai_itext(Sukurimas);
	
	}


	Sukurimas.close();
	auto end = std::chrono::high_resolution_clock::now();
	std::chrono::duration<double> diff = end - start;
	cout << "////////////ATLIKIMO GREITIS////////////////////" << endl;
	cout << "Ataskaitos isvedimas i faila uztruko: " << diff.count() << endl;
	cout << "////////////////////////////////////////////////" << endl;


}





void Pagrindiniai_veiksmai(vector<Mokinys>& group, vector<Mokinys>& good_students, vector<Mokinys>& bad_students, int pasirinkimas) {
	//Sarasu rikiavimas
	
	if (pasirinkimas == 1) {
		cout << "Kuri sarasa rikiuosite?" << endl;
		cout << "Visa [ 1 ], Geri mokiniai [ 2 ], blogi mokiniai [ 3 ];" << endl;
		cin >> pasirinkimas;



		switch (pasirinkimas)
		{
		case 1:
			Saraso_Rikiavimas(group);
			break;
		case 2:
			Saraso_Rikiavimas(good_students);
			break;
		case 3:
			Saraso_Rikiavimas(bad_students);
			break;
		default:
			break;
		}












	}
	//sarasu skirstymas
	else if (pasirinkimas ==2 ){
		//perduodam grupe ir 2 sarasus i kuriuos skirstome grupe
		Saraso_Skirstymas(group, good_students,bad_students);
	}
	else if (pasirinkimas == 3) {
	cout << "Kuri sarasa Spausdinam i konsole?:" << endl;
		cout << "Visas sarasas [ 1 ] | geri mokyniai [ 2 ] | blogi mokyniai [ 3 ]" << endl;
		cin >> pasirinkimas;
		switch (pasirinkimas)
		{
		case 1:
			all_print_v2(group);
			break;
		case 2:
			all_print_v2(good_students);
			break;
		case 3:
			all_print_v2(bad_students);
			break;
		default:
			break;
		}	
	}
	else if (pasirinkimas == 4) {
string stringas;
		cout << "rinkites kuri isvedam i txt:" << endl;
		cout << "Visas sarasas [ 1 ] | geri mokyniai [ 2 ] | blogi mokyniai [ 3 ]" << endl;
	cin >> pasirinkimas;
		cout << "Iveskite ataskaitos pavadinima" << endl;
		cin >> stringas;
	
		switch (pasirinkimas)
		{
		case 1:
			Saraso_Sukurimas(group,stringas);
			break;
		case 2:
			Saraso_Sukurimas(good_students, stringas);
			break;
		case 3:
			Saraso_Sukurimas(bad_students, stringas);
			break;
		default:
			break;
		}



		system("pause");












		







	}








}


//void Pagrindiniai_veiksmai_new(Konteineriai& container, int pasirinkimas) {
//	//Sarasu rikiavimas
//
//	if (pasirinkimas == 1) {
//		cout << "Kuri sarasa rikiuosite?" << endl;
//		cout << "Visa [ 1 ], Geri mokiniai [ 2 ], blogi mokiniai [ 3 ];" << endl;
//		cin >> pasirinkimas;
//
//		switch (pasirinkimas)
//		{
//		case 1:
//			container.Saraso_Rikiavimas_marsrutizavimas(1);
//			break;
//		case 2:
//			container.Saraso_Rikiavimas_marsrutizavimas(2);
//			break;
//		case 3:
//			container.Saraso_Rikiavimas_marsrutizavimas(3);
//			break;
//		default:
//			break;
//		}
//
//	}
//	//sarasu skirstymas
//	else if (pasirinkimas == 2) {
//		//perduodam grupe ir 2 sarasus i kuriuos skirstome grupe
//		container.Saraso_skirstymo_marsrutizavimas();
//
//
//	}
//	else if (pasirinkimas == 3) {
//		cout << "Kuri sarasa Spausdinam i konsole?:" << endl;
//		cout << "Visas sarasas [ 1 ] | geri mokyniai [ 2 ] | blogi mokyniai [ 3 ]" << endl;
//		cin >> pasirinkimas;
//		switch (pasirinkimas)
//		{
//		case 1:
//			container.all_printas_marsrutizavimas(1);
//			break;
//		case 2:
//			container.all_printas_marsrutizavimas(2);
//			break;
//		case 3:
//			container.all_printas_marsrutizavimas(3);
//			break;
//		default:
//			break;
//		}
//	}
//	else if (pasirinkimas == 4) {
//		string stringas;
//		cout << "rinkites kuri isvedam i txt:" << endl;
//		cout << "Visas sarasas [ 1 ] | geri mokyniai [ 2 ] | blogi mokyniai [ 3 ]" << endl;
//		cin >> pasirinkimas;
//		cout << "Iveskite ataskaitos pavadinima" << endl;
//		cin >> stringas;
//
//		switch (pasirinkimas)
//		{
//		case 1:
//
//			
//		case 2:
//		
//			break;
//		case 3:
//		
//			break;
//		default:
//			break;
//		}
//
//
//
//		system("pause");
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//	}
//
//
//
//
//
//
//
//
//}
