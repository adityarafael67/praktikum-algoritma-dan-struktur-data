# <h1 align="center">Laporan Praktikum Modul 3 Abstract Data Type (ADT)</h1>
<p align="center">Rafael Aditya Nugroho</p>

## Dasar Teori

ADT(Abstract Data Type) adalah model matematika yang mendefinisikan sekumpulan operasi dan perilaku untuk suatu struktur data tanpa menentukan bagaimana operasi tersebut diimplementasikan.Jika dalam bahasa C
menggunakan struct PRIMITIF, dalam konteks prosedural, dibuat menjadi fungsi atau
prosedur. 

## Guided 

### 1. [mahasiswa.h]

```C++
//array
#ifndef MAHASISWA_H_INCLUDED
#define MAHASISWA_H_INCLUDED

struct mahasiswa{
    char nim[10];
    int nilai1, nilai2;
};

void inputmhs(mahasiswa &m);
float rata2(mahasiswa m);
#endif

```
program membuat struct mahasiswa yang terdiri dari char nim dan nilai1 dan nilai2.
### 2. [mahasiswa.cpp]

```C++
#include <iostream>
using namespace std;
#include "mahasiswa.h"

void inputmhs(mahasiswa &m) {
    cout << "input nama = ";
    cin >> (m).nim;
    cout << "input nilai1 = ";
    cin >> (m).nilai1;
    cout << "input nilai2 = ";
    cin >> (m).nilai2;

}

float rata2(mahasiswa m) {
    return (m.nilai1 + m.nilai2) /2.0;
}
```
program untuk menyimpan void yang berfungsi untuk menampilkan input nama, nilai1, dan nilai2,menghitung rata rata dari nilai1 dan nilai2 kemudian di bagi 2.0.

### 3. [main.cpp]

```C++
#include <iostream>
#include "mahasiswa.h"
using namespace std;

int main() {
    mahasiswa mhs;
    inputmhs(mhs);
    cout << "rata-rata = " << rata2(mhs);
    return 0;
}

```
program file utama untuk menjalankan dan menyatukan semua program yang sudah di buat di atas.
.

## Unguided 

### 1. [Nilai Mahasiswa]

