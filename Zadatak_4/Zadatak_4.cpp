#include <iostream>
#include "BinomialHeap.h"
//#include <chrono>

using namespace std;

//19253 - Mitic Aleksandar
//Binomni hip - zadatak 3
//Zadatak 3: Sortirajte ulazni niz.
//Nadjite najdužu sekvencu od p elemenata sa minimalnom razlikom
//izmedju najveceg i najmanjeg (p < 101). 

int main()
{
    int a = 1, b = 1000; 
    unsigned long N = 10000;    //1000 <= N <= 10000000
    int k = 10; //10 <= k <= 100     
    int p = 50;           

    vector<int> numbers;
    BinomialHeap heap;
    int num;

    srand(time(NULL));
    //za merenje
    //auto start = chrono::high_resolution_clock::now();
    for (unsigned long i = 0; i < N; i++) {
        num = a + rand() % (b-a);
        heap.insert(num);
        //cout << "Ubacen element: " << num << endl;

        if ((i+1)%k == 0) {
            num = heap.extract_min();
            //cout << "Izbacen najmanji element: " << num << endl;
        }
    }

    //cout << "---------------------------------" << endl;

    while (!heap.is_empty()) {
        num = heap.extract_min();
        //cout << "Dodati elementi : " << num << endl;
        numbers.push_back(num);
    }

    int min_diff = INT_MAX, difStart=0, difEnd=0;

    for (int i = 0; i <= numbers.size() - p; i++) {
        int diff = numbers[i + p - 1] - numbers[i];
        if (diff < min_diff) {
            min_diff = diff;
            difStart = i;
            difEnd = i + p - 1;
        }
    }
    //auto end = chrono::high_resolution_clock::now();
    //auto duration = chrono::duration_cast<chrono::microseconds>(end - start).count();
    cout << "Najduza sekvenca sa minimalnom razlikom: ";
    for (int i = difStart; i <= difEnd; ++i) {
        cout << numbers[i] << " ";
    }
    cout << "\nMinimalna razlika: " << min_diff << endl;

    return 0;
}
