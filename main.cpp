#include <iostream>
#include <string>
#include <cmath>
#include <cstdlib>
#include "time.h"

using namespace std;

void squareFunction(double a, double b, double c){
    double delta = pow(b,2) - 4*a*c;
    if(delta > 0){
        cout << "Wystepuja dwa pierwiastki: " << ((-b-delta)/(2*a)) << " i " << ((-b+delta)/(2*a)) << endl;
    } else if(delta == 0){
        cout << "Wystepuje jeden pierwiastek: " << ((-b)/(2*a)) << endl;
    } else {
        cout << "Brak rzeczywistych miejsc zerowych" << endl;
    }
}



int main() {
    squareFunction(2,3,4);
    squareFunction(1,2,1);
    squareFunction(1,3.2,1);
    return 0;
}