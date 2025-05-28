#include <iostream>
using namespace std;

int main() {
    int num, i, cont = 0;
    cout << "Enter an integer: ";
    cin >> num;

    for (i = 1; i <= num; i++) {
        if (num % i == 0)
            cont++;
    }

    if (cont == 2)
        cout << "The number is prime." << endl;
    else
        cout << "The number is not prime." << endl;

    return 0;
}