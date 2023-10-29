#include <iostream>
#include <vector>

using namespace std;

const int BOYUT = 3; // 3X3 TAHTA

// 3X3 tahta i�in fonksiyon olu�turuyorum
void tahtaYap(const vector<vector<char> >& tahta) {
    for (int i = 0; i < BOYUT; i++) {
        for (int j = 0; j < BOYUT; j++) {
            cout << tahta[i][j] << " ";
        }
        cout << endl;
    }
}

// Her i�lemden sonra oyunun bitip bitmedi�ini kontrol ediyorum
bool kontrolKazanc(const vector<vector<char> >& tahta, char oyuncu) {
    // Sat�rlar i�in
    for (int i = 0; i < BOYUT; i++) {
        if (tahta[i][0] == oyuncu && tahta[i][1] == oyuncu && tahta[i][2] == oyuncu) {
            return true;
        }
    }
    // S�tunlar i�in
    for (int j = 0; j < BOYUT; j++) {
        if (tahta[0][j] == oyuncu && tahta[1][j] == oyuncu && tahta[2][j] == oyuncu) {
            return true;
        }
    }
    // �apraz i�in
    if (tahta[0][0] == oyuncu && tahta[1][1] == oyuncu && tahta[2][2] == oyuncu) {
        return true;
    }
    if (tahta[0][2] == oyuncu && tahta[1][1] == oyuncu && tahta[2][0] == oyuncu) {
        return true;
    }
    return false;
}

int main() {
    
    vector<vector<char> > tahta(BOYUT, vector<char>(BOYUT, '0'));//TAHTAMI G�R�N�R HALE GET�RD�M
    
    char oyuncu1 = '1';
    
    while (true) {
        
        tahtaYap(tahta);
        
        int satir, sutun;
        cout << "Sirasi ile satir ve sutun olarak atamak istediginiz degeri giriniz: " << oyuncu1 << ":";//oyun ba�l�yor.
        cin >> satir >> sutun;
        satir--; // 0'dan ba�lad��� i�in girilen de�eri 1 azaltmam laz�m!!!!
        sutun--;
        if (satir < 0 || satir >= BOYUT || sutun < 0 || sutun >= BOYUT || tahta[satir][sutun] != '0') {
            cout << "Gecersiz hamle yaptiniz, Tekrar deneyiniz." << endl;
            continue;
        }
        tahta[satir][sutun] = oyuncu1;//tahtam�n yeni hali
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
            cout << "Berabere! Dostluk kazand�.." << endl;
            break;
        }
        oyuncu1 = (oyuncu1 == '1') ? '2' : '1';
    }
    return 0;
}

