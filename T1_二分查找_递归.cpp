#include<iostream>
#define N 10
using namespace std;
void Binary_Search(const int a[],const int x, int lf, int rt);
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
	Binary_Search(a, n1, 0, N);
	//���Ե�һ������,Ĭ�����������n1������������
	Binary_Search(a, n2, 0, N);
	//���Եڶ�������,Ĭ�����������n2��������������
	system("pause");
	return 0;
}
void Binary_Search(const int a[], const int x, int lf, int rt)
{
	int mid;
	//mid:�м�ָ��,���ڷְ�
	//lf:��ָ��,���ڻ������
	//rt:��ָ��,���ڻ����յ�
	if (lf <= rt) {
		mid = (rt - lf) / 2 + lf;
		//ÿ�εݹ鶼���м�ָ������У׼
		if (a[mid] == x) {
			cout << x << "���ҵ�,λ��a[" << mid << "]" << endl;
			return;
		}
		else if (a[mid] < x) {
			//����ѯֵ�����м�ֵ,��ݹ鵽�Ҳ�(���һ��)
			Binary_Search(a, x, mid + 1, rt);
		}
		else if (a[mid] > x) {
			//����ѯֵС���м�ֵ,��ݹ鵽���(С��һ��)
			Binary_Search(a, x, lf, mid - 1);
		}
	}
	else {
		cout << x << "�������鵱��" << endl;
		return;
	}
}