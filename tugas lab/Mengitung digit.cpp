#include <iostream>

using namespace std;

int main()
{
    long long bilangan;
    int jumlahDigit = 0;
    cout << "Masukkan bilangan: ";
    cin >> bilangan;

    while (bilangan != 0)
    {
        bilangan /= 10;
        jumlahDigit++;
    }

    cout << "Jumlah digit bilangan: " << jumlahDigit << endl;

    return 0;
}
