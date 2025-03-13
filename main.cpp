/*
Author: Roufiel Hadi
NIM: 241524028
Kelas: 1A
Prodi: Sarjana Terapan Teknik Informatika
Jurusan: Teknik Komputer dan Informatika
Politeknik Negeri Bandung
*/

#include <stdio.h>
#include <stdlib.h>
#include "linked.h"

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char *argv[]) {
	infotype input;
    address List = NULL, PNew, PSearch;
    infotype X;
	
//Mata Kuliah Struktur Data Dan Algoritma
	printf("Hasil pengerjaan quiz 2 Mata Kuliah Struktur Data dan Algoritma\n");

/*1) masukan bilangan 7 sebagai elemen pertama {insert first}
> F.S. : elemen List = {7}*/
	printf("\nHasil soal nomor 1\n");
	input = 7;
    Create_Node(&List);
    Isi_Node(&List, input);
    Tampil_List(List);

/*2) masukan bilangan 11 sebagai elemen kedua {insert last}
> F.S. : elemen List = {7, 11}*/
	printf("\nHasil soal nomor 2\n");
	input = 11;
    Create_Node(&PNew);
    Isi_Node(&PNew, input);
    Ins_Akhir(&List, PNew);
    Tampil_List(List);
    
/*3) masukan bilangan 9 diantara bilangan 7 dan 11 {insert after}
> F.S. : elemen List = {7, 9, 11}*/
	printf("\nHasil soal nomor 3\n");
	input = 9;
    PSearch = Search(List, 7);
    if (PSearch != NULL) {
        Create_Node(&PNew);
        Isi_Node(&PNew, input);
        InsertAfter(&PSearch, PNew);
    }
    Tampil_List(List);
    
/*4) masukan bilangan 5 di awal list {insert first}
> F.S. : elemen List = {5, 7, 9, 11}*/
	printf("\nHasil soal nomor 4\n");
	input = 5;
    Create_Node(&PNew);
    Isi_Node(&PNew, input);
    Ins_Awal(&List, PNew);
    Tampil_List(List);
    
/*5) masukan bilangan 13 di akhir list {insert last}
> F.S. : elemen List = {5, 7, 9, 11, 13}*/
	printf("\nHasil soal nomor 5\n");
	input = 13;
    Create_Node(&PNew);
    Isi_Node(&PNew, input);
    Ins_Akhir(&List, PNew);
    Tampil_List(List);
    
/*6) hapus elemen terakhir (bilangan 13) pada list {delete last}
> F.S. : elemen List = {5, 7, 9, 11}*/
	printf("\nHasil soal nomor 6\n");
	Del_Akhir(&List, &input);
    Tampil_List(List);
    
/*7) hapus bilangan 7 pada list
> F.S. : elemen List = {5, 9, 11}*/
	printf("\nHasil soal nomor 7\n");
	PSearch = Search(List, 7);
    if (PSearch != NULL) {
        Del_After(&PSearch, &X);
    }
    Tampil_List(List);
    
/*8) hapus elemen pertama (bilangan 5) pada list {delete first}
> F.S. : elemen List = {9, 11}*/
	printf("\nHasil soal nomor 8\n");
	Del_Awal(&List, &X);
    Tampil_List(List);
    
/*9) hapus semua elemen list deret bilangan ganjil
> F.S. : elemen List = {}*/
	printf("\nHasil soal nomor 9\n");
	while (List != NULL) {
        if (List->info % 2 == 1) {
            Del_Awal(&List, &X);
        } else {
            break;
        }
    }
    Tampil_List(List);
	
	return 0;
}
