#include <iostream>

using namespace std;

int gcd(int a, int b) {
    // base case
    if (a==b) {
        return a;
    }

    if (a>b) {
        return gcd(a-b, b);
    }
    else {
        return gcd(a, b-a);
    }
}

int main() {
    cout << "GCD of 8 and 6 is " << gcd(8, 6);
}