#include<iostream>
#include<algorithm>
#include <string>
#include <map>
#include <set>

using namespace std;

int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	int N, count = 0;
	map<string,int> scheduleMap;	// place -> <time -> count>
	set<string> student;

	string name, place;
	int sTime, eTime;

	int* schedules[10] = { NULL, };

	cin >> N;

	for (int i = 0; i < N; i++) {
		cin >> name >> place >> sTime >> eTime;
		if (student.find(name) != student.end()) continue;
		if (sTime > 50000 || eTime > 50000) continue;
		student.insert(name);

		scheduleMap.insert({ place,count });
		if (schedules[scheduleMap.find(place)->second] == NULL) {
			schedules[scheduleMap.find(place)->second] = new int[50000];
			count++;
		}

		for (int j = sTime; j < eTime; j++) {
			if (schedules[scheduleMap.find(place)->second][j] > 0)
				schedules[scheduleMap.find(place)->second][j]++;
			else
				schedules[scheduleMap.find(place)->second][j] = 1;
		}
	}

	int maxCount = 0;
	string resPlace;
	int resStime=0, resEtime=0;
	bool isSerial = false;

	for (auto itr = scheduleMap.begin(); itr != scheduleMap.end(); itr++) {
		for (int i = 0; i < 50000; i++) {
			if (maxCount < schedules[itr->second][i]) {
				maxCount = schedules[itr->second][i];
				resPlace = itr->first;
				resStime = i;
				resEtime = i;
				isSerial = true;
			}
			else if (maxCount > schedules[itr->second][i]) {
				isSerial = false;
			}
			if (resPlace == itr->first && maxCount == schedules[itr->second][i] && isSerial) {
				resEtime = i;
			}
		}
	}

	cout << resPlace << " " << resStime << " " << resEtime+1;

	return 0;
}