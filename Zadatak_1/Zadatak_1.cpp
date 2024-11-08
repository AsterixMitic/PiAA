#include <iostream>
#include "ReadFiles.h"
#include "MeasureTime.h"
#include "Algorithms.h"

using namespace std;

//Indeks - 19253 - Mitic Aleksandar
//Knut-Moris-Prat.
//Levenstein 

int main()
{   
    int num = 100;
    string text;
    string patterns[] = { "think", "pick it up", "Then he unrolled and", "Nevertheless he carefully memorized what was writt" };
    string hexPatterns[] = { "F30EA", "15AB92CE62", "4CAC F4843E41 EFE207", "B53871F 991C6B 560DA738 C464A 1C4 1D58A5FF B194EE " };

    for (int j = 0;j < 4;j++) {
        cout << "Trazenje u tekstu od " << num << " karaktera" << endl;
        text = ReadFiles::getString(("Texts/1984_"+to_string(num)+".txt").c_str());
        for (int i = 0; i < 4;i++) {
            cout << "Patern duzine " << patterns[i].length() << endl;
            MeasureTime::startMes(Algorithms::searchKmp, patterns[i], text);
        }
        num *= 10;
        cout << "------------------------" << endl;
    }
    
    cout << endl << "- HEX FAJLOVI - " << endl << endl;
    num = 100;

    for (int j = 0;j < 4;j++) {
        cout << "Trazenje u heksadecimalnom tekstu od " << num << " karaktera" << endl;
        text = ReadFiles::getString(("Texts/hex_" + to_string(num) + ".txt").c_str());
        for (int i = 0; i < 4;i++) {
            cout << "Patern duzine " << hexPatterns[i].length() << endl;
            MeasureTime::startMes(Algorithms::searchKmp, hexPatterns[i], text);
        }
        num *= 10;
        cout << "------------------------" << endl;
    }

    cout << endl << "- LEVENSTEIN ALGORITAM - " << endl << endl;

    num = 100;
    string levPatterns[] = { "party", "telescreen", "world-within-a-world" };
    string levHexPatterns[] = { "F30EA", "15AB92CE62", "4CAC F4843E41 EFE207" };

    for (int j = 0;j < 4;j++) {
        cout << "Trazenje u tekstu od " << num << " karaktera" << endl;
        text = ReadFiles::getString(("Texts/1984_" + to_string(num) + ".txt").c_str());
        for (int i = 0; i < 3;i++) {
            cout << "Pogresno napisane \"" << levPatterns[i] << "\" i duzine " << levPatterns[i].length() << endl;
            MeasureTime::startMes(Algorithms::levenstein, levPatterns[i], text);
        }
        num *= 10;
        cout << "------------------------" << endl;
    }

    num = 100;
    for (int j = 0;j < 4;j++) {
        cout << "Trazenje u tekstu od " << num << " karaktera" << endl;
        text = ReadFiles::getString(("Texts/hex_" + to_string(num) + ".txt").c_str());
        for (int i = 0; i < 3;i++) {
            cout << "Pogresno napisane \"" << levHexPatterns[i] << "\" i duzine " << levHexPatterns[i].length() << endl;
            MeasureTime::startMes(Algorithms::levenstein, levHexPatterns[i], text);
        }
        num *= 10;
        cout << "------------------------" << endl;
    }
    
}