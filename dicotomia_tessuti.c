//
// Created by marco on 16/12/2020.
//
#include <stdlib.h>
#include <stdio.h>
#include "chiavi.h"
#include "tessuti.h"

static inline void stampa_chiave_annidato(struct chiave *c) {
    stampa_chiave(c, 0);
}

int main() {
    crea_tessuti();
    stampa_chiave_annidato(muscolare);

    return EXIT_SUCCESS;
}