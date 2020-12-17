//
// Created by marco on 16/12/2020.
//
#include "tessuti.h"
#include "domanda_tessuto.h"

chiave *crea_chiave_no_sottotipi(domanda *domanda, const char *nome) {
    return crea_chiave(domanda, nome, NULL, 0);
}

void crea_tessuti() {

    semplice = crea_chiave_no_sottotipi(crea_domanda(DOMANDA_SEMPLICE), NOME_SEMPLICE);

    pluristratificato = crea_chiave_no_sottotipi(crea_domanda(DOMANDA_PLURISTRATIFICATO), NOME_PLURISTRATIFICATO);

    esocrino = crea_chiave_no_sottotipi(crea_domanda(DOMANDA_ESOCRINO), NOME_ESOCRINO);

    endocrino = crea_chiave_no_sottotipi(crea_domanda(DOMANDA_ENDOCRINO), NOME_ENDOCRINO);

    ghiandolare = crea_chiave(crea_domanda(DOMANDA_GHIANDOLARI), NOME_GHIANDOLARI,
                              raggruppa_chiavi(2, endocrino, esocrino), 2);

    rivestimento = crea_chiave(crea_domanda(DOMANDA_RIVESTIMENTO), NOME_RIVESTIMENTO,
                               raggruppa_chiavi(2, semplice, pluristratificato), 2);

    epiteliale = crea_chiave(crea_domanda(DOMANDA_EPITELIALE), NOME_EPITELIALE,
                             raggruppa_chiavi(2, ghiandolare, rivestimento), 2);

    /*-------------------------------------------------------------------------------------------------------------------*/

    lasso = crea_chiave_no_sottotipi(crea_domanda(DOMANDA_LASSO), NOME_LASSO);

    denso = crea_chiave_no_sottotipi(crea_domanda(DOMANDA_DENSO), NOME_DENSO);

    cartilagineo = crea_chiave_no_sottotipi(crea_domanda(DOMANDA_CARTILAGINEO), NOME_CARTILAGINEO);

    osseo = crea_chiave_no_sottotipi(crea_domanda(DOMANDA_OSSEO), NOME_OSSEO);

    emopoietico = crea_chiave_no_sottotipi(crea_domanda(DOMANDA_EMOPOIETICO), NOME_EMOPOIETICO);

    linfoide = crea_chiave_no_sottotipi(crea_domanda(DOMANDA_LINFOIDE), NOME_LINFOIDE);

    adiposo = crea_chiave_no_sottotipi(crea_domanda(DOMANDA_ADIPOSO), NOME_ADIPOSO);

    specializzato = crea_chiave(crea_domanda(DOMANDA_SPECIALIZZATO), NOME_SPECIALIZZATO,
                                raggruppa_chiavi(2, emopoietico, linfoide), 2);

    sostegno = crea_chiave(crea_domanda(DOMANDA_SOSTEGNO), NOME_SOSTEGNO, raggruppa_chiavi(2, osseo, cartilagineo), 2);

    propriamente_detto = crea_chiave(crea_domanda(DOMANDA_PROPRIAMENTE_DETTO), NOME_PROPRIAMENTE_DETTO,
                                     raggruppa_chiavi(2, lasso, denso), 2);

    cellulare = crea_chiave(crea_domanda(DOMANDA_CELLULARE), NOME_CELLULARE, raggruppa_chiavi(1, adiposo),
                            1);

    connettivo = crea_chiave(crea_domanda(DOMANA_CONNETTIVO), NOME_CONNETTIVO,
                             raggruppa_chiavi(4, specializzato, sostegno, propriamente_detto, cellulare), 4);

    /*-------------------------------------------------------------------------------------------------------------------*/

    nervoso = crea_chiave_no_sottotipi(crea_domanda(DOMANDA_NERVOSO), NOME_NERVOSO);

    /*-------------------------------------------------------------------------------------------------------------------*/

    striato = crea_chiave_no_sottotipi(crea_domanda(DOMANDA_STRIATO), NOME_STRIATO);

    cardiaco = crea_chiave_no_sottotipi(crea_domanda(DOMANDA_CARDIACO), NOME_CARDIACO);

    liscio = crea_chiave_no_sottotipi(crea_domanda(DOMANDA_LISCIO), NOME_LISCIO);

    muscolare = crea_chiave(crea_domanda(DOMANDA_MUSCOLARE), NOME_MUSCOLARE,
                            raggruppa_chiavi(3, striato, cardiaco, liscio), 3);

    /*-------------------------------------------------------------------------------------------------------------------*/

}