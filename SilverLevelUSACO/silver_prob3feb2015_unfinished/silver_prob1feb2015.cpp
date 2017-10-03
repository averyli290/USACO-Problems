#include <iostream>
#include <fstream>
#include <cmath>
#include <algorithm>
#include <vector>

using namespace std;

char arr[15][15];

int t = 0;

int movecow(int xb, int yb, int cx, int cy, char cc) {
	//cout << cx << " " << cy << endl;
	if(cx == xb && cy == yb) {
		return 1;
	} else {
		if(cx == xb || cy == yb) {
			return 0;
		}
		for(int i = cx; i <= xb; i++) {
			for(int j = cy; j <= yb; j++) {
				if (movecow(xb, yb, i, j, arr[i][j]) && arr[i][j] != cc) {
					t++;
					return 1;
				}
			}
		}
	}
}

int main() {
	ifstream fin ("hopscotch.in");
	ofstream fout ("hopscotch.out");

	int r, c = 0;
	fin >> r >> c;
	for(int a = 0; a < r; a++) {
		for(int b = 0; b < c; b++) {
			fin >> arr[a][b];
		}
	}
	
	cout <<  movecow(r-1, c-1, 0, 0,arr[0][0]) << endl; 
	cout << t << endl;
}
