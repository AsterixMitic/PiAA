#include <iostream>
#include "Graph.h"
#include <chrono>

using namespace std;

//19253 - Mitic Aleksandar
//Graf - zadatak 3
//Zadatak 3: Kreirajte algoritam, baziran na Primovom algoritmu,
//za brisanje grafa cvor po cvor tako da u svakom trenutku graf ostane povezan.

void testCase(int N, int k, int caseNumber) {
    cout << "N=" << N << ", k=" << k << ", slucaj=" << caseNumber << endl;
    Graph g(N);

    if (caseNumber == 1) {
        g.generateCase1(k);
    }
    else {
        g.generateCase2(k);
    }

    auto start = chrono::high_resolution_clock::now();
    vector<int> order = g.deleteNodesKeepConnected();
    auto end = chrono::high_resolution_clock::now();
    auto duration = chrono::duration_cast<chrono::milliseconds>(end - start).count();
    cout << "Brisanje zavrseno za " << duration << " ms. Broj obrisanih: " << order.size() << endl;
}

int main() {
    vector<int> Nvr = { 100, 1000, 10000, 100000 };
    vector<int> Kvr = { 2, 5, 10, 20, 33};

    for (int N : Nvr) {
        for (int mult : Kvr) {
            int k = mult * N;
            testCase(N, k, 1);
            //testCase(N, k, 2);
        }
    }

    return 0;
}