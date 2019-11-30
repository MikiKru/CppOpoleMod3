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
    string alphabet = "0123456789ABCDEFGHIJKLMNOPRSTUWXYZabcdefghijklmnoprstuwxyz ";      //ala ma kota   -> oryginał
//  string alphabet = "cdefghijklmnoprstuwxyz ab";      //cncbocbmrwc   -> szyfr z przesunięciem 2
    string textEncoded = "";
    // pętla po całym napisie text
    for (int i = 0; i < text.length(); i++) {
        // na jakim indeksie występują kolejne znaki w ekście
        int index = alphabet.find(text[i]);
        // indeks przesuwamy o shift
        if(index + shift > alphabet.length() ) {
            index = alphabet.length() - 2 - index + shift;
        } else {
            index = index + shift;
        }
        // za każdym razem do kodu dodajemy znak znajdujący się na indeksie
        textEncoded = textEncoded + alphabet[index];
    }
    return textEncoded;
}
// PROGRAMOWANIE OBIEKTOWE
// deklaracja klasy
class Auto{
public:
    static int globalId;
    int id;
    string brand;
    string model;
    double price;
private :
    double discount = 0.1;      // domyślny rabat
public:
    Auto(string brand, string model, double price){       // konstruktor
        // inkrementacja id
        globalId++;
        // przypisanie wartości statycznej id
        this->id = globalId;              // przypisanie wartości do pola klasowego
        this->brand = brand;
        this->model = model;
        this->price = price;
    }
    ~ Auto(){
        cout << "obiekt zostal zniszczony" << endl;
    }
    void printAuto(){           // funkcja wypisująca informacje o aucie
        cout << "Id: " << this->id << endl;
        cout << "Brand: " << this->brand << endl;
        cout << "Model: " << this->model << endl;
        cout << "Price: " << this->price << " PLN" << endl;
        cout << "Discount: " << this->discount * 100 << "%" << endl;
        cout << "Amount: " << (1 - this->discount) * this->price << "PLN" << endl;
    }

    void setDiscount(double newDiscount){
        // aktualizacja rabatu
        this->discount = newDiscount;
    }
};
// inicjalizacja wartosci globalId
int Auto::globalId = 0;

class Grades{
public:
    double grades[5];                                       // tu będą oceny studentów
    double gradesTemplate[6] = {2, 3, 3.5, 4, 4.5, 5};      // skala ocen
    double grade;
    void assignGrades(){
        for (int i = 0; i < sizeof(grades)/ sizeof(double); i++) {
            cout << "Podaj " << (i+1) << " ocene" << endl;
            cin >> grade;
            bool isOk = false;
            for (int j = 0; j < sizeof(gradesTemplate)/ sizeof(double); j++) {
                if(grade == gradesTemplate[j]){
                    isOk = true;
                    grades[i] = grade;
                    break;
                }
            }
            if(isOk == false){
                i--;
                continue;
            }

        }
    }

    double calculateAvg(){
        double cumSum = 0.;
        for (int i = 0; i < sizeof(grades)/ sizeof(double); i++) {
            cumSum += grades[i];
        }
        return cumSum/(sizeof(grades)/ sizeof(double));
    }
};
int main() {
    Grades g;
    g.assignGrades();
    cout << "AVG: " << g.calculateAvg() << endl;
    return 0;
}