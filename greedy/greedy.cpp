#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <map>
using namespace std;

void oil(){
	int n;
	int64_t price, * dist, res=0;
	int cur_price;

	cin >> n;

	dist = new int64_t[n];

	for (int i = 0; i < n-1; i++) {
		cin >> dist[i];
	}
	for (int i = 0; i < n-1; i++) {
		cin >> price;
		if (i == 0) {
			cur_price = price;
		}
		else
			cur_price = cur_price > price ? price : cur_price;

		res += cur_price * dist[i];
	}
	cin >> price;	//마지막 도시 입력은 결과에 영향을 미치지 않는다.

	cout << res << endl;
}

void lostBracket() {
	string s;

	cin >> s;
	int res = 0;
	int minus = 1;
	int numStart = 0;
	int count = 0;

	if (s[0] == '-') {
		minus = -1;
	}

	res += stoi(s.substr(0));

	for (auto i = ++(s.begin()); i != s.end(); i++) {
		count++;
		if (*i == '+') {
			res += stoi(s.substr(count))*minus;

			cout << stoi(s.substr(count)) * minus << " ";
		}
		else if (*i == '-') {
			minus = -1;
			res += stoi(s.substr(count));

			cout << stoi(s.substr(count))<< " ";
		}
	}

	cout << res;
}

void atm() {
	int n, arr[1000];
	cin >> n;
	arr[0] = 0;
	for (int i=0; i < n; i++) {
		cin >> arr[i];
	}

	sort(arr, arr + n);
	
	int sum = 0, res = 0;

	for (int i = 0; i < n; i++) {
		sum += arr[i];
		res += sum;
	}

	cout << res << endl;
}

void coin0() {
	int n, k;

	cin >> n >> k;

	int* arr = new int[n];

	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}

	int change = k;
	int count = 0, selector = n-1;

	while (change > 0) {
		if (arr[selector] > change) {
			selector--;
			continue;
		}
		change -= arr[selector];
		count++;
	}

	cout << count << endl;
}

void office() {
	int n;
	int count = 0;
	map<unsigned int, vector<unsigned int>> schedules;

	cin >> n;

	for (int i = 0; i < n; i++) {
		unsigned int start, end;
		cin >> start >> end;
		unsigned int sub = end - start;
		if (schedules.find(end) == schedules.end()) {
			vector<unsigned int> v;
			v.push_back(sub);
			schedules.insert({ end,  v});
			continue; 
		}

		if(sub == 0)
			schedules[end].push_back(sub);
		else if (schedules[end][0] == 0) {
			schedules[end].pop_back();
			schedules[end].push_back(sub);
			schedules[end].push_back(0);
		}
		else {
			schedules[end][0] = schedules[end][0] < sub ? schedules[end][0] : sub;
		}



		//
	}

	unsigned int last_end = 0;

	for (auto itr = schedules.begin(); itr != schedules.end(); itr++) {
		if (last_end > itr->first - itr->second[0]) {
			continue;
		}

		count+=itr->second.size();
		last_end = itr->first;

	}
	cout << count << endl;

}

int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	//coin0();
	//office();

	//atm();
	//lostBracket();
	oil();


	return 0;
}