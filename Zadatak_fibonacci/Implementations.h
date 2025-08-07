#include <iostream>
#include <vector>

using namespace std;


namespace Implementations {

	int fibonacciMemoization(vector<int>& arr, int k) {

		if (arr[k] == 0) {
			if (k < 2) {
				arr[k] = 1;
			}
			else {
				arr[k] = fibonacciMemoization(arr, k - 1) + fibonacciMemoization(arr, k - 2);
			}
		}
		return arr[k];
	}

	int fibonacciRecursion(int k) {
		if (k < 2) {
			return 1;
		}
		return fibonacciRecursion(k - 1) + fibonacciRecursion(k - 2);
	}

	int fibonacciIteration(int k) {
		int a = 1, b = 1, c = 1;
		for (int i = 2;i < k;++i) {
			c = a + b;
			a = b;
			b = c;
		}
		cout << " c = " << c << endl;
		return c;
	}

};