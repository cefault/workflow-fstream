#include <iostream>
#include <string>
#include <Windows.h>
#include <vector>
#include <fstream>
using namespace std;

#define _BANNED "TakeOut-Banned.txt"
#define _ORIGIN "TakeOut-Origin.txt"
#define _RESULT "TakeOut-Result.txt"

int takeout() {
	vector <string> End;
	
	ifstream Origin(_ORIGIN);
	if (!Origin.is_open()) { cout << "Возникла ошибка при открытии файла"; return 1; }
	
	string _string;
	while (getline(Origin, _string)) End.push_back(_string);
	Origin.close();

	ifstream Banned(_BANNED);
	ofstream Result(_RESULT);
	if (!Banned.is_open()) { cout << "Возникла ошибка при открытии файла"; return 1; }

	while (getline(Banned, _string)) {
		int INDEX_COUNTER = 0;
		for (string Exist : End) {
			if (Exist == _string) End.erase(End.begin() + INDEX_COUNTER);
			INDEX_COUNTER++;
		}
	}

	for (string Exist : End) { Result << Exist << endl; }

	Result.close();
	Banned.close();
	
	cout << "Заполнение файла завершено!\n";
	cout << "Можете проверить файл " << _RESULT;

	return 0;
}