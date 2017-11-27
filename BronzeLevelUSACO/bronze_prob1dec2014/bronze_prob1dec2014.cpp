#include <iostream>
#include <fstream>
#include <cmath>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    ifstream fin ("marathon.in");
    ofstream fout ("marathon.out");
    
    int c = 0;
    fin >> c;
    
    int x[c];
    int y[c];

    for(int i = 0; i < c; i++) {
        fin >> x[i];
        fin >> y[i];
		// cout << "(" << x[i] << ", " << y[i] << ")" << endl;
    }

    int diff[c-1];

    for(int i = 1; i < c; i++) {
        diff[i-1] = ((abs(x[i-1]-x[i])+abs(y[i-1]-y[i]))+(abs(x[i]-x[i+1])+abs(y[i]-y[i+1])))-(abs(x[i-1]-x[i+1])+abs(y[i-1]-y[i+1]));
		// cout << diff[i-1] << endl;
    }
    
    int max = diff[0];
    
    int index = 0;
    for(int i = 1; i < c-1; i++) {
        if (diff[i] > max) {
            max = diff[i];
        }
    }
    
    int distance = 0;

    for(int i = 0; i < c-1; i++) {
    	distance += abs(x[i+1]-x[i])+abs(y[i+1]-y[i]);
    } 
    fout << distance-max << endl;
}
