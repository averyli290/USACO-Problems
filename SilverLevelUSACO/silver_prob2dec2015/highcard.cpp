#include <iostream>
#include <cmath>
#include <fstream>
#include <algorithm>
#include <vector>

using namespace std;

int main() {
	ofstream fout ("highcard.out");
	ifstream fin ("highcard.in");
	int ln = 0;
	fin >> ln;
	int n = ln/2;
	int b[n];
	int e[n];
	
	for(int i = 0; i < n; i++) {
		fin >> e[i];
	}
	int ind = 0;
	for(int i = 1; i <= n; i++) {
		bool in = false;
		for(int j = 0; j < n; j++) {
			if(i == e[j]) {
				in = true;
				break;
			}
		}
		if(not in) {
			b[ind] = i;
			ind++;
			cout << b[ind] << ", " << endl;
		}
	}
}
