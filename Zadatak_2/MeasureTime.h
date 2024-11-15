#pragma once
#include <iostream>
#include <chrono>

using namespace std;

namespace MeasureTime {

	//Variadic funkcija koja meri prosecno vreme izvrsenja druge funkcije
	template<typename F, typename... Args>
	void startMes(F func, Args&&... args) {

		int numIterations = 1;
		auto start = chrono::high_resolution_clock::now();
		//Pozivanje funkcije 5 puta u cilju preciznije procene
		//prosecnog vremena izvrsavanja te funkcije
		for (int i = 0;i < numIterations;i++) {
			func(forward<Args>(args)...);

		}
		auto end = chrono::high_resolution_clock::now();
		auto duration = chrono::duration_cast<chrono::microseconds>(end - start).count();
		if (duration / numIterations / 1000 > 0) {
			cout << "Prosecno vreme izvrsavanja: " << duration / numIterations / 1000.0 << " ms" << endl;
		}
		else {
			cout << "Prosecno vreme izvrsavanja: " << duration / numIterations << " mikrosekundi" << endl;
		}
	}

}