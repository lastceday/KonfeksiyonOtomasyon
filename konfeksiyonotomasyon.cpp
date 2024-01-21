/* CEYDA METÝN 2212721025 Konfeksiyon Otomasyonu */
#include <iostream>
#include <string>

 using namespace std;
 
// Fonksiyon prototipleri
void urunEkle();
void urunListele();
void urunAra();
void urunSil();

// Ürün yapýsý
struct Urun {
    string ad;
    string beden;
    string renk;
    float fiyat;
};

// Ürün dizisi
Urun urunler[100];
int urunSayisi = 0;

int main() {
    int secim;
       setlocale(LC_ALL, "Turkish");
    do {
        // Kullanýcýya seçenekleri göster
        cout << "Konfeksiyon Otomasyonu" << endl;
        cout << "1. Ürün Ekle" << endl;
        cout << "2. Ürünleri Listele" << endl;
        cout << "3. Ürün Ara" <<endl;
        cout << "4. Ürün Sil" << endl;
        cout << "0. Çýkýþ" << endl;
        cout << "Seçiminizi yapýn: ";
        cin >> secim;

        switch (secim) {
            case 1:
                urunEkle();
                break;
            case 2:
                urunListele();
                break;
            case 3:
                urunAra();
                break;
            case 4:
                urunSil();
                break;
            case 0:
                cout << "Programdan çýkýlýyor..." << endl;
                break;
            default:
                cout << "Geçersiz seçim!" << endl;
                break;
        }

        cout << endl;

    } while (secim != 0);

    return 0;
}

void urunEkle() {
    if (urunSayisi >= 100) {
        cout << "Ürün eklemek için yer kalmadý!" << endl;
        return;
    }

    Urun yeniUrun;

    cout << "Ürün Adý: ";
    cin >> yeniUrun.ad;

    cout << "Ürün Bedeni: ";
    cin >> yeniUrun.beden;

    cout << "Ürün Rengi: ";
    cin >> yeniUrun.renk;

     cout << "Ürün Fiyatý: ";
    cin >> yeniUrun.fiyat;

    urunler[urunSayisi] = yeniUrun;
    urunSayisi++;

    cout << "Ürün baþarýyla eklendi!" << endl;
}

void urunListele() {
    if (urunSayisi == 0) {
        cout << "Henüz hiç ürün eklenmemiþ!" << endl;
        return;
    }

    std::cout << "Ürünler:" << endl;

    for (int i = 0; i < urunSayisi; i++) {
        cout << "Ürün Adý: " << urunler[i].ad << endl;
        cout << "Ürün Bedeni: " << urunler[i].beden << endl;
        cout << "Ürün Rengi: " << urunler[i].renk << endl;
        cout << "Ürün Fiyatý: " << urunler[i].fiyat << endl;
        cout << endl;
    }
}

void urunAra() {
    if (urunSayisi == 0) {
        cout << "Henüz hiç ürün eklenmemiþ!" <<endl;
        return;
    }

    string arananAd;
    cout << "Aranacak Ürün Adý: ";
    cin >> arananAd;

    bool bulundu = false;

    for (int i = 0; i < urunSayisi; i++) {
        if (urunler[i].ad == arananAd) {
            cout << "Ürün Adý: " << urunler[i].ad << endl;
            cout << "Ürün Bedeni: " << urunler[i].beden << endl;
            cout << "Ürün Rengi: " << urunler[i].renk << endl;
            cout << "Ürün Fiyatý: " << urunler[i].fiyat << endl;
            cout << endl;
            bulundu = true;
        }
    }

    if (!bulundu) {
      cout << "Aranan ürün bulunamadý!" << endl;
    }
}

void urunSil() {
    if (urunSayisi == 0) {
        cout << "Henüz hiç ürün eklenmemiþ!" << endl;
        return;
    }

    string silinecekAd;
    cout << "Silinecek Ürün Adý: ";
    cin >> silinecekAd;

    bool silindi = false;

    for (int i = 0; i < urunSayisi; i++) {
        if (urunler[i].ad == silinecekAd) {
            for (int j = i; j < urunSayisi - 1; j++) {
                urunler[j] = urunler[j + 1];
            }
            urunSayisi--;
            silindi = true;
            break;
        }
    }

    if (silindi) {
        cout << "Ürün baþarýyla silindi!" << endl;
    } else {
        cout << "Silinecek ürün bulunamadý!" << endl;
    }
}

