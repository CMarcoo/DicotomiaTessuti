//
// Created by marco on 16/12/2020.
//
#include "domanda.h"
#include <stdlib.h>
#include <stdio.h>

/**
 * Crea una domanda tramite i suoi valori;
 *
 * @param testo Il testo della domanda.
 * @param risposta_corretta La risposta corretta.
 * @return La domanda.
 */
domanda *crea_domanda(const char *testo) {
    domanda *ptr = NULL;

    if (testo == NULL) {
        _set_errno(TESTO_DOMANDA_NULLO);
        printf("Il testo della domanda era NULLO.");
    } else {
        ptr = malloc(sizeof(struct domanda) * 1);
        if (ptr == NULL) {
            _set_errno(ERRORE_CREAZIONE_DOMANDA);
            printf("Non si è riuscitia a creare una domanda");
        } else {
            ptr->testo = testo;
        }
    }
    return ptr;
}