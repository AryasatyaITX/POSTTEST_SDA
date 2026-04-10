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

struct Tiket {
    string namaPenumpang;
    int noKA;
    string namaKereta;
    string asal;
    string tujuan;
    string jamBerangkat;
    int hargaTiket;
    int nomorTiket;
};

struct QueueTiket {
    Tiket data[100];
    int front;
    int rear;
};

struct StackRiwayat {
    Tiket data[100];
    int top;
};

#define MAX_DATA 50
#define MAX 100

Kereta daftarKereta[MAX_DATA] = {
    {101, "Argo Bromo", "Surabaya", "Jakarta", "06:00", 350000},
    {102, "Argo Lawu", "Jakarta", "Solo", "08:30", 250000},
    {103, "Sancaka", "Surabaya", "Yogyakarta", "07:00", 235000},
    {104, "Bengawan", "Solo", "Jakarta", "14:30", 74000},
    {105, "Lodaya", "Bandung", "Solo", "06:30", 217000}
};
int Jumlahkereta = 5;
int nomorTiketCounter = 1000;

void header(string judul){
    cout << judul <<endl;
}

void tukarkereta(Kereta* a, Kereta* b) {
    Kereta temp = *a;
    *a = *b;
    *b = temp;
}

void readjadwal(Kereta* arr, int n) {
    if (n == 0) {
        cout << "Belum ada data kereta." << endl;
        return;
    }
    cout <<"================="<<endl;
    header("| JADWAL KERETA |");
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
    cout << "===============================\n";
    cout << "|   TAMBAH DATA KERETA BARU   |\n";
    cout << "===============================\n" << endl;
    cout << "  Nomor KA  : ";
    while (!(cin >> (arr + n)->noKA)) {
        cin.clear();
        cin.ignore(10000, '\n');
        cout << "Input salah! Masukkan angka: ";
    }
    for (int i = 0; i < n; i++) {
        if ((arr + i)->noKA == (arr + n)->noKA) {
            cout << "Nomor KA sudah ada!\n";
            return;
        }
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
    if ((arr + n)->jamBerangkat == "") {
        cout << "Jam tidak boleh kosong!\n";
        return;
    }
    cout << "Harga Tiket     : ";
    cin >> (arr + n)->hargatiket;
    if (cin.fail() || (arr + n)->hargatiket < 0) {
        cout << "Harga tidak valid!\n";
        cin.clear();
        cin.ignore(10000, '\n');
        return;
    }
    n++;
    cout << "Data kereta berhasil ditambahkan!" << endl;
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

void linearSearch(Kereta* arr, int n) {
    if (n == 0) {
        cout << "Belum ada data kereta." << endl;
        return;
    }
    string cariAsal, cariTujuan;
    bool ditemukan = false;
    int posisi;
    cin.ignore(1000, '\n');
    cout << "=====================================\n";
    cout << "|   CARI KERETA BERDASARKAN RUTE    |\n";
    cout << "=====================================\n"<<endl;
    cout << "Masukkan Asal   : "; 
    getline(cin, cariAsal);
    cout << "Masukkan Tujuan : "; 
    getline(cin, cariTujuan);
    //Iterasi Linear seacrhI
    // loop memeriksa setiap elemen/data satu per satu, mulai dari awal(indeks 0) hingga akhir.
    for (int i = 0; i < n; i++) { 
    //pada setiap iterasi ke - i, program akan membandingkan asal dan tujuan data yang dicari atau dari input yg diberikan
        cout << "Iterasi ke-" << i+1; 
        cout << " : " << (arr + i)->asal; 
        cout << " -> " << (arr + i)->tujuan << endl;
        if ((arr + i)->asal == cariAsal && (arr + i)->tujuan == cariTujuan) {
            ditemukan = true;
            posisi = i + 1;
            tukarkereta(arr, arr + i);
        }
    }
    // Jika setelah dibandingkan dan data yang dicari cocok dengan input atau target maka akan menampilkan pada itearsi ini 
    if(ditemukan) {
        cout << "Data ditemukan pada iterasi ke - " << posisi << endl;
    }
    header("\n| HASIL PENCARIAN RUTE |");
    cout << cariAsal << " -> " << cariTujuan << endl;
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
            Kereta* ptr = (arr + i);
            cout << "| " << setw(4) << ptr->noKA << " | ";
            cout << setw(18) << ptr->namaKereta << " | ";
            cout << setw(15) << ptr->asal << " | ";
            cout << setw(15) << ptr->tujuan << " | ";
            cout << setw(8) << ptr->jamBerangkat << " | ";
            cout << "Rp" << setw(10) << ptr->hargatiket << " |" << endl;
        }
    }
    if (!ditemukan) { 
        cout << "| Tidak ditemukan kereta dengan rute tersebut. |\n";
    }
    cout << "================================================================================================\n";
}

