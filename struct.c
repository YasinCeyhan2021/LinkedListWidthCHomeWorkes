#include <stdio.h>
#include <string.h>
#include<locale.h>

struct Ogrenci {
   char ad[50];
   char soyad[50];
   int yas;
   float not_ort;
};

int main() {
	setlocale(LC_ALL, "Turkish"); 
    struct Ogrenci ogrenci1;
    struct Ogrenci ogrenci2 = {"Ahmet", "Yýlmaz", 22, 75.5};

    // String kopyalama
    strcpy(ogrenci1.ad, "Yasin");
    strcpy(ogrenci1.soyad, "Ceyhan");
    ogrenci1.yas = 23;
    ogrenci1.not_ort = 75;

    // Yazdýrma
    printf("Ogrenci1 -> %s %s | Yas: %d | Not Ort: %.2f\n", 
            ogrenci1.ad, ogrenci1.soyad, ogrenci1.yas, ogrenci1.not_ort);

    printf("Ogrenci2 -> %s %s | Yas: %d | Not Ort: %.2f\n", 
            ogrenci2.ad, ogrenci2.soyad, ogrenci2.yas, ogrenci2.not_ort);

    return 0;
}

