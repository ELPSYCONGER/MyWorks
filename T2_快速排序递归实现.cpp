#include<iostream>
#define N 9
using namespace std;
void Quick_Sort(int a[], int left, int right);
int main()
{
	int a[N] = { 49,48,88,16,80,49,20,72,57 };
	/*
	int a[N];
	for (int i = 0; i < N; i++) {
		cin >> a[i];
	}
	*/
	Quick_Sort(a, 0, N - 1);
	for (int i = 0; i < N; i++) {
		cout << a[i] << " ";
	}
	cout << endl;
	system("pause");
	return 0;
}
void Quick_Sort(int a[], int left, int right)
{
	int i = left;		//左指针，令其等于递归数组的起点
	int j = right;		//右指针，令其等于递归数组的终点
	int temp;			//承接变量，用于临时存放数据
	int key = a[left];	//标定变量，用于表示此次递归的标准值
	while (i < j) {		//在左右指针不重叠交叉时重复以下操作
		/*总体上来说每次循环要做的是先检查右侧是否存在比key小的一个值存在，若存在就进行交换位置
		再检测左侧是否存在一个比key大的一个值存在，若存在就进行交换位置.由此往复，直至左右指针相会*/
		while (i < j && key <= a[j]) {
			//若右指针当前指向的值比标准值大或与标值相等，则满足比标准值大的数存放在标准值的右侧的原则
			//重复循环直至找到比标准值小的右指针位置
			j--;
		}
		if (i < j) {
			//在满足左右指针不重叠交叉的情况下，对当前左右指针所存放的值进行交换
			temp = a[j];
			a[j] = key;
			a[i++] = temp;
			//交换完成后左指针右移一位
		}
		while (i < j && key >= a[i]) {
			//若左指针当前指向的值比标准值小或与标值相等，则满足比标准值小的数存放在标准值的左侧的原则
			//重复循环直到找到比标准值大的左指针位置
			i++;
		}
		if (i < j) {
			//在满足左右指针不重叠交叉的情况下，将左指针的值交付给右指针，右指针左移
			a[j--] = a[i];
			//再将标准值交给左指针指向的位置
			a[i] = key;
		}
	}
	if (i != left) {
		//递归到key值左侧（小于key的一侧）
		Quick_Sort(a, left, j - 1);
	}
	if (i != right) {
		//递归到key值右侧（大于key的一侧）
		Quick_Sort(a, j + 1, right);
	}
}