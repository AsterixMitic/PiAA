#pragma once
#include <iostream>

using namespace std;

namespace Algorithms {

    //Time complexity O(n^2)
    //Space complexity O(1)
	void selection_sort(vector<int>& niz) {

        int n = niz.size();
        for (int i = 0; i < n - 1; ++i) {
            int mi = i;
            for (int j = i + 1; j < n; ++j) {
                if (niz[j] < niz[mi]) {
                    mi = j;
                }
            }
            swap(niz[i], niz[mi]);
        }

	}

    void merge(vector<int>& niz, int l, int mid, int r)
    {
        int n1 = mid - l + 1;
        int n2 = r - mid;

        vector<int> L(n1), R(n2);

        for (int i = 0; i < n1; i++)
            L[i] = niz[l + i];
        for (int j = 0; j < n2; j++)
            R[j] = niz[mid + 1 + j];

        int i = 0, j = 0;
        int k = l;

        while (i < n1 && j < n2) {
            if (L[i] <= R[j]) {
                niz[k] = L[i];
                i++;
            }
            else {
                niz[k] = R[j];
                j++;
            }
            k++;
        }

        while (i < n1) {
            niz[k] = L[i];
            i++;
            k++;
        }

        while (j < n2) {
            niz[k] = R[j];
            j++;
            k++;
        }
    }

    void merge_sub(vector<int>& niz, int l, int r)
    {
        if (l >= r)
            return;

        int mid = l + (r - l) / 2;
        merge_sub(niz, l, mid);
        merge_sub(niz, mid + 1, r);
        merge(niz, l, mid, r);
        
    }

    //Time Complexity O(n log n)
    //Space complexity O(n)
    void merge_sort(vector<int>& niz) {

        merge_sub(niz, 0, niz.size() - 1);

    }


    //Time complexity O( N + M ) N = niz.size(), M = max el u nizu
    //Space complexity O( N + M)
	void counting_sort(vector<int>& niz) {

        int n = niz.size();
        int maxi = 0;

        for (int i = 0; i < n; i++)
            maxi = max(maxi, niz[i]);

        vector<int> brNiz(maxi + 1, 0);
        
        for (int i = 0; i < n; ++i)
            brNiz[niz[i]]++;

        for (int i = 1; i <= maxi; ++i)
            brNiz[i] += brNiz[i - 1];

        vector<int> sortNiz(n);

        for (int i = n - 1; i >= 0; i--)

        {
            sortNiz[brNiz[niz[i]] - 1] = niz[i];

            brNiz[niz[i]]--;
        }

        for (int i = 0;i < niz.size();++i) {
            niz[i] = sortNiz[i];
        }

	}
}