#include <iostream>
using namespace std;

void pertukaran(int* a, int* b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

int main() {
    int nilaia;
    cout << "Masukkan nilai pertama: ";
    cin >> nilaia;
    int nilaib;
    cout << "Masukkan nilai kedua: ";
    cin >> nilaib;
    
    cout << "====================================\n";
    cout << "Nilai sebelum pertukaran: " << nilaia << " dan " << nilaib << endl;
    cout << "===================================\n";
    pertukaran(&nilaia, &nilaib);

    cout << "===================================\n";
    cout << "Nilai sesudah pertukaran: " << nilaia << " dan " << nilaib << endl;
    cout << "===================================\n";
}