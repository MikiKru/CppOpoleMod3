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

class Lotto{
public:
    int result [6];
public:
    // uruchomienie losowania
    void generateNumbers(){
        srand(time(NULL));
        for (int i = 0; i < sizeof(result)/ sizeof(int); i++) {
            // sprawdzenie czy wartośc nie jest już dostępna w liście result
            int number = (rand() % 49) + 1;      // losowanie liczb z zakresu 1 - 49
            bool isUnique = true;
            // pętla sprawdzająca czy wartość number już występuje w liście result
            for (int j = 0; j <= i; j++) {
                if(number == result[j]){
                    // wartość się powtarza
                    isUnique = false;
                    i--;        // dekrementacja i
                    break;
                }
            }
            // gdy wartość się nie powtarza
            if(isUnique){
                result[i] = number;
            }
//            cout << number << endl;
        }
    }
    void getResult(){
        for (int i = 0; i < sizeof(result)/ sizeof(int) ; ++i) {
            cout << result[i] << " ";
        }
        cout << endl;
    }

    void sortNumbers(bool asc){     // asc=true min-max if asc=false max-min //
        for (int i = 0; i < (sizeof(result)/ sizeof(int)) - 1; ++i) {
            for (int j = 0; j < (sizeof(result)/ sizeof(int)) -1; ++j) {
                if((result[j] > result[j+1]) && (asc == true)){
                    int element = result[j+1];
                    result[j+1] = result[j];
                    result[j] = element;
                }
                if((result[j] < result[j+1]) && (asc == false)){
                    int element = result[j+1];
                    result[j+1] = result[j];
                    result[j] = element;
                }
            }
        }

    }
};

class Player{               //  waga / (wzrost/100)^2
public:
    static int globalId;
    int id;
    string name, lastname, repr;
    double weight,height;
public:
    Player(string name, string lastname, string repr, double weight, double height){
        globalId++;
        this->id = globalId;
        this->name = name;
        this->lastname = lastname;
        this->repr = repr;
        this->weight = weight;
        this->height = height;
    }
    void printPlayer(){
        cout << "Id: " << id << endl;
        cout <<  "Name: "<< name << endl;
        cout << "Lastname: "<< lastname << endl;
        cout << "Representation: " << repr << endl;
        cout << "Weight: "<< weight << "KG" << endl;
        cout << "Height: " << height << "CM" << endl;
        cout << "BMI: "<< calculateBMI() << endl;
    }
private:
    double calculateBMI(){
        return weight/(pow(height/100,2));
    }
};
int Player::globalId = 0;


class Employee {        // klasa modelu
private:
    string name, lastname, possition;
    double salary;
public:
    // gettery -> bez argumentu zwracające wartoś typu pola
    string getName(){
        return this->name;
    }
    string getLastname(){
        return this->lastname;
    }
    string getPossition(){
        return this->possition;
    }
    double getSalary(){
        return this->salary;
    }
    // settery -> midyfikacja pól o wartość podaną z argumentu
    void setName(string name){
        this->name = name;
    }
    void setLastname(string lastname){
        this->lastname = lastname;
    }
    void setPossition(string possition){
        this->possition = possition;
    }
    void setSalary(double salary){
        this->salary = salary;
    }
    Employee (){}       // konstruktor domyślny do inicjalizacji listy employees
    // konstruktor
    Employee(string name, string lastname, string possition, double salary){
        this->name = name;
        this->lastname = lastname;
        this->possition = possition;
        this->salary = salary;
    }
    void toString(){
        cout << name << " " << lastname << " " << possition << " " << salary << "PLN" << endl;
    }
};

class Company {      // klasa kontrollera/serwisu -> implemntacja logiki beiznesowej aplikacji
private:
    Employee employees [100];
    int index = 0;
public:
    void addEmployee(string name, string lastname, string possition, double salary){
        // utworzenie obiektu pracownika
        Employee e(name, lastname, possition, salary);
        // dodanie obiektu do listy
        employees[index] = e;
        // inkrementacja indeksu
        index++;
    }
    void getEmployees(){
        for (int i = 0; i <= index; i++) {
            // wypisanie wszystkich pól obiektu
            employees[i].toString();
        }
    }
};

int main() {
    Company c;
    c.addEmployee("x","x","x",1000);
    c.addEmployee("y","y","y",3000);
    c.addEmployee("z","z","z",2000);
    c.getEmployees();
    return 0;
}