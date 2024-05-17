#include <iostream>
#include <string>

using namespace std;

class bank {
    public:
    string nama;
    int tahunBerdiri, kodeBank;


};

int main(){
    bank keuangan;

    keuangan.nama = "BCA";
    keuangan.tahunBerdiri = 1955;
    keuangan.kodeBank = 014;

    cout << "Nama :" << keuangan.nama << endl;
    cout << "Tahun Berdiri :" << keuangan.tahunBerdiri << endl;
    cout << "Kode Bank :" << keuangan.kodeBank << endl;
}
