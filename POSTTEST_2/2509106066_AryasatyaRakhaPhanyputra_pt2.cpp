#include <iostream>
#include <string>
#include <cmath>
#include <iomanip>
using namespace std;

struct Kereta {
    int noKA;
    string namaKereta;
    string asal;
    string tujuan;
    string jamBerangkat;
    int hargatiket;
};

#define MAX_DATA 30
Kereta daftarKereta[MAX_DATA] = {
    {101, "Argo Bromo", "Surabaya", "Jakarta", "06:00", 350000}   
};
int Jumlahkereta = 1;

void tukarkereta(Kereta* a, Kereta* b) {
    Kereta temp = *a;
    *a = *b;
    *b = temp;
}

void tampiljadwal(Kereta* arr, int n) {
    if (n == 0) {
        cout << "Belum ada data kereta." << endl;
        return;
    }
    cout << "" << "JADWAL SEMUA KERETA" << "\n";
    cout << "================================================================================================\n";
    cout << "| " << setw(4) << "no KA" << " | ";
    cout << setw(18) << "Nama Kereta" << " | ";
    cout << setw(15) << "Asal" << " | ";
    cout << setw(15) << "Tujuan" << " | ";
    cout << setw(8) << "Jam" << " | ";
    cout << setw(12) << "Harga Tiket" << " |\n";
    cout << "================================================================================================\n";

    for (int i = 0; i < n; i++) {
        Kereta* ptr = (arr + i);
        cout << "| " << setw(4) << ptr->noKA << " | ";
        cout << setw(18) << ptr->namaKereta << " | ";
        cout << setw(15) << ptr->asal << " | ";
        cout << setw(15) << ptr->tujuan << " | ";
        cout << setw(8) << ptr->jamBerangkat << " | ";
        cout << "Rp" << setw(12) << ptr->hargatiket << " |" << endl;
    }
    cout << "================================================================================================\n";
    cout << endl;
}

void tambahKereta(Kereta* arr, int &n) {
    if (n >= MAX_DATA) {
        cout << "Kapasitas data untuk Kereta sudah penuh!" << endl;
        return;
    }
    cout << "===============================";
    cout << "|   TAMBAH DATA KERETA BARU   |";
    cout << "==============================="<<endl;
    cout << "  Nomor KA  : "; 
    while(!(cin >> (arr + n)->noKA)) {
        cin.clear();
        cin.ignore(10000, '\n');
        cout << "Input salah! Masukkan angka: ";
    }
    cin.ignore();
    cout << "Nama Kereta     : "; 
    getline(cin, (arr + n)->namaKereta);
    cout << "Asal            : "; 
    getline(cin, (arr + n)->asal);
    cout << "Tujuan          : "; 
    getline(cin, (arr + n)->tujuan);
    cout << "Jam Berangkat   : "; 
    getline(cin, (arr + n)->jamBerangkat);
    cout << "Harga Tiket     : "; 
    cin >> (arr + n)->hargatiket;
    n++;
    cout << "Data kereta berhasil ditambahkan!" << endl;
}

void merge(Kereta* arr, int left, int mid, int right) {
    int n1 = mid - left + 1;
    int n2 = right - mid;
// Membuat array sementara untuk menampung struct
    Kereta* L = new Kereta[n1];
    Kereta* R = new Kereta[n2];
// Menyalin data ke array sementara menggunakan pointer akses
    for (int i = 0; i < n1; i++)
        *(L + i) = *(arr + left + i);
    for (int j = 0; j < n2; j++)
        *(R + j) = *(arr + mid + 1 + j);
    int i = 0, j = 0, k = left;
// Proses penggabungan berdasarkan property 'harga'
    while (i < n1 && j < n2) {
        if ((L + i)->namaKereta <= (R + j)->namaKereta) {
            *(arr + k) = *(L + i);
            i++;
        } else {
            *(arr + k) = *(R + j);
            j++;
        }
        k++;
    }
    while (i < n1) {
        *(arr + k) = *(L + i);
        i++; k++;
    }
    while (j < n2) {
        *(arr + k) = *(R + j);
        j++; k++;
    }
    delete[] L;
    delete[] R;
}

void mergeSort(Kereta* arr, int left, int right) {
    if (left < right) {
        int mid = left + (right - left) / 2;
        mergeSort(arr, left, mid);
        mergeSort(arr, mid + 1, right);
        merge(arr, left, mid, right);
    }
}

void tampilmerge(Kereta* arr, int n) {
    if (n == 0) {
        cout << "Belum ada data kereta." << endl;
        return;
    }
    cout << "Data sebelum diurutkan (berdasarkan nama Kereta)" << endl;
    mergeSort(arr, 0, n - 1);
    cout << "Data berhasil diurutkan berdasarkan Nama Kereta!" << endl;
    tampiljadwal(arr, n);
}

