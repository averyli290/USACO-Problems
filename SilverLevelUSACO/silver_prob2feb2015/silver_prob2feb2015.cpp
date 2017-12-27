#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
	
	ifstream fin ("hopscotch.in");
	ofstream fout ("hopscotch.out");
	int r, c, k = 0;
	fin >> r >> c >> k;
	
	int pa[r][c];
	long long dp[r][c];
	for(int i = 0; i < r; i++) {
		for(int j = 0; j < c; j++) {
			fin >> pa[i][j];
			dp[i][j] = 0;
		}
	}
	
	dp[0][0] = 1;
	
	for(int i = 1; i < r; i++) {
		for(int j = 1; j < c; j++) {
			long long n = 0;
			for(int a = 0; a < i; a++) {
				for(int b = 0; b < j; b++) {
					if(pa[a][b] != pa[i][j]) {
						n += dp[a][b] % 1000000007;
					}
				}
			}
			dp[i][j] = n % 1000000007;
			//cout << dp[i][j] << ", ";
		}
		//cout << endl;
	}
	
	fout << dp[r-1][c-1]%1000000007 << endl;
	
}
