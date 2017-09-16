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
	
	vector<char> a;
	vector<char> b;
	for(int i = 0; i < s.length(); i++) {
		a.push_back(s[i]);
	}

	for(int i = 0; i < c.length(); i++) {
		b.push_back(c[i]);
	}
	int i = 0;;
	for(int i = 0; i < a.size()- c.length(); i++) {
		bool match = true;
		for(int j = 0; j < c.length(); j++) {
			if(s[i+j] != c[j]) {
				match = false;
			}
		}
		if(match) {
			a.erase(a.begin() + i - 2, a.begin() + c.length() + i);
			i = 0;
		}
	}

	for(int i = 0; i < a.size(); i++) {
		cout << a[i] << ", ";
	}
	cout << endl;
}
