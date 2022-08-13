#include <iostream>
#include <algorithm>

using namespace std;

int N, M;
int map[50][50] = { 0, };
int vMap[50][50] = { 0, };
int longest = 0;
int res = 0;

void find(int startX, int startY, int _x, int _y, int length) {
	if (vMap[_y][_x] != 0 && vMap[_y][_x] < length || map[_y][_x] == 0) return;
	vMap[_y][_x] = length;

	if (length >= longest) {

		longest = length;
		if (longest == 0) res = map[_y][_x];
		else res = max(res, map[startY][startX] + map[_y][_x]);
		
		cout << "endX : " << _x<< " endY : " << _y<< " = " << map[_y][_x] << endl;
		cout << res << endl;
	}

	for (int i = -1; i< 2; i++) {
		int x = _x + i;
		for (int j = -1; j< 2; j++) {
			int y = _y + j;
			if (j != 0 && i != 0) continue;
			if((x < 0 || x >= M) ||
			   (y < 0 || y >= N)) continue;

			find(startX, startY, x, y, length+1);

		}
	}

	return;
}

void resetVMap() {
	for (int i = 0; i < 50; i++) {
		for (int j = 0; j < 50; j++) {
			vMap[i][j] = 0;
		}
	}
}

int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	cin >> N >> M;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> map[i][j];
		}
	}

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cout << "x : " << j << " y : " << i << " = " << map[i][j] <<endl;
			find(j, i, j, i, 1);
			//res = max(res, map[i][j] + map[endY][endX]);
			resetVMap();
		}
	}

	cout << res;

	return 0;
}