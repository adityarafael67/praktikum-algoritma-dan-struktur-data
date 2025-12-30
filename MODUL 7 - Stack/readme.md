# <h1 align="center">Laporan Praktikum Modul 7 Stack </h1>
<p align="center">Rafael Aditya Nugroho</p>

## Dasar Teori
Pengertian Stack adalah struktur data yang bekerja dengan dengan prinsip LIFO (Last in First Out), artinya elemen yang terakhir masuk akan menjadi yang pertama keluar. Dalam stack hanya ada satu pointer penting yaitu TOP yang menunjuk ke elemen paling atas, implementasi stack di modul ini menggunakan pointer seperti linked list, dengan node yang berisi info dan pointer next. Operasi utama pada stack adalah push untuk menambahkan elemen kebagian atas dan pop untuk mengambil sekaligus menghapus elemen paling atas. stack dianggap kosong jika TOP berniali NULL. 

## Guided

### 1. [Stack.h]

```C++
#ifndef STACK
#define STACK 
#define Nil nullptr

#include <iostream>
using namespace std;

typedef struct node *address;

struct node {
    int dataAngka;
    address next;
};

struct stack{
    address top;
};

bool isEmpty(stack listStack);
void createStack(stack &listStack);
address alokasi(int angka);
void dealokasi(address &node);

void push(stack &listStack, address nodeBaru);
void pop(stack &listStack);
void update(stack &listStack, int posisi);
void view(stack listStack);
void searchData(stack listStack, int data);
#endif
```
Program stack.h digunakan untuk membuat dan mengelola sebuah struktur data Stack. Stack adalah tempat penyimpanan data dengan sistem LIFO (Last In, First Out), artinya data yang terakhir dimasukkan akan menjadi data yang pertama diambil. di file ini berisi deklarasi struktur dan fungsi seperti membuat stack baru, mengecek apakah stack kosong, menambah data atau push, mengahpus data atau pop, mengubah data atau update, menampilkan isi stack dan mencari data tertentu.

### 2. [Stack.cpp]

```C++
#include "stack.h"
#include <iostream>

using namespace std;

bool isEmpty(stack listStack){
    if(listStack.top == Nil){
        return true;
    } else {
        return false;
    }
}

void createStack(stack &listStack){
    listStack.top = Nil;
}

address alokasi(int angka){
    address nodeBaru = new node;
    nodeBaru->dataAngka = angka;
    nodeBaru->next = Nil;
    return nodeBaru;
}

void dealokasi(address &node){
    node->next = Nil;
    delete node;
}

void push(stack &listStack, address nodeBaru){
    nodeBaru->next = listStack.top;
    listStack.top = nodeBaru;
    cout << "Node " << nodeBaru->dataAngka << " berhasil ditambahkan kedalam stack!" << endl;
}

void pop(stack &listStack){
    address nodeHapus;
    if(isEmpty(listStack) == true){
        cout << "Stack kosong!" << endl;
    } else {
        nodeHapus = listStack.top;
        listStack.top = listStack.top->next;
        nodeHapus->next = Nil;
        dealokasi(nodeHapus);
        cout << "node " <<  nodeHapus->dataAngka << " berhasil dihapus dari stack!" << endl;
    }
}

void update(stack &listStack, int posisi){
    if(isEmpty(listStack) == true){
        cout << "Stack kosong!" << endl;
    } else {
        if(posisi == 0){
            cout << "Posisi tidak valid!" << endl;
        } else {
            address nodeBantu = listStack.top;
            int count = 1;
            bool found = false;
            while(nodeBantu != Nil){
                if(count < posisi){
                    nodeBantu = nodeBantu->next;
                    count++;
                } else if(count == posisi){
                    cout << "Update node poisisi ke-" << posisi << endl;
                    cout << "Masukkan angka : ";
                    cin >> nodeBantu->dataAngka;
                    cout << "Data berhasil diupdate!" << endl;
                    cout << endl;
                    found = true;
                    break;
                }
            }
            if(found == false){
                cout << "Posisi " << posisi << " tidak valid!" << endl;
            }
        }
    }
}

void view(stack listStack){
    if(isEmpty(listStack) == true){
        cout << "List kosong!" << endl;
    } else {
        address nodeBantu = listStack.top;
        while(nodeBantu != Nil){
            cout << nodeBantu->dataAngka << " ";
            nodeBantu = nodeBantu->next;
        }
    }
    cout << endl;
}

void searchData(stack listStack, int data){
    if(isEmpty(listStack) == true){
        cout << "List kosong!" << endl;
    } else {
        address nodeBantu = listStack.top;
        int posisi = 1;
        bool found = false;
        cout << "Mencari data " << data << "..." << endl;
        while(nodeBantu != Nil){
            if(nodeBantu->dataAngka == data){
                cout << "Data " << data << " ditemukan pada posisi ke-" << posisi << endl;
                found = true;
                cout << endl;
                break;
            } else {
                posisi++;
                nodeBantu = nodeBantu->next;
            }
        }
        if(found == false){
            cout << "Data " << data << " tidak ditemukan didalam stack!" << endl;
            cout << endl;
        }
    }
}
```
Program ini adalah implementasi struktur data Stack dengan cara penyimpanan berantai (mirip daftar yang saling terhubung). Stack bekerja dengan aturan LIFO (Last In, First Out), artinya data yang terakhir masuk akan menjadi data pertama yang keluar.

