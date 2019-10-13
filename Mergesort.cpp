#include <stdio.h>
#include <windows.h>
#include <malloc.h>
#include <string.h>
#include<stdlib.h>

#define N 16

void MergeData(int* arr, int left, int mid, int  right, int* tmp)
{
	int begin1 = left;
	int end1 = mid;
	int begin2 = mid;
	int end2 = right;
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
//区间为左闭右开 [)
void MergeSort(int* arr, int left, int right, int* tmp)//分治算法
{
	if (right - left > 1)//递归出口
	{
		int mid = (left + right) / 2;
		MergeSort(arr, left, mid, tmp);//左半部分
		MergeSort(arr, mid, right, tmp);//右半部分
		MergeData(arr, left, mid, right, tmp);//数据排序
		memcpy(arr + left, tmp + left, sizeof(arr[0]) * (right - left));//拷贝排序已好的数据
	}

}

void Sort(int* arr, int size) //开辟一个辅助空间
{
	int* tmp = (int*)malloc(sizeof(arr[0])*size);//申请空间
	if (tmp == NULL) //检验空间是否申请成功
		return;
	MergeSort(arr, 0, size, tmp);
	free(tmp);//堆上空间用完要释放，否则导致内存泄露
}

void printf_arr(int arr[], int size) //打印数组
{
	int i = 0;
	for (; i < size; i++)
	{
		printf("%d ", arr[i]);
	}
}
int main()
{
	int arr[N];
	for (int i = 0; i < N; i++) {
		arr[i] = rand() % 100;
	}
	int size = sizeof(arr) / sizeof(arr[0]);
	Sort(arr, size);
	printf_arr(arr, size);
	system("pause");
	return 0;
}
