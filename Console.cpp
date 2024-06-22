#include <iostream>
#include <Windows.h>
using namespace std;

#include "Transliteration.h"

#define CLEAR cout << "\033[2J\033[1;1H"

int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    transliteration();
}
