#include <iostream>
using namespace std;

struct Mahasiswa {
    string nama;
    string nim;
    float ipk;
};

int main() {
    Mahasiswa mhs [5];
    cout << "Masukkan data" << 5 << " Mahasiswa :\n" << endl;
    for (int i = 0; i<5; i++) {
        cout << "Mahasiswa ke-" << i+1 << ":\n";
        cout << "Nama: ";
        cin >> mhs[i].nama;
        cout << "NIM: ";
        cin >> mhs[i].nim;
        cout << "IPK: ";
        cin >> mhs[i].ipk;
    }

    int ipkTertinggi = 0;
    for (int i=0; i<5; i++) {
        if (mhs[i].ipk > mhs[ipkTertinggi].ipk) {
            ipkTertinggi = i;
        }
    }

    cout << "\nMahasiswa dengan IPK tertinggi :\n ";
    cout << "Nama : " << mhs[ipkTertinggi].nama << endl;
    cout << "NIM : " << mhs[ipkTertinggi].nim << endl;
    cout << "IPK : " << mhs[ipkTertinggi].ipk << endl;

    return  0;
}