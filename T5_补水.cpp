#include<stdio.h>
#include<iostream>
#define SIZE 1000
int main()
{
	int m;
	scanf("%d", &m);//喝光水之前可滑行m英里
	int k;
	scanf("%d", &k);//补水地点个数
	int sum = 0;//记录补水次数 
	int a[SIZE];
	int b[SIZE];//存放在第几号喝水站补过水
	int temp = 0;//记录滑行的距离
	int t = 0;
	for (int i = 1; i <= k + 1; i++)
	{
		scanf("%d", &a[i]);//补水站间距
		if (a[i] > m)//如过补水点间距大于最大滑行距离 
			printf("不可到达目的地！");
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
				temp = a[i];//表示已经行驶了两个补水点之间的距离
				b[t] = i - 1;
				t++;
			}
		}
	}
	printf("最少补水次数为：%d\n", sum);
	printf("分别在以下补水站补过水：\n");
	for (int i = 0; i < t; i++)
		printf("第%d个 ", b[i]);
	system("pause");
	return 0;
}