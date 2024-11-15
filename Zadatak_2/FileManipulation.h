#pragma once
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>

using namespace std;

namespace FileManipulation {

	//citanje iz fajla
	void getArr(vector<int>& arr, unsigned long int num) {

		ifstream file(("./Texts/"+to_string(num)+".txt").c_str());
		if (!file.is_open()) {
			cout << "Fail." << endl;
			return;
		}

		arr = vector<int>(num);
		int a;
		unsigned long int i = 0;
		while (file >> a)
		{
			arr[i] = a;
			i++;
		}
		file.close();

	}

	//helper oko kreiranja nizova
	void createArr(unsigned long int num) {
		srand(time(NULL));
		ofstream file(("./Texts/" + to_string(num) + ".txt").c_str());
		for (unsigned long int i = 0;i < num;++i) {
			file << rand() % 1001 << " ";
		}
		file.close();
	}

}