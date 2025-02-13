/*     
//Example 1.1
#include <iostream>
using namespace std;

int max1(int X, int Y) {
    return (X > Y) ? X : Y;
}


void max2(int X, int Y, int& Larger) {
    Larger = (X > Y) ? X : Y;
}


void max3(int X, int Y, int* Larger) {
    *Larger = (X > Y) ? X : Y;
}

int main() {

    int x = 2, y = 8;
    int larger = 10;

    cout << max1(3, 4);

    cout << endl;

    cout << "X = " << x << " , Y = " << y << ", Larger = " << larger << endl;

    return 0;
}
*/


/*

         //Excercise 1.1
#include <iostream>
#include <math.h>
using namespace std;

class Complex {
private:

    float re;
    float im;

public:

    Complex(float r, float i) {
        re = r;
        im = i;
    }
    Complex(float r) {
        re = r;
        im = 0.0;
    }
    ~Complex() {}


    double Magnitude() {
        return sqrt(re * re + Imag() * Imag());
    }


    float Real() {
        return re;
    }
    float Imag() {
        return im;
    }


    Complex operator+ (Complex b) {
        return Complex(re + b.re, im + b.im);
    }


    Complex operator* (Complex b) {
        return Complex((re * b.re - im * b.im), (re * b.im + im * b.re));
    }
};

int main() {
    Complex a(1.0, 1.0);
    Complex* b = new Complex(5.0);
    Complex c(0, 0);
    Complex d(0, 0);


    cout << "a real = " << a.Real() << ",  a imaginary = " << a.Imag() << endl;
    cout << "b real = " << b->Real() << " ,  b imaginary = " << b->Imag() << endl;

    cout << endl;
    cout << "Result of Addition: " << endl;
    c = a + (*b);
    cout << "c real = " << c.Real() << " , c imaginary = " << c.Imag() << endl;

    cout << endl;
    cout << "Result of Subtraction: " << endl;
    d = a * (*b);
    cout << "d real = " << d.Real() << ", d imaginary = " << d.Imag() << endl;


    delete b;

    return 0;
}

*/


/*

           //Example 1.3
#include <iostream>
using namespace std;

template <class T>
T GetMax(T a, T b) {
    T result;
    result = (a > b) ? a : b;
    return result;
}

int main() {
    int i = 5, j = 6, k;
    long l = 10, m = 5, n;

    k = GetMax<int>(i, j);
    n = GetMax<long>(l, m);

    cout << k << endl;
    cout << n << endl;

    return 0;
}

*/


/*

          //Excercise 1.2
#include <iostream>
using namespace std;

template <class T>
class mypair {
    T a, b;

public:
    mypair(T first, T second) {

        a = first;
        b = second;
    }

    T getMax();

    T getMin();
};

template <class T>
T mypair<T>::getMax() {
    T retval;
    retval = (a > b) ? a : b;
    return retval;
}

template <class T>
T mypair<T>::getMin() {
    T retval;
    retval = (a < b) ? a : b;
    return retval;
}

int main() {
    mypair<int> myobject(100, 75);

    cout <<"Maximum Value: "<< myobject.getMax();

    cout << endl;

    cout <<"Minimum Value: "<< myobject.getMin();

    return 0;
}


*/


/*

          //Excercise 1.3
#include <iostream>
using namespace std;

template <class T, int N>
class mysequence {

    T memblock[N];

public:

    void setmember(int x, T value);
    T getmember(int x);

    T getMax();
    T getMin();

};

template <class T, int N>
void mysequence<T, N>::setmember(int x, T value) {

    memblock[x] = value;

}

template <class T, int N>
T mysequence<T, N>::getmember(int x) {

    return memblock[x];

}

template <class T, int N>
T mysequence<T, N>::getMin() {
    T minResult = memblock[0];
    for (int i = 1; i < N; i++) {
        if (memblock[i] < minResult) {
            minResult = memblock[i];
        }
    }
    return minResult;
}


template <class T, int N>
T mysequence<T, N>::getMax() {

    T maxResult = memblock[0];
    for (int i = 1; i < N; i++) {
        if (memblock[i] > maxResult) {
            maxResult = memblock[i];
        }
    }
    return maxResult;
}



int main() {
    mysequence<int, 5> myints;
    mysequence<double, 5> myfloats;

    myints.setmember(0, 100);
    myints.setmember(3, 78);

    myfloats.setmember(3, 3.1416);
    myfloats.setmember(5, 1.2);


    cout << "Max Value: " << myints.getMax() << endl;

    cout << "Min value: " << myints.getMin() << endl;

    return 0;
}

*/


/*
     
          //Excercise 1.4
#include <iostream>
#include <fstream>
using namespace std;

int main() {

    ifstream inFile("fin.txt");

    ofstream outFile("fout.txt");

    if (!inFile) {

        cout << "OOPS! there was some error in opening file :( " << endl;
        return 1;

    }

    char ch;

    int count_char = 0, count_word = 0, count_sentence = 0;

    bool current_word = false;

    while (inFile.get(ch)) {

        outFile << ch;


        if (ch != '\n' && ch != ' ') {

            count_char++;

        }

        if (ch == '\n ' || ch == ' ') {

            current_word = false;

        }
        else if (!current_word) {

            count_word++;
            current_word = true;

        }

        if (ch == '?' || ch == '.' || ch == '!')

            count_sentence++;
    }

    outFile << "\n\nTotal characters in file are : " << count_char << endl;
    outFile << "Total words in file are : " << count_word << endl;
    outFile << "Total sentences in file are : " << count_sentence << endl;



    cout << "Total Character in file are : " << count_char << endl;
    cout << "\nTotal Words in file are : " << count_word << endl;
    cout << "\nTotal Sentences in file are  : " << count_sentence << endl;

    inFile.close();

    outFile.close();

    return 0;
}

*/


