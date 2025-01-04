#include <iostream>
#include <vector>
#include <fstream>
#include <algorithm>
using namespace std;

struct Mahasiswa {
    string nim;
    string nama;
    float nilaiAkhir;
};

vector<Mahasiswa> dataMahasiswa;

void tambahDataMahasiswa() {
    int jumlah;
    cout << "Masukkan jumlah mahasiswa: ";
    cin >> jumlah;

    for (int i = 0; i < jumlah; ++i) {
        Mahasiswa m;
        cout << "Masukkan NIM Mahasiswa ke-" << i + 1 << ": ";
        cin >> m.nim;
        cin.ignore();
        cout << "Masukkan Nama Mahasiswa ke-" << i + 1 << ": ";
        getline(cin, m.nama);
        cout << "Masukkan Nilai Akhir Mahasiswa ke-" << i + 1 << ": ";
        cin >> m.nilaiAkhir;
        dataMahasiswa.push_back(m);
    }
    cout << "Data berhasil ditambahkan!\n";
}

void tampilkanSemuaData() {
    for (const auto &m : dataMahasiswa) {
        cout << "NIM: " << m.nim << ", Nama: " << m.nama << ", Nilai Akhir: " << m.nilaiAkhir << "\n";
    }
}

void cariDataMahasiswa() {
    string nimCari;
    cout << "Masukkan NIM yang ingin dicari: ";
    cin >> nimCari;

    for (const auto &m : dataMahasiswa) {
        if (m.nim == nimCari) {
            cout << "Data ditemukan:\n";
            cout << "NIM: " << m.nim << ", Nama: " << m.nama << ", Nilai Akhir: " << m.nilaiAkhir << "\n";
            return;
        }
    }
    cout << "Data tidak ditemukan!\n";
}

void urutkanData() {
    sort(dataMahasiswa.begin(), dataMahasiswa.end(), [](const Mahasiswa &a, const Mahasiswa &b) {
        return a.nilaiAkhir > b.nilaiAkhir;
    });
    cout << "Data berhasil diurutkan berdasarkan Nilai Akhir (descending).\n";
}

void simpanKeBerkas() {
    ofstream file("data_mahasiswa.txt");
    for (const auto &m : dataMahasiswa) {
        file << m.nim << "," << m.nama << "," << m.nilaiAkhir << "\n";
    }
    file.close();
    cout << "Data berhasil disimpan ke dalam berkas.\n";
}

void bacaDariBerkas() {
    ifstream file("data_mahasiswa.txt");
    string line;
    dataMahasiswa.clear();

    while (getline(file, line)) {
        Mahasiswa m;
        size_t pos1 = line.find(',');
        size_t pos2 = line.rfind(',');
        m.nim = line.substr(0, pos1);
        m.nama = line.substr(pos1 + 1, pos2 - pos1 - 1);
        m.nilaiAkhir = stof(line.substr(pos2 + 1));
        dataMahasiswa.push_back(m);
    }
    file.close();
    cout << "Data berhasil dibaca dari berkas.\n";
}

int main() {
    int pilihan;

    do {
        cout << "\nMenu Utama:\n";
        cout << "1. Tambah Data Mahasiswa\n";
        cout << "2. Tampilkan Semua Data\n";
        cout << "3. Cari Data Mahasiswa\n";
        cout << "4. Urutkan Data\n";
        cout << "5. Simpan Data ke Berkas\n";
        cout << "6. Baca Data dari Berkas\n";
        cout << "7. Keluar\n";
        cout << "Pilih opsi (1-7): ";
        cin >> pilihan;

        switch (pilihan) {
            case 1: tambahDataMahasiswa(); break;
            case 2: tampilkanSemuaData(); break;
            case 3: cariDataMahasiswa(); break;
            case 4: urutkanData(); break;
            case 5: simpanKeBerkas(); break;
            case 6: bacaDariBerkas(); break;
            case 7: cout << "Terima kasih telah menggunakan program ini!\n"; break;
            default: cout << "Pilihan tidak valid. Silakan coba lagi.\n"; break;
        }
    } while (pilihan != 7);

    return 0;
}
