#include <iostream>
using namespace std;

void reverseArray(int* arr, int n) {
    int* awal  = arr;
    int* akhir = arr + n - 1;

    while (awal < akhir) {
        int temp = *awal;
        *awal    = *akhir;
        *akhir   = temp;

        awal++;
        akhir--;
    }
}

int main() {
    int bilPrima[7] = {2, 3, 5, 7, 11, 13, 17};
    int a = 7;
    int* ptr = bilPrima;  
    cout << "==============================\n";
    cout << "|  Array Sebelum Di-reverse  |\n";
    cout << "==============================\n" << endl;
    for (int i = 0; i < a; i++) {
        cout << "Nilai : " << *(ptr + i) << "| Alamatnya : " << (ptr + i) << endl;
    }
    reverseArray(bilPrima, a);
    cout << "==============================\n";
    cout << "|  Array Setelah Di-reverse  |\n";
    cout << "==============================\n" << endl;
    for (int i = 0; i < a; i++) {
        cout << "Nilai : " << *(ptr + i)  << "| Alamatnya : " << (ptr + i) << endl;
    }

    return 0;
}