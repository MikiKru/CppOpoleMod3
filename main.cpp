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
    string names [] = {"Anna", "Jan", "Alicja", "Mateusz", "Robert", "Monika"};
    // iteruje po próbach
    int iterations = 0;
    for (int i = 0; i < (sizeof(names)/ sizeof(string)) - 1; i++) {
        // zmienia kolejność na poszczególnych indeksach
        int change = 0;
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
                // inkrementuje zmienna change
                change++;
            }
        }
        iterations ++;
        if(change == 0){
            cout << "przerwanie" << endl;
            // przerwanie sortowania
            break;
        }
    }
    cout << "POSORTOWANE IMIONA W " << iterations << " ITERACJACH" << endl;
    for (int k = 0; k < sizeof(names)/ sizeof(string); ++k) {
        cout << names[k] << endl;
    }
}
string cesarEncoder(string text, int shift){
    string alphabet = "abcdefghijklmnoprstuwxyz ";
//  string alphabet = "cdefghijklmnoprstuwxyz ab";
    cout << alphabet.find("a") << endl;
    return "";
}


int main() {
    cesarEncoder("ala ma kota" ,2);
    return 0;
}