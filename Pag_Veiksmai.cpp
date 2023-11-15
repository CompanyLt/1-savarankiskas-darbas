#include "Mano_Header.h"
//Pagrindine veiksmu funkcija v0.1
//BOOL funkcijos kuriios iterpiamios i Sort();----------------------------------
bool lyginimas_pagal_varda( Mokinys& mokinys1, Mokinys& mokinys2) {

	return mokinys1.Get_Vardas() > mokinys2.Get_Vardas();

}

bool lyginimas_pagal_vidurki(Mokinys& mokinys1, Mokinys& mokinys2) {
	

	return mokinys1.Get_Vidurkis() > mokinys2.Get_Vidurkis();

}
//------------------------------------------------------------------------------------


///////////////////////////////////////////////////////////////////////////////////
//PAGRINDINE VEIKSMU FUNKCIJA--------------------------------------------------------
void Pagrindiniai_veiksmai_new(Konteineriai& container, int pasirinkimas) {
	//Sarasu rikiavimas

	if (pasirinkimas == 1) {
		cout << "Kuri sarasa rikiuosite?" << endl;
		cout << "Visa [ 1 ], Geri mokiniai [ 2 ], blogi mokiniai [ 3 ];" << endl;
		cin >> pasirinkimas;

		switch (pasirinkimas)
		{
		case 1:
			container.Saraso_Rikiavimas_marsrutizavimas(1);
			break;
		case 2:
			container.Saraso_Rikiavimas_marsrutizavimas(2);
			break;
		case 3:
			container.Saraso_Rikiavimas_marsrutizavimas(3);
			break;
		default:
			break;
		}

	}
	//sarasu skirstymas
	else if (pasirinkimas == 2) {
		//perduodam grupe ir 2 sarasus i kuriuos skirstome grupe
		container.Saraso_skirstymo_marsrutizavimas();


	}
	else if (pasirinkimas == 3) {
		cout << "Kuri sarasa Spausdinam i konsole?:" << endl;
		cout << "Visas sarasas [ 1 ] | geri mokyniai [ 2 ] | blogi mokyniai [ 3 ]" << endl;
		cin >> pasirinkimas;
		switch (pasirinkimas)
		{
		case 1:
			container.all_printas_marsrutizavimas(1);
			break;
		case 2:
			container.all_printas_marsrutizavimas(2);
			break;
		case 3:
			container.all_printas_marsrutizavimas(3);
			break;
		default:
			break;
		}
	}

	else if (pasirinkimas == 4) {
		system("cls");
		string stringas;
		cout << "rinkites kuri isvedam i txt:" << endl;
		cout << "Visas sarasas [ 1 ] | geri mokyniai [ 2 ] | blogi mokyniai [ 3 ]" << endl;
		cin >> pasirinkimas;
		cout << "Iveskite ataskaitos pavadinima" << endl;
		cin >> stringas;

		switch (pasirinkimas)
		{
		case 1:
			if (container.container_type == 1) {
				Saraso_Sukurimas(container.Grupe, stringas);

			}
			else {
				Saraso_Sukurimas_list(container.Grupe1, stringas);
			}
			break;
		case 2:
			if (container.container_type == 1) {
				Saraso_Sukurimas(container.geri_mokiniai, stringas);

			}
			else {
				Saraso_Sukurimas_list(container.geri_mokiniai1, stringas);
			}
			break;
		case 3:
			if (container.container_type == 1) {
				Saraso_Sukurimas(container.vidutiniai_mokiniai, stringas);

			}
			else {
				Saraso_Sukurimas_list(container.vidutiniai_mokiniai1, stringas);
			}
			break;
		default:
			break;
		}



		system("pause");



	}



}


