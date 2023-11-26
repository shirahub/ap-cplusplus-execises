#include <iostream>
#include <sstream>
#include <string>
#include <iomanip>
#include <limits>

using namespace std;

/* 
Nama        : Shirleen Adriana
NIM         : 230401010109
Kelas       : IT104
Mata Kuliah : Algoritma dan Pemrograman
*/

string formatThousandSeparator(int angka)
{
    std::stringstream ss;
    ss << std::fixed << angka;
    std::string formattedNumber = ss.str();

    // Menambahkan pemisah ribuan
    for (int i = formattedNumber.size() - 3; i > 0; i -= 3)
    {
        formattedNumber.insert(i, ".");
    }
    return formattedNumber;
}

int main()
{
    const int opsi_jumlah_penarikan[3] = {100000, 250000, 500000};

    // Program ATM Menu
    const char *menu =
        "Silahkan pilih (1-3) jumlah uang yang akan anda ambil:";
    cout << menu << endl;

    int jumlah_opsi = sizeof(opsi_jumlah_penarikan) / sizeof(opsi_jumlah_penarikan[0]);
    for (int i = 0; i < jumlah_opsi; ++i)
    {
        string jumlah = formatThousandSeparator(opsi_jumlah_penarikan[i]);
        cout << i + 1 << ". " << jumlah << std::endl;
    }

    int input_opsi;
    bool cek_input_opsi = true;

    do
    {
        cout << "Pilihan: ";
        cin >> input_opsi;

        if (cin.fail() || input_opsi <= 0 || input_opsi > jumlah_opsi)
        {
            cin.clear();                                              // Menghapus flag kesalahan pada cin
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Membersihkan input buffer
            cout << "Opsi yang Anda masukkan salah. Mohon input angka sesuai nomor pilihan yang ada." << endl;
        }
        else
        {
            cek_input_opsi = false;
        }
    } while (cek_input_opsi);

    cout << "Silahkan ambil uang " << formatThousandSeparator(opsi_jumlah_penarikan[input_opsi - 1]) << " Anda." << endl;

    // Mengulang Program
    char input_jawaban;
    cout << "Apakah anda ingin melakukan transaksi lagi (Y/N): ";
    cin >> input_jawaban;
    char hurufJawaban = tolower(input_jawaban);

    if (hurufJawaban == 'y')
    {
        main();
    }
    else
    {
        cout << "Terima kasih telah menggunakan ATM ini." << endl;
    }

    return 0;
}