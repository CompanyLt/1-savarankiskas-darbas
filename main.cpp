// Savarankiskas darbas v0.1.cpp 
//
# include "Mano_Header.h"

int main()
{
	vector<Mokinys> Grupe;
	Mokinys mokinys;
	vector<int> skaiciai;
	int choice;


	cout << "Pasirinkite: Skaitymas is failo[1] Ivesti rankiniu budu[2]" << endl;
	cin >> choice;


	while (choice) {

if (choice == 1) {

failo_skaitymas(Grupe,mokinys);



	}
	else if (choice = 2) {

for (int i = 0; i < 2; i++) {	
		
		asmens_ivestis(mokinys);
		pazymiai(mokinys);

		Grupe.push_back(mokinys);
		mokinys.~Mokinys();
	}
	// analogas C# foreach(var variable in Objekt);

	//cia galim realizuoti operacijas
	//1 vidurkiai , 2 visi namu darbai su egzu;


	}


if (choice == 1 || choice == 2) {
all_print(Grupe);
break;
}

	}
	
	
	
	

	
	

	
	


	
}

	
