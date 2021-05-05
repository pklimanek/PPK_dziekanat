#include "Dziekanat.h"
/**
* Sprawdzenie wycieków pamiêci
*/
#define _CRTDBG_MAP_ALLOC
#define new new(_NORMAL_BLOCK, __FILE__, __LINE__)

int main(int argc, char** argv)
{
	string fileName;
	StudentNode* headStudents = nullptr;

	int skip;
	bool flag = 0;
	string a;

	for (int i = 1; i < argc; ++i)
	{
		a = argv[i];
		if (a == "-i")
		{
			flag = 1;
			skip = i;
			break;
			cout << "znaleziono -i";
		}
		if (a == "-h") {
			cout << "Aby poprawnie uruchomic program, przejdz za pomoca polecenia cd do katalogu, w ktorym znajduja sie pliki tektowe oraz plik o rozszerzeniu .exe" << endl;
			cout << "A nasteonie wpisz nastepujaca linie: " << endl;
			cout << "Dziekanat.exe -i plik.txt [plik2.txt]" << endl;
			break;
		}
	}
	if (flag)
	{
		for (int i = 1; i < argc; i++)
		{
			if (i == skip)
				continue;
			a = argv[i];
			getStudentsResults(a, headStudents);
			cout << "Pobrano " << a << "\n";
		}
	}
	else {
		cout << "Program nie zostal wywolany z linii polecen" << endl;
		cout << "Aby poprawnie uruchomic program, przejdz za pomoca polecenia cd do katalogu, w ktorym znajduja sie pliki tektowe oraz plik o rozszerzeniu .exe" << endl;
		cout << "A nasteonie wpisz nastepujaca linie: " << endl;
		cout << "Dziekanat.exe -i plik.txt [plik2.txt]" << endl;


		//cout << "Program zostaje wywolany dla plikow przykladowych" << endl;
		//getStudentsResults("Anatomia.txt", headStudents);
		//getStudentsResults("PodstawyInformatyki.txt", headStudents);
		//getStudentsResults("Anatomia.txt", headStudents);
		//getStudentsResults("BazyDanych.txt", headStudents);
	}


	createStudentFiles(headStudents);

	deleteList(headStudents);

	cout << "Aby zakonczyc dzialanie programu wcisnij klawisz ENTER" << endl;
	cin.get();

	return 0;

	_CrtDumpMemoryLeaks();
}