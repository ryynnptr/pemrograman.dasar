#include <iostream>
#include <string>

using namespace std;

// struktur dari pegawai
struct pegawai {
    string nama;
    string departemen;
    int gaji;
};

// fungsi untuk menaikkan gaji
void naikGaji(pegawai& pegawai1) {
    pegawai1.gaji *= 1.10;
}

// objek dari pegawai1 sebagai output
 int main(){
    pegawai pegawai1;
    pegawai1.nama = "Budi";
    pegawai1.departemen = "IT";
    pegawai1.gaji = 5000000;

// fungsi void naikGaji dipanggil untuk menaikkan gaji objek
    naikGaji(pegawai1);

cout << "Nama: " << pegawai1.nama << endl;
cout << "Departemen: " << pegawai1.departemen << endl;
cout << "Gaji: " << pegawai1.gaji << endl;

return 0;
 }

