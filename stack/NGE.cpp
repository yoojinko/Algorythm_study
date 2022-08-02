#include<iostream>
#include<algorithm>
#include<stack>

using namespace std;

int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	int N, max_right = 0;

	typedef struct __POINT__ {
		int num;
		int order;
	}point;

	stack<point> NGEs;
	
	cin >> N;

	int* res = new int[N];

	//ют╥б
	for (int i = 0; i < N; i++) {
		int num;
		point pt;
		pt.order = i;
		cin >> pt.num;

		res[i] = 0;

		if (NGEs.empty()) {
			NGEs.push(pt);
			continue;
		}

		while (pt.num > NGEs.top().num) {
			res[NGEs.top().order] = pt.num;
			NGEs.pop();

			if (NGEs.empty()) {
				break;
			}
		}

		NGEs.push(pt);
	}

	for (int i = 0; i < N; i++) {
		if (res[i] == 0) {
			cout << -1 << " ";
		}
		else {
			cout << res[i] << " ";
		}
	}

	return 0;
}