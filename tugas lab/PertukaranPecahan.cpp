#include <iostream>

using namespace std;

int main()
{
    int rupiah;
    int jumlahPecahan1000;
    int jumlahPecahan500;
    int jumlahPecahan100;
    int jumlahPecahan50;
    int jumlahPecahan25;

    cout << "Masukkan jumlah rupiah: ";
    cin >> rupiah;

    jumlahPecahan1000 = rupiah / 1000;
    rupiah %= 1000;

    jumlahPecahan500 = rupiah / 500;
    rupiah %= 500;

    jumlahPecahan100 = rupiah / 100;
    rupiah %= 100;

    jumlahPecahan50 = rupiah / 50;
    rupiah %= 50;

    jumlahPecahan25 = rupiah;

    cout << "Jumlah koin 1000 rupiah: " << jumlahPecahan1000 << endl;
    cout << "Jumlah koin 500 rupiah: " << jumlahPecahan500 << endl;
    cout << "Jumlah koin 100 rupiah: " << jumlahPecahan100 << endl;
    cout << "Jumlah koin 50 rupiah: " << jumlahPecahan50 << endl;
    cout << "Jumlah koin 25 rupiah: " << jumlahPecahan25 << endl;

    return 0;
}
