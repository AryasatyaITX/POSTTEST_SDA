#include <iostream>
#include <iomanip>
#include <cmath>
#include <string>
using namespace std;

struct kereta {
    int noKA;
    string namakereta;
    string asal;
    string tujuan;
    string jamberangkat;
    int hargatiket;
};

#define MAX_DATA 50
kereta daftarKereta[MAX_DATA] = {
    {101, "Argo Bromo", "Surabaya", "Jakarta", "06:00", 350000}   
};
int jumlahData = 1;


void tukarkereta(kereta* a, kereta* b) {
    kereta temp = *a;
    *a = *b;
    *b = temp;
}


void tampiljadwal(kereta* arr, int n) {
    if (n == 0) {
        cout << "Belum ada data kereta." << endl;
        return;
    }
    cout << "\n" << "JADWAL SEMUA KERETA" << "\n";
    cout << "================================================================================================\n";
    cout << "| " << setw(4) << "KA" << " | ";
    cout << setw(18) << "Nama Kereta" << " | ";
    cout << setw(15) << "Asal" << " | ";
    cout << setw(15) << "Tujuan" << " | ";
    cout << setw(8) << "Jam" << " | ";
    cout << setw(12) << "Harga Tiket" << " |\n";
    cout << "================================================================================================\n";

    for (int i = 0; i < n; i++) {

        kereta* ptr = (arr + i);
        cout << "| " << setw(4) << ptr->noKA << " | ";
        cout << setw(18) << ptr->namakereta << " | ";
        cout << setw(15) << ptr->asal << " | ";
        cout << setw(15) << ptr->tujuan << " | ";
        cout << setw(8) << ptr->jamberangkat << " | ";
        cout << "Rp" << setw(10) << ptr->hargatiket << " |" << endl;
    }
    cout << "================================================================================================\n";
    cout << endl;
}

void tambahKereta(kereta* arr, int &n) {
    if (n >= MAX_DATA) {
        cout << "Data sudah penuh!" << endl;
        return;
    }
    cout << "\n=== TAMBAH DATA KERETA BARU ===" << endl;

    cout << "Nomor KA        : "; 
    while(!(cin >> (arr + n)->noKA)) {
        cin.clear();
        cin.ignore(10000, '\n');
        cout << "Input salah! Masukkan angka: ";
    }
    cin.ignore();
    cout << "Nama Kereta     : "; 
    getline(cin, (arr + n)->namakereta);
    cout << "Asal            : "; 
    getline(cin, (arr + n)->asal);
    cout << "Tujuan          : "; 
    getline(cin, (arr + n)->tujuan);
    cout << "Jam Berangkat   : "; 
    getline(cin, (arr + n)->jamberangkat);
    cout << "Harga Tiket     : "; 
    cin >> (arr + n)->hargatiket;

    n++;
    cout << "Data kereta berhasil ditambahkan!" << endl;
}

void linearSearchRute(kereta* arr, int n) {
    if (n == 0) {
        cout << "Belum ada data kereta." << endl;
        return;
    }
    string cariAsal, cariTujuan;
    cin.ignore();
    cout << "\n=== CARI KERETA BERDASARKAN RUTE ===" << endl;
    cout << "Masukkan Asal   : "; getline(cin, cariAsal);
    cout << "Masukkan Tujuan : "; getline(cin, cariTujuan);

    bool ditemukan = false;

    cout << "\nHASIL PENCARIAN RUTE: " << cariAsal << " -> " << cariTujuan << "\n";
    cout << "================================================================================================\n";
    cout << "| " << setw(4) << "KA" << " | ";
    cout << setw(18) << "Nama Kereta" << " | ";
    cout << setw(15) << "Asal" << " | ";
    cout << setw(15) << "Tujuan" << " | ";
    cout << setw(8) << "Jam" << " | ";
    cout << setw(12) << "Harga Tiket" << " |\n";
    cout << "================================================================================================\n";

    for (int i = 0; i < n; i++) {
        if ((arr + i)->asal == cariAsal && (arr + i)->tujuan == cariTujuan) {
            kereta* ptr = (arr + i);
            cout << "| " << setw(4) << ptr->noKA << " | ";
            cout << setw(18) << ptr->namakereta << " | ";
            cout << setw(15) << ptr->asal << " | ";
            cout << setw(15) << ptr->tujuan << " | ";
            cout << setw(8) << ptr->jamberangkat << " | ";
            cout << "Rp" << setw(10) << ptr->hargatiket << " |" << endl;
            ditemukan = true;
        }
    }

    if (!ditemukan) {
        cout << "| Tidak ditemukan kereta dengan rute tersebut.                                                |" << endl;
    }
    cout << "================================================================================================\n";
}


