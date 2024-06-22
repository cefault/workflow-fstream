#include <iostream>
#include <string>
#include <Windows.h>
#include <fstream>
using namespace std;

#define _ORIGIN "Translate-Origin.txt"
#define _RESULT "Translate-Result.txt"

struct Translate {
	char Character;
	const char* Translation;
};

Translate Letters[] = {
	{ '�', "A" }, { '�', "B" }, { '�', "V" }, { '�', "H" }, { '�', "D" },
	{ '�', "YE" }, { '�', "YO" }, { '�', "ZH" }, { '�', "Z" }, { '�', "I" },
	{ '�', "Y" }, { '�', "K" }, { '�', "L" }, { '�', "M" }, { '�', "N" },
	{ '�', "O" }, { '�', "P" }, { '�', "R" }, { '�', "S" }, { '�', "T" },
	{ '�', "U" }, { '�', "F" }, { '�', "KH" }, { '�', "TS" }, { '�', "CH" },
	{ '�', "SH" }, { '�', "SHCH" }, { '�', "'" }, { '�', "I" }, { '�', "'" },
	{ '�', "YU" }, { '�', "YA" },  { '�', "YE" }, { '�', "YI" }, { '�', "I" },

	{ '�', "a" }, { '�', "b" }, { '�', "v" }, { '�', "h" }, { '�', "d" },
	{ '�', "ye" }, { '�', "yo" }, { '�', "zh" }, { '�', "z" }, { '�', "i" },
	{ '�', "y" }, { '�', "k" }, { '�', "l" }, { '�', "m" }, { '�', "n" },
	{ '�', "o" }, { '�', "p" }, { '�', "r" }, { '�', "s" }, { '�', "t" },
	{ '�', "u" }, { '�', "f" }, { '�', "kh" }, { '�', "ts" }, { '�', "ch" },
	{ '�', "sh" }, { '�', "shch" }, { '�', "'" }, { '�', "i" }, { '�', "'" },
	{ '�', "yu" }, { '�', "ya" }, { '�', "ye" }, { '�', "yi" }, { 'i', "�" }
};

int transliteration() {
	ifstream Origin(_ORIGIN);
	if (!Origin.is_open()) { cout << "�������� ������ ��� �������� �����"; return 1; }
	ofstream Translation(_RESULT);
	string Input;
	while (getline(Origin, Input)) {
		string Result = "";
		for (char Current : Input) {
			bool Applied = false;
			for (Translate Letter : Letters) {
				if (Letter.Character == Current) { Result += Letter.Translation; Applied = true; }
			}
			if (!Applied) Result += Current;
		}
		Translation << Result << endl;
	}

	Origin.close();
	Translation.close();
	cout << "�������������� ��������� �������!\n";
	cout << "������ ��������� ���� " << _RESULT;

	return 0;
}