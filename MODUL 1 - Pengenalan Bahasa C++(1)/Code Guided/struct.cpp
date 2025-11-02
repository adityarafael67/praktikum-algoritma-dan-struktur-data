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
