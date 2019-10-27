#include<stdio.h>
#include<iostream>
#include<algorithm>

#define MAXSIZE 256
using namespace std;

double Backpack_Problem(double w[],double p[],int n,double bearing);
double weight[MAXSIZE];
double price[MAXSIZE];

int main()
{
	int n;
	cout << "input the number of the items:";
	cin>>n;
	cout << endl;
	for (int i = 0;i < n;i++){
		cout << "input the weight of the item " << i + 1 << ":";
		cin>>weight[i];
		cout << "input the price of the item " << i + 1 << ":";
		cin>>price[i];
		cout << endl;
	}
	/*
	double weight[MAXSIZE] = {8,26,14,21,4,5,16,23,4,11};
	double price[MAXSIZE] = {67,17,65,81,14,83,2,80,56,95};
	*/
	double backpack_bearing;
	cout << "input the bearing of your backpack:";
	cin>>backpack_bearing;
	double max_price; 
	max_price = Backpack_Problem(weight,price,n,backpack_bearing);
	cout << endl;
	cout<<"the maximum profit is "<<max_price<<endl;
	system("pause");
	return 0;
}

double Backpack_Problem(double w[],double p[],int n,double bearing)
{
	double psum = 0;
	double v[MAXSIZE];
	for(int i = 0;i < n;i++){
		v[i] = p[i] / w[i];
	}
	sort(v,v+n);
	for(int i = n - 1;i > -1;i--){
		for(int j = 0;j < n;j++){
			if(v[i] == (p[j] / w[j])){
				if(bearing >= w[j]){
					psum += p[j];
					bearing -= w[j];
				}
				else {
					psum += (v[i] * bearing);
					bearing = 0;
					goto out;
				}
			}
		}
	}
	out:
	return psum;
}