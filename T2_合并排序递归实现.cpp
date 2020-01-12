#include<iostream>
#define N 12
using namespace std;
void MergeData(int* arr, int left, int mid, int  right, int* tmp);
void MergeSort(int* arr, int left, int right, int* tmp);
void Sort(int* arr, int size);
int main()
{
	int a[N] = { 10,43,1,17,33,38,42,17,18,36,26,5 };
	/*
	int a[N];
	for(int i = 0;i < N;i++){
		cin >> a[i];
	}
	*/
	Sort(a, N);
	for (int i = 0; i < N; i++) {
		cout << a[i] << " ";
	}
	system("pause");
	return 0;
}
void Sort(int* arr, int size) //开辟一个辅助空间
{
	int* tmp = new int[size];//申请空间
	if (tmp == NULL) //检验空间是否申请成功
		return;
	MergeSort(arr, 0, size, tmp);
	delete[]tmp;//堆上空间用完要释放，否则导致内存泄露
}
void MergeSort(int* arr, int left, int right, int* tmp)//分治算法
{
	if (right - left > 1)//递归出口
	{
		int mid = (left + right) / 2;
		MergeSort(arr, left, mid, tmp);//左半部分
		MergeSort(arr, mid, right, tmp);//右半部分
		MergeData(arr, left, mid, right, tmp);//数据排序
		memcpy(arr + left, tmp + left, sizeof(arr) * (right - left));//拷贝排序已好的数据
	}
}
void MergeData(int* arr, int left, int mid, int  right, int* tmp)
{
	int begin1 = left;
	int end1 = mid;
	//数组1操作数
	int begin2 = mid;
	int end2 = right;
	//数组2操作数
	int count = left;

	while ((begin1 < end1) && (begin2 < end2))// 两个有序数组的合并
	{
		if (arr[begin1] <= arr[begin2])
		{
			tmp[count++] = arr[begin1++];
		}
		else {
			tmp[count++] = arr[begin2++];
		}
	}

	while (begin1 < end1) { //第二个数组已全部注入到排序数组中，第一数组有剩余元素
		tmp[count++] = arr[begin1++];
	}

	while (begin2 < end2) { //第二个数组未排完
		tmp[count++] = arr[begin2++];
	}
}