### 3. [main.cpp]

```C++
#include "stack.h"
#include <iostream>

using namespace std;

int main(){
    stack listStack;
    address nodeA, nodeB, nodeC, nodeD, nodeE = Nil;
    createStack(listStack);

    nodeA = alokasi(1);
    nodeB = alokasi(2);
    nodeC = alokasi(3);
    nodeD = alokasi(4);
    nodeE = alokasi(5);

    push(listStack, nodeA);
    push(listStack, nodeB);
    push(listStack, nodeC);
    push(listStack, nodeD);
    push(listStack, nodeE);
    cout << endl;

    cout << "--- Stack setelah push ---" << endl;
    view(listStack);
    cout << endl;

    pop(listStack);
    pop(listStack);
    cout << endl;

    cout << "--- Stack setelah pop 2 kali ---" << endl;
    view(listStack);
    cout << endl;

    update(listStack, 2);
    update(listStack, 1);
    update(listStack, 4);
    cout << endl;

    cout << "--- Stack setelah update ---" << endl;
    view(listStack);
    cout << endl;

    searchData(listStack, 4);
    searchData(listStack, 9);
    return 0;
}
```
ini main program stack yang digunakan untuk mengelola data dalam sebuah Stack dengan melakukan operasi push, pop, update, view, dan search. Program akan menunjukkan bagaimana stack berubah setelah setiap operasi.

## Unguided 
### 1. [soalstack.h]

```C++
#ifndef SOALSTACK_H
#define SOALSTACK_H
#define MAX 20
#define NIL -1
#include <iostream>
using namespace std;

typedef int infotype;

struct Stack {
    infotype info[MAX];
    int top;
};

void createStack(Stack &S);
void push(Stack &S, infotype x);
infotype pop(Stack &S);
void printInfo(Stack S);
void balikStack(Stack &S);

// fungsi untuk nomor 2
void pushAscending(Stack &S, infotype x);

// fungsi untuk nomor 3
void getInputStream(Stack &S);

#endif
```
### 2. [soalstack.cpp]
```C++
#include "soalstack.h"

void createStack(Stack &S) {
    S.top = NIL;
}

void push(Stack &S, infotype x) {
    if (S.top == MAX - 1) return;
    S.top++;
    S.info[S.top] = x;
}

infotype pop(Stack &S) {
    if (S.top == NIL) return -999; 
    infotype x = S.info[S.top];
    S.top--;
    return x;
}

void printInfo(Stack S) {
    cout << "[TOP] ";
    for (int i = S.top; i >= 0; i--) {
        cout << S.info[i] << " ";
    }
    cout << endl;
}

void balikStack(Stack &S) {
    Stack temp;
    createStack(temp);

    while (S.top != NIL) {
        push(temp, pop(S));
    }

    S = temp;
}

void pushAscending(Stack &S, infotype x) {
    if (S.top == MAX - 1) return;

    Stack temp;
    createStack(temp);

    while (S.top != NIL && S.info[S.top] < x) {
        push(temp, pop(S));
    }

    push(S, x);

    while (temp.top != NIL) {
        push(S, pop(temp));
    }
}

void getInputStream(Stack &S) {
    char c;
    while (true) {
        c = cin.get();
        if (c == '\n') break;
        int x = c - '0';  
        if (x >= 0 && x <= 9) {
            push(S, x);
        }
    }
}
```
### 3. [main.cpp] soal 1

