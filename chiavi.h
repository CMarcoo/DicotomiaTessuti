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

/**
 * Instanzia una chiave dicotomica da i suoi parametri.
 * @param nome Il nome della chiave dicotomica.
 * @param sottotipi I sottotipi della chiave,
 *        il parametro verrà automaticamente impostato a NULL
 *        se il numero di sottotipi equivale a 0.
 * @param num_sottotipi Il numero di sottotipi della chiave da creare
 * @return La chiave, o NULL se si sono riscontrati errori.
 */
chiave *crea_chiave(const char *nome, chiave **sottotipi, int num_sottotipi);

/**
 * Aggiungi una chiave alla lista di chiavi correntemente presenti.
 * @param chiave La chiave nella quale aggiungere.
 * @param da_aggiungere La chiave da aggiungere.
 */
void aggiungi_chiave(chiave *chiave, struct chiave *da_aggiungere);

/**
 * Raggruppa più chiavi in un unico gruppo;
 * @param chiave[] chiavi
 * @param num_chiavi numero di chiavi totali,
 * @return il gruppo.
 */
chiave **raggruppa_chiavi(int num_chiavi, ...);

#endif //DICOTOMIATESSUTI_CHIAVI_H
