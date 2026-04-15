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
    string namapenumpang;
    int noKA;
    string kereta;
    string asal;
    string tujuan;
    string jam;
    int harga;
    Tiket* next; 
};

#define MAX_DATA 100

Tiket* front = NULL;
Tiket* rear  = NULL;

bool isEmptyQueue() {
    return (front == NULL);
}

bool isFullQueue() {
    return false;
}

void enqueue(Tiket t) {
    t.next = NULL;
    Tiket* nodeBaru = new Tiket;
    *nodeBaru = t;              
    nodeBaru->next = NULL;
    if (isEmptyQueue()) {
        front = rear = nodeBaru;
    } else {
        rear->next = nodeBaru;
        rear = nodeBaru;
    }
    cout << ">> " << t.namapenumpang << " masuk antrian.\n";
}

Tiket dequeue() {
    Tiket kosong;
    kosong.noKA = -1;
    kosong.next = NULL;
    if (isEmptyQueue()) {
        cout << "Queue underflow! Antrian kosong!\n";
        return kosong;
    }
    Tiket* hapus = front;
    Tiket t = *front;         
    front = front->next;       
    if (front == NULL) {
        rear = NULL;
    }
    delete hapus;
    t.next = NULL;
    cout << ">> Memproses: " << t.namapenumpang
         << " | " << t.asal << " -> " << t.tujuan
         << " | Rp" << t.harga << endl;
    return t;
}

void tampilQueue() {
    if (isEmptyQueue()) {
        cout << "Antrian kosong!\n";
        return;
    }
    cout << "============================\n";
    cout << "|   ANTRIAN (front -> rear)|\n";
    cout << "============================\n";
    Tiket* temp = front;
    while (temp != NULL) {
        cout << "Nama: " << temp->namapenumpang
             << " | KA " << temp->noKA << " - " << temp->kereta
             << " | " << temp->asal << " -> " << temp->tujuan
             << " | " << temp->jam
             << " | Rp" << temp->harga << endl;
        temp = temp->next;
    }
    cout << "NULL\n";
}

void peekQueue() {
    if (isEmptyQueue()) {
        cout << "Antrian terdepan: (kosong)\n";
        return;
    }

    cout << "Antrian terdepan: " << front->namapenumpang
         << " | " << front->asal << " -> " << front->tujuan
         << " | Rp" << front->harga << endl;
}

Tiket* top = NULL;

bool isEmptyStack() {
    return (top == NULL);
}

bool isFullStack() {
    return false;
}

void push(Tiket t) {
    Tiket* nodeBaru = new Tiket;
    *nodeBaru = t;        
    nodeBaru->next = top;  
    top = nodeBaru;
}

void pop() {
    if (isEmptyStack()) {
        cout << "Stack underflow! Riwayat kosong!\n";
        return;
    }

    Tiket* hapus = top;
    cout << ">> Menghapus transaksi terakhir: " << hapus->namapenumpang
         << " | " << hapus->asal << " -> " << hapus->tujuan
         << " | Rp" << hapus->harga << endl;
    top = top->next;
    delete hapus;
}

void tampilStack() {
    if (isEmptyStack()) {
        cout << "Riwayat kosong!\n";
        return;
    }

    cout << "==============================\n";
    cout << "|RIWAYAT (top -> NULL)       |\n";
    cout << "==============================\n";
    Tiket* temp = top;
    while (temp != NULL) {
        cout << "Nama: " << temp->namapenumpang
             << " | KA " << temp->noKA << " - " << temp->kereta
             << " | " << temp->asal << " -> " << temp->tujuan
             << " | " << temp->jam
             << " | Rp" << temp->harga << endl;
        temp = temp->next;
    }
    cout << "NULL\n";
}

void peekStack() {
    if (isEmptyStack()) {
        cout << "Transaksi terakhir: (kosong)\n";
        return;
    }

    cout << "Transaksi terakhir: " << top->namapenumpang
         << " | " << top->asal << " -> " << top->tujuan
         << " | Rp" << top->harga << endl;
}

bool ambilKereta(Kereta* arr, int n, int no, Kereta* out) {
    for (int i = 0; i < n; i++) {
        if ((arr + i)->noKA == no) {
            *out = *(arr + i);
            return true;
        }
    }
    return false;
}

Kereta daftarKereta[MAX_DATA] = {
    {101, "Argo Bromo", "Surabaya", "Jakarta", "06:00", 350000},
    {102, "Argo Lawu", "Jakarta", "Solo", "08:30", 250000},
    {103, "Sancaka", "Surabaya", "Yogyakarta", "07:00", 235000},
    {104, "Bengawan", "Solo", "Jakarta", "14:30", 74000},
    {105, "Lodaya", "Bandung", "Solo", "06:30", 217000}
};
int Jumlahkereta = 5;

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
    // jika setelah loop membandingkan semua data dan target seluruh iterasi bila tidak ada yang cocok dengan input yg diberikan,maka tampilkan :
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

