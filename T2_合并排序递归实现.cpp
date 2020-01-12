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
void Sort(int* arr, int size) //����һ�������ռ�
{
	int* tmp = new int[size];//����ռ�
	if (tmp == NULL) //����ռ��Ƿ�����ɹ�
		return;
	MergeSort(arr, 0, size, tmp);
	delete[]tmp;//���Ͽռ�����Ҫ�ͷţ��������ڴ�й¶
}
void MergeSort(int* arr, int left, int right, int* tmp)//�����㷨
{
	if (right - left > 1)//�ݹ����
	{
		int mid = (left + right) / 2;
		MergeSort(arr, left, mid, tmp);//��벿��
		MergeSort(arr, mid, right, tmp);//�Ұ벿��
		MergeData(arr, left, mid, right, tmp);//��������
		memcpy(arr + left, tmp + left, sizeof(arr) * (right - left));//���������Ѻõ�����
	}
}
void MergeData(int* arr, int left, int mid, int  right, int* tmp)
{
	int begin1 = left;
	int end1 = mid;
	//����1������
	int begin2 = mid;
	int end2 = right;
	//����2������
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