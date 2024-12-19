#include <iostream>
using namespace std;

// Sum of first N natural numbers

int main()
{
    int n;
    cout << "Enter a number: ";
    cin >> n;

    int sum = (n*(n+1))/2;

    cout << "The num of first " << n <<  " natural numbers is: " << sum;

    return 0;
}
