//
// Created by marco on 16/12/2020.
//
#include "tessuti.h"
#include "domanda_tessuto.h"

chiave *crea_chiave_no_sottotipi(domanda *domanda, const char *nome) {
    return crea_chiave(domanda, nome, NULL, 0);
}

void crea_tessuti() {
    /*
    lasso = crea_chiave_no_sottotipi(, "Lasso");

    denso = crea_chiave_no_sottotipi("Denso");

    cartilagineo = crea_chiave_no_sottotipi("Cartilagineo");

    osseo = crea_chiave_no_sottotipi("Osseo");

    emopoietico = crea_chiave_no_sottotipi("Emopoietico");

    linfoide = crea_chiave_no_sottotipi("Linfoide");

    adiposo = crea_chiave_no_sottotipi("Adiposo");

    specializzato = crea_chiave("Specializzato", raggruppa_chiavi(2, emopoietico, linfoide), 2);

    sostegno = crea_chiave("Sostegno", raggruppa_chiavi(2, osseo, cartilagineo), 2);

    propriamente_detto = crea_chiave("Propriamente Detto", raggruppa_chiavi(2, lasso, denso), 2);

    cellulare = crea_chiave("A Costituzione Cellulare", raggruppa_chiavi(1, adiposo), 1);

    connettivo = crea_chiave("Connettivo", raggruppa_chiavi(4, specializzato, sostegno, propriamente_detto, cellulare),4);
    */

    /*-------------------------------------------------------------------------------------------------------------------*/

    nervoso = crea_chiave_no_sottotipi(crea_domanda(DOMANDA_NERVOSO), NOME_NERVOSO);

    /*-------------------------------------------------------------------------------------------------------------------*/

    striato = crea_chiave_no_sottotipi(crea_domanda(DOMANDA_STRIATO), NOME_STRIATO);

    cardiaco = crea_chiave_no_sottotipi(crea_domanda(DOMANDA_CARDIACO), NOME_CARDIACO);

    liscio = crea_chiave_no_sottotipi(crea_domanda(DOMANDA_LISCIO), NOME_LISCIO);

    muscolare = crea_chiave(crea_domanda(DOMANDA_MUSCOLARE), NOME_MUSCOLARE, raggruppa_chiavi(3, striato, cardiaco, liscio), 3);
}