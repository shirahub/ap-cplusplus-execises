#include <iostream>
#include <sstream>
#include <limits>
#include <vector>
#include <string>

using namespace std;

/* 
Nama        : Shirleen Adriana
NIM         : 230401010109
Kelas       : IT104
Mata Kuliah : Algoritma dan Pemrograman
*/

bool apakahBilanganPrima(int bilangan)
{
    if (bilangan <= 1)
    {
        return false;
    }

    for (int i = 2; i * i <= bilangan; ++i)
    {
        if (bilangan % i == 0)
        {
            return false;
        }
    }

    return true;
}

int main()
{
    // Input dan Validasinya
    int input_bilangan;

    bool cek_input_opsi = true;

    do
    {
        cout << "Ketik bilangan Anda di sini: ";
        cin >> input_bilangan;

        if (cin.fail())
        {
            cin.clear();                                         // Menghapus flag kesalahan pada cin
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Membersihkan input buffer
            cout << "Opsi yang Anda masukkan salah. Mohon input bilangan dan bukan huruf" << endl;
        }
        else
        {
            cek_input_opsi = false;
        }
    } while (cek_input_opsi);

    // Periksa input
    string properti_bilangan[3];

    if (input_bilangan == 0 || input_bilangan % 2 == 0)
    {
        properti_bilangan[0] = "genap";
    }
    else
    {
        properti_bilangan[0] = "ganjil";
    }

    if (input_bilangan > 0)
    {
        properti_bilangan[1] = "positif";
    }
    else if (input_bilangan < 0)
    {
        properti_bilangan[1] = "negatif";
    }

    if (apakahBilanganPrima(input_bilangan))
    {
        properti_bilangan[2] = "prima";
    }

    // Bentuk kalimat jawaban
    string delimiter = " ";
    string hasil;
    int panjang_properti = sizeof(properti_bilangan) / sizeof(properti_bilangan[0]);

    for (int i = 0; i < panjang_properti; ++i)
    {
        if (properti_bilangan[i] != "")
        {

            hasil += properti_bilangan[i];
            if (i < (panjang_properti - 1))
            {
                hasil += delimiter;
            }
        }
    }

    cout << "Bilangan " << input_bilangan << " adalah bilangan " << hasil << endl;

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