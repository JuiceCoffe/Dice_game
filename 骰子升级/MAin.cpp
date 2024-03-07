#include <bits/stdc++.h>
using namespace std;
void sort(int* arr);
int getlevel(int arr[5]);
int getsame(int arr[5]);
int getsame2(int arr[5]);
int compair(int arr1[5], int arr2[5]);
void displayrst(int level);

class result {
public:
	int arr[5];
	int level;
	
	result(int arr_origin[5]) {
		sort(arr_origin);
		for (int i = 0; i < 5; i++) {
			arr[i] = arr_origin[i];
		}
		level = getlevel(arr);
		//cout << level << endl;
	}
};


int main() {
	int num;
	cin >> num;
	vector<result>A;
	
	for (int i = 0; i < num; i++) {
		int arr1[5];
		cin >> arr1[0] >> arr1[1] >> arr1[2] >> arr1[3] >> arr1[4];		
		result temp(arr1);
		A.push_back(temp);
	}
	for (vector<result>::iterator it = A.begin();it!=A.end();it++) {
		displayrst((*it).level);
	}
}
void sort(int* arr) {
	for (int i = 0; i < 4; i++) {
		for (int k = 0; k < 5 - i - 1; k++) {
			if (*(arr + k) > *(arr + k + 1)) {
				int temp = *(arr + k);
				*(arr + k) = *(arr + k + 1);
				*(arr + k + 1) = temp;
			}
		}
	}
}

int getlevel(int arr[5]) {
	sort(arr);
	int arr6[5] = { 2,3,4,5,6 };
	int arr5[5] = { 1,2,3,4,5 };
	if (compair(arr, arr6) == 1) {
		return 6;
	}
	else if (compair(arr, arr5) == 1) {
		return 5;
	}
	int samenum = getsame(arr);
	//cout <<samenum << endl;
	switch (samenum) {
	case 1:return 1; break;
	case 2:return getsame2(arr); break;
	case 3:if (getsame2(arr) == 5) { return 7; }
		  else { return 4; }break;
	case 4:return 8; break;
	case 5:return 9; break;
	}
}

int getsame(int arr[5]) {
	int num[6] = { 0,0,0,0,0 };
	for (int i = 1; i <= 6; i++) {
		for (int k = 0; k < 5; k++) {
			if (arr[k] == i) {
				num[i-1]++;
			}
		}
	}
	sort(num);
	if (num[4] > num[5]) { return num[4]; }
	else { return num[5]; }
}

int getsame2(int arr[5]) {
	int num[6] = { 0,0,0,0,0 };
	for (int i = 1; i <= 6; i++) {
		for (int k = 0; k < 5; k++) {
			if (arr[k] == i) {
				num[i-1]++;
			}
		}
	}
	sort(num);
	sort(num + 1);
	return num[4] + num[5] - 1;
}

int compair(int arr1[5], int arr2[5]) {
	for (int i = 0; i < 5; i++) {
		if (arr1[i] != arr2[i]) {
			return 0;
		}
	}
	return 1;
}


void displayrst(int level) {
	switch (level) {
	case 1:
		cout << "5 229 432" << endl; break;
	case 2:
		cout << "3 13 18" << endl; break;
	case 3:
		cout << "3 4 9" << endl; break;
	case 4:
		cout << "2 4 9" << endl; break;
	case 5:
		cout << "1 1 6" << endl; break;
	case 6:
		cout << "4 11 108" << endl; break;
	case 7:
		cout << "2 11 36" << endl; break;
	case 8:
		cout << "1 1 6" << endl; break;
	case 9:
		cout << "0 0 1" << endl; break;

	}
}
