#include<iostream>
#define N 20
using namespace std;
void n_find_k(const int arr[], const int n, const int k);
void find_k(int t[], int n, int k);
int main()
{
	int a[N];
	int n, k;
	cout << "input n:";
	cin >> n;
	cout << "input k:";
	cin >> k;
	cout << "input numbers:";
	for(int i = 0;i < n;i++){
		cin >> a[i];
	}
	n_find_k(a, n, k);
	system("pause");
	return 0;
}
void n_find_k(const int arr[], const int n, const int k)
{
	int *tmp = new int[n];
	memcpy(tmp, arr, sizeof(arr) * n);
	find_k(tmp, n, k);
	delete[]tmp;
}
void find_k(int t[], int n, int k)
{
	int min = t[0];
	if (n == 1) {
		cout << min << endl;
		return;
	}
	for (int i = 0; i < n; i++) {
		if (t[i] < min) {
			min = t[i];
			t[i] = t[0];
			t[0] = min;
		}
	}
	cout << min << ' ';
	if (k > 1) {
		find_k(t + 1, n - 1, k - 1);
	}
}