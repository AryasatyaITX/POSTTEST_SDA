#include <iostream>
#include <string>
#include <cmath>
#include <iomanip>
using namespace std;

struct Kereta {
    int noKereta;
    string namaKereta;
    string asal;
    string tujuan;
    string jamBerangkat;
    int hargaTiket;
};

const int MAX_DATA = 50;
Kereta daftarKereta[MAX_DATA];
int jumlahData = 0;

void swapKereta(Kereta* a, Kereta* b) {
    Kereta temp = *a;
    *a = *b;
    *b = temp;
}

void cetakGaris(int panjang) {
    for (int i = 0; i < panjang; i++) cout << "-";
    cout << endl;
}

void tampilkanJadwal(Kereta* arr, int n) {
    if (n == 0) {
        cout << "Belum ada data kereta." << endl;
        return;
    }
    cetakGaris(88);
    cout << "| " << setw(7) << "No KA"
         << " | " << setw(14) << "Nama Kereta"
         << " | " << setw(12) << "Asal"
         << " | " << setw(12) << "Tujuan"
         << " | " << setw(6) << "Jam"
         << " | " << setw(12) << "Harga Tiket" << " |" << endl;
    cetakGaris(88);
    for (int i = 0; i < n; i++) {
        Kereta* ptr = (arr + i);
        cout << "| " << setw(7) << ptr->noKereta
             << " | " << setw(14) << ptr->namaKereta
             << " | " << setw(12) << ptr->asal
             << " | " << setw(12) << ptr->tujuan
             << " | " << setw(6) << ptr->jamBerangkat
             << " | Rp" << setw(9) << ptr->hargaTiket << " |" << endl;
    }
    cetakGaris(88);
    cout << "Total data: " << n << " kereta" << endl << endl;
}

void tampilDetailKereta(Kereta* ptr) {
    cetakGaris(45);
    cout << "| " << setw(16) << "No Kereta"      << " : " << setw(22) << ptr->noKereta      << " |" << endl;
    cout << "| " << setw(16) << "Nama Kereta"    << " : " << setw(22) << ptr->namaKereta    << " |" << endl;
    cout << "| " << setw(16) << "Stasiun Asal"   << " : " << setw(22) << ptr->asal          << " |" << endl;
    cout << "| " << setw(16) << "Stasiun Tujuan" << " : " << setw(22) << ptr->tujuan        << " |" << endl;
    cout << "| " << setw(16) << "Jam Berangkat"  << " : " << setw(22) << ptr->jamBerangkat  << " |" << endl;
    cout << "| " << setw(16) << "Harga Tiket"    << " : Rp" << setw(18) << ptr->hargaTiket  << " |" << endl;
    cetakGaris(45);
}

void tambahKereta(Kereta* arr, int &n) {
    if (n >= MAX_DATA) {
        cout << "Data kereta sudah penuh!" << endl;
        return;
    }
    cetakGaris(45);
    cout << "       TAMBAH DATA KERETA BARU" << endl;
    cetakGaris(45);

    Kereta* ptrBaru = (arr + n);

    cout << "Nomor Kereta    : ";
    cin >> ptrBaru->noKereta;
    cin.ignore();
    cout << "Nama Kereta     : ";
    getline(cin, ptrBaru->namaKereta);
    cout << "Stasiun Asal    : ";
    getline(cin, ptrBaru->asal);
    cout << "Stasiun Tujuan  : ";
    getline(cin, ptrBaru->tujuan);
    cout << "Jam Berangkat   : ";
    getline(cin, ptrBaru->jamBerangkat);
    cout << "Harga Tiket     : Rp ";
    cin >> ptrBaru->hargaTiket;

    n++;
    cout << endl;
    cetakGaris(45);
    cout << ">> Data kereta berhasil ditambahkan! <<" << endl;
    cetakGaris(45);
    cout << endl;
}

void linearSearchRute(Kereta* arr, int n) {
    if (n == 0) {
        cout << "Belum ada data kereta." << endl;
        return;
    }
    string cariAsal, cariTujuan;
    cin.ignore();

    cetakGaris(55);
    cout << "  LINEAR SEARCH - CARI BERDASARKAN RUTE" << endl;
    cetakGaris(55);
    cout << "Masukkan Stasiun Asal   : ";
    getline(cin, cariAsal);
    cout << "Masukkan Stasiun Tujuan : ";
    getline(cin, cariTujuan);

    bool ditemukan = false;
    int langkah = 0;

    cout << endl;
    cetakGaris(55);
    cout << "PROSES LINEAR SEARCH" << endl;
    cetakGaris(55);

    for (int i = 0; i < n; i++) {
        langkah++;
        Kereta* ptr = (arr + i);

        cout << "Langkah " << setw(2) << langkah
             << " : Periksa [" << setw(12) << ptr->namaKereta << "] "
             << setw(12) << ptr->asal << " -> " << setw(12) << ptr->tujuan;

        if (ptr->asal == cariAsal && ptr->tujuan == cariTujuan) {
            cout << " >> COCOK!" << endl << endl;
            cout << ">> DITEMUKAN pada indeks " << i << " <<" << endl;
            tampilDetailKereta(ptr);
            ditemukan = true;
        } else {
            cout << " (tidak cocok)" << endl;
        }
    }

    cetakGaris(55);
    if (!ditemukan) {
        cout << "Kereta rute " << cariAsal << " -> " << cariTujuan
             << " TIDAK DITEMUKAN." << endl;
    }
    cout << "Total langkah pencarian : " << langkah << endl;
    cetakGaris(55);
    cout << endl;
}

