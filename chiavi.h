//
// Created by marco on 16/12/2020.
//

#ifndef DICOTOMIATESSUTI_CHIAVI_H
#define DICOTOMIATESSUTI_CHIAVI_H

typedef struct chiave chiave; // pre-dichiarazione per consentire riferimenti a se-stesso nella struttura.

/**
 * Chiave dicotomica, rappresentazione:
 * nome : nome della chiave.
 * sottotipi : tutte le chiavi dicotomiche
 *             che sono sottoinsiemi della
 *             seguente.
 * num_sottotipi : numero di sottotipi.
 *
 * Se il numero di sottotipi passato è 0,
 * allora i sottotipi saranno un puntatore
 * di tipo NULL.
 */
typedef struct chiave {
    const char *nome;
    chiave **sottotipi;
    int num_sottotipi;
} chiave;

chiave *crea_chiave(const char *nome, chiave **sottotipi, int num_sottotipi);

#endif //DICOTOMIATESSUTI_CHIAVI_H
