# <h1 align="center">Laporan Praktikum Modul Pengenalan Bahasa C++ (1)</h1>
<p align="center">Rafael Aditya Nugroho</p>

## Dasar Teori

Bahasa Pemograman C++ adalah bahasa yang kodenya harus dikompilasi dahulu agar bisa dijalankan oleh komputer.Perintah #include digunakan untuk menyertakan header file dari sebuah library yang akan digunakan program.C++ banyak digunakan karena performanya yang sangat cepat dan fleksibel.

## CODE Guided 

### 1. [Cetak Teks:Hello World!]

```C++
#include <iostream>
using namespace std;

int main() {
cout << "Hello, World!" << std::endl;
return 0;
}
```
Program ini dibuat menggunakan bahasa pemrograman C++,program akan menghasilkan output "Hello World",sesuai dengan apa yang diketikan didalam program.
### 2. [Input-Output]

```C++
#include <iostream>
using namespace std;

int main(){
    int n;
    const float pi = 3.14;

    cout << "Masukan Angka:";
    cin >> n ;

    cout << "Angka Dikeluarkan:" << n << endl;
    cout << "Nilai Konstanta Pi:" << pi << endl;
    return 0;
}
```
Program input-output ini membuat user dapat menginputkan variable bertipe int dengan const 3,14(Nilai phi),cout di gunakan untuk input dan cin sebagai output program.

### 3. [Operator Dasar]

```C++
#include <iostream>
using namespace std;

int main(){
    int a;
    int b;

    cout << "Masukan Angka:" ;
    cin >> a;
    cout << "Masukan Angka:" ;
    cin >> b;

    //oprater aritmatika
    cout << "a+b=" << (a+b) << endl;
    cout << "a-b=" << (a-b) << endl;
    cout << "a*b=" << (a*b) << endl;
    cout << "a/b=" << (a/b) << endl;
    cout << "a%b=" << (a%b) << endl;

    //operator logika
    cout << "a>b=" << (a>b) << endl;
    cout << "a<b=" << (a<b) << endl;
    cout << "a>>b=" << (a>>b) << endl;
    cout << "a<<b=" << (a<<b) << endl;
    cout << "a==b=" << (a==b) << endl;
    cout << "a!=b" << (a!=b) << endl;
}
```
Program ini menampilkan bagaimana operasi dasar dan oprasi logika yang dapat dijalankan didalam sebuah program,(+-*/%)merupakan sistem operasi dasar.

### 4. [Percabangan]

```C++
#include <iostream>
using namespace std;

int main(){
    int angka1 = 10;
    int angka2 = 20;

    if (angka1 > angka2) {
        cout << "Angka 1 lebih besar dari Angka 2" << endl;
    }else if (angka1 < angka2) {
        cout << "Angka 1 lebih kecil dari Angka 2" << endl;
    }else {
        cout << "Angka 1 sama dengan Angka 2" << endl;
    }
    return 0;
}
```
Program yang menggunakan if-else untuk melakukan sebuah operasi,untuk menentukkan output yang sesuai dengan inputan dari pengguna.

### 5. [Perulangan]

```C++
#include <iostream>
using namespace std;

int main() {
    int i;
    int j;

    for (int i = 0; i <= 10;i++) {
        cout << i << " ";
    }
    cout << endl;

    for (int j = 20;j >=10;j--){
        cout << j << " ";
    }
    return 0;
}
```
Program ini melakukkan perulangan menggunakan for untuk inputannya.

### 6. [Perulangan While-Do]

```C++
#include <iostream>
using namespace std;

int main(){
    int i = 0;
    int j = 20;

    while (i <= 10) {
        cout << i << " ";
        i++;
    }

    cout << endl;

    do {
        cout << j << "-";
        j++;
    } while (j <=10);

    return 0;
}
```
Merupakan program yang sama seperti sebelumnya,namun untuk perulangan While-Do akan terus berjalan jika kondisi nya terus benar dan akan berhenti jika false.

### 7. [Struct]

```C++
#include <iostream>
#include <string>
using namespace std;

struct mahasiswa{
    string nama;
    int umur;
};

int main(){
    int jumlah;

    cout << "Masukan Jumlah Mahasiswa:";
    cin >> jumlah;

    mahasiswa mhs[jumlah];

    //Input data menggunakan loop
    for (int i = 0;i < jumlah;i++){
        cout << "\nMahasiswaa Ke:" << i+1 << endl;
        cout << "Nama:";
        cin >> mhs[i].nama;
        cout << "Umur:";
        cin >> mhs[i].umur;
    }
    
    //Menampilkan Data
    cout << "\nDATA MAHASISWA\n";
    for (int i = 0;i < jumlah;i++){
        cout << "Mahasiswa Ke" << i+1 
        << "| Nama:" << mhs[i].nama
        << "| Umur:" << mhs[i].umur << endl;
    }
    return 0;
}
```
Program ini merupakan implementasi dari struct yang bisa memuat berbagai tipe variable yang nantinya bisa digunakan didalam program.
## CODE Unguided 

### 1. [Operasi Dasar]

