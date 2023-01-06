#include <iostream>
#include <cmath>
#include <vector>
using namespace std;

bool isOk(int q[], int c) {
	for (int i = 0; i < c; i++) {
		if (q[c] == q[i] or (c - i) == abs(q[c] - q[i]))
		{
			return false;
		}
	}
	return true;
}
void Print(int q[]
) { //Function required to print the 2D board with the answers

	for (int i = 0; i < 8; i++) {
		for (int j = 0; j < 8; j++) { //the two for loops required to print the 2D Chess Board
			if (q[i] == j) {
				cout << "1" << " "; //Printing a Queen
			}
			else {

				cout << "0" << " "; //If condition isn't met, place a 0 (Empty space).

			}
		}
		cout << endl; //"\n" necessary to make sure the spacing is there so that it's an 8x8 board
	}
	cout << endl; //"\n" necessary to make sure the spacing is there so that it's an 8x8 board
}
void Backtrack(int& c) { //Backtracking function

	c--;

	if (c == -1) { //if Columns reach past the 8th point in the board, end the program. We have found all the solutions
		cout << "No more solutions to this problem." << endl;
		exit(0); //Way of terminating the program since return 0; wouldn't work in this scenario.
	}
}
int main() {

	string a(8, char(219));
	string b(8, ' ');
	string c = "1" + b;
	string d = "0" + a;

	cout << "							" << " The 8 Queens Problem with all of it's solutions " << endl;


	cout << "				    	      "; //top border

	for (int i = 0; i < 64; i++) {
		cout << char(196);
	}
	cout << endl;
	cout << endl;
	cout << endl;
	for (int k = 0; k < 92; k++) {
		static int solnum = 1;
		cout << endl;
		cout << endl;
		cout << "                                                                Solution #: " << solnum++ << endl;
		cout << endl;
		cout << endl;
		cout << "                                              ";
		for (int c = 0; c < 64; c++) {
			cout << char(196);
		}
		cout << endl;
		for (int j = 0; j < 4; j++) {
			for (int i = 0; i < 4; i++) {
				cout << "                                             " << char(179);

				cout << b << a << b << a << b << a << b << a << char(179) << endl;

			}
			for (int i = 0; i < 4; i++) {
				cout << "                                             " << char(179);

				cout << a << b << a << b << a << b << a << b << char(179) << endl;

			}
		}
		cout << "                                              "; //bottom border
		for (int i = 0; i < 64; i++) {
			cout << char(196);
		}
	}
}