# <h1 align="center">Laporan Praktikum Modul 8 Queue </h1>
<p align="center">Rafael Aditya Nugroho</p>

## Dasar Teori
#### Queue

Queue adalah struktur data yang dapat diartikan seperti sebuah antrean.Jadi prinsip dasar dalam Queue adalah FIFO (First in
Fisrt out), proses yang pertama masuk akan diakses terlebih dahulu. Dalam pengimplementasian
struktur Queue dalam C dapat menggunakan tipe data array dan linked list.

## Guided 

### 1. [Queu.h]

```C++
#ifndef QUEUE_H
#define QUEUE_H

#include <iostream>
using namespace std;

const int MAX = 5;

struct Paket {
    string KodeResi;
    string NamaPengirim;
    int BeratBarang; 
    string Tujuan;
};

struct QueueEkspedisi {
    Paket dataPaket[MAX];
    int Head;
    int Tail;
};

bool isEmpty(QueueEkspedisi Q);
bool isFull(QueueEkspedisi Q);
void createQueue(QueueEkspedisi &Q);
void enQueue(QueueEkspedisi &Q);
void deQueue(QueueEkspedisi &Q);
void viewQueue(QueueEkspedisi Q);

int TotalBiayaPengiriman(QueueEkspedisi Q);

#endif
```
Program ini digunakan untuk mengelola antrean paket ekspedisi menggunakan struktur queue.

### 2. [Queu.cpp]

```C++
#include "queu.h"

bool isEmpty(QueueEkspedisi Q) {
    return (Q.Head == -1 && Q.Tail == -1);
}

bool isFull(QueueEkspedisi Q) {
    return (Q.Tail == MAX - 1);
}

void createQueue(QueueEkspedisi &Q) {
    Q.Head = -1;
    Q.Tail = -1;
}

void enQueue(QueueEkspedisi &Q) {
    if (isFull(Q)) {
        cout << "Queue penuh!\n";
        return;
    }

    Paket P;
    cout << "Masukkan Kode Resi     : "; cin >> P.KodeResi;
    cout << "Masukkan Nama Pengirim : "; cin >> P.NamaPengirim;
    cout << "Masukkan Berat Barang  : "; cin >> P.BeratBarang;
    cout << "Masukkan Tujuan        : "; cin >> P.Tujuan;

    if (isEmpty(Q)) {
        Q.Head = Q.Tail = 0;
    } else {
        Q.Tail++;
    }

    Q.dataPaket[Q.Tail] = P;
}

void deQueue(QueueEkspedisi &Q) {
    if (isEmpty(Q)) {
        cout << "Queue kosong!\n";
        return;
    }

    cout << "Menghapus paket dengan resi: " << Q.dataPaket[Q.Head].KodeResi << "\n";

    for (int i = Q.Head; i < Q.Tail; i++) {
        Q.dataPaket[i] = Q.dataPaket[i + 1];
    }

    Q.Tail--;

    if (Q.Tail < 0) {
        Q.Head = Q.Tail = -1;
    }
}

void viewQueue(QueueEkspedisi Q) {
    if (isEmpty(Q)) {
        cout << "Queue kosong!\n";
        return;
    }

    cout << "\n--- Daftar Paket dalam Antrian ---\n";
    for (int i = Q.Head; i <= Q.Tail; i++) {
        cout << "Posisi " << i + 1 << ":\n";
        cout << "  Kode Resi     : " << Q.dataPaket[i].KodeResi << endl;
        cout << "  Pengirim      : " << Q.dataPaket[i].NamaPengirim << endl;
        cout << "  Berat Barang  : " << Q.dataPaket[i].BeratBarang << " kg" << endl;
        cout << "  Tujuan        : " << Q.dataPaket[i].Tujuan << endl;
        cout << "-----------------------------------\n";
    }
}

int TotalBiayaPengiriman(QueueEkspedisi Q) {
    if (isEmpty(Q)) return 0;

    int total = 0;
    for (int i = Q.Head; i <= Q.Tail; i++) {
        total += Q.dataPaket[i].BeratBarang * 8250;
    }
    return total;
}
```
Program ini berfungsi untuk mengelola antrean paket ekspedisi menggunakan struktur queue berbasis array.

