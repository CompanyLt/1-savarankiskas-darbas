// Savarankiskas darbas v0.2.cpp  updated
//
# include "Mano_Header.h"

//namespace fs = std::filesystem;

int main()
{


	srand(time(0));
	vector<Mokinys> Grupe;
	Mokinys mokinys;
	vector<int> skaiciai;
	int choice;
	//2 kategorijos
	vector<Mokinys>geri_mokiniai;
	vector<Mokinys>vidutiniai_mokiniai;
	//------------------------------------

	
	
   // failo_generavimas(Grupe, mokinys);
	while (true) {
		cout << "Pasirinkite:" << endl;
		cout<<"Skaitymas is failo[ 1 ] | Ivesti rankiniu budu[ 2 ] | Saraso generavimas [ 3 ]"  << endl;
	cin >> choice;
	if (cin.fail() || choice>3) {
		cin.clear();
		cin.ignore(100, '\n');
		cout << "Neteisinga ivestis"<<endl;
	}
	else if(choice == 3) {
		failo_generavimas();
	}
	else {
		break;
	}

	}
	

if (choice == 1) {

	while (true) {
	cout << "Kuri faila skaitome?" << endl;
	cout << "sarasas1000 [ 1 ] | sarasas10000 [ 2 ] | sarasas100000 [ 3 ] " << endl;
		cin >> choice;
		if (cin.fail() || choice > 3 || choice <1) {
			cin.clear();
			cin.ignore(100, '\n');
			cout << "Neteisinga ivestis" << endl;

		}
		else {
		failo_skaitymas(Grupe,mokinys,choice);
			break;
		}
		
	}
	while (true) {
		cout << "Pasirinkite veiksmus" << endl;
		cout << "Saraso rikiavimas [ 1 ] | Sarasu skirstymas [ 2 ] | Saraso spausdinimas [ 3 ] ataskaitos sukurimas [ 4 ]  Exit [ 5 ]" << endl;
		cin >> choice;
		if (cin.fail() || choice > 5 || choice < 1) {
			cin.clear();
			cin.ignore(100, '\n');
			cout << "Neteisinga ivestis" << endl;

		}
		else if(choice == 5) {

			//cia reik perduoti visus konteinerius 
			
			break;
		}
		Pagrindiniai_veiksmai(Grupe, geri_mokiniai, vidutiniai_mokiniai, choice);

	}

	





	//failo_generavimas();

	
	//cout <<Grupe[0].Get_Egzaminas() << "   " << Grupe[1].Get_Egzaminas() << endl;
	//Saraso_Rikiavimas(Grupe);
	////cout << Grupe[0].Get_Egzaminas() << "   " << Grupe[1].Get_Egzaminas() << endl;


	//Saraso_Skirstymas(Grupe, geri_mokiniai, vidutiniai_mokiniai);

	//Saraso_Rikiavimas(geri_mokiniai);
	//Saraso_Rikiavimas(vidutiniai_mokiniai);

	//all_print(geri_mokiniai);
	//all_print(vidutiniai_mokiniai);



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
all_print(Grupe);

	}
		/*else if(choice ==3){
		failo_generavimas();




		}*/





	
	


	
}

	
