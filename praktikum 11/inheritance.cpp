#include <iostream>

using namespace std ;

class hewan {
    public:
    void predator () {
        cout << "hewan ini adalah predator ." << endl;
    }
    void taring(){
        cout << "Hewan bertaring." << endl;
    }
    void cakar(){
        cout << "Hewan ini memiliki cakar." << endl;
    }
};

class harimau:public hewan {
    public:
    void getharimau() {
        cout << "Harimau adalah hewan yang berbulu." << endl;
    }
};

class singa:public hewan {
    public:
    void getsinga() {
        cout << "singa adalah raja hutan." << endl;
    }
};

class macanKumbang:public hewan {
    public:
    void getmacanKumbang() {
        cout << "macan kumbang itu temannya harimau sama macan." << endl;
    }
};

int main() {
    harimau hrm;
    hrm.getharimau();
    hrm.predator();
    hrm.taring();
    hrm.cakar();

    cout << endl;
    

    singa sing;
    sing.getsinga();
    sing.predator();
    sing.taring();
    sing.cakar();

    cout << endl;

    macanKumbang mcn;
    mcn.getmacanKumbang();
    mcn.predator();
    mcn.taring();
    mcn.cakar();

    return 0;
}
