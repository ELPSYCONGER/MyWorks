#include<stdio.h>
#include<iostream>
#define SIZE 1000
int main()
{
	int m;
	scanf("%d", &m);//�ȹ�ˮ֮ǰ�ɻ���mӢ��
	int k;
	scanf("%d", &k);//��ˮ�ص����
	int sum = 0;//��¼��ˮ���� 
	int a[SIZE];
	int b[SIZE];//����ڵڼ��ź�ˮվ����ˮ
	int temp = 0;//��¼���еľ���
	int t = 0;
	for (int i = 1; i <= k + 1; i++)
	{
		scanf("%d", &a[i]);//��ˮվ���
		if (a[i] > m)//�����ˮ�����������о��� 
			printf("���ɵ���Ŀ�ĵأ�");
		else
		{
			temp += a[i];
			if (temp == m)
			{
				sum++;
				temp = 0;
				b[t] = i;
				t++;
			}
			if (temp > m)
			{
				sum++;
				temp = a[i];//��ʾ�Ѿ���ʻ��������ˮ��֮��ľ���
				b[t] = i - 1;
				t++;
			}
		}
	}
	printf("���ٲ�ˮ����Ϊ��%d\n", sum);
	printf("�ֱ������²�ˮվ����ˮ��\n");
	for (int i = 0; i < t; i++)
		printf("��%d�� ", b[i]);
	system("pause");
	return 0;
}