void sortNomor(Kereta *arr, int n) {
    for(int i = 0; i < n-1; i++) {
        for(int j = i+1; j < n; j++) {
            if((arr+i)->noKA > (arr+j)->noKA) {
                tukarkereta((arr+i), (arr+j));
            }
        }
    }
}

int jumpSearch(Kereta *arr, int n, int target) {
    int step = (int)sqrt((double)n);
    int prev = 0;

    while (step < n && (arr + step - 1)->noKA < target) {
        prev = step;
        step += (int)sqrt((double)n);
        if (prev >= n)
            return -1;
    }

    int batas = step;
    if (batas > n) batas = n;

    while (prev < batas) {
        if ((arr + prev)->noKA == target)
            return prev;
        prev++;
    }

    return -1;
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
    cout << "============================================================\n";
    cout << "Data berhasil diurutkan berdasarkan Harga Tiket (Termurah)!" << endl;
    readjadwal(arr, n);
}

void initQueue(QueueTiket* q) {
    q->front = -1;
    q->rear = -1;
}
bool cekKosongQueue(QueueTiket* q) {
    return q->front == -1;
}
bool cekPenuhQueue(QueueTiket* q) {
    return q->rear == MAX - 1;
}

void tambahAntrian(QueueTiket* q, Tiket* tiket) {
    if (cekPenuhQueue(q)) {
        cout << "Antrian sudah penuh\n";
        return;
    }
    if (cekKosongQueue(q)) {
        q->front = 0;
    }
    q->rear++;
    *(q->data + q->rear) = *tiket;
    cout << "\n>> " << tiket->namaPenumpang << " berhasil masuk antrian\n";
    cout << "   Kereta: " << tiket->namaKereta << "\n";
    cout << "   Rute: " << tiket->asal << " -> " << tiket->tujuan << "\n";
}

Tiket ambilAntrian(QueueTiket* q) {
    Tiket kosong = {"", 0, "", "", "", "", 0, 0};

    if (cekKosongQueue(q)) {
        cout << "Tidak ada antrian\n";
        return kosong;
    }

    Tiket* ambil = q->data + q->front;
    Tiket hasil = *ambil;

    if (q->front == q->rear) {
        q->front = q->rear = -1;
    } else {
        q->front++;
    }

    return hasil;
}

void initStack(StackRiwayat* s) {
    s->top = -1;
}
bool cekKosongStack(StackRiwayat* s) {
    return s->top == -1;
}
bool cekPenuhStack(StackRiwayat* s) {
    return s->top == MAX - 1;
}

void tambahRiwayat(StackRiwayat* s, Tiket* tiket) {
    if (cekPenuhStack(s)) {
        cout << "Riwayat sudah penuh\n";
        return;
    }

    s->top++;
    *(s->data + s->top) = *tiket;
}

Tiket hapusRiwayat(StackRiwayat* s) {
    Tiket kosong = {"", 0, "", "", "", "", 0, 0};

    if (cekKosongStack(s)) {
        cout << "Belum ada riwayat\n";
        return kosong;
    }

    Tiket* ambil = s->data + s->top;
    Tiket hasil = *ambil;
    s->top--;

    return hasil;
}

void daftarPenumpang(QueueTiket* q) {
    cin.ignore(1000, '\n');
    cout << "===========================================\n";
    cout << "|         PENDAFTARAN PENUMPANG           |\n";
    cout << "===========================================\n\n";

    readjadwal(daftarKereta, Jumlahkereta);

    Tiket baru;
    cout << "Nama Penumpang: ";
    getline(cin, baru.namaPenumpang);

    cout << "Nomor KA: ";
    cin >> baru.noKA;

    bool ketemu = false;
    for (int i = 0; i < Jumlahkereta; i++) {
        if ((daftarKereta + i)->noKA == baru.noKA) {
            ketemu = true;
            baru.namaKereta = (daftarKereta + i)->namaKereta;
            baru.asal = (daftarKereta + i)->asal;
            baru.tujuan = (daftarKereta + i)->tujuan;
            baru.jamBerangkat = (daftarKereta + i)->jamBerangkat;
            baru.hargaTiket = (daftarKereta + i)->hargatiket;
            break;
        }
    }

    if (!ketemu) {
        cout << "Nomor KA tidak ditemukan\n";
        return;
    }

    baru.nomorTiket = nomorTiketCounter++;
    tambahAntrian(q, &baru);
}

