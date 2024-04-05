// Riyan putra pratama - 2C2230016


#include <iostream>

using namespace std;

void addScore(int *score) {
    *score = *score + 5;
    cout << "Score dibuah ke : " << *score << endl;


}

int main(){
    int score = 0;

    cout << "Score sebelum diubah :" << score << endl;
    addScore( &score); 
    addScore( &score); 
    addScore( &score); 
    addScore( &score); 
    addScore( &score); 
    addScore( &score); 
    cout << "Score setelah diubah :" << score << endl;

     


return 0;

}
