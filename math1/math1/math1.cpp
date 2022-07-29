#include <iostream>
#include <math.h>

using namespace std;

void sugar() {
	int n;
	int count;
	cin >> n;

	bool clear = true;
	
	count = n / 5;

	int num = n;
	int mod = n % 5;

	for (int i = 0; i <= 2; i++) {
		int tmp = (mod + i * 5);
		if (tmp % 3 == 0) {
			if (n - i * 5 < 0) {
				clear = false;
				break;
			}
			count += tmp/3 - i;
			break;
		}
	}
	if (clear) {
		cout << count << endl;
	}
	else cout << -1 << endl;
}

void apart() {
	int t;
	int k, n;

	cin >> t;

	int arr[15][15] = { 0, };

	for (int i = 0; i < 15; i++) {
		for (int j = 0; j < 15; j++) {
			if (i == 0)
				arr[i][j] = j+1;
			else {
				if (j == 0) {
					arr[i][j] = 1;
				}
				else {
					arr[i][j] = arr[i][j - 1] + arr[i - 1][j];
				}
			}
		}
	}


	for (int i = 0; i < t; i++) {
		cin >> k >> n;
		cout << arr[k][n-1]<<endl;
	}
}

void hotel() {
	int t;
	int h, w, n;

	cin >> t;

	for (int i = 0; i < t; i++) {
		cin >> h >> w >> n;
		n--;
		int res_h = n % h + 1;
		int res_w = n / h + 1;


		cout << res_h;
		if (res_w < 10)
			cout << "0";
		
		cout << res_w  << endl;
	}
}

void snail() {
	unsigned int a, b, v;

	cin >> a >> b >> v;
	
	unsigned int height, days;

	height = v - a;
	double c = a - b;
	double t = (double)height / c;
	days = ceil(t) + 1;

	cout << days;
}

void bunsu() {
	int X;
	int n = 1, nn = 0, count = 1;
	cin >> X;

	while (X > n) {
		count++;
		nn = n;
		n = count * (count + 1) / 2;
	}
	count++;
	int sub = n - X + 1;
	int son, mom;
	if (count % 2 == 1) {
		son = count - sub;
		mom = count - son;
	}
	else {
		mom = count - sub;
		son = count - mom;
	}
	
	cout << son << "/" << mom;
	
	//cout << nn << "/" << n << " "<<sub;

}

void BEP() {
	unsigned int A, B, C;
	int incom;
	cin >> A >> B >> C;

	incom = C - B;

	if (incom <= 0) {
		cout << -1;
	}
	else {
		unsigned int bep = A / incom + 1; 
		cout << bep;
	}
}

void BeeHouse() {
	int N;
	cin >> N;

	int count = 1;
	int subber = 6;
	N--;

	while (N > 0) {
		count++;
		N -= subber;
		subber +=6;
	}
	cout << count;
}

int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	//BEP();
	//BeeHouse();
	//bunsu();
	//snail();
	//hotel();
	//apart();
	sugar();
}