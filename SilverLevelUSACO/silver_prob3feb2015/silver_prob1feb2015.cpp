#include <iostream>
#include <fstream>
#include <cmath>
#include <algorithm>
#include <vector>

using namespace std;

int t = 0;

int movecow(int xb, int yb, int cx, int cy, char cc, arr) {
	if(cx == xb && cy == yb) {
		return 1;
	} else {
		if(cx == xb || cy == yb) {
			return 0;
		}
		for(int i = cx; i <= xb; i++) {
			for(int j = cy; j <= yb; j++) {
				if(arr[i][j] != cc) {
					return t + movecow(xb, yb, i, j, arr[i][j], arr);
				}
			}
		}
	}
}

int main() {
	ifstream fin ("hopscotch.in");
	ofstream fout ("hopscotch.out");

	int r, c = 0;
	char hopfield[r][c];
	for(int a = 0; a < r; a++) {
		for(int b = 0; b < c; b++) {
			fin >> hopfield[a][b];
		}
	}
	
	movecow(r-1, c-1, 0, 0, hopfield[0][0], hopfield);
	return t;
}
