#include<stdio.h>
#define N 8

bool BS(int a[],int lf,int rt,int x){
	int mid;
	if(lf <= rt){
		mid = (rt - lf)/2 + lf;
		if(a[mid] == x){
			printf("已找到，目标在a[%d]位置",mid);
			return true;
		}else if(a[mid] < x){
			BS(a,mid+1,rt,x);
		}else if(a[mid] > x){
			BS(a,lf,mid-1,x);
		}
	}else{
		printf("此数不在数列中");
		return false;
	}
}

int main(){
	int a[N] = {2,6,9,17,21,63,87,107};
	int x;
	scanf("%d",&x);
	BS(a,0,N,x);
	return 0;
}