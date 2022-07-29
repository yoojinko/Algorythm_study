#include <iostream>
#include <stdio.h>
using namespace std;

void moduler_sum() {
	int n = 0, m = 0;
	int num = 0;
	int* dp;
	cin >> n >> m;

	int* sum = new int[n + 1];
	dp = new (int[m]);
	for (int i = 0; i < m; i++) {
		dp[i] = 0;
	}
	sum[0] = 0;
	for (int i = 1; i <= n; i++) {
		cin >> num;
		sum[i] = (sum[i - 1] + num)%m;
		dp[sum[i]]++;
	}

	long long res = 0;
	for (int i = 0; i < m; i++) {
		if (dp[i] == 0) continue;
		res += (long long)dp[i] * ((long long)dp[i]-1) / 2;
	}
	cout << res + dp[0];
}

//3 2 2 1 2 1
//
//3 5 7 8 10 11
//0 2 1 2 1 2

void section_sum5() {
	int n = 0, m = 0;
	int data;
	int x1, x2, y1, y2;

	cin >> n >> m;

	//2차원 배열 할당
	int** sum = new int* [n];

	for (int i = 0; i < n; i++) {
		sum[i] = new int[n];
	}
	
	int num = 0; 

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> num;
			j == 0 ?  sum[i][j] = num : sum[i][j] = sum[i][j - 1] + num;
		}
	}


	for (int i = 0; i < m; i++) {
		int res = 0;
		cin >> x1 >> y1 >> x2 >> y2;
		for (int j = x1-1; j < x2; j++) {
			if (y1 > 1)
				res += sum[j][y2 - 1] - sum[j][y1 - 2];
			else
				res += sum[j][y2 - 1];
		}
		cout << res << '\n';
	}
}

void section_sum4() {
	int n = 0, m = 0;

	cin >> n >> m;

	int* nums = new int[n];
	int* sums = new int[n+1];
	sums[0] = 0;
	for (int i = 0; i < n; i++) {
		cin >> nums[i];
		sums[i + 1] = sums[i] + nums[i];
	}

	for (int i = 0; i < m; i++) {
		int start, end;
		cin >> start >> end;
		
		cout << sums[end] - sums[start-1] << "\n";
	}
}

void sum_temp() {
	int n = 0, k = 0;

	cin >> n >> k;

	int* temps = new int[n];
	int* sums = new int[n + 1];
	sums[0] = 0;
	for (int i = 0; i < n; i++) {
		cin >> temps[i];
		sums[i + 1] = sums[i] + temps[i];
	}
	int maxTemp = sums[k];
	for (int i = k; i < n; i++) {
		maxTemp = max(maxTemp, sums[i+1] - sums[i+1-k]);
	}
	cout << maxTemp;


}

int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	//section_sum4();
	//sum_temp();
	//section_sum5();
	moduler_sum();

	return 0;
}


