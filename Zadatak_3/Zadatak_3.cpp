#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

//struktura za skladistenje 
struct Aktivnost {
    int index;    
    int pocetak;  
    int kraj;     
};

bool compare(const Aktivnost& a, const Aktivnost& b) {
    return a.kraj < b.kraj;
}

//funkcija za odredjivanje aktivnosti
void izaberiAktivnosti(int n, vector<int>& pocetak, vector<int>& kraj) {
    vector<Aktivnost> aktivnosti;

    for (int i = 0; i < n; i++) {
        aktivnosti.push_back({ i, pocetak[i], kraj[i] });
    }

    //sortiramo aktivnosti po vremenu zavrsetka
    sort(aktivnosti.begin(), aktivnosti.end(), compare);

    int poslednjiKraj = -1;
    for (int i = 0;i < n; ++i) {
        if (aktivnosti[i].pocetak > poslednjiKraj) {
            cout << aktivnosti[i].index << " ";
            poslednjiKraj = aktivnosti[i].kraj;
        }
    }
}

int main() {
    int n;
    cin >> n;
    vector<int> poc(n), kraj(n);
    for (int i = 0;i < n;++i) {
        cin >> poc[i];
    }
    for (int i = 0;i < n;++i) {
        cin >> kraj[i];
    }

    cout << "Aktivnosti: ";
    izaberiAktivnosti(n,poc, kraj);

    return 0;
}