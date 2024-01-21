/* CEYDA MET�N 2212721025 Konfeksiyon Otomasyonu */
#include <iostream>
#include <string>

 using namespace std;
 
// Fonksiyon prototipleri
void urunEkle();
void urunListele();
void urunAra();
void urunSil();

// �r�n yap�s�
struct Urun {
    string ad;
    string beden;
    string renk;
    float fiyat;
};

// �r�n dizisi
Urun urunler[100];
int urunSayisi = 0;

int main() {
    int secim;
       setlocale(LC_ALL, "Turkish");
    do {
        // Kullan�c�ya se�enekleri g�ster
        cout << "Konfeksiyon Otomasyonu" << endl;
        cout << "1. �r�n Ekle" << endl;
        cout << "2. �r�nleri Listele" << endl;
        cout << "3. �r�n Ara" <<endl;
        cout << "4. �r�n Sil" << endl;
        cout << "0. ��k��" << endl;
        cout << "Se�iminizi yap�n: ";
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
                cout << "Programdan ��k�l�yor..." << endl;
                break;
            default:
                cout << "Ge�ersiz se�im!" << endl;
                break;
        }

        cout << endl;

    } while (secim != 0);

    return 0;
}

void urunEkle() {
    if (urunSayisi >= 100) {
        cout << "�r�n eklemek i�in yer kalmad�!" << endl;
        return;
    }

    Urun yeniUrun;

    cout << "�r�n Ad�: ";
    cin >> yeniUrun.ad;

    cout << "�r�n Bedeni: ";
    cin >> yeniUrun.beden;

    cout << "�r�n Rengi: ";
    cin >> yeniUrun.renk;

     cout << "�r�n Fiyat�: ";
    cin >> yeniUrun.fiyat;

    urunler[urunSayisi] = yeniUrun;
    urunSayisi++;

    cout << "�r�n ba�ar�yla eklendi!" << endl;
}

void urunListele() {
    if (urunSayisi == 0) {
        cout << "Hen�z hi� �r�n eklenmemi�!" << endl;
        return;
    }

    std::cout << "�r�nler:" << endl;

    for (int i = 0; i < urunSayisi; i++) {
        cout << "�r�n Ad�: " << urunler[i].ad << endl;
        cout << "�r�n Bedeni: " << urunler[i].beden << endl;
        cout << "�r�n Rengi: " << urunler[i].renk << endl;
        cout << "�r�n Fiyat�: " << urunler[i].fiyat << endl;
        cout << endl;
    }
}

void urunAra() {
    if (urunSayisi == 0) {
        cout << "Hen�z hi� �r�n eklenmemi�!" <<endl;
        return;
    }

    string arananAd;
    cout << "Aranacak �r�n Ad�: ";
    cin >> arananAd;

    bool bulundu = false;

    for (int i = 0; i < urunSayisi; i++) {
        if (urunler[i].ad == arananAd) {
            cout << "�r�n Ad�: " << urunler[i].ad << endl;
            cout << "�r�n Bedeni: " << urunler[i].beden << endl;
            cout << "�r�n Rengi: " << urunler[i].renk << endl;
            cout << "�r�n Fiyat�: " << urunler[i].fiyat << endl;
            cout << endl;
            bulundu = true;
        }
    }

    if (!bulundu) {
      cout << "Aranan �r�n bulunamad�!" << endl;
    }
}

void urunSil() {
    if (urunSayisi == 0) {
        cout << "Hen�z hi� �r�n eklenmemi�!" << endl;
        return;
    }

    string silinecekAd;
    cout << "Silinecek �r�n Ad�: ";
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
        cout << "�r�n ba�ar�yla silindi!" << endl;
    } else {
        cout << "Silinecek �r�n bulunamad�!" << endl;
    }
}

