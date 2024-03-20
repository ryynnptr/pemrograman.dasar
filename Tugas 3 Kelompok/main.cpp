    // Budi kurnia - 2C2230018
    // Fadhli Jahfal aufa maulana - 2C2230008
    // Riyan putra pratama - 2C2230016

#include <iostream>
#include <string.h>

using namespace std;

struct book {
    int code;
    char judul[50];
    string pengarang;
    int tahunTerbit;
    string isbn;

} library[100];

int nomorBuku = 0;
 
//  penambahan buku
void addBook() {
    system("cls");
    cout << "Tambahkan buku baru.....\n";
    library[nomorBuku].code = nomorBuku + 1;
    cout << "Masukkan judul  : " ;
    cin.ignore();
    cin.getline(library[nomorBuku].judul, 50);
    cout << "Masukkan nama pengarang : ";
    cin >> library[nomorBuku].pengarang;
    cout << "Masukkan Tahun terbit : ";
    cin >> library[nomorBuku].tahunTerbit;;
    cout << "Masukkan Nomor ISBN : ";
    cin >> library[nomorBuku].isbn;
    nomorBuku++;
    cout << "\n BUKU BERHASIL DITAMBAHKAN";
    cout << endl;
    system("pause");

    }

    // menampilkan buku
void displayBooks() {
    system("cls");
    cout << "Kumpulan buku :\n\n";
    if (nomorBuku == 0) {
        cout << "Buku tidak ditemukan.\n";
    } else {
        for (int i = 0; i < nomorBuku; i++) {
            cout << "Code         : " << library[i].code << endl;
            cout << "Judul        : " << library[i].judul << endl;
            cout << "Pengarang    : " << library[i].pengarang << endl;
            cout << "Tahun terbit : " << library[i].tahunTerbit << endl;
            cout << "No ISBN      : " << library[i].isbn << endl;
            cout << endl;
        }
    }
    system("pause");
}
   
// mencari buku
    void searchBooks(){
        system("cls");
        cout << "Cari Buku\n"; 
        string judul;
        cout << "Masukkan judul buku : ";
        cin.ignore();
        getline(cin, judul);
        int found = 0;
        for(int i = 0; i < nomorBuku; i++) {
            if(strcasecmp(library[i].judul, judul.c_str()) == 0) {
                cout << " Code           : " << library[i].code << endl;
                cout << " Judul Buku     : " << library[i].judul << endl;
                cout << " Nama pengarang : " << library[i].pengarang << endl;
                cout << " Tahun terbit   : " << library[i].tahunTerbit << endl;
                cout << " Nomor ISBN     : " << library[i].isbn << endl;
                found = 1;

            }
            }
            if(found == 0) {
                cout << "\n Buku tidak ditemukan. \n";
            
            }
            system("pause");
        }

//		hapus buku
        void deleteBook() {
            system("cls");
            cout << "Hapus buku" << endl;
            int code;
            cout << "Masukkan code buku : ";
            cin >> code;
            int found = -1;
            for(int i = 0; i < nomorBuku; i++) {
                if(library[i].code == code) {
                    found = i;
                    break;
                }
            }
            if(found == -1){
                cout << "Buku tidak ditemukan";

            }
            else {
                for(int i = found; i < nomorBuku - 1; i++) {
                    library[i] = library[i + 1];

                }
                nomorBuku--;
                cout << "Buku berhasil dihapus";

            }
            system("pause");
        }
 
// 		output pilhan menu

        int main() {
            int choice;
            while (true) {
                system("cls");
                cout << "Sistem manajemen Perpustakaan \n";
				cout << "----------------------------- \n";
                cout << "1. Tambah buku\n";
                 cout << "2. Tampilkan Buku\n";
                 cout << "3. Cari Buku\n";
                  cout << "4. Hapus Buku\n";
                   cout << "5. Exit\n";
                    cout << "Enter your choice : ";
                    cin >> choice;
                    switch(choice) {
                        case 1:
                        addBook();
                        break;
                        case 2:
                        displayBooks();
                        break;
                        case 3:
                        searchBooks();
                        break;
                        case 4:
                        deleteBook();
                        break;
                        case 5:
                        exit(0);
                        default:
                        cout << "Pilihan salah. Coba lagi kembali.";
                        system("pause");
                    }

             }
             return 0;
        }
    
