#include <iostream>
using namespace std;


void reverseArray(int* arr, int n) {
    int* awal = arr;          
    int* akhir = arr + n - 1;    
    
    while (awal < akhir) {
        int temp = *awal;
        *awal = *akhir;
        *akhir = temp;
        
        awal++;
        akhir--;
    }
}

int main() {
    int angkaprima[7] = {2, 3, 5, 7, 11, 13, 17};
    int n = 7;

    cout << "Array Sebelum Di-reverse :\n";
    for (int i = 0; i < n; i++) {
        cout << "Nilai: " << angkaprima[i] << " dengan alamat: " << (angkaprima + i) << endl;
    }

    reverseArray(angkaprima, n);

    cout << "Array Setelah Di-reverse :\n";
    for (int i = 0; i < n; i++) {
        cout << "Nilai: " << angkaprima[i]  << " dengan alamat: " << (angkaprima + i) << endl;
    }
    
    return 0;
}