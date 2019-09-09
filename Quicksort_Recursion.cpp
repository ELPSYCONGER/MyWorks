#include<stdio.h>
 #define N 6

int Quicksort(int left,int a[],int right){
	int key = a[left],temp;
	while(1){
		if(left < right){
			while(a[right] > key){
				right--;
			}
			if(left >= right){
				break;
			}
			temp = a[right];
			a[right] = a[left];
			a[left++] = temp;
		}
		else{
			break;
		}
		if(left < right){
			while(a[left] < key){
				left++;
			}
			if(left >= right){
				break;
			}
			temp = a[left];
			a[left] = a[right];
			a[right--] = temp;
		}else{
			break;
		}
	}
	//���� left �� right ����ͬһ���ָ�ֵ
	return right;
}

void Split(int left,int a[],int right)
{
	int middle;
	if(left < right){
		middle = Quicksort(left,a,right);//��ȡ�ָ�ֵ
		Split(left,a,middle-1);//�����߽�������
		Split(middle+1,a,right);//���Ұ�߽�������
	}
	else
		return;
}

int main()
{
	int a[N],i;
	for(i=0;i<N;i++){
		scanf("%d",&a[i]);
	}
	Split(0,a,N-1);
	for(i=0;i<N;i++){
		printf("%d ",a[i]);
	}
	return 0;
}
