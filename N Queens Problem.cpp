#include <iostream>
#include <cmath>
using namespace std;

bool ok(int q[], int c) { //ok function from the 8 Queens Problem 1D w/out GOTO 

    for (int i = 0; i < c; i++) {
        if (q[c] == q[i] or (c - i) == abs(q[c] - q[i])){
            return false;
        }
    }
    return true;
}

// This function should return the number of solutions for the given board size (you don't need to print the solutions).
int nqueens(int n) {
    int* q = new int[n]; //declaring q, a pointer integer to new int[n]
    q[0] = 0; 

    int c = 0; //columns to 0
    int solutions = 0; //Integer needed to determine how many solutions there is to the problem 
    
    //nested while-loop similar to the 8 Queens Problem 1D w/out GOTO
    while (c >= 0) {
        if (c == n - 1) {
            ++solutions;
            c--;
        }
        else {
            q[++c] = -1;
        }
        while (c >= 0) {
            ++q[c];
            if (q[c] == n) {
                c--;
            }
            else if (ok(q, c) == true) {
                break;
            }
        }
    }
    delete[] q; //get rid of the [] q we declared earlier before returning the amount of solutions
    return solutions; //return back the amount of solutions (an integer)

}

int main() {
    int n = 12; //1-12 queens problem

    //printing a border
    for (int i = 0; i < 36; i++) {
        cout << char(196);
    }
    cout << endl;
    cout << "        N Queens Problem" <<  endl;
    //printing a border
    for (int i = 0; i < 36; i++) {
        cout << char(196);
    }
    cout << endl;
    

    for (int i = 1; i <= n; i++) { //printing out the solutions to the (i) queens problem until 12
        if (i == 1) {
            cout << "There is " << nqueens(i) << " Solution to the " << i << " Queens Problem." << endl;
            cout << endl; //for correct grammar when it is 1 solution
        }
        else { //for everything else
            cout << "There are " << nqueens(i) << " Solutions to the " << i << " Queens Problem." << endl;
            cout << endl;
        }
    }

}