### 3. [main.cpp]

```C++
#include <iostream>
#include "queue.h"

using namespace std;

int main() {
    QueueEkspedisi Q;
    createQueue(Q);

    int pilihan;

    do {
        cout << "\n--- Meca Express ---\n";
        cout << "1. Input Data Paket\n";
        cout << "2. Hapus Data Paket\n";
        cout << "3. Tampilkan Queue/Antrian Paket\n";
        cout << "4. Hitung Total Biaya Pengiriman\n";
        cout << "5. Exit\n";
        cout << "Masukan pilihan anda : ";
        cin >> pilihan;

        switch (pilihan) {
        case 1:
            enQueue(Q);
            break;

        case 2:
            deQueue(Q);
            break;

        case 3:
            viewQueue(Q);
            break;

        case 4:
            cout << "Total Biaya Pengiriman: Rp. " 
                 << TotalBiayaPengiriman(Q) << endl;
            break;

        case 5:
            cout << "Keluar...\n";
            break;

        default:
            cout << "Pilihan tidak valid!\n";
        }

    } while (pilihan != 5);

    return 0;
}
```
Program main() ini digunakan sebagai menu interaktif untuk menjalankan sistem antrean ekspedisi Meca Express,program ini mensimulasikan sistem antrean layanan pengiriman paket menggunakan queue.

## Unguided 
### 1. [queue.h]

```C++
#ifndef QANTRI_H
#define QANTRI_H

#include <iostream>
using namespace std;

#define MAX 5
#define NIL -1

typedef int infotype;
struct queue {
    infotype info[MAX];
    int head;
    int tail;
};

void createQueue(queue &Q);
bool isEmptyQueue(queue Q);
bool isFullQueue(queue Q);
void enqueue(queue &Q, infotype x);
infotype dequeue(queue &Q);
void printInfo(queue Q);

#endif
```
### 2. [queue.cpp]
```C++
#include "queue.h"

void createqueue(queue &Q) {
    Q.head = NIL;
    Q.tail = NIL;
}

bool isEmptyqueue(queue Q) {
    return Q.head == NIL;
}

bool isFullqueue(queue Q) {
    return Q.tail == MAX - 1;
}

void enqueue(queue &Q, infotype x) {
    if (!isFullQueue(Q)) {
        if (isEmptyQueue(Q)) {
            Q.head = 0;
            Q.tail = 0;
        } else {
            Q.tail++;
        }
        Q.info[Q.tail] = x;
    }
}

infotype dequeue(queue &Q) {
    infotype x = Q.info[Q.head];

    if (Q.head == Q.tail) {
        Q.head = NIL;
        Q.tail = NIL;
    } else {
        Q.head++;
    }
    return x;
}

void printInfo(queue Q) {
    cout << Q.head << " - " << Q.tail << "   | ";

    if (isEmptyQueue(Q)) {
        cout << "empty queue";
    } else {
        for (int i = Q.head; i <= Q.tail; i++) {
            cout << Q.info[i] << "";
        }
    }
   cout << endl;
}
```
### 4. [queue2.cpp]

```C++
#include "queue.h"

void createQueue(queue &Q) {
    Q.head = -1;
    Q.tail = -1;
}

bool isEmptyQueue(queue Q) {
    return (Q.head == -1 && Q.tail == -1);
}

bool isFullQueue(queue Q) {
    return (Q.tail == 4);
}

void enqueue(queue &Q, infotype x) {
    if (!isFullQueue(Q)) {
        if (isEmptyQueue(Q)) {
            Q.head = 0;
            Q.tail = 0;
        } else {
            Q.tail++;
        }
        Q.info[Q.tail] = x;
    }
}

infotype dequeue(queue &Q) {
    infotype x = -1;
    if (!isEmptyQueue(Q)) {
        x = Q.info[Q.head];
        Q.head++;
        if (Q.head > Q.tail) {
            Q.head = -1;
            Q.tail = -1;
        }
    }
    return x;
}

void printInfo(queue Q) {
    cout << Q.head << " - " << Q.tail << " | ";
    if (isEmptyQueue(Q)) {
        cout << "empty queue";
    } else {
        for (int i = Q.head; i <= Q.tail; i++) {
            cout << Q.info[i] << " ";
        }
    }
    cout << endl;
}
```
### 5. [queue3.cpp]

