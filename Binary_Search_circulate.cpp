#include<stdio.h>
#define N 7

int main()
{
	int a[N] = {1,5,9,23,46,76,94};
	int lf = 0,rt = N,md;
	int n;
	scanf("%d",&n);
	while(true){
		md = (rt - lf)/2 + lf;
		if(n > a[md]){
			lf = md + 1;
		}else if(n < a[md]){
			rt = md - 1;
		}else if(n == a[md]){
			printf("已找到,在a[%d]\n",md);
			break;
		}
		if(lf > rt){
			printf("此数不在数组中");
			break;
		}
	}
	return 0;
}