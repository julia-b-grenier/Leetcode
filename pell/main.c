#include <stdio.h>

int pell(int n) {
    if (n == 1)
        return 1;
    if (n == 0)
        return 0;

    return 2*pell(n-1) + pell(n-2);
} // pell

int main() {
    printf("%d", pell(10));
}