```C++
#include <iostream>
using namespace std;

int main(){
     float a;
     float b;

     cout << "Masukan Angka:";
     cin >> a;
     cout << "Masukan Angka:";
     cin >> b;

     cout << "Hasil Pertambahan:" << (a+b) << endl;
     cout << "Hasil Pengurangan:" << (a-b) << endl;
     cout << "Hasil Perkalian:" << (a*b) << endl;
     cout << "Hasil Pembagian:" << (a/b) << endl;
}
```
#### Output Code:
![alt text](https://github.com/adityarafael67/praktikum-algoritma-dan-struktur-data/blob/main/Asset/Screenshot%202025-11-02%20162152.png?raw=true)

Kode tersebut berguna untuk membuat bilangan bertipe float bisa melakukkan operasi dasar berupa penjumlahan,pengurangan,perkalian dan pembagian,masukan 2 inputan bertipe float yang diminta oleh program,lalu program akan mengeksekusinya sesuai dengan operasi dasar yang ada,dan program akan mengeluarkan output hasil dari oprasi dasar tersebut.

#### Screenshot Full Code:
![alt text](https://github.com/adityarafael67/praktikum-algoritma-dan-struktur-data/blob/main/Asset/Screenshot%202025-11-02%20162945.png?raw=true)


### 2. [Mengubah Angka Menggunakan String]

```C++
#include <iostream>
using namespace std;

int main() {
    int n;
    cout << "";
    cin >> n;

    string satuan[] = {"Nol", "Satu", "Dua", "Tiga", "Empat", "Lima",
                       "Enam", "Tujuh", "Delapan", "Sembilan", "Sepuluh", "Sebelas"};

    string hasil;

    if (n < 12) {
        hasil = satuan[n];
    } else if (n < 20) {
        hasil = satuan[n - 10] + " belas";
    } else if (n < 100) {
        int puluh = n / 10;
        int sisa = n % 10;
        hasil = satuan[puluh] + " puluh";
        if (sisa != 0) hasil += " " + satuan[sisa];
    } else if (n == 100) {
        hasil = "seratus";
    } else {
        hasil = "Angka Melebihi Kapasitas ";
    }

    cout << n << " : " << hasil << endl;

    return 0;
}
```
#### Output:
![alt text](https://github.com/adityarafael67/praktikum-algoritma-dan-struktur-data/blob/main/Asset/Screenshot%202025-11-02%20173314.png?raw=true)


Kode tersebut berfungsi untuk mengubah angka yang bertipe integer menjadi string,program akan meminta input berupa int lalu program akan mengecek if-else,jika sesuai dengan aturan maka angka akan diubah,jika angka puluhan ataupu ratusam maka akan ada tambahan string yang sudah di siapkan di string satuan (buat string satuan []) dan jika angkanya melebihi kapasitas output yang keluar "Angka Melebihi Kapasitas".

#### Screenshot Full Code:
![alt text](https://github.com/adityarafael67/praktikum-algoritma-dan-struktur-data/blob/main/Asset/Screenshot%202025-11-02%20173325.png?raw=true)


### 3. [Segitiga Angka]

```C++
#include <iostream>
using namespace std;

int main() {
    int n;
    cout << "Inputkan Angka: ";
    if (!(cin >> n)) return 0;

    for (int i = n; i >= 0; i--) {
        // Spasi di depan
        for (int s = 0; s < n - i; s++) cout << "  ";

        // Angka menurun
        for (int a = i; a >= 1; a--) cout << a << " ";

        // Bintang di tengah
        cout << "* ";

        // Angka menaik
        for (int b = 1; b <= i; b++) cout << b << " ";

        cout << '\n';
    }

    return 0;
}

```
#### Output:
![alt text](https://github.com/adityarafael67/praktikum-algoritma-dan-struktur-data/blob/main/Asset/Screenshot%202025-11-02%20174323.png?raw=true)

Kode ini dapat meng-urutkan angka yang berbentuk segitiga sama sisi,pengguna dapat menginputkan variable bertipe int,lalu diperulangan akan menulis ulang angka yang di inputkan (terbesar ke terkecil) dengan di batasi tanda bintang,for memilki fungsi masing-masing untuk bisa membuat bentuk segitiga.

#### Screenshot Full Code:
![alt text](https://github.com/adityarafael67/praktikum-algoritma-dan-struktur-data/blob/main/Asset/Screenshot%202025-11-02%20174352.png?raw=true)


## Kesimpulan
Saya jadi dapat mengenal bahasa pemrograman C++ dengan lebih dalam,mengenal dasar pemrograman,structure program,running code,compile code,variable dan juga output-nya,yang memang sangat berbeda(lebih mudah) daripada menggunakan Golang.   

## Referensi
[1] I. Holm, Narrator, and J. Fullerton-Smith, Producer, How to Build a Human [DVD]. London: BBC; 2002.

Keluaran:
tangkapan layar

Tangkapan Layar Kode Lengkap:
tangkapan layar

Referensi
[1] I. Holm, Narator, dan J. Fullerton-Smith, Produser, Cara Membangun Manusia [DVD]. London: BBC; 2002.
