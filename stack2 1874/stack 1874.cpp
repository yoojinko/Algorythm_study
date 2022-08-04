#include<iostream>
#include<algorithm>
#include<stack>

using namespace std;

int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	
	int n;
	char arr[200000];
	int curNum = 2, charCount = 1;
	stack<int> s;
	cin >> n;

	s.push(1);
	arr[0] = '+';
	arr[n * 2 - 1] = '-';
	for(int i = 0; i < n; i++) {
		int num;
		cin >> num;
		bool isPoped = false;
		while(!isPoped)
		if (s.empty()) {
			s.push(curNum++);
			arr[charCount++] = '+';
		}
		else {

			if (s.top() > num) {
				cout << "NO";
				return 0;
			}
			if (s.top() < num) {
				s.push(curNum);
				arr[charCount++] = '+';
				curNum++;
			}
			if (s.top() == num) {
				s.pop();
				arr[charCount++] = '-';
				isPoped = true;
			}
		}
	}

	for (int i = 0; i < n * 2; i++) {
		cout << arr[i] << "\n";
	}

	return 0;
}