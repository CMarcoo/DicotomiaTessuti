//
// Created by marco on 16/12/2020.
//
#include <stdlib.h>
#include <stdio.h>
#include "chiavi.h"
#include "tessuti.h"

void stampa_chiave(struct chiave *c, int livello);

static inline void stampa_chiave_annidato(struct chiave *c) {
    stampa_chiave(c, 0);
}

int main() {
    crea_tessuti();

    stampa_chiave_annidato(connettivo);

    return EXIT_SUCCESS;
}

void stampa_chiave(struct chiave *c, int livello) {
    for (int i = 0; i < livello; ++i) {
        printf(" ");
    }

    printf("Tessuto %s%c\n", c->nome, livello != 0 ? ' ' : ':');
    if (c->num_sottotipi == 0) {
    } else {
        for (int i = 0; i < c->num_sottotipi; ++i) {
            chiave *chiave_temp = c->sottotipi[i];
            stampa_chiave(chiave_temp, livello + 1);
        }
    }
}