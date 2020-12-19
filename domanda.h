//
// Created by marco on 16/12/2020.
//

#ifndef DICOTOMIATESSUTI_DOMANDA_H
#define DICOTOMIATESSUTI_DOMANDA_H

#include <stdbool.h>
#include "errori.h"

/**
 * Rappresentazione di una domanda.
 * La domanda contiene un array di caratteri,
 * ossia una stringa di testo che rappresenta
 * la domanda da effettuare all'utente finale.
 * Il valore booleano all'interno rappresenta
 * la risposta corretta.
 */
typedef struct domanda {
    const char *testo;
} domanda;

/**
 * Crea una domanda tramite i suoi valori;
 *
 * @param testo Il testo della domanda.
 * @param risposta_corretta La risposta corretta.
 * @return La domanda.
 */
domanda *crea_domanda(const char *testo);

#endif //DICOTOMIATESSUTI_DOMANDA_H