void sortByNoKereta(Kereta* arr, int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if ((arr + j)->noKereta > (arr + j + 1)->noKereta) {
                swapKereta((arr + j), (arr + j + 1));
            }
        }
    }
}

void jumpSearchNoKereta(Kereta* arr, int n) {
    if (n == 0) {
        cout << "Belum ada data kereta." << endl;
        return;
    }

    int cariNo;
    cetakGaris(55);
    cout << "  JUMP SEARCH - CARI BERDASARKAN NOMOR KERETA" << endl;
    cetakGaris(55);
    cout << "Masukkan Nomor Kereta : ";
    cin >> cariNo;

    sortByNoKereta(arr, n);
    cout << "(Data diurutkan berdasarkan No Kereta)" << endl;

    int step = (int)sqrt((double)n);
    int prev = 0;
    int langkah = 0;

    cout << endl;
    cetakGaris(55);
    cout << "PROSES JUMP SEARCH (step = " << step << ")" << endl;
    cetakGaris(55);

    cout << endl << "[FASE 1: LOMPAT]" << endl;
    while ((arr + ((step < n ? step : n) - 1))->noKereta < cariNo) {
        langkah++;
        int idx = (step < n ? step : n) - 1;
        cout << "Langkah " << setw(2) << langkah
             << " : Lompat ke indeks " << setw(2) << idx
             << " -> No Kereta = " << setw(4) << (arr + idx)->noKereta
             << " < " << cariNo << " (lanjut)" << endl;
        prev = step;
        step += (int)sqrt((double)n);
        if (prev >= n) {
            cout << endl;
            cetakGaris(55);
            cout << "No Kereta " << cariNo << " TIDAK DITEMUKAN." << endl;
            cout << "Total langkah : " << langkah << endl;
            cetakGaris(55);
            cout << endl;
            return;
        }
    }
    langkah++;
    int batasAtas = (step < n ? step : n) - 1;
    cout << "Langkah " << setw(2) << langkah
         << " : Berhenti indeks " << setw(2) << batasAtas
         << " -> No Kereta = " << setw(4) << (arr + batasAtas)->noKereta
         << " >= " << cariNo << " (STOP)" << endl;

    int batas = step;
    if (batas > n) batas = n;

    cout << endl << "[FASE 2: LINEAR dalam blok " << prev << " - " << batas - 1 << "]" << endl;

    while (prev < batas) {
        langkah++;
        Kereta* ptr = (arr + prev);
        cout << "Langkah " << setw(2) << langkah
             << " : Periksa indeks " << setw(2) << prev
             << " -> No Kereta = " << setw(4) << ptr->noKereta;

        if (ptr->noKereta == cariNo) {
            cout << " >> COCOK!" << endl << endl;
            cout << ">> DITEMUKAN di indeks " << prev << " <<" << endl;
            tampilDetailKereta(ptr);
            cetakGaris(55);
            cout << "Total langkah : " << langkah << endl;
            cetakGaris(55);
            cout << endl;
            return;
        }
        cout << " (tidak cocok)" << endl;
        prev++;
    }

    cout << endl;
    cetakGaris(55);
    cout << "No Kereta " << cariNo << " TIDAK DITEMUKAN." << endl;
    cout << "Total langkah : " << langkah << endl;
    cetakGaris(55);
    cout << endl;
}

