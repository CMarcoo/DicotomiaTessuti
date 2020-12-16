//
// Created by marco on 16/12/2020.
//
#include "chiavi.h"
#include <stdlib.h>
#include <stdio.h>

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