/*

              //Example 1.7
#include <iostream>
#include <fstream>

using namespace std;

int main() {
    char name[10];

    float mt1, mt2, final, avg;

    ifstream fin;

    ofstream fout;

    fin.open("input.dat");

    fout.open("output.dat");

    while (!fin.eof()) {

        fin >> name >> mt1 >> mt2 >> final;
        avg = 0.25 * mt1 + 0.25 * mt2 + 0.5 * final;
        fout << name << "\t" << avg << endl;
    }

    fin.close();
    fout.close();

    return 0;
}

*/


/* 
             //Excercise 1.5
#include <iostream>
#include <string>
#include <iomanip>
using namespace std;

class House {
public:
    string house_owner;
    string house_address;
    int bedroom_no;
    float house_price;


    void inputData() {

        cout << "Taking Details of House from User" << endl;

        cout << "\nInput name of owner: ";
        getline(cin, house_owner);

        cout << "\nInput address of house: ";
        getline(cin, house_address);

        cout << "\nInput number of bedrooms: ";
        cin >> bedroom_no;

        cout << "\nInput price of house: ";
        cin >> house_price;

        cin.ignore();

        cout << endl;
    }

    void displayData() const {

        cout << left << setw(12) << house_owner << setw(12) << house_address<< setw(11) << bedroom_no<< fixed << setprecision(2) << house_price << endl;

    }
};

int main() {
    House Available[100];
    int house_count = 0;

    char ch;

    do {

        if (house_count >= 100) {

            cout << "OOPS ! Max limit reached :( " << endl;
            break;

        }

        Available[house_count].inputData();

        house_count++;

        cout << "\nPress Y if you wish to enter another house, otherwise press no to display details of entered houses. ";

        cin >> ch;

        cout << endl;

        cin.ignore();

    } while (ch == 'y' || ch == 'Y');

    cout << "Displaying Details of Houses:" << endl;

    cout << "\nOwner     Address     Bedrooms     Price" << endl;

    cout << endl;

    for (int i = 0; i < house_count; i++) {
        Available[i].displayData();
        cout << endl;
    }

    return 0;
}

*/



               //Excercise 1.6

// #include <iostream>
// #include <fstream>
// #include <string>
// #include <iomanip>
// using namespace std;

// class Student {

// private:

//     char name[30];
//     int grades[10];
//     float average;

// public:

//     void readData(ifstream& file, int no_of_grades) {

//         file >> ws;
        
//         file.getline(name, 30);

//         cout << "\Student Name: " << name << endl;

//         int sum = 0;

//         for (int i = 0; i < no_of_grades; i++) {

//             file >> grades[i];
//             sum += grades[i];

//         }
//         cout << endl;

//         average = static_cast<float>(sum) / no_of_grades;
//     }

//     void displayData(int no_of_grades) const {

//         cout << left << setw(18) << name;

//         for (int i = 0; i < no_of_grades; i++) {
//             cout << setw(5) << grades[i];
//         }

//         cout << setw(10) << fixed << setprecision(2) << average << endl;
//     }

//     float getAverage() const {

//         return average;

//     }
//     const char* getName() const {

//         return name;

//     }
// };

// int main() {
//     string name_of_file;

//     cout << "Input name of file: ";
//     cin >> name_of_file;

//     cin.ignore();

//     ifstream file(name_of_file.c_str());

//     if (!file) {

//         cerr << "OOPS! there was some error in opening the file :( " << endl;

//         return 1;

//     }
  


//     int no_of_students = 100;
//     int no_of_grades=100;

//     file >> no_of_students >> no_of_grades;

//     file.ignore();

//     Student students[100];


//     cout << "\nReading Data From File Of The Following Students: " << endl;

//     cout << endl;

//     for (int i = 0; i < no_of_students; i++) {

//         students[i].readData(file, no_of_grades);

//     }
//     if (no_of_students > 100) {

//         cerr << "OOPS! Maximum Students Limit Reached :(" << endl;

//         return 1;
//     }

//     cout << "\n/Displaying Student Details/" << endl;

//     cout << endl;

//     cout << left << setw(18) << "Full Name";

//     for (int i = 1; i <= no_of_grades; i++) {
//         cout << "G" << i << "   ";
//     }
//     cout << setw(10) << "Average" << endl;
//     cout << endl;

//     for (int i = 0; i < no_of_students; i++) {
//         students[i].displayData(no_of_grades);
//     }


//     float sum = 0;

//     for (int i = 0; i < no_of_students; i++) {

//         sum += students[i].getAverage();

//     }
//     float class_average = sum / no_of_students;

//     cout << "\nClass Average: " << fixed << setprecision(2) << class_average << endl;


//     float highest_average = students[0].getAverage();

//     float lowest_average = students[0].getAverage();

//     for (int i = 1; i < no_of_students; i++) {

//         if (students[i].getAverage() > highest_average) {

//             highest_average = students[i].getAverage();

//         }

//         if (students[i].getAverage() < lowest_average) {

//             lowest_average = students[i].getAverage();

//         }
//     }

//     cout << "\nHighest Average: " << highest_average << endl;
//     cout << "\nLowest Average: " << lowest_average << endl;


//     cout << "\n\nList Of Students below class average:" << endl;

//     cout << endl;

//     for (int i = 0; i < no_of_students; i++) {

//         if (students[i].getAverage() < class_average) {

//             cout << students[i].getName() << endl;

//         }
//     }

//     file.close();

//     return 0;
// }

