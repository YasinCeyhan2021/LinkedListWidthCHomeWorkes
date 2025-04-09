#include <stdio.h>

struct Ogrenci {
   char ad[50];
   char soyad[50];
   int yas;
   float not_ort;
}ogrn;
void main(){
	struct Ogrenci ogrenci1;
	ogrn ogrenci2 = {"Ahmet", "Yýlmaz", 22, 75.5};
	ogrenci1.ad = "Yasin";
	ogrenci1.soyad = "Ceyhan";
	ogrenci1.yas = 23;
	ogrenci1.not_ort = 75;
	
	
}
