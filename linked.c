/*
Author: Roufiel Hadi
NIM: 241524028
Kelas: 1A
Prodi: Sarjana Terapan Teknik Informatika
Jurusan: Teknik Komputer dan Informatika
Politeknik Negeri Bandung
*/

#include "linked.h"
#include <stdlib.h>

boolean isEmpty(address p) {
    return (p == NULL);
}

void Create_Node(address *p) {
    *p = (address)malloc(sizeof(ElmtList));
    if (*p != NULL) {
        (*p)->next = NULL;
    }
}

void Isi_Node(address *p, infotype nilai) {
    if (*p != NULL) {
        (*p)->info = nilai;
        (*p)->next = NULL;
    }
}

void Tampil_List(address p) {
    while (p != NULL) {
        printf("%d -> ", p->info);
        p = p->next;
    }
    printf("NULL\n");
}

void Ins_Awal(address *p, address PNew) {
    if (PNew != NULL) {
        PNew->next = *p;
        *p = PNew;
    }
}

void Ins_Akhir(address *p, address PNew) {
    if (*p == NULL) {
        *p = PNew;
    } else {
        address temp = *p;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = PNew;
    }
}

address Search(address p, infotype nilai) {
    while (p != NULL) {
        if (p->info == nilai) {
            return p;
        }
        p = p->next;
    }
    return NULL;
}

void InsertAfter(address *pBef, address PNew) {
    if (*pBef != NULL && PNew != NULL) {
        PNew->next = (*pBef)->next;
        (*pBef)->next = PNew;
    }
}

void Del_Awal(address *p, infotype *X) {
    if (*p != NULL) {
        address temp = *p;
        *X = temp->info;
        *p = temp->next;
        free(temp);
    }
}

void Del_Akhir(address *p, infotype *X) {
    if (*p != NULL) {
        address temp = *p, prev = NULL;
        while (temp->next != NULL) {
            prev = temp;
            temp = temp->next;
        }
        *X = temp->info;
        if (prev != NULL) {
            prev->next = NULL;
        } else {
            *p = NULL;
        }
        free(temp);
    }
}

void Del_After(address *pBef, infotype *X) {
    if (*pBef != NULL && (*pBef)->next != NULL) {
        address temp = (*pBef)->next;
        *X = temp->info;
        (*pBef)->next = temp->next;
        free(temp);
    }
}

void DeAlokasi(address *p) {
    free(*p);
    *p = NULL;
}

int NbElmt(address p) {
    if (p == NULL) return 0;
    return 1 + NbElmt(p->next);
}

infotype Min(address p) {
    if (p == NULL) return 0;
    infotype minVal = p->info;
    while (p != NULL) {
        if (p->info < minVal) {
            minVal = p->info;
        }
        p = p->next;
    }
    return minVal;
}

infotype Rerata(address p) {
    if (p == NULL) return 0;
    int sum = 0, count = 0;
    while (p != NULL) {
        sum += p->info;
        count++;
        p = p->next;
    }
    return (count == 0) ? 0 : (sum / count);
}

address BalikList(address p) {
    address prev = NULL, current = p, next;
    while (current != NULL) {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }
    return prev;
}

