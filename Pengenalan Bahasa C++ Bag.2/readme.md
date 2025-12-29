# <h1 align="center">Laporan Praktikum Modul 2 Pengenalan Bahasa C++ Bag.2</h1>
<p align="center">Rafael Aditya Nugroho</p>

## Dasar Teori

Bahasa pemrograman C++, merupakan bahasa yang memerlukkan code khusus untuk memamnggil suatu character agar bisa di compile dan bisa di baca oleh komputer seperti #include <iostream> digunakan untuk mendeklarasikan library yang akan digunakan dalam program.

Modul ini mempelajari array satu dimensi, dua dimensi, tiga dimensi, function (void), prosedur, serta pointer dsn refrence sebagai cara untuk mengelola data di dalam memori. 

## Guided 

### 1. [array]

```C++
//array
#include <iostream>
using namespace std;

int main() {
    //---Array 1Dimensi ---
    int arr1D[5] = {10,20,30,40,50};
    cout << "Array 1 Dimensi: " << endl;
    for (int i = 0; i < 5; i++) {
        cout << "arr1D[" << i << "] = " << arr1D[i] << endl;
    }
    cout << endl;

    //---Array 2 Dimensi (baris x kolom)
    int arr2D[2] [3] = {
        {1,2,3},
        {4,5,6}
    };
    cout << "Array 2 Dimensi: " << endl;
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 3; j++) {
            cout << "arr2D[" << i << "] [" << j << "] = " << arr2D[i][j]
            << " ";
        }
        cout << endl;
    }
    cout << endl;

    //---Array Multi Dimensi (3D)---
    int arr3D[2][2][3] = {
        { {1,2,3}, {4,5,6} },
        { {7,8,9}, {10,11,12} }
    };
    cout << "Array 3 Dimensi: " << endl;
    for (int i =0; i < 2; i++) {
        for (int j =0; j < 2; j++) {
            for (int k =0; k < 3; k++) {
                cout << "arr3D[" << i << "] [" << j <<"] ["
                << k << "] = " << arr3D[i][j][k] << endl;
            }
        }
    }
    return 0;
}
```
dalam program ini menunjukkan penggunaan array 1 dimensi, 2 dimensi dan 3 dimensi pada program C++, array 1 dimensi berfungsi untuk menyimpan data dalam baris, 2 dimensi menyimpan data array dalam bentuk baris dan kolom, dan 3 dimensi digunakan untuk data yang memiliki lebih dari dua lapisan baris dan kolom.

### 2. [Produser]

```C++
//Prosedur
#include <iostream>
using namespace std;

void tulis (int x) {
    for (int i = 0; i < x; i++) {
        cout << "Baris ke-: " << i+1 << endl;
    }
}

int main() {
    int jum;
    cout << "Jumlah Baris Kata: ";
    cin >> jum;
    tulis(jum);
    return 0;
}
```
program ini menggunakan prosedur tulis() untuk menampilkan sejumlah baris text yang dimasukkan pengguna. nilai input di disimpan pada variable jum, lalu dikirim ke prosedur untuk menampilkan perulangan for.

### 3. [Pointer]

```C++
//Pointer
#include <iostream>
using namespace std;

void tukar(int *x, int *y) {
    int temp;
    temp = *x;
    *x = *y;
    *y = temp;
} 

int main() {
    int a =20, b =30;
    int *ptr;

    ptr = &a;

    cout << "Value of a: " << a << endl;
    cout << "Address of a: " << &a << endl;
    cout << "Value stored in ptr (Address of a): " << ptr << endl;
    cout << "Value pointes to by ptr: " << *ptr << endl;

    tukar(&a, &b);
    cout << "After swapping, value of a = " << a << " and b = " << b << endl;

    return 0;
    
}
```
program ini menggunakan pointer untuk menukar dua nilai variable, pointer menyimpan alamat dari variable a sehingga nilai a bisa di akses oleh *ptr. fungsi tukar() untuk menukar nilai a dan b.

