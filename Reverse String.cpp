#include<iostream>
#include<cmath>
#include<cstring>
using namespace std;
void reversestring(string str) {
	string reversed = str;
	for (int i = reversed.length() - 1; i >= 0; i--) {
		cout << reversed[i];
	}

}
int main() {
	string userinput;
	
	cout << "Please enter the string you would like to see reversed: " << endl;
	cin >> userinput;
	reversestring(userinput);

}
