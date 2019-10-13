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

	while ((begin1 < end1) && (begin2 < end2))// ������������ĺϲ�
	{
		if (arr[begin1] <= arr[begin2])
		{
			tmp[count++] = arr[begin1++];
		}
		else {
			tmp[count++] = arr[begin2++];
		}
	}

	while (begin1 < end1) { //�ڶ���������ȫ��ע�뵽���������У���һ������ʣ��Ԫ��
		tmp[count++] = arr[begin1++];
	}

	while (begin2 < end2) { //�ڶ�������δ����
		tmp[count++] = arr[begin2++];
	}
}
//����Ϊ����ҿ� [)
void MergeSort(int* arr, int left, int right, int* tmp)//�����㷨
{
	if (right - left > 1)//�ݹ����
	{
		int mid = (left + right) / 2;
		MergeSort(arr, left, mid, tmp);//��벿��
		MergeSort(arr, mid, right, tmp);//�Ұ벿��
		MergeData(arr, left, mid, right, tmp);//��������
		memcpy(arr + left, tmp + left, sizeof(arr[0]) * (right - left));//���������Ѻõ�����
	}

}

void Sort(int* arr, int size) //����һ�������ռ�
{
	int* tmp = (int*)malloc(sizeof(arr[0])*size);//����ռ�
	if (tmp == NULL) //����ռ��Ƿ�����ɹ�
		return;
	MergeSort(arr, 0, size, tmp);
	free(tmp);//���Ͽռ�����Ҫ�ͷţ��������ڴ�й¶
}

void printf_arr(int arr[], int size) //��ӡ����
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
