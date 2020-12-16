//
// Created by marco on 16/12/2020.
//
#ifndef DICOTOMIATESSUTI_TESSUTI_H
#define DICOTOMIATESSUTI_TESSUTI_H

#include "chiavi.h"
#include <stdlib.h>

chiave *crea_chiave_no_sottotipi(domanda *domanda, const char *nome);

void crea_tessuti();

// definizioni dei nomi di tutti i gruppi di tessuti.

#define NOME_NERVOSO "Nervoso"
#define NOME_STRIATO "Striato"
#define NOME_CARDIACO "Cardiaco"
#define NOME_LISCIO "Liscio"
#define NOME_MUSCOLARE "Muscolare"

/*-------------------------------------------------------------------------*/

// gruppo specifico:

// chiave *lasso, *denso, *cartilagineo, *osseo, *emopoietico, *linfoide, *adiposo;

// gruppo intermedio:

// chiave *specializzato, *sostegno, *propriamente_detto, *cellulare;

// gruppo generale:

// chiave *connettivo;

/*-------------------------------------------------------------------------*/

// gruppo specifico: ASSENTE
// gruppo intermedio: ASSENTE
// gruppo generale:

chiave *nervoso;

/*-------------------------------------------------------------------------*/

//gruppo specifico: ASSENTE

// gruppo intermedio:

chiave *striato, *cardiaco, *liscio;

// gruppo generale:

chiave *muscolare;


/*-------------------------------------------------------------------------*/

#endif //DICOTOMIATESSUTI_TESSUTI_H
