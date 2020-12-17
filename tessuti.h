//
// Created by marco on 16/12/2020.
//
#ifndef DICOTOMIATESSUTI_TESSUTI_H
#define DICOTOMIATESSUTI_TESSUTI_H

#include "chiavi.h"
#include <stdlib.h>

chiave *crea_chiave_no_sottotipi(domanda *domanda, const char *nome);

void crea_tessuti();

#define TESSUTI_GENERALI 4

// definizioni dei nomi di tutti i gruppi di tessuti.

// Sezione nomi t. nervosi

#define NOME_NERVOSO "Nervoso"

// Sezione nomi t. muscolari

#define NOME_MUSCOLARE "Muscolare"
#define NOME_STRIATO "Striato"
#define NOME_CARDIACO "Cardiaco"
#define NOME_LISCIO "Liscio"

// Sezione nomi t. connettivi

#define NOME_CONNETTIVO "Connettivo"
#define NOME_SPECIALIZZATO "Specializzato"
#define NOME_SOSTEGNO "Sostegno"
#define NOME_PROPRIAMENTE_DETTO "Propriamente Detto"
#define NOME_CELLULARE "A costituzione cellulare"
#define NOME_LASSO "Lasso"
#define NOME_DENSO "Denso"
#define NOME_CARTILAGINEO "Cartilagineo"
#define NOME_OSSEO "Osseo"
#define NOME_EMOPOIETICO "Emopoietico"
#define NOME_LINFOIDE "Linfoide"
#define NOME_ADIPOSO "Adiposo"

// Sezione nomi t. epiteliale

#define NOME_EPITELIALE "Epiteliale"
#define NOME_RIVESTIMENTO "Rivestimento"
#define NOME_GHIANDOLARI "Ghiandolari"
#define NOME_SEMPLICE "Semplice"
#define NOME_PLURISTRATIFICATO "Pluristratificato"
#define NOME_ESOCRINO "Esocrino"
#define NOME_ENDOCRINO "Endocrino"

/*-------------------------------------------------------------------------*/

// gruppo specifico:

chiave *semplice, *pluristratificato, *esocrino, *endocrino;

// gruppo intermedio:

chiave *rivestimento, *ghiandolare;

// gruppo generale:

chiave *epiteliale;

/*-------------------------------------------------------------------------*/

// gruppo specifico:

chiave *lasso, *denso, *cartilagineo, *osseo, *emopoietico, *linfoide, *adiposo;

// gruppo intermedio:

chiave *specializzato, *sostegno, *propriamente_detto, *cellulare;

// gruppo generale:

chiave *connettivo;

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
