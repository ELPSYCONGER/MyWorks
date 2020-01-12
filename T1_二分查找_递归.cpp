#include<iostream>
#define N 10
using namespace std;
void Binary_Search(const int a[],const int x, int lf, int rt);
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
	Binary_Search(a, n1, 0, N);
	//测试第一组数据,默认输入情况下n1存在于数组中
	Binary_Search(a, n2, 0, N);
	//测试第二组数据,默认输入情况下n2不存在于数组中
	system("pause");
	return 0;
}
void Binary_Search(const int a[], const int x, int lf, int rt)
{
	int mid;
	//mid:中间指针,用于分半
	//lf:左指针,用于划分起点
	//rt:右指针,用于划分终点
	if (lf <= rt) {
		mid = (rt - lf) / 2 + lf;
		//每次递归都对中间指针重新校准
		if (a[mid] == x) {
			cout << x << "已找到,位于a[" << mid << "]" << endl;
			return;
		}
		else if (a[mid] < x) {
			//若查询值大于中间值,则递归到右侧(大的一侧)
			Binary_Search(a, x, mid + 1, rt);
		}
		else if (a[mid] > x) {
			//若查询值小于中间值,则递归到左侧(小的一侧)
			Binary_Search(a, x, lf, mid - 1);
		}
	}
	else {
		cout << x << "不在数组当中" << endl;
		return;
	}
}