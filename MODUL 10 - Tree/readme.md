# <h1 align="center">Laporan Praktikum Modul 10 Tree </h1>
<p align="center">Rafael Aditya Nugroho</p>

## Dasar Teori
Pengertian Rekursi adalah suatu proses pengulangan yang dilakukan dengan cara kesamaan-diri, yaitu suatu prosedur atau fungsi yang memanggil dirinya sendiri secara langsung maupun tidak langsung. Dalam pemrograman, rekursif digunakan untuk menyelesaikan permasalahan dengan cara memecah masalah besar menjadi submasalah yang lebih kecil hingga mencapai kondisi dasar (base case).Dengan demikian, penggunaan rekursif dalam subprogram dapat membantu menghasilkan program yang lebih terstruktur, mudah dipahami, dan efisien dalam pengembangan maupun pemeliharaan.
## Guided

### 1. [bst.h]

```C++
#ifndef BST_H
#define BST_H

#define Nil NULL

// Struktur node BST
struct BST {
    int angka;
    BST *left;
    BST *right;
};

// Tipe data
typedef BST* node;
typedef BST* BinTree;

// Fungsi dasar
bool isEmpty(BinTree tree);
void createTree(BinTree &tree);

// Alokasi & dealokasi
node alokasi(int angkaInput);
void dealokasi(node nodeHapus);

// Operasi BST
void insertNode(BinTree &tree, node nodeBaru);
void searchByData(BinTree tree, int angkaCari);

// Traversal
void preOrder(BinTree tree);
void inOrder(BinTree tree);
void postOrder(BinTree tree);

// Delete
bool deleteNode(BinTree &tree, int angka);

// Utility
node mostRight(BinTree tree);
node mostLeft(BinTree tree);
void deleteTree(BinTree &tree);

// Informasi tree
int size(BinTree tree);
int height(BinTree tree);

#endif
```
Berisi deklarasi struktur node dan prototype fungsi BST yang digunakan sebagai penghubung antara main.cpp dan bst.cpp.

### 2. [bst.cpp]

