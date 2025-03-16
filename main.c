#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_HASTA 100

// Hasta bilgilerini tutan yapi
typedef struct {
    int id;
    char isim[50];
    int yas;
    char cinsiyet[10];
    int oncelik; // 1: Yuksek, 2: Orta, 3: Dusuk
    int recete_no;
} Hasta;

Hasta hastalar[MAX_HASTA];
int hasta_sayisi = 0;
int recete_sayaci = 1000;

// HL7 formatinda hasta kaydi olusturma
void hasta_ekle() {
    if (hasta_sayisi >= MAX_HASTA) {
        printf("Hasta kaydedilemiyor, maksimum kapasiteye ulasildi!\n");
        return;
    }

    Hasta yeni_hasta;
    yeni_hasta.id = hasta_sayisi + 1;
    printf("Hasta Adi: ");
    scanf("%s", yeni_hasta.isim);
    printf("Yas: ");
    scanf("%d", &yeni_hasta.yas);
    printf("Cinsiyet: ");
    scanf("%s", yeni_hasta.cinsiyet);
    printf("Oncelik (1: Yuksek, 2: Orta, 3: Dusuk): ");
    scanf("%d", &yeni_hasta.oncelik);

    yeni_hasta.recete_no = recete_sayaci++;
    hastalar[hasta_sayisi++] = yeni_hasta;

    printf("Hasta eklendi! HL7 Formatinda: ");
    printf("MSH|^~\&|ACIL|HOSPITAL|||\nPID|%d|%s|%d|%s|%d|%d\n",
        yeni_hasta.id, yeni_hasta.isim, yeni_hasta.yas,
        yeni_hasta.cinsiyet, yeni_hasta.oncelik, yeni_hasta.recete_no);
}

// Hastalari oncelik sirasina gore listeleme
void hasta_listele() {
    if (hasta_sayisi == 0) {
        printf("Listelenecek hasta yok!\n");
        return;
    }

    printf("ID | Isim | Yas | Cinsiyet | Oncelik | Recete No\n");
    printf("------------------------------------------------\n");
    for (int i = 0; i < hasta_sayisi; i++) {
        printf("%d | %s | %d | %s | %d | %d\n", hastalar[i].id, hastalar[i].isim,
               hastalar[i].yas, hastalar[i].cinsiyet, hastalar[i].oncelik,
               hastalar[i].recete_no);
    }
}

// Ana menu
void menu() {
    int secim;
    do {
        printf("\nAcil Servis Sistemi\n");
        printf("1. Hasta Ekle\n");
        printf("2. Hasta Listele\n");
        printf("3. Cikis\n");
        printf("Seciminiz: ");
        scanf("%d", &secim);

        switch (secim) {
            case 1:
                hasta_ekle();
                break;
            case 2:
                hasta_listele();
                break;
            case 3:
                printf("Cikis yapiliyor...\n");
                break;
            default:
                printf("Gecersiz secim!\n");
        }
    } while (secim != 3);
}

int main() {
    menu();
    return 0;
}
