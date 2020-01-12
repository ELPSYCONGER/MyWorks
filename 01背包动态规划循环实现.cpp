#include <iostream>
using namespace std;
#define max(a,b) (((a)>(b))?(a):(b))

int w[105], val[105];
int dp[105][1005];

int main()
{
	int t, m;
	cin >> t >> m;
	for (int i = 1; i <= m; i++)
		cin >> w[i] >> val[i];

	for (int i = 1; i <= m; i++) //物品 
		for (int j = t; j >= 0; j--) //容量 
		{
			if (j >= w[i])
				dp[i][j] = max(dp[i - 1][j - w[i]] + val[i], dp[i - 1][j]);
			else      //只是为了好理解
				dp[i][j] = dp[i - 1][j];
		}
	cout << dp[m][t] << endl;
	system("pause");
	return 0;
}