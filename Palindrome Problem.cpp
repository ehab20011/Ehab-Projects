#include<iostream>
#include<cmath>
#include<cstring>
#include<vector>
using namespace std;
bool palindrome(int x) {
	int temp = x;
	int reverse = 0;
	int remainder;
	
	do {
		remainder = temp % 10;
		reverse = (reverse * 10) + remainder;
		temp = temp / 10;
	} while (temp != 0);
	
	cout << endl;
	cout << x << " Is your number and your number reversed is: " << reverse << endl;
	cout << endl;

	if (x == reverse) {
		return true;
	}
	else {
		return false;
	}
}
int main() {
	int x;
	cout << "Please enter a number: " << endl;
	cin >> x;

	if (palindrome(x) == true) {
		cout << "This integer "<< x <<" is a palindrome." << endl;
	}
	else {
		cout << "This integer " << x << " is not a palindrome." << endl;
	}
}