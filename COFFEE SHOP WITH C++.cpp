#include <iostream>
#include <string.h>
#include <conio.h>
#include <stdlib.h>

using namespace std;

#define ppn 0.10 // PPN = 10%
const int diskon = 5000;

int main() {
    char nama[100], menu[20], back;
    int jumlah, kopi, minum, total, bayar, kurang, bonus, pajak, kembalian,
        harga[6] = {25000, 30000, 35000, 40000, 20000, 50000},
        stok[6] = {10, 10, 10, 10, 10, 10},
        i = 0;
    bool saldo;

    do {
        system("CLS");
        cout << "============================= Cafe Harlan ==============================" << endl;
        cout << "============================ Selamat Datang di Cafe Harlan  =====================" << endl;
        cout << "==================== Cafe Harlan, Tempat Terbaik untuk Menikmati Kopi || Siahkan Mampir ! ============" << endl;
        cout << endl;
        cout << "Masukkan Nama Anda : ";
        cin >> nama;
        cout << "Pilihan menu kopi yang tersedia---" << endl;
        cout << "--------------------------------------------------------------------------" << endl;
        cout << "|    [1] Espresso       = Rp 25.000                           |" << endl;
        cout << "|    [2] Cappuccino     = Rp 30.000                           |" << endl;
        cout << "|    [3] Latte          = Rp 35.000                           |" << endl;
        cout << "|    [4] Mocha          = Rp 40.000                           |" << endl;
        cout << "|    [5] Americano      = Rp 20.000                           |" << endl;
        cout << "|    [6] Affogato       = Rp 50.000                           |" << endl;
        cout << "--------------------------------------------------------------------------" << endl;

        cout << "            (Masukkan Menu Kopi berdasarkan Nomor)" << endl;
        cout << " Silahkan Pilih Menu Kopi anda : ";
        cin >> kopi;

        // Percabangan
        switch (kopi) {
            case 1:
                strcpy(menu, "Espresso");
                i = 0;
                break;
            case 2:
                strcpy(menu, "Cappuccino");
                i = 1;
                break;
            case 3:
                strcpy(menu, "Latte");
                i = 2;
                break;
            case 4:
                strcpy(menu, "Mocha");
                i = 3;
                break;
            case 5:
                strcpy(menu, "Americano");
                i = 4;
                break;
            case 6:
                strcpy(menu, "Affogato");
                i = 5;
                break;
            default:
                cout << "Pilihan menu yang anda pilih tidak tersedia..." << endl;
                goto ulang;
        }

        cout << "    Anda memilih " << menu << endl;
        cout << endl;

        if (stok[i] <= 0) {
            cout << "Maaf, menu ini telah habis. Silakan pilih menu lain." << endl;
            goto ulang;
        }

        cout << "Stok tersedia: " << stok[i] << " gelas" << endl;
        cout << "Jumlah Kopi yang dipesan: ";
        cin >> jumlah;

        if (jumlah > stok[i]) {
            cout << "Maaf, stok tidak mencukupi. Stok tersedia: " << stok[i] << " gelas" << endl;
            goto ulang;
        }

        stok[i] -= jumlah;

        minum = jumlah * harga[i];
        pajak = minum * ppn;
        total = pajak + minum;
        cout << endl;
        cout << "-------------------------------------------------------" << endl;
        cout << "|                    Cafe Harlan                   |" << endl;
        cout << "-------------------------------------------------------" << endl;
        cout << "\tNama Pemesan          : " << nama << endl;
        cout << "\tMenu Kopi             : " << menu << endl;
        cout << "\tJumlah Kopi           : " << jumlah << " gelas" << endl;
        cout << "\tHarga Kopi            : Rp " << harga[i] << " * " << jumlah << endl;
        cout << "\tPajak Cafe            : Rp " << pajak << endl;
        cout << "\tTotal Pembayaran      : Rp " << total << endl;

        if (jumlah >= 4) {
            bonus = total - diskon;
            total = bonus;
            cout << endl;
            cout << "# Anda mendapatkan diskon Potongan Harga : Rp " << diskon << " #" << endl;
            cout << "Total Pembayaran Setelah diskon  : Rp " << total << endl;
        }

        cout << "--------------------------------------------" << endl;
        cout << "Silahkan bayar disini          : Rp.";
        cin >> bayar;
        cout << endl;

        // Perulangan
        while (saldo = bayar < total) {
            cout << "Saldo anda kurang, Silahkan bayar lagi : Rp. ";
            cin >> kurang;
            bayar += kurang;
        };

        kembalian = bayar - total;
        cout << "Uang yang anda bayar                   : Rp. " << bayar << endl;
        cout << "Uang kembalian                         : Rp. " << kembalian << endl;
        cout << "##################################################" << endl;

    ulang:
        cout << "            [Y = ya / T = tidak]" << endl;
        cout << "        Apakah anda ingin memesan lagi ? [Y/T]  =  ";
        cin >> back;
    } while (back == 'Y' || back == 'y');
    cout << endl;
    cout << "        Terima kasih telah Memesan Kopi di Cafe Harlan!" << endl;
    cout << "            Selamat Menikmati" << endl;

    return 0;
}

