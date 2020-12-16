//
// Created by marco on 16/12/2020.
//
#include <stdlib.h>
#include <stdio.h>
#include "chiavi.h"

chiave *crea_chiave_no_sottotipi(const char *nome);

void stampa_chiave(struct chiave *c, int livello);

static inline void stampa_chiave_annidato(struct chiave *c) {
    stampa_chiave(c, 0);
}

chiave *connettivo;
chiave *specializzato, *sostegno, *propriamente_detto, *cellulare;
chiave *lasso, *denso, *cartilagineo, *osseo, *emopoietico, *linfoide, *adiposo;

int main() {

    lasso = crea_chiave_no_sottotipi("Lasso");
    denso = crea_chiave_no_sottotipi("Denso");
    cartilagineo = crea_chiave_no_sottotipi("Cartilagineo");
    osseo = crea_chiave_no_sottotipi("Osseo");
    emopoietico = crea_chiave_no_sottotipi("Emopoietico");
    linfoide = crea_chiave_no_sottotipi("Linfoide");
    adiposo = crea_chiave_no_sottotipi("Adiposo");

    specializzato = crea_chiave("Specializzato", raggruppa_chiavi(2, emopoietico, linfoide), 2);
    sostegno = crea_chiave("Sostegno", raggruppa_chiavi(2, osseo, cartilagineo), 2);
    propriamente_detto = crea_chiave("Propriamente Detto", raggruppa_chiavi(2, lasso, denso), 2);
    cellulare = crea_chiave("Costituzione cellulare", raggruppa_chiavi(1, adiposo), 1);

    connettivo = crea_chiave("Connettivo", raggruppa_chiavi(4, specializzato, sostegno, propriamente_detto, cellulare),
                             4);
    stampa_chiave_annidato(connettivo);

    return EXIT_SUCCESS;
}

chiave *crea_chiave_no_sottotipi(const char *nome) {
    return crea_chiave(nome, NULL, 0);
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