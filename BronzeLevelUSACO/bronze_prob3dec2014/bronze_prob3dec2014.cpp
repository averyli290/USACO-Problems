#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>

using namespace std;

int main () {
	ifstream fin ("cowjog.in");
	ofstream fout ("cowjog.out");
	int n = 0;
	fin >> n;
	int speeds[n];
	int filler = 0;
	for(int i = 0; i < n; i++) {
		fin >> filler;
		fin >> speeds[i];
	}
	int groups = 1;
	for(int i = n-1; i > 0; i--) {
		if(speeds[i] >= speeds[i-1]) {
			groups++;
		} else {
			speeds[i-1] = speeds[i];
		}
	}
	fout << groups << endl;
}
