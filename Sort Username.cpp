#include<iostream>
#include<cmath>
#include<cstring>
using namespace std;
void sortnumsandletters(string title) {
	
	cout << "You entered: " << title << endl;
	cout << endl;
	cout << "The digits in your title are: ";
	for (int i = 0; i < title.length(); i++) {
		if (isdigit(title[i])) {
			cout <<title[i];
		}
	}

	cout << endl;
	cout << endl;
	cout<<"The letters in your title are: ";
	for (int i = 0; i < title.length(); i++) {
		if (isalpha(title[i])) {
			cout << title[i];
		}
	}
	cout << endl;
}
int main() {
	
	string userinput;
	cout << "Please enter the title/username and this program will sort the #'s and letters out of it." << endl;
	cin >> userinput;
	cout << endl;
	sortnumsandletters(userinput);

	//Xxprodefender0112elitexX (example input)
}
