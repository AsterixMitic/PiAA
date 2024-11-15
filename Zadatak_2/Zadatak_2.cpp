#include <iostream>
#include <vector>
#include "Algorithms.h"
#include "FileManipulation.h"
#include "MeasureTime.h"

using namespace std;

//Indeks - 19253
//Problem 2, Selection, Merge, Counting sort

/*
Prodavnica slatkisa sadrzi N razlicitih tipova slatkisa.
Razliciti slatkisi su predstavljeni celobrojnim nizom gde i-ti element predstavlja
cenu i-tog slatkisa. Student je resio da proba sve vrste slatkisa koje 
prodavnica ima u ponudi, a prodavac mu je ponudio specijalnu akciju,
za kupovinu jednog slatkisa, student moze da dobije najvise K razlicitih slatkisa besplatno.
Naci najmanji iznos novca koji student mozde da potrosi kako bi probao svih N razlicitih vrsta slatkisa.
Smatrati da je K 20% vrednosti N.
*/

int main()
{
    unsigned long int n=100,k; // K = 20% * N
    vector<int> test;
    int sum;

    //Resenje zadatka:
    //Student sortira slatkise po ceni pa nakon toga
    //kupi 5 najjeftinijih slatkisa pritom probajuci 20% najskupljih svaki put
    //s obzirom da je broj slatkisa (n) veliki broj
    //racunicu za minimalni iznos mozemo smatrati O(1) slozenoscu i samim tim ne utice
    //na vreme izvrsavanja algoritma
    for (n; n <= 10000000;n *= 10) {
        k = n * 0.2;
        cout << " - Za niz duzine : " << n << endl << endl;
        //FileManipulation::createArr(n);
        for (int j = 2;j >= 0;--j) {
            FileManipulation::getArr(test, n);
            
            switch (j) {
                case 0: {
                    cout << "Selection sort" << endl;
                    MeasureTime::startMes(Algorithms::selection_sort, test);
                    break;
                }
                case 1: {
                    cout << "Merge sort" << endl;
                    MeasureTime::startMes(Algorithms::merge_sort, test);
                    break;
                }
                default: {
                    cout << "Counting sort" << endl;
                    MeasureTime::startMes(Algorithms::counting_sort, test);
                    break;
                
                }
            }     
            
            sum = 0;
            for (int i = 0;i < 5;i++) {
                sum += test[i];
                //cout << test[i] << endl;
            }
            cout << "Najjeftiniji iznos: " << sum << endl << endl;
            
        }
    }
}
