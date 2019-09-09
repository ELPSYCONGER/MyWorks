#include<stdio.h>
#define N 6
void fun(){
    int a[N],i,j,temp;
    for(i = 0;i < N;i++){
        scanf("%d",&a[i]);
    }
    /*for(i = 0;i < N - 1;i++){
        for(j = 0;j < N - 1 - i;j++){
            if(a[j] > a[j + 1]){
                temp = a[j];
                a[j] = a[j + 1];
                a[j + 1] = temp;
            }
        }
    }由大至小由小至大*/
        for(i = 0;i < N - 1;i++){
        for(j = 0;j < N - 1 - i;j++){
            if(a[j] < a[j + 1]){
                temp = a[j];
                a[j] = a[j + 1];
                a[j + 1] = temp;
            }
        }
    }/*由大至小*/
    for(i = 0;i < N;i++){
        printf("%d\t",a[i]);
    }
}

int main()
{
    fun();
    return 0;
}