void Pesantiket() {
    system("cls");
    if (Jumlahkereta == 0) {
        cout << "Belum ada data kereta.\n";
        return;
    }
    Tiket t;
    cin.ignore(10000, '\n');
    cout << "Nama Penumpang : ";
    getline(cin, t.namapenumpang);
    if (t.namapenumpang == "") {
        cout << "Nama tidak boleh kosong!\n";
        return;
    }
    header("Daftar jadwal:\n");
    readjadwal(daftarKereta, Jumlahkereta);
    int no;
    cout << "Pilih Nomor KA : ";
    while (!(cin >> no)) {
        cin.clear();
        cin.ignore(10000, '\n');
        cout << "Input salah! Masukkan angka: ";
    }
    Kereta k;
    if (!ambilKereta(daftarKereta, Jumlahkereta, no, &k)) {
        cout << "Nomor KA tidak ditemukan.\n";
        return;
    }
    t.noKA = k.noKA;
    t.kereta = k.namaKereta;
    t.asal = k.asal;
    t.tujuan = k.tujuan;
    t.jam = k.jamBerangkat;
    t.harga = k.hargatiket;
    t.next = NULL;

    enqueue(t);
}

void Prosestiket() {
    system("cls");
    if (isEmptyQueue()) {
        cout << "Queue underflow! Antrian kosong!\n";
        return;
    }
    if (isFullStack()) { // selalu false (linked list)
        cout << "Stack overflow! Riwayat penuh!\n";
        return;
    }
    Tiket t = dequeue();
    if (t.noKA != -1) {
        push(t);
        cout << ">> Transaksi masuk riwayat.\n";
    }
}

void lihatPeek() {
    system("cls");
    cout << "=======================\n";
    cout << "|  Tampil (peek) |\n";
    cout << "=======================\n";
    peekQueue();
    peekStack();
}

void lihatAntrian() {
    system("cls");
    cout << "=======================\n";
    cout << "|     TAMPIL ANTRIAN  |\n";
    cout << "=======================\n";
    tampilQueue();
}

void lihatRiwayat() {
    system("cls");
    cout << "=======================\n";
    cout << "|    TAMPIL RIWAYAT   |\n";
    cout << "=======================\n";
    tampilStack();
}

void hapuspopakhir() {
    system("cls");
    pop();
}

int main() {
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
        cout << "===============================================================" <<endl;
        cout << "|           STACKT & QUEUE TIKET KERETA API                   |" << endl;
        cout << "===============================================================" << endl;
        cout << "|7. Pesan Tiket (Enqueue)                                     |" << endl;
        cout << "|8. Proses Tiket (Dequeue + Push)                             |" << endl;
        cout << "|9. Lihat(Peek Antrian & Transaksi)                           |" << endl;
        cout << "|10. Tampil Antrian                                           |" << endl;
        cout << "|11. Tampil Riwayat                                           |" << endl;
        cout << "|12. Hapus Transaksi Terakhir (Pop)                           |" << endl;
        cout << "|13. Keluar                                                   |" << endl;
        cout << "===============================================================" << endl;
        cout << "Pilih menu: "; cin >> pilihan;

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
                cout << "Masukkan Nomor Kereta Api(KA) yang dicari: ";
                while(!(cin >> cari)) {
                    cin.clear();
                    cin.ignore(10000, '\n');
                    cout << "Input salah! Masukkan angka: ";
                }
                sortNomor(daftarKereta, Jumlahkereta);
                int hasil = jumpSearch(daftarKereta, Jumlahkereta, cari);
                if (hasil != -1) {
                    cout << "Nomor kereta(KA) ditemukan:\n";
                    tukarkereta(daftarKereta, daftarKereta + hasil);
                    readjadwal(daftarKereta + hasil, 1);
                    system("pause");
                    system("cls");
                } else {
                    cout << "=======================================\n";
                    cout << "|Nomor kereta Api(KA) tidak ditemukan.|\n";
                    cout << "======================================="<<endl;
                    system("pause");
                    system("cls");
                }
                break;
            }
            case 5:
                system("cls");
                if (Jumlahkereta == 0) {
                    cout << "Belum ada data kereta." << endl;
                    break;
                }
                cout << "Data sebelum diurutkan (berdasarkan nama Kereta)" << endl;
                readjadwal(daftarKereta, Jumlahkereta);
                mergeSort(daftarKereta, 0, Jumlahkereta - 1);
                cout << "Data berhasil diurutkan berdasarkan Nama Kereta!" << endl;
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
                   Pesantiket();
                   system("pause");
                   system("cls");
            break;
            case 8:
                   Prosestiket();
                   system("pause");
                   system("cls");
            break;
            case 9:
                lihatPeek();
                system("pause");
                system("cls");
            break;
            case 10:
                lihatAntrian();
                system("pause");
                system("cls");
            break;
            case 11:
                lihatRiwayat();
                system("pause");
                system("cls");
            break;
            case 12:
                hapuspopakhir();
                system("pause");
                system("cls");
            break;
            case 13:
                system("cls");
                cout << "==================================\n";
                cout << "|         Terima kasih!          |\n";
                cout << "| Telah Menggunakan Layanan Kami |\n";
                cout << "|          Sampai Jumpa!         |\n";
                cout << "=================================="<<endl;
            break;
            default:
                cout << "Pilihan tidak valid!" << endl;
                system("pause");
                system("cls");
        }
    } while (pilihan != 13);

    return 0;
}