#include <iostream>
#include <string>

using namespace std;

class bank {
    private:
    string nama;
    int tahunBerdiri;
    string kodeBank;


public:
bank(string n, int t, string k){
    nama = n;
    tahunBerdiri = t;
    kodeBank = k;
}

void setnama(string n){
    nama = n;
}

string getnama() {
    return nama;
}

void settahunBerdiri(int t){
    tahunBerdiri = t;
}

int gettahunBerdiri() {
    return tahunBerdiri;
}

void setkodeBank(string k){
    kodeBank = k;
}

string getkodeBank() {
    return kodeBank;
}

void tampilkanInfo() {
    cout << "Nama Bank: " << nama << " Tahun berdiri: " << tahunBerdiri << "Kode bank :" << kodeBank << endl;
}

};

int main(){
    bank bnk1("BCA", 1955, "014");

    cout << "Informasi Bank  :" << endl;
    bnk1.tampilkanInfo();

    cout << " Nama Bank :" << bnk1.getnama() << endl;
    cout << " Tahun berdiri : " << bnk1.gettahunBerdiri() << endl;
    cout << " Kode Bank : " << bnk1.getkodeBank()<< endl;
    
    cout << endl;

bank bnk2("BRI", 1985, "002");

    cout << "Informasi Bank  :" << endl;
    bnk2.tampilkanInfo();

    cout << " Nama Bank :" << bnk2.getnama() << endl;
    cout << " Tahun berdiri : " << bnk2.gettahunBerdiri() << endl;
    cout << " Kode Bank : " << bnk2.getkodeBank()<< endl;
    return 0;
}
