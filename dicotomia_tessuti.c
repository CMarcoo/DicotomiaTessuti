//
// Created by marco on 16/12/2020.
//
#include <stdlib.h>
#include <stdio.h>
#include "chiavi.h"

int main() {

    chiave *tessuto_nervoso_test = crea_chiave("Tessuto Nervoso", NULL, 0);

    printf("Tessuto: %s\n Numero Sottotipi: %d\n", tessuto_nervoso_test->nome, tessuto_nervoso_test->num_sottotipi);

    return EXIT_SUCCESS;
}
