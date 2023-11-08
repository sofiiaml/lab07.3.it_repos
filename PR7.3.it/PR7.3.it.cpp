#include <iostream>
#include <iomanip>
#include <time.h>
using namespace std;
void Create(int** a, const int n,const int Low, const int High);
void Print(int** a, const int n);
void Sort(int** a, int n);
int findFirstRowWithoutPositive(int** a, int n);
int main() {
	srand((unsigned)time(NULL));
	int Low = -15;
	int High = 5;
	int n;
	cout << "n = "; cin >> n;
	int** a = new int* [n];
	for (int i = 0; i < n; i++)
		a[i] = new int[n];
	Create(a, n,Low, High);
	Print(a, n);
	cout << "I="<< findFirstRowWithoutPositive(a, n);
	findFirstRowWithoutPositive(a, n);
	Sort(a, n);
	Print(a, n);
	for (int i = 0; i < n; i++) {
		delete[] a[i];
	}
	delete[] a;
	return 0;
}
void Create(int** a, const int n,const int Low, const int High)
{
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			a[i][j] = Low + rand() % (High - Low + 1);
}
void Print(int** a, const int n)
{
	cout << endl;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
			cout << setw(4) << a[i][j];
		cout << endl;
	}
	cout << endl;
}
void Sort(int** a, int n) {
	for (int k = 0; k < n; k++) {
		int max = INT_MIN;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				if (k == 0 && a[i][j] > max) {
					max = a[i][j];
				}
				if (k > 0 && a[i][j] > max && a[i][j] < a[k - 1][k - 1]) {
					max = a[i][j];
				}
			}
		}
		a[k][k] = max;
	}
}
int findFirstRowWithoutPositive(int**a,int n) {
	for (int i = 0; i < n; i++) {
		bool hasPositive = false;
		for (int j = 0; j < n; ++j) {
			if (a[i][j] > 0) {
				hasPositive = true;
				break;
			}
		}
		if (!hasPositive) {
			return i + 1;
		}
	}
	return -1;
}
//int findFirstRowWithoutPositive(int**a,int n, int i) {
//	if (i == n) {
//		return -1; 
//	}
//	bool hasPositive = false;
//	for (int j = 0; j < n; j++) {
//		if (a[i][j] > 0) {
//			hasPositive = true;
//			break;
//		}
//	}
//	if (!hasPositive) {
//		return i + 1; 
//	}
//	return findFirstRowWithoutPositive(a, i + 1);
//}
//void Sort(int** a, int n, int k) {
//	if( k < n){
//		int max = INT_MIN;
//		for (int i = 0; i < n; i++) {
//			for (int j = 0; j < n; j++) {
//				if (k == 0 && a[i][j] > max) {
//					max = a[i][j];
//				}
//				if (k > 0 && a[i][j] > max && a[i][j] < a[k - 1][k - 1]) {
//					max = a[i][j];
//				}
//			}
//		}
//		a[k][k] = max;
//		Sort(a, n, k + 1);
//	}
//}