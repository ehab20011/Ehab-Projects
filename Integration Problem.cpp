#include <iostream>
#include <cmath>
using namespace std;

typedef double (*FUNC)(double); //typedef

double integrate(FUNC f, double a, double b) { //Function with the 3 arguments
   double sum = 0; //sum
   double  increment = 0.0001; //each rectangle has a width of 0.0001
   for (double x = a + increment/2; x < b; x += increment) // For each rectangle,
      sum += f(x) * increment; //finding the area then adding it to the sum
   return sum;
}
double line(double x){
   return x;
}

double square(double x){
   return x*x;
}

double cube(double x){
   return x*x*x;
}

int main() {
   cout << "The integral of f(x) = x between 1 and 5 is: " << integrate(line, 1, 5) << endl;     // 12
   cout<<endl;
   cout << "The integral of f(x) = x^2 between 1 and 5 is: " << integrate(square, 1, 5) << endl; // 41.3333
   cout<<endl;
   cout << "The integral of f(x) = x^3 between 1 and 5 is: " << integrate(cube, 1, 5) << endl;   // 156
   return 0;
}