#include<iostream>
#include<cmath>
#include<vector>
using namespace std;
int main() {
	vector<int> b[3]; //creating our vector 
	int n; 
	cout << "Please enter the # of rings to move: ";
	cin >> n; //User inputs numbers of rings to move

	//printing a border
	for (int i = 0; i < 36; i++) {
		cout << char(196);
	}
	cout << endl;
	

	int from = 0;
	// the initial value of to depends on whether n is odd or even. 
	int ClosestTower = (n % 2 == 0 ? 2 : 1); //so I created two variables for when it's odd and for when it's even.
	int FurthestTower = (n % 2 == 0 ? 1 : 2);
	int to = ClosestTower; 
	int candidate = 1;
	int move = 0; //Which move we are on.


	//intializing the towers
	for (int i = n + 1; i >= 1; i--) {
		b[0].push_back(i);
	}
		b[1].push_back(n + 1);
		b[2].push_back(n + 1);
	

	while (b[1].size() < n + 1) { //while t[1] does not contain all of the rings
		cout << "Move #" << ++move << ": Transfer ring " << candidate << " from tower " << char(from + 'A') << " to tower " << char(to + 'A') << "\n";	
		cout << endl;

		//here we move the ring from the "from tower" to the "to tower" (Copy it, then delete it from the "from tower)"
		b[to].push_back(b[from].back());
		b[from].pop_back();

		//from = the index of the tower with the smallest ring that has not just been moved: (to+1)%3 or (to+2)%3
		if (b[(to + 1) % 3].back() < b[(to + 2) % 3].back()) {
			from = (to + 1) % 3;
		}
		else {
			from = (to + 2) % 3;
		}
		//candidate = the ring on top of the b[from] tower
		candidate = b[from].back();

		//to = the index of the closest tower on which the candidate can be placed: (from+1)%3 or (from+2)%3
		// (compare the candidate with the ring on the closer tower; which tower is "closer" depends on whether n
		// odd or even)
		if (b[(from + ClosestTower) % 3].back() > candidate) { 
			to = (from + ClosestTower) % 3; //Determining the closest tower where the ring can be placed.
		}
		else {
			to = (from + FurthestTower) % 3;


		}
	}
	return 0;
}