```C++
#include "soalstack.h"

int main() {
    cout << "Hello world!" << endl;

    Stack S;
    createStack(S);

    push(S, 3);
    push(S, 4);
    push(S, 8);
    push(S, 2);

    printInfo(S);

    cout << "balik stack" << endl;
    balikStack(S);
    printInfo(S);

    return 0;
}
```
### 4. [main.cpp] soal 2

```C++
#include "soalstack.h"

int main() {
    cout << "Hello world!" << endl;

    Stack S;
    createStack(S);

    pushAscending(S, 3);
    pushAscending(S, 4);
    pushAscending(S, 8);
    pushAscending(S, 2);
    pushAscending(S, 3);
    pushAscending(S, 9);

    printInfo(S);

    cout << "balik stack" << endl;
    balikStack(S);
    printInfo(S);

    return 0;
}
```
### 5. [main.cpp] soal 3

```C++
#include "soalstack.h"

int main() {
    cout << "Hello world!" << endl;

    Stack S;
    createStack(S);

    cout << "Masukkan input: ";
    getInputStream(S);

    printInfo(S);

    cout << "balik stack" << endl;
    balikStack(S);
    printInfo(S);

    return 0;
}
```

#### Output:
#### Soal nomor 1,2, dan 3:
![alt text](https://github.com/adityarafael67/praktikum-algoritma-dan-struktur-data/blob/main/Asset/Screenshot%202025-12-30%20140647.png?raw=true)

Program ini dibuat untuk mengimplementasikan struktur data stack menggunakan pendekatan pointer seperti pada linked list. Stack bekerja dengan prinsip LIFO (Last In First Out), sehingga data terakhir yang dimasukkan akan menjadi data pertama yang diambil.

#### Full code Screenshot:
![alt text](https://github.com/adityarafael67/praktikum-algoritma-dan-struktur-data/blob/main/Asset/Screenshot%202025-12-30%20140719.png?raw=true)
![alt text](https://github.com/adityarafael67/praktikum-algoritma-dan-struktur-data/blob/main/Asset/Screenshot%202025-12-30%20140731.png?raw=true)
![alt text](https://github.com/adityarafael67/praktikum-algoritma-dan-struktur-data/blob/main/Asset/Screenshot%202025-12-30%20140739.png?raw=true)
![alt text](https://github.com/adityarafael67/praktikum-algoritma-dan-struktur-data/blob/main/Asset/Screenshot%202025-12-30%20140746.png?raw=true)
![alt text](https://github.com/adityarafael67/praktikum-algoritma-dan-struktur-data/blob/main/Asset/Screenshot%202025-12-30%20140754.png?raw=true)


## Kesimpulan
Dari pembelajaran Modul 7, saya memahami cara kerja Stack yang menggunakan prinsip LIFO (Last In, First Out). Konsep ini mengajarkan data yang terakhir kita input justru adalah yang pertama kali akan diproses, saya jadi mengerti bagaimana Stack digunakan untuk mengatur keluar-masuknya data secara rapi dan bagaimana menerapkannya untuk menyelesaikan masalah pemrograman.



## Referensi
[1] I. Holm, Narrator, and J. Fullerton-Smith, Producer, How to Build a Human [DVD]. London: BBC; 2002.
