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
	{ 'А', "A" }, { 'Б', "B" }, { 'В', "V" }, { 'Г', "H" }, { 'Д', "D" },
	{ 'Е', "YE" }, { 'Ё', "YO" }, { 'Ж', "ZH" }, { 'З', "Z" }, { 'И', "I" },
	{ 'Й', "Y" }, { 'К', "K" }, { 'Л', "L" }, { 'М', "M" }, { 'Н', "N" },
	{ 'О', "O" }, { 'П', "P" }, { 'Р', "R" }, { 'С', "S" }, { 'Т', "T" },
	{ 'У', "U" }, { 'Ф', "F" }, { 'Х', "KH" }, { 'Ц', "TS" }, { 'Ч', "CH" },
	{ 'Ш', "SH" }, { 'Щ', "SHCH" }, { 'Ъ', "'" }, { 'Ы', "I" }, { 'Ь', "'" },
	{ 'Ю', "YU" }, { 'Я', "YA" },  { 'Є', "YE" }, { 'Ї', "YI" }, { 'І', "I" },

	{ 'а', "a" }, { 'б', "b" }, { 'в', "v" }, { 'г', "h" }, { 'д', "d" },
	{ 'е', "ye" }, { 'ё', "yo" }, { 'ж', "zh" }, { 'з', "z" }, { 'и', "i" },
	{ 'й', "y" }, { 'к', "k" }, { 'л', "l" }, { 'м', "m" }, { 'н', "n" },
	{ 'о', "o" }, { 'п', "p" }, { 'р', "r" }, { 'с', "s" }, { 'т', "t" },
	{ 'у', "u" }, { 'ф', "f" }, { 'х', "kh" }, { 'ц', "ts" }, { 'ч', "ch" },
	{ 'ш', "sh" }, { 'щ', "shch" }, { 'ъ', "'" }, { 'ы', "i" }, { 'ь', "'" },
	{ 'ю', "yu" }, { 'я', "ya" }, { 'є', "ye" }, { 'ї', "yi" }, { 'i', "і" }
};

int transliteration() {
	ifstream Origin(_ORIGIN);
	if (!Origin.is_open()) { cout << "Возникла ошибка при открытии файла"; return 1; }
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
	cout << "Транслитерация выполнена успешно!\n";
	cout << "Можете проверить файл " << _RESULT;

	return 0;
}