void panggilPenumpang(QueueTiket* q, StackRiwayat* s) {
    Tiket panggil = ambilAntrian(q);

    if (panggil.nomorTiket == 0) return;

    cout << "===========================================\n";
    cout << "|         PEMANGGILAN PENUMPANG           |\n";
    cout << "===========================================\n";
    cout << "Nama     : " << panggil.namaPenumpang << "\n";
    cout << "Kereta   : " << panggil.namaKereta << "\n";
    cout << "Rute     : " << panggil.asal << " -> " << panggil.tujuan << "\n";
    cout << "Jam      : " << panggil.jamBerangkat << "\n";
    cout << "No Tiket : " << panggil.nomorTiket << "\n";
    cout << "===========================================\n";
    cout << ">> Penumpang sudah dipanggil\n";

    tambahRiwayat(s, &panggil);
    cout << ">> Data tersimpan di riwayat\n";
}

void tampilSemuaData(QueueTiket* q, StackRiwayat* s) {
    cout << "===========================================\n";
    cout << "|          ANTRIAN PENUMPANG              |\n";
    cout << "===========================================\n";

    if (cekKosongQueue(q)) {
        cout << "[!] Belum ada antrian\n";
    } else {
        cout << "\n>> Penumpang Terdepan:\n";
        Tiket* depan = q->data + q->front;
        cout << "   " << depan->namaPenumpang << " (" << depan->namaKereta << ")\n";

        cout << "\n>> Daftar Antrian:\n";
        int no = 1;
        for (Tiket* ptr = q->data + q->front; ptr <= q->data + q->rear; ptr++) {
            cout << "   " << no++ << ". " << ptr->namaPenumpang;
            cout << " - " << ptr->asal << " ke " << ptr->tujuan;
            cout << " (Rp" << ptr->hargaTiket << ")\n";
        }
    }

    cout << "===========================================\n";
    cout << "|          RIWAYAT TRANSAKSI              |\n";
    cout << "===========================================\n";

    if (cekKosongStack(s)) {
        cout << "Belum ada riwayat\n";
    } else {
        cout << "\n>> Transaksi Terakhir:\n";
        Tiket* terakhir = s->data + s->top;
        cout << "   " << terakhir->namaPenumpang << " (" << terakhir->namaKereta << ")\n";

        cout << "\n>> Semua Riwayat:\n";
        int no = 1;
        for (Tiket* ptr = s->data + s->top; ptr >= s->data; ptr--) {
            cout << "   " << no++ << ". " << ptr->namaPenumpang;
            cout << " - " << ptr->asal << " ke " << ptr->tujuan;
            cout << " (Rp" << ptr->hargaTiket << ")\n";
        }
    }

    cout << "===========================================\n";
}

void batalkanTransaksi(StackRiwayat* s, QueueTiket* q) {
    Tiket batal = hapusRiwayat(s);

    if (batal.nomorTiket == 0) return;

    cout << "\n===========================================\n";
    cout << "        PEMBATALAN TRANSAKSI\n";
    cout << "===========================================\n";
    cout << "Nama   : " << batal.namaPenumpang << "\n";
    cout << "Kereta : " << batal.namaKereta << "\n";
    cout << "Rute   : " << batal.asal << " -> " << batal.tujuan << "\n";
    cout << "===========================================\n";

    if (cekPenuhQueue(q)) {
        cout << "[!] Antrian penuh, tidak bisa dikembalikan\n";
        tambahRiwayat(s, &batal);
        return;
    }

    if (!cekKosongQueue(q)) {
        q->rear++;
        for (Tiket* ptr = q->data + q->rear; ptr > q->data + q->front; ptr--) {
            *ptr = *(ptr - 1);
        }
    } else {
        q->front = 0;
        q->rear = 0;
    }

    *(q->data + q->front) = batal;

    cout << ">> Transaksi dibatalkan\n";
    cout << ">> Penumpang kembali ke antrian terdepan\n";
}

