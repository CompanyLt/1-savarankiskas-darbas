// Savarankiskas darbas v1.1.cpp 
//
# include "Mano_Header.h"
#include <list>

//namespace fs = std::filesystem;
bool pasirinkimas(Konteineriai& container, int choice);
int main()
{

	srand(time(0));
	Konteineriai konteineris;
	int choice;

   // failo_generavimas(Grupe, mokinys);
	while (true) {
			cout << "Pasirinkite:" << endl;
			cout<<"Skaitymas is failo[ 1 ] | Ivesti rankiniu budu[ 2 ] | Saraso generavimas [ 3 ]"  << endl;

		cin >> choice;
		if (cin.fail() || choice>3) {
			cin.clear(); cin.ignore(100, '\n'); cout << "Neteisinga ivestis"<<endl;	
		}
		else if(choice == 3) {
			failo_generavimas();
		}
		else {
			break;
		}
	}
	
	system("cls");
if (choice == 1) {
	while (true) {
		cout << "Kuri konteineri renkates: Vector[ 1 ] ; List[ 2 ]" << endl;
		cin >> konteineris.container_type;
		system("cls");
	cout << "Kuri faila skaitome?" << endl; cout << "sarasas10000 [ 1 ] | sarasas100000 [ 2 ] | sarasas1000000 [ 3 ] " << endl;
	
		cin >> choice;
system("cls");
		if (cin.fail() || choice > 3 || choice <1) {
			cin.clear(); cin.ignore(100, '\n'); cout << "Neteisinga ivestis" << endl;			
		}
		else {
			failo_skaitymas_new(konteineris, choice, konteineris.container_type);
			break;
		}		
	}
	
	while (true) {
		if (pasirinkimas(konteineris, choice) == false)break;
	}

	}
//Rankinio budo realizavimas-------------
	else if (choice = 2) {		
		konteineris.container_type = 1;
		int temp;
		cout << "Iveskite pazimiu kieki?";
		cin >> temp;
		for (int i = 0; i < 2; i++) {	
				asmens_ivestis(konteineris.mokinys); pazymiai(konteineris.mokinys,temp);
				konteineris.Grupe.push_back(konteineris.mokinys); konteineris.mokinys.~Mokinys();
		}

		while (true) {
			if (pasirinkimas(konteineris, choice) == false)break;
		}
		
	}

konteineris.~Konteineriai();
return EXIT_SUCCESS;
}

//meniu funkcija---------------------------------------------
bool pasirinkimas(Konteineriai& container, int choice) {
	cout << "Pasirinkite veiksmus" << endl;
	cout << "Sarasu rikiavimas [ 1 ] | Sarasu skirstymas [ 2 ] | Saraso spausdinimas [ 3 ] ataskaitos sukurimas [ 4 ]  Exit [ 5 ]" << endl;
	cin >> choice;
	if (cin.fail() || choice > 5 || choice < 1) {
		cin.clear();
		cin.ignore(100, '\n');
		cout << "Neteisinga ivestis" << endl;

	}
	else if (choice == 5) {

		//cia reik perduoti visus konteinerius 

		return false;
	}
	Pagrindiniai_veiksmai_new(container, choice);


	return true;
 }

	