```C++
#include "bst.h"
#include <iostream>

using namespace std;

//NOTE : parameter tree disini maksudnya merujuk ke node; baik itu node root atau node lain dari tree

bool isEmpty(BinTree tree){
    if(tree == Nil){
        return true;
    } else {
        return false;
    }
}

void createTree(BinTree &tree){
    tree = Nil;
}

node alokasi(int angkaInput){
    node nodeBaru = new BST;
    nodeBaru->angka = angkaInput;
    nodeBaru->left = Nil;
    nodeBaru->right = Nil;
    return nodeBaru;
}

void dealokasi(node nodeHapus){
    delete nodeHapus;
}

void insertNode(BinTree &tree, node nodeBaru){
    if(tree == Nil){
        tree = nodeBaru;
        cout << "Node " << nodeBaru->angka << " berhasil ditambahkan ke dalam tree!" << endl;
        return;
    } else if(nodeBaru->angka < tree->angka){
        insertNode(tree->left, nodeBaru);
    } else if(nodeBaru->angka > tree->angka){
        insertNode(tree->right, nodeBaru);
    }
}

void searchByData(BinTree tree, int angkaCari){
    if(isEmpty(tree) == true){
        cout << "Tree kosong!" << endl;
    } else {
        node nodeBantu = tree;
        node parent = Nil;
        bool ketemu = false;
        while(nodeBantu != Nil){
            if(angkaCari < nodeBantu->angka){
                parent = nodeBantu;
                nodeBantu = nodeBantu->left;
            } else if(angkaCari > nodeBantu->angka){
                parent = nodeBantu;
                nodeBantu = nodeBantu->right;
            } else if(angkaCari == nodeBantu->angka){
                ketemu = true;
                break;
            }
        }
        if(ketemu == false){
            cout << "Data tidak ditemukan" << endl;
        } else if(ketemu == true){
            cout << "Data ditemukan didalam tree!" << endl;
            cout << "Data Angka : " << nodeBantu->angka << endl;

            //menampilkan parentnya & pengecekan sibling
            node sibling = Nil;
            if(parent != Nil){
                cout << "Parent : " << parent->angka << endl;
                if(parent->left == nodeBantu){
                    sibling = parent->right;
                } else if(parent->right == nodeBantu){
                    sibling = parent->left;
                }
            } else {
                cout << "Parent : - (node root)"<< endl;
            }

            //menampilkan siblingnya
            if(sibling != Nil){
                cout << "Sibling : " << sibling->angka << endl;
            } else {
                cout << "Sibling : - " << endl;
            }

            //menampilkan childnya
            if(nodeBantu->left != Nil){
                cout << "Child kiri : " << nodeBantu->left->angka << endl;
            } else if(nodeBantu->left == Nil){
                cout << "Child kiri : -" << endl;
            }
            if(nodeBantu->right != Nil){
                cout << "Child kanan : " << nodeBantu->right->angka << endl;
            } else if(nodeBantu->right == Nil){
                cout << "Child kanan : -" << endl;
            }
        }
    }
}

void preOrder(BinTree tree){
    if(tree == Nil){
        return;
    }
    cout << tree->angka << " - ";
    preOrder(tree->left);
    preOrder(tree->right);
}

void inOrder(BinTree tree){
    if(tree == Nil){
        return;
    }
    inOrder(tree->left);
    cout << tree->angka << " - ";
    inOrder(tree->right);
}

void postOrder(BinTree tree){
    if(tree == Nil){
        return;
    }
    postOrder(tree->left);
    postOrder(tree->right);
    cout << tree->angka << " - ";
}



bool deleteNode(BinTree &tree, int angka) {
    if (tree == Nil) {
        return false; //data tidak ditemukan di subtree ini
    } else {
        if (angka < tree->angka) {
            return deleteNode(tree->left, angka);
        } else if (angka > tree->angka) {
            return deleteNode(tree->right, angka);
        } else {
            //jika node yang mau dihapus ditemukan
            //Case 1 : node yang mau dihapus adalah leaf
            if (tree->left == Nil && tree->right == Nil) {
                node tmp = tree;
                tree = Nil;
                dealokasi(tmp);
            }
            //Case 2 : node yang mau dihapus hanya punya right child
            else if (tree->left == Nil) {
                node tmp = tree;
                tree = tree->right;
                dealokasi(tmp);
            }
            //Case 3 : node yang mau dihapus hanya punya left child
            else if (tree->right == Nil) {
                node tmp = tree;
                tree = tree->left;
                dealokasi(tmp);
            }
            // Case 4 : jika node yang mau dihapus punya dua child, maka ambil mostleft dari subtree kanan untuk menggantikan node yang mau dihapus
            else {
                //mostleft dari subtree kanan = node successor (node penerus)
                node successor = mostLeft(tree->right);
                //salin data successor ke node saat ini
                tree->angka = successor->angka;
                //hapus successor pada subtree kanan
                return deleteNode(tree->right, successor->angka);
            }
            return true; //berhasil dihapus
        }
    }
}

node mostRight(BinTree tree){
    while (tree->right != Nil){
        tree = tree->right;
    }
    return tree;    
}

node mostLeft(BinTree tree){
    while (tree->left != Nil){
        tree = tree->left;
    }
    return tree;
}

void deleteTree(BinTree &tree){
    if(tree == Nil){
        return;
    } else {
        deleteTree(tree->left);
        deleteTree(tree->right);
        dealokasi(tree);
        tree = Nil;
    }
}

int size(BinTree tree){ //mengembalikan jumlah semua node
    if(isEmpty(tree) == true){
        return 0;
    } else {
        return 1 + size(tree->left) + size(tree->right);
    }
    cout << endl;
}

int height(BinTree
```
File implementasi yang berisi logika dan algoritma BST. Pada file ini didefinisikan seluruh fungsi BST, seperti pembuatan tree, penyisipan node secara rekursif, pencarian data, traversal (preorder, inorder, postorder), penghapusan node berdasarkan kasus (leaf, satu child, dua child), serta perhitungan ukuran dan tinggi tree.

### 3. [main.cpp]

