#include <iostream>
#include <string>
using namespace std;

int main() {
    double saldoAwal, saldo, totalPengeluaran = 0;
    int pilihan;

    cout << "Selamat datang di Aplikasi Keuangan Harian!\n";
    cout << "Masukkan saldo awal Anda: ";
    cin >> saldoAwal;
    saldo = saldoAwal;

    do {
        cout << "\nMenu Utama:\n";
        cout << "1. Tambah Pengeluaran\n";
        cout << "2. Tampilkan Total Pengeluaran\n";
        cout << "3. Tampilkan Sisa Saldo\n";
        cout << "4. Keluar\n";
        cout << "Pilih opsi (1-4): ";
        cin >> pilihan;

        switch (pilihan) {
            case 1: {
                string kategori;
                double jumlah;

                cout << "Masukkan nama kategori pengeluaran: ";
                cin.ignore();
                getline(cin, kategori);

                cout << "Masukkan jumlah pengeluaran: ";
                cin >> jumlah;

                if (jumlah > saldo) {
                    cout << "Pengeluaran melebihi saldo Anda!\n";
                } else {
                    totalPengeluaran += jumlah;
                    saldo -= jumlah;
                    cout << "Pengeluaran berhasil ditambahkan!\n";
                }
                break;
            }
            case 2:
                cout << "Total pengeluaran Anda: " << totalPengeluaran << "\n";
                break;
            case 3:
                cout << "Sisa saldo Anda: " << saldo << "\n";
                break;
            case 4:
                cout << "Terima kasih telah menggunakan Aplikasi Keuangan Harian!\n";
                break;
            default:
                cout << "Pilihan tidak valid. Silakan coba lagi.\n";
                break;
        }
    } while (pilihan != 4);

    return 0;
}
