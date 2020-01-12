#include<iostream>
#define N 10
using namespace std;
void Binary_Search(const int a[], const int n);
int main()
{
	//默认输入模块
	int a[N] = { 16,24,25,26,53,66,84,88,96,99 };
	int n1 = 24;
	int n2 = 27;
	/*
	//自定义输入模块
	int a[N];
	for (int i = 0; i < N; i++) {
		cin >> a[i];
	}
	int n1, n2;
	cin >> n1 >> n2;
	*/
	Binary_Search(a, n1);
	//测试第一组数据,默认输入情况下n1存在于数组中
	Binary_Search(a, n2);
	//测试第二组数据,默认输入情况下n2不存在于数组中
	system("pause");
	return 0;
}
void Binary_Search(const int a[], const int n)
{
	int mid, left = 0, right = N;
	//mid:中间指针,用于分半
	//left:左指针,用于划分起点
	//right:右指针,用于划分终点
	while (true) {
		mid = (right - left) / 2 + left;
		//每次循环都对中间指针重新校准
		if (n > a[mid]) {
			left = mid + 1;
			//在查询值大于中间值的情况下,左指针右移至中指针后(大的一侧)查询
		}
		else if (n < a[mid]) {
			right = mid - 1;
			//在查询值小于中间值的情况下,右指针左移至中指针前(小的一侧)查询
		}
		else if (n == a[mid]) {
			cout << n << "已找到,位于a[" << mid << "]" << endl;
			return;
		}
		if (left > right) {
			//若左指针大于右指针(即指针交叉),则说明此数不存在于该数组中
			cout << n << "不在数组当中" << endl;
			return;
		}
	}
}