#include <iostream>
using namespace std;

void pertukaran(int* a, int* b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

int main() {
    int nilai_a;
    cout << "Masukkan nilai pertama: ";
    cin >> nilai_a;
    int nilai_b;
    cout << "Masukkan nilai kedua: ";
    cin >> nilai_b;

    cout << "Nilai sebelum pertukaran: " << nilai_a << " dan " << nilai_b << endl;
    pertukaran(&nilai_a, &nilai_b);
    cout << "Nilai setelah pertukaran: " << nilai_a << " dan " << nilai_b << endl;
}