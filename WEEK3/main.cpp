
/*
     //Example 3.1

#include <iostream>
using namespace std;

int fact(int n) {
    if (n == 0)
        return 1;
    else
        return n * fact(n - 1);
}

int main() {
    cout << "Factorial of 5: " << fact(5) << endl;
    return 0;
}

*/

/*
     //Example 3.2

#include <iostream>
using namespace std;

void rev() {
    char ch;
    cin.get(ch);
    if (ch != '\n') {
        rev();
        cout.put(ch);
    }
}

int main() {
    cout << "Enter a string: ";
    rev();
    cout << endl;
    return 0;
}
*/

/*
      //Example 3.3

#include <iostream>
using namespace std;

int Power(int X, int N) {
    if (N == 0)
        return 1;
    else
        return Power(X, N - 1) * X;
}

int main() {
    cout << "2^5 = " << Power(2, 5) << endl;
    return 0;
}

*/

/*
      //Excercise 3.1
#include <iostream>
using namespace std;

int Power(int X, int N) {

    if (N == 0) {

        return 1;

    }

    else {

        return Power(X, N - 1) * X;

    }
}

int main() {

    cout << "Printing 2^N in Tabular Form: " << endl;

    cout << endl;

    for (int i = 0; i <= 20; i++) {

        cout <<"2 ^ "<< i <<" = "<< "   "<< Power(2, i) << endl;

    }

    return 0;
}
*/


/*
      //Example 3.4 & Excercise 3.2

#include <iostream>
using namespace std;

int Ackermann(int m, int n) {

    if (m == 0) {

        return n + 1;
    }
    else if (m > 0 && n == 0){

        return Ackermann(m - 1, 1);
    }

    else if (m > 0 && n > 0){

        return Ackermann(m - 1, Ackermann(m, n - 1));

    }
}

int main() {

    cout << "Ackermann(3,4) is : " << Ackermann(3, 4) << endl;

    return 0;

}
*/


/*
       //Excercise 3.3(a)

#include <iostream>
using namespace std;

void printNumbers(int no) {

    if (no < 0)
    {
        return;
    }

    cout << no << " ";

    printNumbers(no - 1);
}

int main() {

    int no;
    
    cout << "Input a number till which you want to print:  ";
    cin >> no;

    printNumbers(no);

    cout << endl;

    return 0;
}
*/

/*
     //Excercise 3.3(b)

#include <iostream>
using namespace std;

int binomialCoeff(int n, int k) {

    if (k == 0 || k == n) {

        return 1;
    }

    return binomialCoeff(n - 1, k - 1) + binomialCoeff(n - 1, k);

}

int main() {

    int n, k;

    cout << "Input Value for n: ";
    cin >> n;
    cout << "\nInput Value for k: ";
    cin >> k;

    cout << endl;

    cout << "C(" << n << ", " << k << ") is : " << binomialCoeff(n, k) << endl;

    return 0;
}
*/


/*

     //Excercise 3.3(c)

#include <iostream>
using namespace std;

bool isPrime(int no,int i ) {


    if (no<=2){

        return (no == 2);

    }

    if (no%i==0){

        return false;
    }
    if (i * i > no){

        return true;
    }

    return isPrime(no, i + 1);

}

int main() {

    int no;

    cout << "Input number to check if its Prime: " << endl;
    cin >> no;

    if (isPrime(no)){

        cout << no << " is a Prime Number :) " << endl;

    }

    else {

        cout << no << " is not a prime number :( " << endl;

    }

    return 0;
}
*/

