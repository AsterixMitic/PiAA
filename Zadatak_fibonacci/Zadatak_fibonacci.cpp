#include <iostream>
#include <vector>
#include "Implementations.h"
#include "MeasureTime.h"
#define MAXNUM 1000001
#define MAX_TIME_WAIT_IN_MICROSECONDS 20000

using namespace std;

//predavanje
//Domaci koliko ima razlicitih stabala kod 
//menjanja redosleda mnozenja matrica;
//ideja od poslednjeg krenemo

//vezbe
//primov algoritam
//istrazi kraskalov algoritam za sprezna stabla
//boruvka algoritam


int main()
{
    vector<int> arr(MAXNUM, 0);
    int prevI = 0, prevR = 0, prevM = 0;
    for (int i = 2; i < 1000000; i += 5) {
        cout << "I = " << i << endl;
        if (prevI < MAX_TIME_WAIT_IN_MICROSECONDS) {
            cout << "Iterative: " << endl;
            prevI = MeasureTime::startMes(Implementations::fibonacciIteration, i);
        }
        if (prevR < MAX_TIME_WAIT_IN_MICROSECONDS) {
            cout << "Recursive: " << endl;
            prevR = MeasureTime::startMes(Implementations::fibonacciRecursion, i);
        }
        if (prevM < MAX_TIME_WAIT_IN_MICROSECONDS) {
            cout << "Memoization: " << endl;
            prevM = MeasureTime::startMes(Implementations::fibonacciMemoization, arr, i);
            cout << arr[i];
        }
        cout << endl;
    }


}
