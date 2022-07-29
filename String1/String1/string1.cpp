#include <cstring>
#include <iostream>

using namespace std;

void string1_kroatia();
void string2_group();

int main() {
	string2_group();
}

void string1_kroatia() {
	char buffer[101] = "";
	int count = 0;

	cin >> buffer;

	for (int i = 0; i < strlen(buffer); i++) {
		switch (buffer[i]) {
		case 'c':
			if (buffer[i + 1] == '=' || buffer[i + 1] == '-') i++;
			break;
		case 'd':
			if (buffer[i + 1] == '-') i++;
			else if (buffer[i + 1] == 'z' && buffer[i + 2] == '=') i += 2;
			break;
		case 'l':
		case 'n':
			if (buffer[i + 1] == 'j') i++;
			break;
		case 's':
		case 'z':
			if (buffer[i + 1] == '=') i++;
			break;
		case '-':
		case '=':
			count--;
			break;
		default: break;
		}
		count++;
	}

	cout << count << endl;

}

void string2_group() {
	int n=0, count=0;
	char curWord[101]="";
	cin >> n;

	for (int i = 0; i < n; i++) {
		cin >> curWord;
		bool isOK = true;
		char curAlp = curWord[0];
		int alpCount = 0;
		char alps[26] = "";
		for (int j = 1; j < strlen(curWord); j++)
		{
			if (curWord[j] != curAlp) {
				
				for (int k = 0; k < alpCount; k++){
					if (curWord[j] == alps[k]){
						isOK = false;
						break;
					}
				}
				if (!isOK) break;

				alps[alpCount++] = curAlp;
				curAlp = curWord[j];
			}
			if (!isOK) break;
		}
		if (isOK) count++;

	}
	cout << count;
}
