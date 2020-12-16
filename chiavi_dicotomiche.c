//
// Created by marco on 16/12/2020.
//
#include "chiavi.h"
#include <stdlib.h>
#include <stdio.h>
#include <stdarg.h>

/**
 * Instanzia una chiave dicotomica da i suoi parametri.
 * @param nome Il nome della chiave dicotomica.
 * @param sottotipi I sottotipi della chiave,
 *        il parametro verrà automaticamente impostato a NULL
 *        se il numero di sottotipi equivale a 0.
 * @param num_sottotipi Il numero di sottotipi della chiave da creare
 * @return La chiave, o NULL se si sono riscontrati errori.
 */
chiave *crea_chiave(const char *nome, chiave **sottotipi, int num_sottotipi) {
    chiave *c;
    c = malloc(sizeof(struct chiave));
    if (c == NULL) {
        printf("Impossibile allocare memoria per chiave chiamata %s", nome);
    } else {
        c->nome = nome;
        c->num_sottotipi = num_sottotipi;
        if (num_sottotipi == 0) {
            c->sottotipi = NULL;
            if (sottotipi != NULL) {
                printf("La chiave %s sarebbe dovuta essere creata con sottotipi nulli.", nome);
            }
        } else {
            c->sottotipi = sottotipi;
        }
    }
    return c;
}

/**
 * Aggiungi una chiave alla lista di chiavi correntemente presenti.
 * @param chiave La chiave nella quale aggiungere.
 * @param da_aggiungere La chiave da aggiungere.
 */
void aggiungi_chiave(chiave *chiave, struct chiave *da_aggiungere) {
    if (da_aggiungere == NULL) {
        printf("Si è provato ad aggiungere una chiave nulla!");
    } else if (chiave == NULL) {
        printf("Si è provato ad aggiungere una chiave in un'altra chiave nulla (%s)!", da_aggiungere->nome);
    } else {
        int numero_sottotipi = chiave->num_sottotipi;
        int nuova_grandezza = numero_sottotipi + 1;
        void *nuovi_sottotipi = realloc(chiave->sottotipi, sizeof(struct chiave) * nuova_grandezza);
        if (nuovi_sottotipi == NULL) {
            printf("Qualcosa è andato storto nell'inserimento di %s in %s", da_aggiungere->nome, chiave->nome);
        } else {
            chiave->num_sottotipi = nuova_grandezza;
            chiave->sottotipi = ((struct chiave **) nuovi_sottotipi);
            chiave->sottotipi[nuova_grandezza - 1] = da_aggiungere;
        }
    }
}

/**
 * Raggruppa più chiavi in un unico gruppo;
 * @param chiave[] chiavi
 * @param num_chiavi numero di chiavi totali,
 * @return il gruppo.
 */
chiave **raggruppa_chiavi(int num_chiavi, ...) {
    va_list list;
    va_start(list, num_chiavi);

    chiave *ultima_chiave = NULL;
    chiave **chiavi = NULL;

    chiavi = malloc(sizeof(struct chiave) * num_chiavi);

    if (chiavi == NULL) {
        printf("Qualcosa è andato storto con l'allocazione di chiavi.");
    }

    for (int i = 0; i < num_chiavi; ++i) {
        ultima_chiave = va_arg(list, struct chiave*);
        if (ultima_chiave == NULL) {
            printf("Errore durante raggruppamento di chiave ad indice %d", i);
        } else {
            chiavi[i] = ultima_chiave;
        }
    }

    return chiavi;
}