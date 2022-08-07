#include <iostream>
#include <algorithm>

using namespace std;

int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	int N, K, A, B;
	int plant[100];

	cin >> N >> K >> A >> B;

	for (int i = 0; i < N; i++) {
		plant[i] = K;
	}

	int count = 0, day = 0;;
	bool isRunning = true;
	while (1) {
 		day++;
		for (int i = count; i < count + A; i++) {
			if (i >= N) {
				count -= N;
				i -= N;
			}

			plant[i] += B;
		}
		count += A;
		for (int i = 0; i < N; i++) {
			plant[i]--;
			if (plant[i] == 0) {
				cout << day;
				return 0;
			}
		}
		
	}


	return 0;
}