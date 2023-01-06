#include <iostream>
#include <cmath>
using namespace std;
void TowersOfHanoi(int n, char from, char to, char towerp){
    static int moveNumber;

    if (n == 0) {
        return;
    }

    TowersOfHanoi(n - 1, from, towerp, to); //recalling the function
    
    cout <<"Move #"<<++moveNumber<<": Transfer ring " << n << " from tower " << from
        << " to tower " << to << endl;
    cout << endl;

    TowersOfHanoi(n - 1, towerp, to, from); //recalling the function again
}

int main()
{
    int n; //the # of rings that will be moved around . The user enters this number

    for (int i = 0; i < 29; i++) { //printing border
        cout << char(196);
    }
    cout << endl;
    cout << " Towers of Hanoi - Recursive " << endl;
    for (int i = 0; i < 29; i++) { //printing border
        cout << char(196);
    }
    cout << endl;
    cout << endl;

    cout << "Please enter the # of rings to move: ";
    cin >> n;
    cout << endl;

    

    TowersOfHanoi(n, 'A', 'B', 'C'); //A B and C are the names of the towers
    cout << endl;
    return 0;
}