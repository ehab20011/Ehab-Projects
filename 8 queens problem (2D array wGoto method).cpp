#include <iostream>
#include <cmath>
#include <vector>

using namespace std;
int main() {
	static int solnum = 1;
	int b[8][8] = {};
	int r = 0;
	int c = 0;
	b[r][c] = 1;
NC:
	c++;
	if (c == 8) {
		goto Print;
	}
	r = -1;
NR:
	r++;
		if (r == 8) {
			goto Backtrack;
		}
	for (int i = 0; i < c; i++) {
		if (b[r][i] == 1) {
			goto NR;
		}
	}
	for (int i = 1; ((r - i) >= 0 && (c - i) >= 0); i++) {
		if (b[r - i][c - i] == 1) {
			goto NR;
		}
	}
	for (int i = 1; ((r + i) <= 7 && (c - i) >= 0); i++) {
		if (b[r + i][c - i] == 1) {
			goto NR;
		}
	}
	b[r][c] = 1;
		goto NC;
Print:
	cout << "Solution #: " << solnum++ << endl;
		for (int i = 0; i < 8; i++) {
			for (int j = 0; j < 8; j++) {
				cout << b[i][j] << " ";
			}
			cout << endl;
		}
	cout<<endl;
	goto Backtrack;
	
Backtrack:
	c--;

	if (c == -1) {
		cout << "No more solutions" << endl;
		return 0;
	}
	r = 0;
	while (b[r][c] != 1) {
		r++;
	}
	b[r][c] = 0;
	goto NR;
}

