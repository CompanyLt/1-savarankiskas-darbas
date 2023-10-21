// Savarankiskas darbas v0.1.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
# include "Mano_Header.h"

int main()
{
	vector<Mokinys> Grupe;
	Mokinys mokinys;
	vector<int> skaiciai;

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

	