```C++
#include <iostream>
using namespace std;

struct Mahasiswa {
    string nama;
    string nim;
    float uts, uas, tugas, nilaiAkhir;
};

float hitung(float uts, float uas, float tugas) {
    return 0.3 * uts + 0.4 * uas + 0.3 * tugas;
}

int main() {
    Mahasiswa mhs[10];
    int n;

    cout << "Jumlah mahasiswa : ";
    cin >> n;

    for (int i = 0; i < n; i++) {
        cout << "\nData mahasiswa ke-" << i + 1 << endl;
        cout << "Nama: ";
        cin >> mhs[i].nama;
        cout << "NIM : ";
        cin >> mhs[i].nim;
        cout << "Nilai UTS   : ";
        cin >> mhs[i].uts;
        cout << "Nilai UAS   : ";
        cin >> mhs[i].uas;
        cout << "Nilai Tugas : ";
        cin >> mhs[i].tugas;

        mhs[i].nilaiAkhir = hitung(mhs[i].uts, mhs[i].uas, mhs[i].tugas);
    }

    cout << "\n--- Data Mahasiswa ---\n";
    for (int i = 0; i < n; i++) {
        cout << "Nama: " << mhs[i].nama << endl;
        cout << "NIM : " << mhs[i].nim << endl;
        cout << "Nilai Akhir: " << mhs[i].nilaiAkhir << endl;
        cout << "---------------------------\n";

    }

    return 0;
}

```
#### Output:
![alt text](https://github.com/adityarafael67/praktikum-algoritma-dan-struktur-data/blob/main/Asset/Screenshot%202025-12-30%20035332.png?raw=true)

Program ini menyimpan data mahasiswa berisi nama, nim, nilai uts, uas, tugas dan nilai akhir, nilai akhir akan di hitung menggunakan rumus,penggunaan array of struct, input/output dan fungsi perhitungan sederhana untuk menghitung nilai akhir mahasiswa.

#### Full code Screenshot:
![alt text](https://github.com/adityarafael67/praktikum-algoritma-dan-struktur-data/blob/main/Asset/Screenshot%202025-12-30%20035344.png?raw=true)


### 2. [Nama Mata Kuliah]

```C++
//pelajaran.h
#ifndef PELAJARAN_H_INCLUDED
#define PELAJARAN_H_INCLUDED

#include <string>
using namespace std;

struct Pelajaran {
    string namaMapel;
    string kodeMapel;
};

Pelajaran create_pelajaran(string nama, string kode);
void tampil_pelajaran(Pelajaran pel);

#endif
```
deklarasi struct dan fungsi untuk menyimpan data nama pelajaran.
```C++
//pelajaran.cpp
#include <iostream>
#include "pelajaran.h"
using namespace std;

Pelajaran create_pelajaran(string nama, string kode) {
    Pelajaran p;
    p.namaMapel = nama;
    p.kodeMapel = kode;
    return p;
}

void tampil_pelajaran(Pelajaran pel) {
    cout << "Nama pelajaran : " << pel.namaMapel << endl;
    cout << "Nilai          : " << pel.kodeMapel << endl;
}D
```
implementasi fungsi yang ada di header.
```C++
//main.cpp
#include <iostream>
#include "pelajaran.h"
using namespace std;

int main() {
    string namaPel = "Struktur Data";
    string kodePel = "STD";

    Pelajaran pel = create_pelajaran(namaPel, kodePel);

    tampil_pelajaran(pel);

    return 0;
}
```
file utama untuk menjalankan program.

#### Output:
![alt text](https://github.com/adityarafael67/praktikum-algoritma-dan-struktur-data/blob/main/Asset/Screenshot%202025-12-30%20041824.png?raw=true)


Program ini menggunakan ADT (Abstract Data Type) untuk menyimpan dan menampilkan data pelajaran. Struct Pelajaran berisi nama dan kode mapel, lalu ada fungsi create_pelajaran untuk membuat data baru dan tampil_pelajaran untuk menampilkannya. Program ini menunjukkan cara memisahkan data dan fungsinya agar kode lebih rapi dan terstruktur.

#### Full code Screenshot:
![alt text](https://github.com/adityarafael67/praktikum-algoritma-dan-struktur-data/blob/main/Asset/Screenshot%202025-12-30%20041858.png?raw=true)
![alt text](https://github.com/adityarafael67/praktikum-algoritma-dan-struktur-data/blob/main/Asset/Screenshot%202025-12-30%20041909.png?raw=true)
![alt text](https://github.com/adityarafael67/praktikum-algoritma-dan-struktur-data/blob/main/Asset/Screenshot%202025-12-30%20041918.png?raw=true)


### 3. [Tukar array 2D]

```C++
#include <iostream>
using namespace std;

void tampilArray(int arr[3][3]) {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            cout << arr[i][j] << "\t";
        }
        cout << endl;
    }
}

void tukarPosisi(int arr1[3][3], int arr2[3][3], int baris, int kolom) {
    int temp = arr1[baris][kolom];
    arr1[baris][kolom] = arr2[baris][kolom];
    arr2[baris][kolom] = temp;
}

void tukarPointer(int* a, int* b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

int main() {
    int A[3][3] = {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9}
    };

    int B[3][3] = {
        {10, 11, 12},
        {13, 14, 15},
        {16, 17, 18}
    };

    cout << "Array A sebelum ditukar:\n";
    tampilArray(A);
    cout << "\nArray B sebelum ditukar:\n";
    tampilArray(B);

    tukarPosisi(A, B, 0, 0);

    cout << "\nSetelah tukar posisi (baris 1 kolom 1):\n";
    cout << "Array A:\n";
    tampilArray(A);
    cout << "\nArray B:\n";
    tampilArray(B);

    int x = 100, y = 200;
    int* px = &x;
    int* py = &y;

    cout << "\nSebelum tukar pointer: x = " << x << ", y = " << y << endl;
    tukarPointer(px, py);
    cout << "Setelah tukar pointer: x = " << x << ", y = " << y << endl;

    return 0;
}
```
#### Output:
![alt text](https://github.com/adityarafael67/praktikum-algoritma-dan-struktur-data/blob/main/Asset/Screenshot%202025-12-30%20042427.png?raw=true)

Program menukar nilai antar elemen array 2 dimensi dan antar variabel menggunakan pointer. Program ini menunjukkan penggunaan array, fungsi, dan pointer. 

#### Full code Screenshot:
![alt text](https://github.com/adityarafael67/praktikum-algoritma-dan-struktur-data/blob/main/Asset/Screenshot%202025-12-30%20042438.png?raw=true)



## Kesimpulan
Dari praktikum minggu ketiga ini, pandangan saya jadi berubah setelah mengerti Abstract Data Type (ADT). Konsep ini ternyata sangat membantu membuat program terlihat clean dan tidak membingungkan. Teknik memecah data dan fungsi ke dalam file terpisah membuat program lebih jelas. Saya jadi paham bahwa cara ini sangat efektif untuk mengelola kode.

## Referensi
[1] I. Holm, Narrator, and J. Fullerton-Smith, Producer, How to Build a Human [DVD]. London: BBC; 2002.