void sortByNoKA(kereta* arr, int n) {
    for (int i = 0; i < n - 1; i++) {
        int minIdx = i;
        for (int j = i + 1; j < n; j++) {
            if ((arr + j)->noKA < (arr + minIdx)->noKA) {
                minIdx = j;
            }
        }
        if (minIdx != i) {
            tukarkereta(arr + i, arr + minIdx);
        }
    }
}

void jumpSearchNoKA(kereta* arr, int n) {
    if (n == 0) {
        cout << "Belum ada data kereta." << endl;
        return;
    }
    int target;
    cout << "\n=== CARI KERETA BERDASARKAN NOMOR KA (Jump Search) ===" << endl;
    cout << "Masukkan Nomor KA : "; cin >> target;

    // Urutkan dulu berdasarkan noKA agar jump search bisa bekerja
    sortByNoKA(arr, n);

    int step = (int)sqrt((double)n);
    int prev = 0;

    //  FASE 1: LOMPAT antar blok 
    /*
        Proses Iterasi Fase Lompat:
        - Periksa arr[step - 1], jika < target maka lompat
        - prev = step, step += sqrt(n)
        - Jika prev >= n, berarti sudah melewati semua elemen
    */
    while ((arr + step - 1)->noKA < target) {
        prev = step;
        step += (int)sqrt((double)n);

        if (prev >= n) {
            cout << "Nomor KA " << target << " tidak ditemukan." << endl;
            return;
        }
    }

    //  FASE 2: LINEAR SEARCH 
    /*
        Proses Iterasi Fase Linear:
        - Cari satu per satu dari prev sampai step (atau n jika step > n)
        - Jika arr[prev] == target -> KETEMU
        - Jika sudah melewati batas blok -> TIDAK KETEMU
    */
    int batas = step;
    if (batas > n) batas = n; // jangan lewati akhir array

    while (prev < batas) {
        if ((arr + prev)->noKA == target) {
            cout << "\nHASIL PENCARIAN NOMOR KA: " << target << "\n";
            cout << "================================================================================================\n";
            cout << "| " << setw(4) << "KA" << " | ";
            cout << setw(18) << "Nama Kereta" << " | ";
            cout << setw(15) << "Asal" << " | ";
            cout << setw(15) << "Tujuan" << " | ";
            cout << setw(8) << "Jam" << " | ";
            cout << setw(12) << "Harga Tiket" << " |\n";
            cout << "================================================================================================\n";
            kereta* ptr = (arr + prev);
            cout << "| " << setw(4) << ptr->noKA << " | ";
            cout << setw(18) << ptr->namakereta << " | ";
            cout << setw(15) << ptr->asal << " | ";
            cout << setw(15) << ptr->tujuan << " | ";
            cout << setw(8) << ptr->jamberangkat << " | ";
            cout << "Rp" << setw(10) << ptr->hargatiket << " |" << endl;
            cout << "================================================================================================\n";
            return;
        }
        prev++;
    }

    cout << "Nomor KA " << target << " tidak ditemukan." << endl;
}


void merge(kereta* arr, int left, int mid, int right) {
    int n1 = mid - left + 1;
    int n2 = right - mid;
    
    kereta* L = new kereta[n1];
    kereta* R = new kereta[n2];

    for (int i = 0; i < n1; i++)
        *(L + i) = *(arr + left + i);
    for (int j = 0; j < n2; j++)
        *(R + j) = *(arr + mid + 1 + j);
    int i = 0, j = 0, k = left;
    while (i < n1 && j < n2) {
        if ((L + i)->namakereta <= (R + j)->namakereta) {
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

void mergeSort(kereta* arr, int left, int right) {
    if (left < right) {
        int mid = left + (right - left) / 2;
        mergeSort(arr, left, mid);
        mergeSort(arr, mid + 1, right);
        merge(arr, left, mid, right);
    }
}

void sortNamaKereta(kereta* arr, int n) {
    if (n == 0) {
        cout << "Belum ada data kereta." << endl;
        return;
    }
    mergeSort(arr, 0, n - 1);
    cout << "\nData berhasil diurutkan berdasarkan Nama Kereta (A-Z)!" << endl;
    tampiljadwal(arr, n);
}


void selectionSortHarga(kereta* arr, int n) {
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
            case 1: tampiljadwal(daftarKereta, jumlahData); break;
            case 2: tambahKereta(daftarKereta, jumlahData); break;
            case 3: linearSearchRute(daftarKereta, jumlahData); break;
            case 4: jumpSearchNoKA(daftarKereta, jumlahData); break;
            case 5: sortNamaKereta(daftarKereta, jumlahData); break;
            case 6: selectionSortHarga(daftarKereta, jumlahData); break;
            case 0: cout << "Terima kasih! Program selesai." << endl; break;
            default: cout << "Pilihan tidak valid!" << endl;
        }
    } while (pilihan != 0);

    return 0;
}