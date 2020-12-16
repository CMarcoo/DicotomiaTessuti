//
// Created by marco on 16/12/2020.
//
#include "tessuti.h"

chiave *crea_chiave_no_sottotipi(const char *nome) {
    return crea_chiave(nome, NULL, 0);
}

void crea_tessuti() {
    lasso = crea_chiave_no_sottotipi("Lasso");
    denso = crea_chiave_no_sottotipi("Denso");
    cartilagineo = crea_chiave_no_sottotipi("Cartilagineo");
    osseo = crea_chiave_no_sottotipi("Osseo");
    emopoietico = crea_chiave_no_sottotipi("Emopoietico");
    linfoide = crea_chiave_no_sottotipi("Linfoide");
    adiposo = crea_chiave_no_sottotipi("Adiposo");

    specializzato = crea_chiave("Specializzato", raggruppa_chiavi(2, emopoietico, linfoide), 2),
            sostegno = crea_chiave("Sostegno", raggruppa_chiavi(2, osseo, cartilagineo), 2);
    propriamente_detto = crea_chiave("Propriamente Detto", raggruppa_chiavi(2, lasso, denso), 2);
    cellulare = crea_chiave("A Costituzione Cellulare", raggruppa_chiavi(1, adiposo), 1);

    connettivo = crea_chiave("Connettivo",
                             raggruppa_chiavi(4, specializzato, sostegno, propriamente_detto, cellulare),
                             4);
}