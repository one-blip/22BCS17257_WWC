#include <iostream>
using namespace std;

int lastRemaining(int n) {
    bool leftToRight = true;
    int head = 1, step = 1;
    int remaining = n;

    while (remaining > 1) {
        if (leftToRight || remaining % 2 == 1) {
            head += step;
        }
        step *= 2;
        remaining /= 2;
        leftToRight = !leftToRight;
    }

    return head;
}

int main() {
    int n = 9;
    cout << lastRemaining(n) << endl;
    return 0;
}
