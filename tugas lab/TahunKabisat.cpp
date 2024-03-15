#include <iostream>

using namespace std;

int main()
{
    int tahun;
    cout << "Masukkan tahun: ";
    cin >> tahun;

    if (tahun % 4 == 0)
    {
        if (tahun % 100 == 0)
        {
            if (tahun % 400 == 0)
            {
                cout << tahun << " adalah tahun kabisat." << endl;
            }
            else
            {
                cout << tahun << " bukan tahun kabisat." << endl;
            }
        }
        else
        {
            cout << tahun << " adalah tahun kabisat." << endl;
        }
    }
    else {
    	 cout << tahun << " bukan tahun kabisat." << endl;
	}

	return 0;
    }
	
  
