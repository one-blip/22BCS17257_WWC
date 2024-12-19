#include <iostream>
using namespace std;

// Program to print if the given number is prime or not.

int main() {
    int n;
    cout << "Enter the number: ";
    cin >> n;
    int cnt = 0;
    if (n <= 1)
        cout << n << " is NOT prime" << endl;
    else {

        for (int i = 2; i * i <= n; i++) {
            if (n % i == 0)
                cnt++;
        }

        if (cnt > 0)
            cout << n << " is NOT prime" << endl;

        else
            cout << n << " is prime" << endl;
    }

    return 0;
}