void linearSearchRute(Kereta* arr, int n) {
    if (n == 0) {
        cout << "Belum ada data kereta." << endl;
        return;
    }
    string cariAsal, cariTujuan;
    cin.ignore();
    cout << "=====================================";
    cout << "|   CARI KERETA BERDASARKAN RUTE    |";
    cout << "====================================="<<endl;
    cout << "Masukkan Asal   : "; 
    getline(cin, cariAsal);
    cout << "Masukkan Tujuan : "; 
    getline(cin, cariTujuan);
    bool ditemukan = false;
    cout << "HASIL PENCARIAN RUTE: " << cariAsal << " -> " << cariTujuan << "\n";
    cout << "================================================================================================\n";
    cout << "| " << setw(4) << "KA" << " | ";
    cout << setw(18) << "Nama Kereta" << " | ";
    cout << setw(15) << "Asal" << " | ";
    cout << setw(15) << "Tujuan" << " | ";
    cout << setw(8) << "Jam" << " | ";
    cout << setw(12) << "Harga Tiket" << " |\n";
    cout << "================================================================================================\n";

    for (int i = 0; i < n; i++) {
        // Pointer aritmatika (syarat 3)
        if ((arr + i)->asal == cariAsal && (arr + i)->tujuan == cariTujuan) {
            Kereta* ptr = (arr + i);
            cout << "| " << setw(4) << ptr->noKA << " | ";
            cout << setw(18) << ptr->namaKereta << " | ";
            cout << setw(15) << ptr->asal << " | ";
            cout << setw(15) << ptr->tujuan << " | ";
            cout << setw(8) << ptr->jamBerangkat << " | ";
            cout << "Rp" << setw(10) << ptr->hargatiket << " |" << endl;
            ditemukan = true;
        }
    }
    if (!ditemukan) {
        cout << "| Tidak ditemukan kereta dengan rute tersebut.                                                |" << endl;
    }
    cout << "================================================================================================\n";
}
void sortNomor(Kereta *arr, int n) {//untuk jumpsearch agar data terurut dulu
    for(int i = 0; i < n-1; i++) {
        for(int j = i+1; j < n; j++) {
            if((arr+i)->noKA > (arr+j)->noKA) {
                tukarkereta((arr+i), (arr+j));
            }
        }
    }
}

int jumpSearch(Kereta *arr, int n, int target) {
    int step = (int)sqrt((double)n); // ukuran satu lompatan
    int prev = 0;

    while (arr[step - 1] < target) {
        prev = step;
        step += (int)sqrt((double)n);
        if (prev >= n)
        return -1; // sudah melewati semua elemen
    }
// === FASE 2: LINEAR SEARCH dalam blok ===
// Cari satu per satu dari prev sampai ujung blok
    int batas = step;
    if (batas > n) batas = n; // jangan lewati akhir array
    while (prev < batas) {
        if (arr[prev] == target)
            return prev; // KETEMU
        prev++;
    }
    return -1; // TIDAK KETEMU
}


void selectionSortHarga(Kereta* arr, int n) {
    if (n == 0) {
        cout << "Belum ada data kereta." << endl;
        return;
    }
    for (int i = 0; i < n - 1; i++) {
        int minIdx = i;
        for (int j = i + 1; j < n; j++) {
            if ((arr + j)->hargatiket < (arr + minIdx)->hargatiket) {
                minIdx = j;
            }
        }
        if (minIdx != i) {
            tukarkereta(arr + i, arr + minIdx);
        }
    }
    cout << "\nData berhasil diurutkan berdasarkan Harga Tiket (Termurah)!" << endl;
    tampiljadwal(arr, n);
}

int main() {
    int pilihan;
    do {
        cout << "\n============================================" << endl;
        cout << "  SISTEM MANAJEMEN KEBERANGKATAN KERETA API" << endl;
        cout << "============================================" << endl;
        cout << "1. Tampil Jadwal Semua Kereta" << endl;
        cout << "2. Tambah Data Kereta Baru" << endl;
        cout << "3. Cari Kereta Berdasarkan Rute (Linear Search)" << endl;
        cout << "4. Cari Kereta Berdasarkan Nomor KA (Jump Search)" << endl;
        cout << "5. Urutkan Berdasarkan Nama Kereta A-Z (Merge Sort)" << endl;
        cout << "6. Urutkan Berdasarkan Harga Tiket Termurah (Selection Sort)" << endl;
        cout << "0. Keluar" << endl;
        cout << "============================================" << endl;
        cout << "Pilih menu: "; cin >> pilihan;

        switch (pilihan) {
            case 1: tampiljadwal(daftarKereta, Jumlahkereta); break;
            case 2: tambahKereta(daftarKereta, Jumlahkereta); break;
            case 3: linearSearchRute(daftarKereta, Jumlahkereta); break;
            case 4: jumpSearch(daftarKereta, Jumlahkereta); break;
            case 5: tampilmerge(daftarKereta, Jumlahkereta); break;
            case 6: selectionSortHarga(daftarKereta, Jumlahkereta); break;
            case 0: cout << "Terima kasih! Program selesai." << endl; break;
            default: cout << "Pilihan tidak valid!" << endl;
        }
    } while (pilihan != 0);

    return 0;
}