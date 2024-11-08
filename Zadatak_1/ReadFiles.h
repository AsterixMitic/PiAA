#pragma once
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>

using namespace std;

namespace ReadFiles {
	
	//citanje iz fajla
	string getString(const char* path) {
		ifstream file(path);
		if (!file.is_open()) { 
			cout << "Fail." << endl; 
			return string(); 
		} 

		stringstream ss;
		ss << file.rdbuf(); 
		file.close();
		return ss.str();

	}

	//helper oko hex fajlova
	void createHexFile(int numOfWords) {
		srand(time(NULL));
		ofstream file(("C:\\Users\\Admin\\Desktop\\hex_" + to_string(numOfWords) + ".txt").c_str());
		char allowedChars[] = "0123456789ABCDEF";
		int wordLength;
		for (int i = 0;i < numOfWords;++i) {
			//duzina reci 3 - 9
			int wordLength = rand() % 7 + 3;
			for (int j = 0;j < wordLength;j++) {
				file << allowedChars[rand() % 16];
			}
			file << " ";
		}
		file.close();
	}

}