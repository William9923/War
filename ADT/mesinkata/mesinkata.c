#include "./mesinkata.h"
#include <stdio.h>

boolean EndKata;
Kata CKata;

/* Definisi Mesin Kata: Model Akuisisi Versi I */

void IgnoreBlank()
/* Mengabaikan satu atau beberapa BLANK
   I.S. : CC sembarang
   F.S. : CC ≠ BLANK atau CC = MARK */
{
    while ((CC == BLANK || CC == newline) && CC != MARK) {
        ADV();
    }
}

void IgnoreBlankIn()
{
  while ((CC == BLANK) && CC != MARK) {
        ADV();
    }
}

void STARTKATA(char s[])
/* I.S. : CC sembarang
   F.S. : EndKata = true, dan CC = MARK;
          atau EndKata = false, CKata adalah kata yang sudah diakuisisi,
          CC karakter pertama sesudah karakter terakhir kata */
{
    START(s);
    IgnoreBlank();
    if (CC == MARK) {
        EndKata = true;
    } else {
        EndKata = false;
        SalinKata();
    }
}

void STARTKATAIn(){
  STARTIn();
  IgnoreBlankIn();
  if (CC == newline) {
    EndKata = true;
  } else {
    EndKata = false;
    SalinKataIn();
  }
}

void ADVKATA()
/* I.S. : CC adalah karakter pertama kata yang akan diakuisisi
   F.S. : CKata adalah kata terakhir yang sudah diakuisisi,
          CC adalah karakter pertama dari kata berikutnya, mungkin MARK
          Jika CC = MARK, EndKata = true.
   Proses : Akuisisi kata menggunakan procedure SalinKata */
{
    IgnoreBlank();
    if (CC == MARK) {
        EndKata = true;
    } else {
        SalinKata();
    }
    IgnoreBlank();
}

void ADVKATAIn()
/* I.S. : CC adalah karakter pertama kata yang akan diakuisisi
   F.S. : CKata adalah kata terakhir yang sudah diakuisisi,
          CC adalah karakter pertama dari kata berikutnya, mungkin MARK
          Jika CC = MARK, EndKata = true.
   Proses : Akuisisi kata menggunakan procedure SalinKata */
{
    //IgnoreBlank();
    if (CC == newline) {
        EndKata = true;
    } else {
        SalinKataIn();
    }
    IgnoreBlankIn();
}


void SalinKata()
/* Mengakuisisi kata, menyimpan dalam CKata
   I.S. : CC adalah karakter pertama dari kata
   F.S. : CKata berisi kata yang sudah diakuisisi;
          CC = BLANK atau CC = MARK;
          CC adalah karakter sesudah karakter terakhir yang diakuisisi.
          Jika panjang kata melebihi NMax, maka sisa kata "dipotong" */
{
    int i = 0;
    IgnoreBlank();

    while (CC != MARK && CC != BLANK && i < NMax && CC != newline) {
        i++;
        CKata.TabKata[i] = CC;
        ADV();
    }
    CKata.Length = i;
}

void SalinKataIn()
{
  int i = 0;
  IgnoreBlankIn();
  while(CC != newline && CC != BLANK && i < NMax) {
    i++;
    CKata.TabKata[i] = CC;
    ADV();
  }
  CKata.Length = i;
}