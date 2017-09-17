#include <iostream>
#include <fstream>
#include <cmath>
#include <algorithm>
#include <vector>

using namespace std;

int main() {
	ifstream fin ("censor.in");
	ofstream fout ("censor.out");
	
	string s = " ";
	string c = " ";
	fin >> s >> c;
	
	cout << s << endl << endl;

	vector<char> a;
	vector<char> b;
	for(int i = 0; i < s.length(); i++) {
		a.push_back(s[i]);
	}

	for(int i = 0; i < c.length(); i++) {
		b.push_back(c[i]);
	}
	int i = 0;
	for(i = 0; i < a.size()- c.length(); i++) {
		bool match = true;
		for(int j = 0; j < c.length(); j++) {
			if(s[i+j] != c[j]) {
				cout << c[j];
				match = false;
			}
		}
		cout << endl;
		if(match) {
			for(int e = i; e < i + c.length(); e++) {
				cout << a[e];
			}
			a.erase(a.begin() + i , a.begin() + c.length() + i);
			for(int b = 0; b < a.size(); b++) {
				cout << a[b];
			}
			cout << endl;
			i = 0;
		}
	}
	string solution = "";
	for(int b = 0; b < a.size(); b++) {
		solution += a[b];
	}
	cout << solution << endl;
}
