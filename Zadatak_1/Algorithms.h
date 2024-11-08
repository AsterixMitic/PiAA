#pragma once
#include <vector>
#include <cmath>
#include <iostream>
#include <unordered_map>

using namespace std;

namespace Algorithms {

    //Funkcija koja kreira LPS - Longest Prefix Sufix 
    void kmpHelper(string& pat, vector<int>& lps) {

        int len = 0;
        lps[0] = 0;

        int i = 1;
        while (i < pat.length()) {

            if (pat[i] == pat[len]) {
                len++;
                lps[i] = len;
                i++;
            }

            else {
                if (len != 0) {

                    len = lps[len - 1];
                }
                else {

                    lps[i] = 0;
                    i++;
                }
            }
        }
    }

    int searchKmp(string& pat, string& txt) {
        int n = txt.length();
        int m = pat.length();

        vector<int> lps(m);

        kmpHelper(pat, lps);

        int i = 0;
        int j = 0;

        while (i < n) {

            if (txt[i] == pat[j]) {
                i++;
                j++;

                if (j == m) {
                    //cout << "Obrazac pronadjen " << pat << " na " << i - j;
                    return i - j;
                }
            }
            else {
                if (j != 0)
                    j = lps[j - 1];
                else
                    i++;
            }
        }
        //cout << "Nije pronadjen pattern " << endl;
        return -1;
    }

    //time complexity O(str1.length() * str2.length()) = O(m*n)
    int levenshteinHelper(string& str1, string& str2)
    {
        int m = str1.length();
        int n = str2.length();

        vector<int> prevRow(n + 1, 0);
        vector<int> currRow(n + 1, 0);

        for (int j = 0; j <= n; j++) {
            prevRow[j] = j;
        }

        for (int i = 1; i <= m; i++) {
            currRow[0] = i;

            for (int j = 1; j <= n; j++) {
                if (str1[i - 1] == str2[j - 1]) {
                    currRow[j] = prevRow[j - 1];
                }
                else {
                    currRow[j] = 1 + min(currRow[j - 1], min(prevRow[j], prevRow[j - 1]));
                }
            }

            prevRow = currRow;
        }

        return currRow[n];
    }

    int levenstein(string& pat, string& txt) {

        int m = pat.length();

        stringstream ss(txt);
        string word;

        int output, numOfSimilar = 0;
        //iteracija kroz svaku rec u fajlu
        while (ss >> word) {
            if (abs((double) word.length() - m) <= m * 0.2) {
                output = levenshteinHelper(word, pat);
                if (output > 0 && (double)output <= m * 0.3) {
                    //ispis pronadjenih reci
                    cout << word << " " << output << endl;
                    numOfSimilar++;
                }
            }
        }
        return numOfSimilar;
    }

    //Funkcija za odredjivanje raspodele duzine reci
    vector<int> getWordFrequencyByLength(string& txt) {

        vector<int> textLength(30,0);

        stringstream ss(txt);
        string word;
        while (ss >> word) {
            textLength[word.length()]++;
        }

        for (int i = 0;i < textLength.size();i++) {
            cout << i << " " << textLength[i] << endl;
        }

        return textLength;
    }

}