```C++
#include "queue.h"

void createQueue(queue &Q) {
    Q.head = -1;
    Q.tail = -1;
}

bool isEmptyQueue(queue Q) {
    return (Q.head == -1);
}

bool isFullQueue(queue Q) {
    return ((Q.tail + 1) % 5 == Q.head);
}

void enqueue(queue &Q, infotype x) {
    if (!isFullQueue(Q)) {
        if (isEmptyQueue(Q)) {
            Q.head = 0;
            Q.tail = 0;
        } else {
            Q.tail = (Q.tail + 1) % 5;
        }
        Q.info[Q.tail] = x;
    }
}

infotype dequeue(queue &Q) {
    infotype x = -1;
    if (!isEmptyQueue(Q)) {
        x = Q.info[Q.head];
        if (Q.head == Q.tail) {
            Q.head = -1;
            Q.tail = -1;
        } else {
            Q.head = (Q.head + 1) % 5;
        }
    }
    return x;
}

void printInfo(queue Q) {
    cout << Q.head << " - " << Q.tail << " | ";
    if (isEmptyQueue(Q)) {
        cout << "empty queue";
    } else {
        int i = Q.head;
        while (true) {
            cout << Q.info[i] << " ";
            if (i == Q.tail) break;
            i = (i + 1) % 5;
        }
    }
    cout << endl;
}
```
### 3. [main.cpp]

```C++
#include "queue.h"

int main() {
    cout << "Hello world!" << endl;

    queue Q;
    createQueue(Q);

    cout << "------------------------" << endl;
    cout << "H - T \t| Queue Info" << endl;
    cout << "------------------------" << endl;

    printInfo(Q);

    enqueue(Q, 5);  printInfo(Q);
    enqueue(Q, 2);  printInfo(Q);
    enqueue(Q, 7);  printInfo(Q);
    dequeue(Q);     printInfo(Q);
    enqueue(Q, 4);  printInfo(Q);
    dequeue(Q);     printInfo(Q);
    dequeue(Q);     printInfo(Q);
    return 0;
}
```
#### Output:
#### Soal 1:
![alt text](https://github.com/adityarafael67/praktikum-algoritma-dan-struktur-data/blob/main/Asset/Screenshot%202025-12-30%20143948.png?raw=true)


Program ini dibuat untuk mengimplementasikan konsep ADT Queue (antrian) menggunakan array dalam bahasa C++. Program mensimulasikan proses antrian dengan operasi utama enqueue (menambah data) dan dequeue (menghapus data) sesuai prinsip FIFO (First In First Out).

#### Full code Screenshot:
![alt text](https://github.com/adityarafael67/praktikum-algoritma-dan-struktur-data/blob/main/Asset/Screenshot%202025-12-30%20144009.png?raw=true)
![alt text](https://github.com/adityarafael67/praktikum-algoritma-dan-struktur-data/blob/main/Asset/Screenshot%202025-12-30%20144026.png?raw=true)
![alt text](https://github.com/adityarafael67/praktikum-algoritma-dan-struktur-data/blob/main/Asset/Screenshot%202025-12-30%20144035.png?raw=true)
![alt text](https://github.com/adityarafael67/praktikum-algoritma-dan-struktur-data/blob/main/Asset/Screenshot%202025-12-30%20144046.png?raw=true)
![alt text](https://github.com/adityarafael67/praktikum-algoritma-dan-struktur-data/blob/main/Asset/Screenshot%202025-12-30%20144055.png?raw=true)

## Kesimpulan
Dari praktikum ini, saya memahami bahwa Queue sangat krusial untuk menangani proses antrean yang harus berjalan berurutan,perbedaan signifikan antara tipe Linear dan Circular.Circular Queue jauh lebih baik digunakan karena mengatasi kelemahan Queue biasa yang sering memboroskan tempat.

## Referensi
[1] I. Holm, Narrator, and J. Fullerton-Smith, Producer, How to Build a Human [DVD]. London: BBC; 2002.
