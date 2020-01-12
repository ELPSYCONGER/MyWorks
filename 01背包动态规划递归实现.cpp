#include<iostream>
#include<algorithm>
#define MaxWeigth 34
#define number 10
using namespace std;
int w[MaxWeigth] = { 4,5,7,2,8,3,6,1,10,9 };
int v[number] = { 25,14,15,4,14,5,8,1,10,2 };
int Value(int i, int j);
int main()
{
	cout << Value(number, MaxWeigth) << endl;
	system("pause");
}
int Value(int i, int j)
{
	if (i > 0) {
		if (j < w[i - 1]) {
			return Value(i - 1, j);
		}
		else {
			return max(Value(i - 1, j), Value(i - 1, j - w[i - 1]) + v[i - 1]);
		}
	}
	else {
		return 0;
	}
}