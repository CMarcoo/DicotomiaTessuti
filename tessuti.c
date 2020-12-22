//
// Created by marco on 16/12/2020.
//
#include "tessuti.h"
#include "domanda_tessuto.h"

/**
 * Crea una chiave predefinita al non avere alcun sottotipo assegnato.
 * Questo non comportà però l'inabiltà di aggiungere sottotipi
 * in momenti successivi alla creazione del puntatore di questa chiave.
 *
 * @param domanda La domanda per questa chiave.
 * @param nome Il nome di questa chiave.
 * @return Il puntatore della chiave, o NULL se si sono riscontrati
 * errori durante la creazione. Verrà impostato un codice d'errore
 * nel caso ciò accadesse, questo codice è ottenibile tramite il metodo
 * _get_errno (https://docs.microsoft.com/it-it/cpp/c-runtime-library/reference/get-errno?view=msvc-160)
 */
chiave *crea_chiave_no_sottotipi(domanda *domanda, const char *nome) {
    return crea_chiave(domanda, nome, NULL, 0);
}

chiave *cilindrico_pseudostratificato_fake;

/**
 * Instanzia tutti i tessuti disponibili in "tessuti.h"
 */
void crea_tessuti() {

    pavimentoso_semplice = crea_chiave_no_sottotipi(crea_domanda(DOMANDA_PAVIMENTOSO_SEMPLICE),
                                                    NOME_PAVIMENTOSO_SEMPLICE);

    cilindrico_pseudostratificato_ciliato = crea_chiave_no_sottotipi(
            crea_domanda(DOMANDA_CILINDRICO_PSEUDOSTRATIFICATO_CILIATO), NOME_CILINDRICO_PSEUDOSTRATIFICATO_CILIATO);


    cubico_semplice = crea_chiave_no_sottotipi(crea_domanda(DOMANDA_CUBICO_SEMPLICE), NOME_CUBICO_SEMPLICE);

    cilindrico_semplice = crea_chiave_no_sottotipi(crea_domanda(DOMANDA_CILINDRICO_SEMPLICE), NOME_CILINDRICO_SEMPLICE);

    cilindrico_semplice_ciliato = crea_chiave_no_sottotipi(crea_domanda(DOMANDA_CILINDRICO_SEMPLICE_CILIATO),
                                                           NOME_CILINDRICO_SEMPLICE_CILIATO);

    pavimentoso_pluristratificato = crea_chiave(crea_domanda(DOMANDA_PAVIMENTOSO_PLURISTRATIFICATO),
                                                NOME_PAVIMENTOSO_PLURISTRATIFICATO,
                                                raggruppa_chiavi(1, cilindrico_pseudostratificato_ciliato), 1);

    cubico_pluristratificato = crea_chiave_no_sottotipi(crea_domanda(DOMANDA_CUBICO_PLURISTRATIFICATO),
                                                        NOME_CUBICO_PLURISTRATIFICATO);

    cubico_ghiandolare = crea_chiave_no_sottotipi(crea_domanda(DOMANDA_CUBICO_GHIANDOALARE), NOME_CUBICO_GHIANDOLARE);

    cubico = crea_chiave(crea_domanda(DOMANDA_CUBICO), NOME_CUBICO,
                         raggruppa_chiavi(2, cubico_ghiandolare, cubico_pluristratificato), 2);

    cilindrico_pseudostratificato_fake = crea_chiave_no_sottotipi(
            crea_domanda(DOMANDA_CILINDRICO_PSEUDOSTRATIFICATO),
            NOME_CILINDRICO_PSEUDOSTRATIFICATO);

    cilindrico_pseudostratificato = crea_chiave(crea_domanda(DOMANDA_CILINDRICO_PSEUDOSTRATIFICATO),
                                                NOME_CILINDRICO_PSEUDOSTRATIFICATO,
                                                raggruppa_chiavi(2, cilindrico_pseudostratificato_ciliato,
                                                                 cilindrico_pseudostratificato_fake), 2);


    cilindrico = crea_chiave(crea_domanda(DOMANDA_CILINDRICO), NOME_CILINDRICO,
                             raggruppa_chiavi(2, cilindrico_pseudostratificato, cubico), 2);

    non_pavimentosi = crea_chiave(crea_domanda(DOMANDA_CILINDRICO), NOME_CILINDRICO,
                                  raggruppa_chiavi(2,
                                                   crea_chiave(crea_domanda(DOMANDA_CILINDRICO_SEMPLICE),
                                                               NOME_CILINDRICO_SEMPLICE,
                                                               raggruppa_chiavi(2, cilindrico_semplice,
                                                                                cilindrico_semplice_ciliato), 2),
                                                   crea_chiave(crea_domanda(DOMANDA_CUBICO_SEMPLICE),
                                                               NOME_CUBICO_SEMPLICE,
                                                               raggruppa_chiavi(2, cubico_semplice, cubico_ghiandolare),
                                                               2)
                                  ), 2);

    monostratificati = crea_chiave(crea_domanda(DOMANDA_MONOSTRATIFICATI), NOME_MONOSTRATIFICATI,
                                   raggruppa_chiavi(2, pavimentoso_semplice, non_pavimentosi), 2);

    pluristratificati = crea_chiave(crea_domanda(DOMANDA_PLURISTRATIFICATI), NOME_PLURISTRATIFICATI,
                                    raggruppa_chiavi(2, pavimentoso_pluristratificato, cilindrico), 2
    );

    epiteliale = crea_chiave(crea_domanda(DOMANDA_EPITELIALE), NOME_EPITELIALE,
                             raggruppa_chiavi(2, monostratificati, pluristratificati), 2);

    /*-------------------------------------------------------------------------------------------------------------------*/

    lasso = crea_chiave_no_sottotipi(crea_domanda(DOMANDA_LASSO), NOME_LASSO);

    cartilagineo = crea_chiave_no_sottotipi(crea_domanda(DOMANDA_CARTILAGINEO), NOME_CARTILAGINEO);

    osseo = crea_chiave_no_sottotipi(crea_domanda(DOMANDA_OSSEO), NOME_OSSEO);

    emopoietico = crea_chiave_no_sottotipi(crea_domanda(DOMANDA_EMOPOIETICO), NOME_EMOPOIETICO);

    adiposo = crea_chiave_no_sottotipi(crea_domanda(DOMANDA_ADIPOSO), NOME_ADIPOSO);

    fibroso = crea_chiave_no_sottotipi(crea_domanda(DOMANDA_FIBROSO), NOME_FIBROSO);

    connettivo = crea_chiave(crea_domanda(DOMANA_CONNETTIVO), NOME_CONNETTIVO,
                             raggruppa_chiavi(6, osseo, emopoietico, cartilagineo, adiposo, fibroso, lasso), 6);

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