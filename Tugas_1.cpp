#include <iostream>
#include <sstream>
#include <limits>

using namespace std;

/* 
Nama        : Shirleen Adriana
NIM         : 230401010109
Kelas       : IT104
Mata Kuliah : Algoritma dan Pemrograman
*/

int main()
{
    // Membuat Bintang berdasarkan input
    int jumlah_baris;

    bool cek_input_opsi = true;

    do
    {
        cout << "Jumlah baris? ";
        cin >> jumlah_baris;

        if (cin.fail() || jumlah_baris <= 0)
        {
            cin.clear();                                         // Menghapus flag kesalahan pada cin
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Membersihkan input buffer
            cout << "Opsi yang Anda masukkan salah. Mohon input bilangan bulat positif" << endl;
        }
        else
        {
            cek_input_opsi = false;
        }
    } while (cek_input_opsi);

    cout << "Bintang(" << jumlah_baris << ")" << endl;

    if (jumlah_baris % 2 == 0)
    {
        cout << "Anda memasukkan jumlah Genap. Masukkan hanya jumlah Ganjil." << endl;
    }
    else
    {
        for (int i = 1; i <= jumlah_baris; i++)
        {
            if (i == jumlah_baris / 2 + 1)
            {
                for (int j = 1; j <= jumlah_baris; j++)
                {
                    cout << "*";
                }
                cout << endl;
            }
            else
            {
                for (int j = 1; j <= jumlah_baris; j++)
                {
                    if (j == jumlah_baris / 2 + 1)
                    {
                        cout << "*";
                    }
                    cout << " ";
                }
                cout << endl;
            }
        }
    }

    // Mengulang Program
    char input_jawaban;
    cout << "Apakah Anda ingin mengulang Program (Y/N): ";
    cin >> input_jawaban;
    char hurufJawaban = tolower(input_jawaban);

    if (hurufJawaban == 'y')
    {
        main();
    }
    else
    {
        cout << "Terima kasih telah menggunakan Program ini." << endl;
    }

    return 0;
}