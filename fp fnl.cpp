#include <iostream>
#include <string>
#include <cctype>
#include <queue>
#include <vector>

using namespace std;

struct Barang {
    string nama;
    int harga;
    int jumlah;
};

struct Node {
    Barang barang;
    Node* next;
};

struct Penjualan {
    string namaPembeli;
    string telepon;
    string alamat;
    Node* head;
    int jumlahBarang;
    vector<Barang> barangDibeli;
};

bool validasiIDBarang(int id, int n) {
    return id >= 1 && id <= n;
}

void bubbleSort(Barang daftarBarang[], int n) {
    for (int i = 0; i < n - 1; ++i) {
        for (int j = 0; j < n - i - 1; ++j) {
            if (daftarBarang[j].nama > daftarBarang[j + 1].nama) {
                Barang temp = daftarBarang[j];
                daftarBarang[j] = daftarBarang[j + 1];
                daftarBarang[j + 1] = temp;
            }
        }
    }
}

void tambahKeLinkedList(Penjualan &penjualan, Barang barang) {
    Node* newNode = new Node();
    newNode->barang = barang;
    newNode->next = nullptr;

    if (penjualan.head == nullptr) {
        penjualan.head = newNode;
    } else {
        Node* temp = penjualan.head;
        while (temp->next != nullptr) {
            temp = temp->next;
        }
        temp->next = newNode;
    }
    penjualan.jumlahBarang++;
}

void tampilkanBarangDibeli(Penjualan &penjualan) {
    Node* temp = penjualan.head;
    int total = 0;
    int i = 1;
    while (temp != nullptr) {
        cout << i << ". " << temp->barang.nama << " (x" << temp->barang.jumlah << ")"
             << " - Rp. " << temp->barang.harga << endl;
        total += temp->barang.harga;
        temp = temp->next;
        i++;
    }
    cout << "Total Belanja: Rp. " << total << endl;
}


