#include <iostream>
#include <cmath>
#include <vector>
using namespace std;

bool okFunction(int q[], int c) {
    for (int i = 0; i < c; ++i) {
        if (q[i] == q[c] || abs(q[i] - q[c]) == c - i)
            return false;
    }
    return true;
}

void print(int q[]) {
    static int solnum = 1;
    int i, j, k, l;
    typedef char box[5][7];   // Using typedef to create a Char data type 2D array thats 5x7

    box bb, wb, * board[8][8]; // We use that data type we created to declare bb for black box and wb for white box.
    //we also declare an 8x8 array of pointers to boxes.
    //since it is not a static char, you don't have to clear the board everytime after you print it will 
    //reintialize everytime that the funciton is called.

// Fill in bb (black box) and wb (white box).  They each represent a square of the chessboard.
// You only need to create one of each, since the chessboard can contain many pointers to the same box.
    for (i = 0; i < 5; i++)
        for (j = 0; j < 7; j++) {
            bb[i][j] = ' ';
            wb[i][j] = char(219);
        }

    // Here we use the typedef character data type Box we created to draw 2 pictures. One of the black queen
    // and one of the white queen.
 
    //Black Queen
    static box bq = { {char(219),char(219),char(219),char(219),char(219),char(219),char(219)},
                      {char(219),' '      ,char(219),' '      ,char(219),' '      ,char(219)},
                      {char(219),' '      ,' '      ,' '      ,' '      ,' '      ,char(219)},
                      {char(219),' '      ,' '      ,' '      ,' '      ,' '      ,char(219)},
                      {char(219),char(219),char(219),char(219),char(219),char(219),char(219)} };
    //White Queen
    static box wq = { {' '      ,' '      ,' '      ,' '      ,' '      ,' '      ,' '      },
                      {' '      ,char(219),' '      ,char(219),' '      ,char(219),' '      },
                      {' '      ,char(219),char(219),char(219),char(219),char(219),' '      },
                      {' '      ,char(219),char(219),char(219),char(219),char(219),' '      },
                      {' '      ,' '      ,' '      ,' '      ,' '      ,' '      ,' '      } };

    // Fill board with pointers to bb and wb in alternate positions.
    for (i = 0; i < 8; i++) {
        for (j = 0; j < 8; j++) {
            if ((i + j) % 2 == 0) //if condition needed so we can know if we will need to print white box or black box
                board[i][j] = &wb;
            else
                board[i][j] = &bb;
        }
    }

    cout << "Solution #: " << solnum++ << endl; 
   
    //making sure that black queens go on white square and white queens go on black square with this block of code:
    for (int i = 0; i < 8; i++) { 
        if (board[i][q[i]] == &wb) { 
            board[i][q[i]] = &bq; //if that spot is a white board spot replace it with the address of a black queen address(&bq)
        }
        if (board[i][q[i]] == &bb) {
            board[i][q[i]] = &wq; //if that spot is a black board spot replace it with the address of a white queen address (&wq)
        }
    }

    // For loop needed to print the upper border of the chess board for every solution.
    for (i = 0; i < 7 * 8; i++)
        cout << '_';
    cout << endl;


    // Printing the board
    for (i = 0; i < 8; i++)          // i is the index for the rows for the 8x8 board
        for (k = 0; k < 5; k++) {     // k is the index for the rows for EACH box
            cout << char(179); //vertical border
            for (j = 0; j < 8; j++)    // j is the index for the columns for the 8x8 board
                for (l = 0; l < 7; l++) // l is the index for the columns for EACH box


                    // board[i][j] is the box pointer in the ith row, jth column of the board.
                    // *board[i][j] is the box being pointed to.
                    // (*board[i][j])[k][l] is the kth row, lth column of the box.
                    cout << (*board[i][j])[k][l];
            cout << char(179) << endl; //vertical border
        }

    // For loop needed to print the lower border of the chess board for every solution.
    cout << " ";
    for (i = 0; i < 7 * 8; i++)
        cout << char(196);
    cout << endl;
}
void BackTrackFunction(int &c){
    c--; //Backtrack.
    if (c == -1) { //If columns reached -1. There is no more solutions to the problem.
        cout << "No more solutions to this problem." << endl;
        exit(0); //So we terminate the program. (We use exit(0) since we cant use return 0; in a void function)
    }
}

int main() {
    int q[8]{}; //declaring the 1D array that will help us place our queens in the right spots.
    int c = 0; //Set columns equal to 0.
    q[0] = 0; //set rows/q[c] equal to 0.

    while (c >= 0) { //nested while loop just like the 1D 8 Queens Problem and the 8 Numbers in a cross problem.
        c++;
        if (c == 8) {
            print(q);
            BackTrackFunction(c);
        }
        else {
            q[c] = -1;
        }

        while (c >= 0) {
            q[c]++;
            if (q[c] == 8) {
                BackTrackFunction(c);
            }
            else {
                if (okFunction(q, c)) {
                    break;
                }
            }

        }
    }
}