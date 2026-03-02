#include <iostream>
using namespace std;

/* */

int findmin(int A[], int n) {
    int min = A[0];
    for (int i = 1; i < n; i++) {
        if (A[i] < min) {
            min = A[i];
        }
    }
    return min;
}

int main() {
    int Bilfibonacci[8] = {1, 1, 2, 3, 5, 8, 13, 21};
    int 
}