//
// Created by marco on 16/12/2020.
//
#ifndef DICOTOMIATESSUTI_TESSUTI_H
#define DICOTOMIATESSUTI_TESSUTI_H

#include "chiavi.h"
#include <stdlib.h>

chiave *crea_chiave_no_sottotipi(const char *nome);

void crea_tessuti();

chiave
        *lasso,
        *denso,
        *cartilagineo,
        *osseo,
        *emopoietico,
        *linfoide,
        *
        adiposo;

chiave *connettivo;

chiave *specializzato, *sostegno, *propriamente_detto, *cellulare;

#endif //DICOTOMIATESSUTI_TESSUTI_H