```C++
#include <iostream>
#include "bst.h"

using namespace std;

int main() {
    BinTree tree;
    createTree(tree);

    int pilih, angka;

    do {
        cout << "========= MENU BST =========" << endl;
        cout << "1. Insert Node" << endl;
        cout << "2. Delete Node" << endl;
        cout << "3. Search Data" << endl;
        cout << "4. Tampilkan PreOrder" << endl;
        cout << "5. Tampilkan InOrder" << endl;
        cout << "6. Tampilkan PostOrder" << endl;
        cout << "7. Size Tree (jumlah node)" << endl;
        cout << "8. Height Tree (tinggi level)" << endl;
        cout << "9. Tampilkan mostright" << endl;
        cout << "10. Tampilkan mostleft" << endl;
        cout << "11. Delete Seluruh Tree" << endl;
        cout << "0. Keluar" << endl;
        cout << "pilihan anda : ";
        cin >> pilih;
        cout << endl;

        switch (pilih){
        case 1:
            cout << "Masukkan angka: ";
            cin >> angka;
            insertNode(tree, alokasi(angka));
            cout << endl;
            break;

        case 2:
            if(isEmpty(tree) == true){
                cout << "Tree kosong!" << endl;
            } else {
                cout << "Masukkan angka yang ingin dihapus: ";
                cin >> angka;
                if(deleteNode(tree, angka)){
                    cout << "Data " << angka << " berhasil dihapus!" << endl;
                } else {
                    cout << "Data " << angka << " tidak ditemukan!" << endl;
                }
            }
            cout << endl;
            break;

        case 3:
            if(isEmpty(tree) == true){
                cout << "Tree kosong!" << endl;
            } else {
                cout << "Masukkan angka yang ingin dicari: ";
                cin >> angka;
                searchByData(tree, angka);
            }
            cout << endl;
            break;

        case 4:
            if(isEmpty(tree) == true){
                cout << "Tree kosong!" << endl;
            } else {
                cout << "PreOrder : ";
                preOrder(tree);
                cout << endl;
            }
            cout << endl;
            break;

        case 5:
            if(isEmpty(tree) == true){
                cout << "Tree kosong!" << endl;
            } else {
                cout << "InOrder : ";
                inOrder(tree);
                cout << endl;
            }
            cout << endl;
            break;

        case 6:
            if(isEmpty(tree) == true){
                cout << "Tree kosong!" << endl;
            } else {
                cout << "PostOrder : ";
                postOrder(tree);
                cout << endl;
            }
            cout << endl;
            break;

        case 7:
            cout << "Size Tree = " << size(tree) << endl;
            cout << endl;
            break;

        case 8:
            cout << "Height Tree = " << height(tree) << endl;
            cout << endl;
            break;

        case 9: 
            if(isEmpty(tree) == true){
                cout << "Tree kosong!" << endl;
                cout << endl;
            } else {
                cout << "Mostright : " << mostRight(tree)->angka << endl;
                cout << endl;
            }
            break;
        
        case 10:
            if(isEmpty(tree) == true){
                cout << "Tree kosong!" << endl;
                cout << endl;
            } else {
                cout << "Mostleft : " << mostLeft(tree)->angka << endl;
                cout << endl;
            }
            break;

        case 11:
            if(isEmpty(tree) == true){
                cout << "Tree kosong!" << endl;
            } else {
                deleteTree(tree);
                cout << "Seluruh tree berhasil dihapus!" << endl;
            }
            cout << endl;
            break;

        case 0:
            cout << "Keluar dari program..." << endl;
            break;

        default:
            cout << "Pilihan tidak valid!" << endl;
            break;
        }

    } while (pilih != 0);

    return 0;
}
```
File ini berfungsi sebagai antarmuka pengguna untuk memanggil fungsi-fungsi BST yang didefinisikan di bst.cpp melalui bst.h. Pengguna dapat melakukan insert, delete, search, traversal, dan operasi lainnya melalui menu.

## Unguided 
### 1. [bstree.h]

