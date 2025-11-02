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