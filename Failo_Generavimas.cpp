#include "Mano_Header.h"
//failo generavimas v.0.1

void failo_generavimas() {
	int kiekis;
	cout << "Namu darbu skaicius??" << endl;
	cin >> kiekis;
	int countas = 100000;

	for (int i = 0; i < 3; i++) {
		auto start = std::chrono::high_resolution_clock::now();
		std::ofstream Sukurimas("sarasas/Kursiokai" + std::to_string(i + 1) + ".txt");

		//Sukurimas << "sdsds";

		label_itexta(Sukurimas, kiekis);
		for (int j = 0; j < countas; j++) {
			pazymiai_itexta_random(Sukurimas, kiekis, j);

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

void label_itexta(std::ofstream& skaitymas, int kiekis) {

	skaitymas << std::setw(15) << "Vardas" << std::setw(15) << "Pavarde";
	for (int g = 0; g < kiekis; g++) {

		skaitymas << std::setw(11) << "ND" << g + 1;

	}
	skaitymas << std::setw(13) << "egz." << endl;;

}


void pazymiai_itexta_random(std::ofstream& skaitymas, int kiekis, int student_id) {

	int rand_skaicius;
	skaitymas << std::setw(15) << "Vardenis" << student_id << std::setw(15) << "Pavardenis" << student_id << std::setw(5);
	for (int l = 0; l < kiekis; l++) {
		rand_skaicius = rand() % 10 + 1;

		skaitymas << std::setw(12) << rand_skaicius;
	}
	skaitymas << std::setw(12) << rand_skaicius << endl;


}
