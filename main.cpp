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
double* getSquareFunctionPeaks(double a, double b, double c){
    double peaks [2] = { -b/(2*a) , (pow(b,2) - 4*a*c)/(4*a) };
    return peaks;
}

void getSquareFunctionPeaksRef(double a, double b, double c, double & p, double & q){
    p = -b/(2*a);
    q = (pow(b,2) - 4*a*c)/(4*a);
}

void incrementValue(int & value){
    cout << "wprowadzono " << value << endl;
    cout << "po inkrementacji " << ++value << endl;
}

void triangleConstructCheck(int a, int b, int c, bool & check){
    // wyszukanie wartości max
    if((a + b) >= c){
        check = !check;
    }
}
int main() {
    bool check = false;
    triangleConstructCheck(1,1,2, check);
    if(check){
        cout << "z podanych bokow mozna skonstruowac trojkat" << endl;
    } else {
        cout << "z podanych bokow nie mozna skonstruowac trojkata" << endl;
    }

    return 0;
}