void merge(Kereta* arr, int left, int mid, int right) {
    int n1 = mid - left + 1;
    int n2 = right - mid;

    Kereta* L = new Kereta[n1];
    Kereta* R = new Kereta[n2];

    for (int i = 0; i < n1; i++)
        *(L + i) = *(arr + left + i);
    for (int j = 0; j < n2; j++)
        *(R + j) = *(arr + mid + 1 + j);

    int i = 0, j = 0, k = left;

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

void mergeSortNamaKereta(Kereta* arr, int n) {
    if (n <= 0) {
        cout << "Belum ada data kereta." << endl;
        return;
    }

    cetakGaris(88);
    cout << "      MERGE SORT - URUTKAN BERDASARKAN NAMA KERETA (A-Z)" << endl;
    cetakGaris(88);

    cout << endl << "Data SEBELUM sorting:" << endl;
    tampilkanJadwal(arr, n);

    mergeSort(arr, 0, n - 1);

    cout << "Data SETELAH sorting:" << endl;
    tampilkanJadwal(arr, n);
}

void selectionSortHarga(Kereta* arr, int n) {
    if (n <= 0) {
        cout << "Belum ada data kereta." << endl;
        return;
    }

    cetakGaris(88);
    cout << "   SELECTION SORT - URUTKAN BERDASARKAN HARGA TIKET (TERMURAH)" << endl;
    cetakGaris(88);

    cout << endl << "Data SEBELUM sorting:" << endl;
    tampilkanJadwal(arr, n);

    cout << "Proses Selection Sort:" << endl;
    cetakGaris(70);
    cout << setw(8) << "Iterasi"
         << " | " << setw(14) << "Posisi i"
         << " | " << setw(14) << "Minimum"
         << " | " << setw(10) << "Harga i"
         << " | " << setw(10) << "Harga Min"
         << " | Status" << endl;
    cetakGaris(70);

    for (int i = 0; i < n - 1; i++) {
        int minIdx = i;

        for (int j = i + 1; j < n; j++) {
            if ((arr + j)->hargaTiket < (arr + minIdx)->hargaTiket) {
                minIdx = j;
            }
        }

        cout << setw(8) << (i + 1)
             << " | " << setw(14) << (arr + i)->namaKereta
             << " | " << setw(14) << (arr + minIdx)->namaKereta
             << " | Rp" << setw(7) << (arr + i)->hargaTiket
             << " | Rp" << setw(7) << (arr + minIdx)->hargaTiket;

        if (minIdx != i) {
            swapKereta((arr + i), (arr + minIdx));
            cout << " | SWAP" << endl;
        } else {
            cout << " | TETAP" << endl;
        }
    }
    cetakGaris(70);

    cout << endl << "Data SETELAH sorting:" << endl;
    tampilkanJadwal(arr, n);
}

void inisialisasiData(Kereta* arr, int &n) {
    Kereta dataAwal[] = {
        {77, "Argo Bromo",  "Surabaya",   "Jakarta",  "06:00", 350000},
        {23, "Taksaka",     "Yogyakarta", "Jakarta",  "08:00", 280000},
        {45, "Gajayana",    "Malang",     "Jakarta",  "16:00", 320000},
        {12, "Mutiara",     "Surabaya",   "Jakarta",  "19:00", 250000},
        {89, "Lodaya",      "Bandung",    "Surabaya", "07:30", 300000},
        {34, "Sembrani",    "Surabaya",   "Jakarta",  "20:00", 400000},
        {56, "Bima",        "Malang",     "Jakarta",  "15:00", 370000},
        {68, "Turangga",    "Bandung",    "Surabaya", "09:00", 290000}
    };

    n = 8;
    for (int i = 0; i < n; i++)
        *(arr + i) = *(dataAwal + i);
}

void tampilMenu() {
    cout << endl;
    cetakGaris(50);
    cout << "  SISTEM MANAJEMEN KEBERANGKATAN KERETA API" << endl;
    cetakGaris(50);
    cout << "  [1] Tampilkan Jadwal Semua Kereta" << endl;
    cout << "  [2] Tambah Data Kereta Baru" << endl;
    cout << "  [3] Linear Search  - Cari Berdasarkan Rute" << endl;
    cout << "  [4] Jump Search    - Cari Berdasarkan No Kereta" << endl;
    cout << "  [5] Merge Sort     - Urutkan Nama Kereta (A-Z)" << endl;
    cout << "  [6] Selection Sort - Urutkan Harga (Termurah)" << endl;
    cout << "  [0] Keluar" << endl;
    cetakGaris(50);
    cout << "  Pilih menu >> ";
}

int main() {
    inisialisasiData(daftarKereta, jumlahData);

    int pilihan;

    do {
        tampilMenu();
        cin >> pilihan;
        cout << endl;

        switch (pilihan) {
            case 1:
                tampilkanJadwal(daftarKereta, jumlahData);
                break;
            case 2:
                tambahKereta(daftarKereta, jumlahData);
                break;
            case 3:
                linearSearchRute(daftarKereta, jumlahData);
                break;
            case 4:
                jumpSearchNoKereta(daftarKereta, jumlahData);
                break;
            case 5:
                mergeSortNamaKereta(daftarKereta, jumlahData);
                break;
            case 6:
                selectionSortHarga(daftarKereta, jumlahData);
                break;
            case 0:
                cetakGaris(50);
                cout << "  Terima kasih! Program selesai." << endl;
                cetakGaris(50);
                break;
            default:
                cout << "Pilihan tidak valid!" << endl;
                break;
        }
    } while (pilihan != 0);

    return 0;
}