int main() {
    Barang daftarBarang[] = {
        {"Minyak Goreng Bimoli 2L", 33000},
        {"Indomie Goreng 1 pack", 12000},
        {"Gula Pasir Gulaku 1kg", 15000},
        {"Beras Rojolele 5kg", 60000},
        {"Susu Ultra Milk 1L", 18000},
        {"Sampo Pantene 200ml", 22000},
        {"Sabun Lifebuoy 100g", 5000},
        {"Pasta Gigi Pepsodent 190g", 12000},
        {"Teh Celup Sosro 1 pack", 10000},
        {"Kopi Kapal Api 100g", 15000},
        {"Susu Kental Manis Frisian Flag", 13000},
        {"Baterai ABC AA 2pcs", 8000},
        {"Tissue Paseo 250 sheets", 15000},
        {"Minuman Isotonik Pocari Sweat 350ml", 7000},
        {"Air Mineral Aqua 1.5L", 6000},
        {"Biskuit Roma Kelapa", 12000},
        {"Cokelat SilverQueen 65g", 15000},
        {"Permen Mentos 37g", 7000},
        {"Telur Ayam 1kg", 24000},
        {"Margarin Blue Band 200g", 12000},
        {"Tepung Terigu Bogasari 1kg", 12000},
        {"Mie Sedaap Goreng 1 pack", 10000},
        {"Saus Sambal ABC 340ml", 12000},
        {"Kecap Manis Bango 220ml", 10000},
        {"Minyak Kayu Putih Cap Lang 60ml", 17000},
        {"Obat Nyamuk Baygon 600ml", 30000},
        {"Sikat Gigi Formula 2 pcs", 18000},
        {"Shampoo Clear 170ml", 25000},
        {"Body Lotion Vaseline 200ml", 29000},
        {"Masker Sensi 50 pcs", 150000},
        {"Vitamin C Redoxon 10 tablet", 20000},
        {"Obat Flu Neozep 10 tablet", 15000},
        {"Madu TJ 150ml", 30000},
        {"Minuman Kesehatan You C1000 140ml", 15000},
        {"Air Susu Bear Brand 189ml", 11000},
        {"Keripik Singkong Chitato 70g", 12000},
        {"Snack Cheetos 55g", 10000},
        {"Wafer Tango 150g", 14000},
        {"Kue Monde Butter Cookies 150g", 18000},
        {"Sirup Marjan Cocopandan 460ml", 20000},
        {"Jam Tangan Casio", 350000},
        {"Buku Tulis Sinar Dunia 58g", 6000},
        {"Bolpoin Standard AE7", 3000},
        {"Pulpen Pilot Frixion", 20000},
        {"Stapler Kenko", 15000},
        {"Isolasi Lakban 1 inch", 7000},
        {"Kertas HVS A4 70gsm", 40000},
        {"Map Kertas F4", 1000},
        {"Gunting Kertas", 12000},
        {"Penggaris Plastik 30cm", 5000},
        {"Calculator Casio", 60000},
        {"Amplop Putih 1 pack", 5000},
        {"Tempat Pensil", 15000},
        {"Masking Tape 1 inch", 8000},
        {"Cutter Besar", 10000},
        {"Sticky Note 3x3", 10000},
        {"Spidol Hitam Snowman", 9000},
        {"Binder Clip 1 inch", 6000},
        {"Klip Kertas 33mm 1 box", 5000},
        {"Tipe-X Kenko", 7000},
        {"Lampu LED Philips 9 watt", 25000},
        {"Kabel USB Charger", 20000},
        {"Adaptor Charger", 30000},
        {"Power Bank 10000mAh", 150000},
        {"Headphone JBL", 300000},
        {"Speaker Bluetooth", 250000},
        {"Flashdisk SanDisk 32GB", 80000},
        {"Memory Card 32GB", 60000},
        {"Harddisk Eksternal 1TB", 800000},
        {"Mouse Logitech", 150000},
        {"Keyboard Wireless Logitech", 300000},
        {"Webcam HD", 400000},
        {"Tas Laptop 15 inch", 200000},
        {"Cooling Pad", 50000},
        {"Printer Canon", 1500000},
        {"Tinta Printer Canon", 100000},
        {"Kabel HDMI", 30000},
        {"Kunci Pas", 20000},
        {"Obeng Set", 30000},
        {"Tang Potong", 25000},
        {"Perangkat Perbaikan", 50000},
        {"Kotak P3K", 100000},
        {"Sarung Tangan Karet", 15000},
        {"Masker 3M N95", 50000},
        {"Sepatu Boot", 200000},
        {"Jaket Safety", 250000},
        {"Helm Safety", 50000},
        {"Rompi Reflektor", 30000},
        {"Raincoat", 150000},
        {"Senter LED", 30000},
        {"Baterai Alkalin AA", 15000},
        {"Celana Dalam GT MAN ", 50000},
        {"Singlet GT MAN ", 50000},
        {"Kinderjoy Pembuat Mamah Resah", 15000},
        {"Ice Cream Magnum", 20000},
        {"Sapu Lantai", 15000},
        {"Pel Lantai", 20000},
        {"Hotwheels", 50000},
        {"1000 Diamond Free Fire", 50000},
        {"Google Play Voucher RP.50.000", 55000},
    };
    
    int n = sizeof(daftarBarang) / sizeof(daftarBarang[0]); 
    Penjualan penjualan;
    penjualan.jumlahBarang = 0;
    penjualan.head = nullptr;

    cout << "=== Selamat Datang di Minimarket ===\n";
    cout << "Masukkan Nama Anda: ";
    getline(cin, penjualan.namaPembeli);
    cout << "Masukkan Nomor Telepon Anda: ";
    getline(cin, penjualan.telepon);
    cout << "Masukkan Alamat Anda: ";
    getline(cin, penjualan.alamat);

    bubbleSort(daftarBarang, n);

    int pilihan;
    do {
        cout << "\n=== Menu Utama ===\n";
        cout << "1. Lihat Katalog Barang\n";
        cout << "2. Cari Barang\n";
        cout << "3. Tambah Pembelian\n";
        cout << "4. Proses Pembayaran\n";
        cout << "5. Keluar\n";
        cout << "Pilih menu (1-5): ";
        cin >> pilihan;
        cin.ignore();

        switch (pilihan) {
            case 1:
                cout << "\n=== Katalog Barang ===\n";
                for (int i = 0; i < n; ++i) {
                    cout << i + 1 << ". " << daftarBarang[i].nama 
                         << " - Rp. " << daftarBarang[i].harga << endl;
                }
                break;

            case 2: {
                string cari;
                cout << "\nMasukkan nama barang yang ingin dicari: ";
                getline(cin, cari);
                bool ditemukan = false;
                for (int i = 0; i < n; ++i) {
                    if (daftarBarang[i].nama.find(cari) != string::npos) {
                        cout << "Barang ditemukan: " << daftarBarang[i].nama 
                             << " dengan harga Rp. " << daftarBarang[i].harga << endl;
                        ditemukan = true;
                    }
                }
                if (!ditemukan) {
                    cout << "Barang tidak ditemukan.\n";
                }
                break;
            }

            case 3: {
    char tambahLagi;
    do {
        if (penjualan.jumlahBarang >= 20) {
            cout << "Keranjang penuh!\n";
            break;
        }

        int id;
        cout << "\nMasukkan nomor barang (ID) yang ingin dibeli: ";
        cin >> id;
        cin.ignore();

        if (validasiIDBarang(id, n)) {
            int jumlah;
            cout << "Masukkan jumlah barang yang ingin dibeli: ";
            cin >> jumlah;
            cin.ignore();

            if (jumlah > 0) {
                Barang barangDibeli = daftarBarang[id - 1];
                barangDibeli.harga *= jumlah;
                tambahKeLinkedList(penjualan, barangDibeli);
                cout << "Barang berhasil ditambahkan ke keranjang: "
                     << barangDibeli.nama 
                     << " sebanyak " << jumlah 
                     << " buah dengan total harga Rp. " << barangDibeli.harga << endl;
                penjualan.barangDibeli.push_back(barangDibeli);
            } else {
                cout << "Jumlah barang harus lebih dari 0.\n";
            }
        } else {
            cout << "ID barang tidak valid.\n";
        }

        cout << "Apakah Anda ingin membeli barang lain? (y/n): ";
        cin >> tambahLagi;
        cin.ignore();

    } while (tambahLagi == 'y' || tambahLagi == 'Y');
    break;
}

            case 4: {
                int total = 0;
                cout << "\n=== Daftar Belanjaan ===\n";
                for (int i = 0; i < penjualan.barangDibeli.size(); ++i) {
                    cout << i + 1 << ". " << penjualan.barangDibeli[i].nama 
                         << " - Rp. " << penjualan.barangDibeli[i].harga << endl;
                    total += penjualan.barangDibeli[i].harga;
                }
                cout << "Total Belanja: Rp. " << total << endl;

                if (total > 300000) {
                    int diskon = total * 0.1;
                    total -= diskon;
                    cout << "Diskon 10%: Rp. " << diskon << endl;
                    cout << "Total Final: Rp. " << total << endl;
                }

                int pembayaran;
                cout << "Masukkan jumlah pembayaran: Rp. ";
                cin >> pembayaran;

                int kembalian = pembayaran - total;
                if (kembalian >= 0) {
                    cout << "Kembalian: Rp. " << kembalian << endl;
                } else {
                    cout << "Pembayaran kurang sebesar Rp. " << -kembalian << endl;
                }
                break;
            }

            case 5:
                cout << "Terima kasih, " << penjualan.namaPembeli << "!\n";
                break;

            default:
                cout << "Pilihan tidak valid.\n";
        }
    } while (pilihan != 5);

    return 0;
}