### 4. [Refrence]

```C++
//refrence
#include <iostream>
using namespace std;

void tukar(int &x, int &y) {
    int temp;
    temp = x;
    x = y;
    y = temp;
} 

int main() {
    int a =20, b =30;
    int& ref = a;

    cout << "Nilai a: " << a << endl;
    cout << "Alamat a (&a): " << &a << endl;
    cout << "Nilai ref (alias a): " << ref << endl;
    cout << "Alamat ref (&ref): " << &ref << endl;

    // mengubah nilai a lewat refrence
    ref = 50;
    cout << "\nSetelah ref = 50:" << endl;
    cout << "Nilai a: " << a << endl;
    cout << "Nilai ref: " << ref << endl;

    tukar(a, b);
    cout << "After swapping, value of a = " << a << " and b = " << b << endl;

    return 0;
    
}
```
Program ini menggunakan reference untuk menukar nilai dua variabel. Reference (ref) berfungsi sebagai alias dari variabel a. Fungsi tukar() menukar nilai a dan b tanpa menggunakan pointer.

## Unguided 

### 1. [Matrix 3x3]

```C++
#include <iostream>
using namespace std;

int main() {
    int A[3][3], B[3][3],
    C[3][3];

    cout << "Matrix A:\n";
    for (int i =0; i < 3; i++){
        for (int j=0; j < 3; j++){
            cin >> A[i][j];
        }
    }

    cout << "Matrix B:\n";
    for (int i =0; i < 3; i++){
        for (int j =0; j < 3; j++){
            cin >> B[i][j];
        }
    }
        cout << "\nHasil Penjumlahan:\n";
        for (int i =0; i < 3; i++){
            for (int j =0; j < 3; j++){
                cout << A[i][j] + B[i][j] << "\t";
            }
            cout << endl;
        } 

        cout << "\nHasil Pengurangan:\n";
        for (int i=0; i < 3; i++) {
            for (int j =0; j < 3; j++) {
                cout << A[i][j] - B[i][j] << "\t";
            }
            cout << endl;
        }

        cout << "\nHasil Perkalian:\n";
        for (int i=0; i < 3; i++) {
            for (int j=0; j < 3; j++) {
                C[i][j] = 0;
                for (int k=0; k < 3; k++)
                C[i][j] += A[i][k] * B[k][j];
                cout << C[i][j] << "\t";
            }
            cout << endl;
        }

    return 0;
}
```
#### Output:
![alt text](https://github.com/adityarafael67/praktikum-algoritma-dan-struktur-data/blob/main/Asset/Screenshot%202025-12-30%20030924.png?raw=true)

Program ini berfungsi sebagai operasi dasar penjumlahan, pengurangan dan perkalian terhadap 2 buah matrix dengan ukuran 3x3, output nya bentuk matrix 3x3.

#### Full code Screenshot:
![alt text](https://github.com/adityarafael67/praktikum-algoritma-dan-struktur-data/blob/main/Asset/Screenshot%202025-12-30%20030944.png?raw=true)


### 2. [Menukar nilai variable]

```C++
#include <iostream>
using namespace std;

//Pakai Pointer
void Pointer(int *x, int *y, int *z) {
    int temp = *x;
    *x = *y;
    *y = *z;
    *z = temp;
}
//Pakai Refrence
void Refrence(int &x, int &y, int &z) {
    int temp = x;
    x = y;
    y = z;
    z = temp;
}
int main() {
    int a,b,c;

    cout << "TUKAR NILAI" << endl;
    cout << "Masukkan Nilai a = ";
    cin >> a;
    cout << "Masukkan Nilai b = ";
    cin >> b;
    cout << "Masukkan Nilai c = ";
    cin >> c;

    cout << "\nNILAI AWAL" << endl;
    cout << "a = " << a << ", b = " << b << ", c = " << c << endl;

    // Tukar Pakai Pointer
    Pointer(&a, &b, &c);
    cout << "\nPakai Pointer" << endl;
    cout << "a = " << a << ", b = " << b << ", c = " << c << endl;

    // Tukar Pakai Refrence
    Refrence(a, b, c);
    cout << "\nPakai Pointer" << endl;
    cout << "a = " << a << ", b = " << b << ", c = " << c << endl;

    return 0;

}
```
#### Output:
![alt text](https://github.com/adityarafael67/praktikum-algoritma-dan-struktur-data/blob/main/Asset/Screenshot%202025-12-30%20031546.png?raw=true)

program berfungsi untuk menukar 3 nilai variable menggunakan 2 cara yaitu pointer dan refrence,  program akan menjalankan void pertama pertukaran nilai menggunakan pointer kemudian dilanjutkan melakukakan petukaran menggunakan fungsi refrence, output adalah hasil dari proses pertukaran 3 variable.

#### Full code Screenshot:
![alt text](https://github.com/adityarafael67/praktikum-algoritma-dan-struktur-data/blob/main/Asset/Screenshot%202025-12-30%20031613.png?raw=true)


### 3. [array 1 dimensi]

```C++
#include <iostream>
using namespace std;

//cari nilai min
int Minimum(int arr[], int n) {
    int min = arr[0];
    for (int i = 1; i < n; i++) {
        if (arr[i] < min)
            min = arr[i];
    }
    return min;
}

//cari niai max
int Maximum(int arr[], int n) {
    int max = arr[0];
    for (int i = 1; i < n; i++) {
        if (arr[i] > max)
            max = arr[i];
    }
    return max;
}

//cari nilai rata rata
void Ratarata(int arr[], int n) {
    float total = 0;
    for (int i = 0; i < n; i++) {
        total += arr[i];
    }
    float rata = total / n;
    cout << "Nilai rata-rata = " << rata << endl;
}


int main() {
    int arrA[] = {1,2,3,4,5,6,7,8,9,10};
    int n = 10;
    int pilih;

    do {
        cout << "\n---Menu---\n" << endl;
        cout << "1.Tampilkan Array" << endl;
        cout << "2.Cari Nilai Maximum" << endl;
        cout << "3.Cari Nilai Minimum" << endl;
        cout << "4.Cari Nilai Rata-Rata" << endl;
        cout << "5.Keluar\n" << endl;
        cout << "Pilih menu (1-5):";
        cin >> pilih;

        switch (pilih) {
             case 1:
                cout << "Masukan array: ";
                for (int i = 0; i < n; i++)
                    cout << arrA[i] << " ";
                cout << endl;
                break;
            case 2:
                cout << "Nilai maksimum = " << Maximum(arrA, n) << endl;
                break;
            case 3:
                cout << "Nilai minimum = " << Minimum(arrA, n) << endl;
                break;
            case 4:
                Ratarata(arrA, n);
                break;
            case 5:
                cout << "Program selesai\n";
                break;
            default:
                cout << "Tidak ada yang sesuai\n";
        }
    } while (pilih !=5);
    return 0;
}
     

```
#### Output:
![alt text](https://github.com/adityarafael67/praktikum-algoritma-dan-struktur-data/blob/main/Asset/Screenshot%202025-12-30%20024643.png?raw=true)

Program data array 1 dimensi untuk mencari nilai max, min dan nilai rata-rata.

#### Full code Screenshot:
![alt text](https://github.com/adityarafael67/praktikum-algoritma-dan-struktur-data/blob/main/Asset/Screenshot%202025-12-30%20025148.png?raw=true)
![alt text](https://github.com/adityarafael67/praktikum-algoritma-dan-struktur-data/blob/main/Asset/Screenshot%202025-12-30%20025252.png?raw=true)



## Kesimpulan
Dapat memahami bagaimana cara membuat fungsi terpisah di C++, mempelajari pointer dan refrence kita jadi bisa paham bagaimana cara memori bekerja.

## Referensi
[1] I. Holm, Narrator, and J. Fullerton-Smith, Producer, How to Build a Human [DVD]. London: BBC; 2002.
