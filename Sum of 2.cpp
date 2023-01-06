#include <iostream>
#include <cmath>

using namespace std;
int main(){
    int target = 9;
    int b[5]{1,2,3,4,5};
    
    for(int i=0; i<5; i++){
        for(int j=0; j<5; j++){
            if(b[i]+b[j]==target){
                cout<<"The two indicies that will add up to TARGET are: "<<b[i]<<" and "<<b[j]<<endl;
                return 0;
            }
        }
    }

}