int main() {
    QueueTiket antrian;
    StackRiwayat riwayat;

    initQueue(&antrian);
    initStack(&riwayat);
    int pilihan;
    do {
        cout << "===============================================================" << endl;
        cout << "|         SISTEM MANAJEMEN KEBERANGKATAN KERETA API           |" << endl;
        cout << "===============================================================" << endl;
        cout << "|1. Tampil Jadwal Semua Kereta                                |" << endl;
        cout << "|2. Tambah Data Kereta Baru                                   |" << endl;
        cout << "|3. Cari Kereta Berdasarkan Rute (Linear Search)              |" << endl;
        cout << "|4. Cari Kereta Berdasarkan Nomor KA (Jump Search)            |" << endl;
        cout << "|5. Urutkan Berdasarkan Nama Kereta A-Z (Merge Sort)          |" << endl;
        cout << "|6. Urutkan Berdasarkan Harga Tiket Termurah (Selection Sort) |" << endl;
        cout << "|7. Daftar Penumpang                                          |" << endl;
        cout << "|8. Panggil Penumpang                                         |" << endl;
        cout << "|9. Tampilkan Antrian dan Riwayat                            |" << endl;
        cout << "|10. Batalkan Transaksi                                       |" << endl;
        cout << "|11. Keluar                                                    |" << endl;
        cout << "===============================================================" << endl;
        cout << "Pilih menu: "; 
        cin >> pilihan;
        switch (pilihan) {
            case 1:
                system("cls");
                readjadwal(daftarKereta, Jumlahkereta);
                system("pause");
                system("cls");
                break;
            case 2:
                system("cls");
                tambahKereta(daftarKereta, Jumlahkereta);
                system("pause");
                system("cls");
                break;
            case 3:
                system("cls");
                linearSearch(daftarKereta, Jumlahkereta);
                system("pause");
                system("cls");
                break;
            case 4: {
                system("cls");
                int cari;
                cout << "Masukkan Nomor Kereta Api yang dicari: ";
                while(!(cin >> cari)) {
                    cin.clear();
                    cin.ignore(10000, '\n');
                    cout << "Input salah! Masukkan angka: ";
                }
                sortNomor(daftarKereta, Jumlahkereta);
                int hasil = jumpSearch(daftarKereta, Jumlahkereta, cari);
                if (hasil != -1) {
                    cout << "\nKereta ditemukan:\n";
                    tukarkereta(daftarKereta, daftarKereta + hasil);
                    readjadwal(daftarKereta + hasil, 1);
                } else {
                    cout << "\n[!] Nomor KA tidak ditemukan\n";
                }
                system("pause");
                system("cls");
                break;
            }
            case 5:
                system("cls");
                if (Jumlahkereta == 0) {
                    cout << "Belum ada data kereta." << endl;
                    break;
                }
                cout << "\nData sebelum diurutkan:\n";
                readjadwal(daftarKereta, Jumlahkereta);
                mergeSort(daftarKereta, 0, Jumlahkereta - 1);
                cout << "\nData setelah diurutkan:\n";
                readjadwal(daftarKereta, Jumlahkereta);
                system("pause");
                system("cls");
                break;
            case 6:
                system("cls");
                selectionSortHarga(daftarKereta, Jumlahkereta);
                system("pause");
                system("cls");
                break;
            case 7:
                system("cls");
                daftarPenumpang(&antrian);
                system("pause");
                system("cls");
                break;
            case 8:
                system("cls");
                panggilPenumpang(&antrian, &riwayat);
                system("pause");
                system("cls");
                break;
            case 9:
                system("cls");
                tampilSemuaData(&antrian, &riwayat);
                system("pause");
                system("cls");
                break;
            case 10:
                system("cls");
                batalkanTransaksi(&riwayat, &antrian);
                system("pause");
                system("cls");
                break;
            case 11:
                system("cls");
                cout << "\n===========================================\n";
                cout << "          Terima kasih!\n";
                cout << "    Sampai jumpa lagi!\n";
                cout << "===========================================\n";
                break;
            default:
                cout << " Pilihan tidak valid\n";
                system("pause");
                system("cls");
        }
    } while (pilihan != 11);

    return 0;
}