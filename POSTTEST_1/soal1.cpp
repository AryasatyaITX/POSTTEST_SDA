#include <iostream>
using namespace std;
//====================================================================================
/* Pseudocode                                   Cost          Tmin        Tmax
procedure FindMin                               C1              1           1
  min ← A[0]                                    C2              1           1
  for i ← 1 to n - 1 do                         C3              n           n
    if A[i] < min then                          C4              n - 1       n - 1
      min ← A[i]                                C5              0           n - 1
    end if                                      C6              n - 1       n - 1
  end for                                       C7              n           n
  return min                                    C8              1           1
end procedure                                   C9              1           1
_____________________________________________________________________________________
 Total Waktu (Tn)                                              O(n)         O(n)
=====================================================================================
 Tmin (Best Case) = C1 + C2 + C3n + C4(n-1) + 0 + C6(n-1) + C7n + C8 + C9
 = C1 + C2 + C3n + C4n-C4 + 0 + C6n-C6 + C7n + C8+ C9
 = (C3 + C4 + C6 + C7)n + (C1 + C2 + C8 + C9 - C4 - C6)
 = (1 + 1 + 1 + 1)n + (1 + 1 + 1 + 1 - 1 - 1)
 = 4n + 2
 Big - O = O(n) karena membentuk fungsi linear
====================================================================================
  Tmax (Worst Case) = C1 + C2 + C3n + C4(n-1) + C5(n-1) + C6(n-1) + C7n + C8 + C9
  = C1 + C2 + C3n + C4n-C4 + C5n-C5 + C6n-C6 + C7n + C8+ C9
  = (C3 + C4 + C5 + C6 + C7)n + (C1 + C2 + C8 + C9 - C4 - C5 - C6)
  = (1 + 1 + 1 + 1 + 1)n + (1 + 1 + 1 + 1 - 1 - 1 - 1)
  = 5n + 1
  Big - O = O(n) sama seperti best case, karena membentuk fungsi linear
*/                                  

#include <iostream>
using namespace std;

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
    int minimum;
    int index;

    minimum = findmin(Bilfibonacci, 8);

    for (int i = 0; i < 8; i++) {
        if (Bilfibonacci[i] == minimum) {
            index = i;
            break;
        }
    }

    cout << "Nilai minimum : " << minimum << " ditemukan pada indeks ke-" << index << endl;

    return 0;
}