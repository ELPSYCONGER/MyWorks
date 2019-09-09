#include <stdio.h>
#define N 6

void fun(){
    int a[N],i,m,t,cnt,index;
    for(i = 0;i < N;i++){
        scanf("%d",&a[i]);
    }
    for(cnt = 0;N - cnt > 0;){
        m = a[0];
        index = 0;
        for(i = 0;i < N - cnt;i++){
            if(a[i] < m){            //由大至小
            //if(a[i] > m){         //由小至大
            m = a[i];
            index = i;
            }
        }
        cnt++;
        t = a[N-cnt];
        a[N-cnt] = m;
        a[index] = t;
    }
    for(i = 0;i < N;i++){
        printf("%d\t",a[i]);
    }
}

int main(){
    fun();
    return 0;
}