```C++
#ifndef BSTREE_H
#define BSTREE_H
#define NIL NULL

#include <iostream>
using namespace std;

typedef int infotype;
typedef struct Node *address;

struct Node {
    infotype info;
    address left;
    address right;
};

// ADT BST
address alokasi(infotype x);
void insertNode(address &root, infotype x);
address findNode(address root, infotype x);
void InOrder(address root);

int hitungJumlahNode(address root);
int hitungTotalInfo(address root);
int hitungKedalaman(address root, int start);

#endif
```
### 2. [bstree.cpp]
```C++
#include "bstree.h"

// Alokasi node
address alokasi(infotype x) {
    address P = new Node;
    P->info = x;
    P->left = NIL;
    P->right = NIL;
    return P;
}

// Insert BST
void insertNode(address &root, infotype x) {
    if (root == NIL) {
        root = alokasi(x);
    } else if (x < root->info) {
        insertNode(root->left, x);
    } else if (x > root->info) {
        insertNode(root->right, x);
    }
}

// Cari node
address findNode(address root, infotype x) {
    if (root == NIL || root->info == x) {
        return root;
    } else if (x < root->info) {
        return findNode(root->left, x);
    } else {
        return findNode(root->right, x);
    }
}

// Traversal InOrder
void InOrder(address root) {
    if (root != NIL) {
        InOrder(root->left);
        cout << root->info << " - ";
        InOrder(root->right);
    }
}

// Hitung jumlah node
int hitungJumlahNode(address root) {
    if (root == NIL) {
        return 0;
    }
    return 1 + hitungJumlahNode(root->left) + hitungJumlahNode(root->right);
}

// Hitung total nilai info
int hitungTotalInfo(address root) {
    if (root == NIL) {
        return 0;
    }
    return root->info +
           hitungTotalInfo(root->left) +
           hitungTotalInfo(root->right);
}

// Hitung kedalaman maksimal tree
int hitungKedalaman(address root, int start) {
    if (root == NIL) {
        return start;
    }

    int kiri = hitungKedalaman(root->left, start + 1);
    int kanan = hitungKedalaman(root->right, start + 1);

    return (kiri > kanan) ? kiri : kanan;
}
```
### 3. [main.cpp]

```C++
#include <iostream>
#include "bstree.h"

using namespace std;

int main() {
    cout << "Hello World!" << endl;

    address root = NIL;

    insertNode(root, 1);
    insertNode(root, 2);
    insertNode(root, 6);
    insertNode(root, 4);
    insertNode(root, 5);
    insertNode(root, 3);
    insertNode(root, 6);
    insertNode(root, 7);

    InOrder(root);
    cout << endl;

    cout << "kedalaman : " << hitungKedalaman(root, 0) << endl;
    cout << "jumlah node : " << hitungJumlahNode(root) << endl;
    cout << "total : " << hitungTotalInfo(root) << endl;

    return 0;
}
```

#### Output:
![alt text](https://github.com/adityarafael67/praktikum-algoritma-dan-struktur-data/blob/main/Asset/Screenshot%202025-12-30%20145459.png?raw=true)


File bstree.h berisi definisi struktur Binary Search Tree dan deklarasi fungsi-fungsi yang digunakan. File bstree.cpp berisi implementasi seluruh fungsi BST seperti insert, traversal inorder, dan perhitungan node, total, serta kedalaman tree. File main.cpp digunakan untuk menjalankan dan menguji program dengan memasukkan data ke dalam tree lalu menampilkan hasilnya.

#### Full code Screenshot:
![alt text](https://github.com/adityarafael67/praktikum-algoritma-dan-struktur-data/blob/main/Asset/Screenshot%202025-12-30%20145510.png?raw=true)
![alt text](https://github.com/adityarafael67/praktikum-algoritma-dan-struktur-data/blob/main/Asset/Screenshot%202025-12-30%20145521.png?raw=true)
![alt text](https://github.com/adityarafael67/praktikum-algoritma-dan-struktur-data/blob/main/Asset/Screenshot%202025-12-30%20145529.png?raw=true)


## Kesimpulan
Melalui praktikum Modul 10, wawasan saya berkembang dari struktur data linear ke non-linear melalui materi Binary Search Tree (BST), memanfaatkan fungsi rekursif untuk menyederhanakan proses insert, search, hingga delete,penggunaan BST membuat pengelolaan data menjadi jauh lebih rapi dan efisien, terutama karena sifatnya yang otomatis mengurutkan data.


## Referensi
[1] I. Holm, Narrator, and J. Fullerton-Smith, Producer, How to Build a Human [DVD]. London: BBC; 2002.
tangkapan layar

