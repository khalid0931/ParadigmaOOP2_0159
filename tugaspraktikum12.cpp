#include <iostream>
#include <string>
using namespace std;

// Abstract Base Class
class RekeningBank
{
protected:
    string namaNasabah;
    double saldo;

public:
    RekeningBank(string nama, double s)
    {
        namaNasabah = nama;
        saldo = s;
    }

    virtual void potongAdmin() = 0;

    void tampilkanSaldo()
    {
        cout << "Nama Nasabah : " << namaNasabah << endl;
        cout << "Saldo Akhir  : Rp " << saldo << endl;
    }

    virtual ~RekeningBank() {}
};

// Rekening Syariah
class RekeningSyariah : public RekeningBank
{
public:
    RekeningSyariah(string nama, double s)
        : RekeningBank(nama, s) {}

    void potongAdmin()
    {
        cout << "Rekening Syariah bebas biaya admin." << endl;
    }
};

// Rekening Konvensional
class RekeningKonvensional : public RekeningBank
{
public:
    RekeningKonvensional(string nama, double s)
        : RekeningBank(nama, s) {}

    void potongAdmin()
    {
        saldo -= 15000;
        cout << "Biaya admin Rp 15.000 dipotong." << endl;
    }
};

// Rekening Premium
class RekeningPremium : public RekeningBank
{
public:
    RekeningPremium(string nama, double s)
        : RekeningBank(nama, s) {}

    void potongAdmin()
    {
        if (saldo > 10000000)
        {
            cout << "Saldo di atas Rp 10.000.000, bebas biaya admin." << endl;
        }
        else
        {
            saldo -= 50000;
            cout << "Biaya admin Rp 50.000 dipotong." << endl;
        }
    }
};

int main()
{
    RekeningBank *rekening1;
    RekeningBank *rekening2;
    RekeningBank *rekening3;

    rekening1 = new RekeningSyariah("Andi", 5000000);
    rekening2 = new RekeningKonvensional("Budi", 3000000);
    rekening3 = new RekeningPremium("Citra", 8000000);

    cout << "=== Rekening Syariah ===" << endl;
    rekening1->potongAdmin();
    rekening1->tampilkanSaldo();

    cout << endl;

    cout << "=== Rekening Konvensional ===" << endl;
    rekening2->potongAdmin();
    rekening2->tampilkanSaldo();

    cout << endl;

    cout << "=== Rekening Premium ===" << endl;
    rekening3->potongAdmin();
    rekening3->tampilkanSaldo();

    delete rekening1;
    delete rekening2;
    delete rekening3;

    return 0;
}