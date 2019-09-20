#include<stdio.h>
#include<stdlib.h>
#define N 10

int QuickSort(int a[],int lf,int rt)
{
	int i = lf,j = rt;
	int key = a[lf];
	while(i < j){
		while(i < j && key <= a[j]){
			j--;
		}
		if(i < j){
			a[i]  = a[j];
			i++;
		}
		while(i < j && key >= a[i]){
			i++;
		}
		if(i < j){
			a[j] = a[i];
			j--;
		}
	}
	a[i] = key;
	if(lf > i){
		QuickSort(a,lf,j-1);
	}
	if(i < rt){
		QuickSort(a,j+1,rt);
	}
	return 0;
}

int main()
{
	int i;
	int a[16];
	for(i = 0;i < N;i++){
		a[i] = rand();
	}
	QuickSort(a,0,N-1);
	for(i = 0;i <N;i++){
		printf("%d\t",a[i]);
	}
	printf("\n");
	return 0;
}