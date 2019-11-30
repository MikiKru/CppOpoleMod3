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
void sortNamesAsc(){
    string names [] = {"Jan", "Alicja", "Mateusz", "Robert", "Monika", "Anna"};
    // iteruje po próbach
    int iterations = 0;
    for (int i = 0; i < (sizeof(names)/ sizeof(string)) - 1; i++) {
        // zmienia kolejność na poszczególnych indeksach
        for (int j = 0; j < (sizeof(names)/ sizeof(string)) - 1; ++j) {
            // sprawdzam sąsiednie elementy
            if(names[j] > names[j+1]){
                // zmiana kolejności wartości na indeksach j oraz j+1
                // wyprowadzam do zmiennej wartość która będzie nadpisywana
                string name = names[j + 1];
                // nadpisuję wartość na indeksie j + 1 wartością j
                names[j+1] = names[j];
                // na indeks j nadpisujemy wartość ze zmiennnej name
                names[j] = name;
            }
        }
        iterations ++;
    }
    cout << "POSORTOWANE IMIONA W " << iterations << " ITERACJACH" << endl;
    for (int k = 0; k < sizeof(names)/ sizeof(string); ++k) {
        cout << names[k] << endl;
    }
}

int main() {
//    string names [] = {"Jan", "Alicja", "Mateusz", "Robert", "Monika", "Anna"};
    sortNamesAsc();
    return 0;
}