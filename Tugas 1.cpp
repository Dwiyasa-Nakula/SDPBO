#include <iostream>
#include <string>
using namespace std;

struct Penduduk {
    string nama;
    int umur;
    string kota_lahir;
    string tanggal_lahir;
    string kota_tinggal;
    string agama;
    string no_ktp;
    string no_kk;
    string status;
    string pekerjaan;
};

Penduduk* penduduk; // pointer
int jumlahPenduduk = 0;
const int maxPenduduk = 10; // Maximum number of Penduduk

void Menu() {
    cout << "Menu Pendudukan\n";
    cout << "1. Tambah Data Penduduk\n";
    cout << "2. Tampilkan Data Penduduk\n";
    cout << "3. Ubah Data Penduduk\n";
    cout << "4. Hapus Data Penduduk\n";
    cout << "5. Keluar\n\n";
    cout << "Pilih Menu: ";
}

void TambahData() {
    if (jumlahPenduduk < maxPenduduk) {
        cout << "Nama: ";
        cin.ignore(); // delete buffer
        getline(cin, penduduk[jumlahPenduduk].nama);

        cout << "Umur: ";
        cin >> penduduk[jumlahPenduduk].umur;

        cout << "Kota Lahir: ";
        cin.ignore();
        getline(cin, penduduk[jumlahPenduduk].kota_lahir);

        cout << "Tanggal Lahir: ";
        getline(cin, penduduk[jumlahPenduduk].tanggal_lahir);

        cout << "Kota Tinggal: ";
        getline(cin, penduduk[jumlahPenduduk].kota_tinggal);

        cout << "Agama: ";
        getline(cin, penduduk[jumlahPenduduk].agama);

        cout << "Nomor KTP: ";
        getline(cin, penduduk[jumlahPenduduk].no_ktp);

        cout << "Nomor KK: ";
        getline(cin, penduduk[jumlahPenduduk].no_kk);

        cout << "Status: ";
        getline(cin, penduduk[jumlahPenduduk].status);

        cout << "Pekerjaan: ";
        getline(cin, penduduk[jumlahPenduduk].pekerjaan);

        jumlahPenduduk++;
        cout << "\nData Penduduk baru telah ditambahkan." << endl;
        cout << "Nomer Data Penduduk anda adalah " << jumlahPenduduk << ".\n\n" << endl;

    } else {
        cout << "Data Penduduk mencapai batas penyimpanan.\n\n" << endl;
    }
}

void TampilData(){
    if (jumlahPenduduk == 0) {
        cout << "Data Penduduk kosong.\n\n" << endl;
    } else {
        cout << "Data Penduduk:" << endl;
        for (int i = 0; i < jumlahPenduduk; ++i) {
            cout << "Nama: " << penduduk[i].nama << endl;
            cout << "Umur: " << penduduk[i].umur << " tahun" << endl;
            cout << "Tempat Tanggal Lahir: " << penduduk[i].kota_lahir;
            cout << ", " << penduduk[i].tanggal_lahir << endl;
            cout << "Kota Tinggal: " << penduduk[i].kota_tinggal << endl;
            cout << "Agama: " << penduduk[i].agama << endl;
            cout << "Nomor KK: " << penduduk[i].no_kk << endl;
            cout << "Nomor KTP: " << penduduk[i].no_ktp << endl;
            cout << "Status: " << penduduk[i].status << endl;
            cout << "Pekerjaan: " << penduduk[i].pekerjaan << endl;
            cout << "\n" << endl;
        }
    }
}

void EditData() {
    if (jumlahPenduduk > 0) {
        int nomor;
        cout << "Masukkan nomor data yang ingin diubah: "; cin >> nomor;

        if (nomor >= 1 && nomor <= jumlahPenduduk) {
            cout << "Nama: ";
            cin.ignore();
            getline(cin, penduduk[jumlahPenduduk].nama);

            cout << "Umur: ";
            cin >> penduduk[jumlahPenduduk].umur;

            cout << "Kota Lahir: ";
            cin.ignore();
            getline(cin, penduduk[jumlahPenduduk].kota_lahir);

            cout << "Tanggal Lahir: ";
            getline(cin, penduduk[jumlahPenduduk].tanggal_lahir);

            cout << "Kota Tinggal: ";
            getline(cin, penduduk[jumlahPenduduk].kota_tinggal);

            cout << "Agama: ";
            getline(cin, penduduk[jumlahPenduduk].agama);

            cout << "Nomor KTP: ";
            getline(cin, penduduk[jumlahPenduduk].no_ktp);

            cout << "Nomor KK: ";
            getline(cin, penduduk[jumlahPenduduk].no_kk);

            cout << "Status: ";
            cin.ignore();
            getline(cin, penduduk[jumlahPenduduk].status);

            cout << "Pekerjaan: ";
            getline(cin, penduduk[jumlahPenduduk].pekerjaan);

            cout << "Data Penduduk baru telah diubah\n\n";
        } else {
            cout << "Nomor Tidak Valid. \n\n";
        }
    } else {
        cout << "Belum ada data penduduk. \n\n";
    }
}

void HapusData() {
    if (jumlahPenduduk > 0) {
        int nomor;
        cout << "Masukkan nomor data yang ingin dihapus: "; cin >> nomor;

        if (nomor >= 1 && nomor <= jumlahPenduduk) {
            for (int i = nomor - 1; i < jumlahPenduduk - 1; i++) {
                penduduk[i] = penduduk[i+1];
            }
            jumlahPenduduk--;
            cout << "Data penduduk berhasil dihapus.\n\n";
        } else {
            cout << "Nomor tidak valid.\n\n";
        }
    } else {
        cout << "Belum ada data penduduk.\n\n";
    }
}

void ExitData() {
    cout << "Terimakasih sudah menggunakan program ini. \n";
    delete[] penduduk; //bebaskan memori yang telah dialokasikan untuk pointer buku
}

int main() {
    int pilihan_menu;
    penduduk = new Penduduk[maxPenduduk];

    while (true) { // loop menu
        Menu();
        cin >> pilihan_menu;

        switch (pilihan_menu) {
            case 1: // 1. Tambah Data Penduduk
            TambahData(); break;;   

            case 2: // 2. Tampilkan Data Penduduk
            TampilData(); break;

            case 3: //3. Ubah Data Penduduk
            EditData(); break;

            case 4: //hapus data
            HapusData(); break;

            case 5: //exit program
            ExitData(); break;
            return 0;

            default:
            cout << "Pilihan tidak valid. Silahkan coba lagi dari Menu yang tersedia\n\n";
            }
    }
return 0;
}
//commit update 3 (memindahkan Menu ke void)
