#include <iostream>

using namespace std;

class Number1 {
    private :
    int y ;

    public :
    void setY(int ui) {
        y = ui;
    }

    int getY() {
        return y;
    }
};

class Number2 {
   public :
   int x ;
};

int main() {
    Number1 satu ;
    Number2 dua ;

    satu.setY(25);
    dua.x = 30;

    cout << "Number Y: " << satu.getY() << endl;
    cout << "Number X: " << dua.x << endl;

    return 0;
}
