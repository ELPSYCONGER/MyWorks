#include<iostream>
#define N 10
using namespace std;
void Binary_Search(const int a[], const int n);
int main()
{
	//Ĭ������ģ��
	int a[N] = { 16,24,25,26,53,66,84,88,96,99 };
	int n1 = 24;
	int n2 = 27;
	/*
	//�Զ�������ģ��
	int a[N];
	for (int i = 0; i < N; i++) {
		cin >> a[i];
	}
	int n1, n2;
	cin >> n1 >> n2;
	*/
	Binary_Search(a, n1);
	//���Ե�һ������,Ĭ�����������n1������������
	Binary_Search(a, n2);
	//���Եڶ�������,Ĭ�����������n2��������������
	system("pause");
	return 0;
}
void Binary_Search(const int a[], const int n)
{
	int mid, left = 0, right = N;
	//mid:�м�ָ��,���ڷְ�
	//left:��ָ��,���ڻ������
	//right:��ָ��,���ڻ����յ�
	while (true) {
		mid = (right - left) / 2 + left;
		//ÿ��ѭ�������м�ָ������У׼
		if (n > a[mid]) {
			left = mid + 1;
			//�ڲ�ѯֵ�����м�ֵ�������,��ָ����������ָ���(���һ��)��ѯ
		}
		else if (n < a[mid]) {
			right = mid - 1;
			//�ڲ�ѯֵС���м�ֵ�������,��ָ����������ָ��ǰ(С��һ��)��ѯ
		}
		else if (n == a[mid]) {
			cout << n << "���ҵ�,λ��a[" << mid << "]" << endl;
			return;
		}
		if (left > right) {
			//����ָ�������ָ��(��ָ�뽻��),��˵�������������ڸ�������
			cout << n << "�������鵱��" << endl;
			return;
		}
	}
}