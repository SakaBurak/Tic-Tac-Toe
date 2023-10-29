#include <iostream>
#include <vector>

using namespace std;

const int BOYUT = 3; // 3X3 TAHTA

// 3X3 tahta için fonksiyon oluþturuyorum
void tahtaYap(const vector<vector<char> >& tahta) {
    for (int i = 0; i < BOYUT; i++) {
        for (int j = 0; j < BOYUT; j++) {
            cout << tahta[i][j] << " ";
        }
        cout << endl;
    }
}

// Her iþlemden sonra oyunun bitip bitmediðini kontrol ediyorum
bool kontrolKazanc(const vector<vector<char> >& tahta, char oyuncu) {
    // Satýrlar için
    for (int i = 0; i < BOYUT; i++) {
        if (tahta[i][0] == oyuncu && tahta[i][1] == oyuncu && tahta[i][2] == oyuncu) {
            return true;
        }
    }
    // Sütunlar için
    for (int j = 0; j < BOYUT; j++) {
        if (tahta[0][j] == oyuncu && tahta[1][j] == oyuncu && tahta[2][j] == oyuncu) {
            return true;
        }
    }
    // Çapraz için
    if (tahta[0][0] == oyuncu && tahta[1][1] == oyuncu && tahta[2][2] == oyuncu) {
        return true;
    }
    if (tahta[0][2] == oyuncu && tahta[1][1] == oyuncu && tahta[2][0] == oyuncu) {
        return true;
    }
    return false;
}

int main() {
    
    vector<vector<char> > tahta(BOYUT, vector<char>(BOYUT, '0'));//TAHTAMI GÖRÜNÜR HALE GETÝRDÝM
    
    char oyuncu1 = '1';
    
    while (true) {
        
        tahtaYap(tahta);
        
        int satir, sutun;
        cout << "Sirasi ile satir ve sutun olarak atamak istediginiz degeri giriniz: " << oyuncu1 << ":";//oyun baþlýyor.
        cin >> satir >> sutun;
        satir--; // 0'dan baþladýðý için girilen deðeri 1 azaltmam lazým!!!!
        sutun--;
        if (satir < 0 || satir >= BOYUT || sutun < 0 || sutun >= BOYUT || tahta[satir][sutun] != '0') {
            cout << "Gecersiz hamle yaptiniz, Tekrar deneyiniz." << endl;
            continue;
        }
        tahta[satir][sutun] = oyuncu1;//tahtamýn yeni hali
        if (kontrolKazanc(tahta, oyuncu1)) {
            cout << "Oyunu " << oyuncu1 << " Kazandi!" << endl;
            break;
        }
        bool beraberlik = true;
        for (int i = 0; i < BOYUT; i++) {
            for (int j = 0; j < BOYUT; j++) {
                if (tahta[i][j] == '0') {
                    beraberlik = false;
                    break;
                }
            }
            if (!beraberlik) {
                break;
            }
        }
        if (beraberlik) {
            cout << "Berabere! Dostluk kazandý.." << endl;
            break;
        }
        oyuncu1 = (oyuncu1 == '1') ? '2' : '1';
    }
    return 0;
}

