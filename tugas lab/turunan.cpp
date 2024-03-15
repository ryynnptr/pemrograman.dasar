#include <iostream>
using namespace std;

class Fungsi {
public:
    double a, b, c;

    Fungsi(double a, double b, double c) : a(a), b(b), c(c) {}

    Fungsi turunan_fungsi() const {
        return Fungsi(2 * a, b + 5, 0);
    }

    double hitung_fungsi(double x) const {
        return a * x * x + b * x + c;
    }
};

int main() {
    Fungsi fungsi(1, 2, 3);
    Fungsi turunan_fungsi = fungsi.turunan_fungsi();

    double x = 2;
    cout << "Fungsi asli: " << fungsi.hitung_fungsi(x) << endl;
    cout << "Turunan fungsi: " << turunan_fungsi.hitung_fungsi(x) << endl;

    return 0;
}
