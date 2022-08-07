#include <iostream>
#include <algorithm>
#include <queue>
#include <stack>

using namespace std;

typedef struct __POINT__ {
	int priority;
	int weight;
}point;

int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	int N, M;
	queue<point> containers;
	stack<point> storage, tmpStorage;
	int priorityCounts[101] = { 0, }, curPriority;
	int resPrice = 0;

	cin >> N >> M;
	curPriority = M;
	for (int i = 0; i < N; i++) {
		point pt;
		cin >> pt.priority >> pt.weight;
		containers.push(pt);
		priorityCounts[pt.priority]++;
	}

	while (!containers.empty()) {
		if (priorityCounts[curPriority] == 0) {
			curPriority--;
			continue;
		}

		point curContainer = containers.front();

		if (curContainer.priority != curPriority) {	//우선순위 안맞으면 뒤로 보내기.
			containers.push(curContainer);
			resPrice += curContainer.weight;
			containers.pop();
		}
		else {
 			if (storage.empty()) {
				storage.push(curContainer);
				resPrice += curContainer.weight;
				containers.pop(); priorityCounts[curPriority]--;
				continue;
			}
			while (storage.top().priority == curContainer.priority && storage.top().weight < curContainer.weight) {
				tmpStorage.push(storage.top());
				resPrice += storage.top().weight * 2;
				storage.pop();
				if (storage.empty()) break;
			}
			storage.push(curContainer);
			resPrice += curContainer.weight;
			containers.pop(); priorityCounts[curPriority]--;

			while (!tmpStorage.empty()) {
				storage.push(tmpStorage.top());
				tmpStorage.pop();
			}
			
		}
	}
	cout << resPrice;

	return 0;
}