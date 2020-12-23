//
// Created by marco on 16/12/2020.
//
#ifndef DICOTOMIATESSUTI_TESSUTI_H
#define DICOTOMIATESSUTI_TESSUTI_H

#include "chiavi.h"
#include <stdlib.h>

/**
 * Crea una chiave predefinita al non avere alcun sottotipo assegnato.
 * Questo non comportà però l'inabiltà di aggiungere sottotipi
 * in momenti successivi alla creazione del puntatore di questa chiave.
 *
 * @param domanda La domanda per questa chiave.
 * @param nome Il nome di questa chiave.
 * @return Il puntatore della chiave, o NULL se si sono riscontrati
 * errori durante la creazione. Verrà impostato un codice d'errore
 * nel caso ciò accadesse, questo codice è ottenibile tramite il metodo
 * _get_errno (https://docs.microsoft.com/it-it/cpp/c-runtime-library/reference/get-errno?view=msvc-160)
 */
chiave *crea_chiave_no_sottotipi(domanda *domanda, const char *nome);

/**
 * Crea tutti i tessuti usati dal programma.
 */
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
#define NOME_LASSO "Lasso"
#define NOME_CARTILAGINEO "Cartilagineo"
#define NOME_OSSEO "Osseo"
#define NOME_EMOPOIETICO "Emopoietico"
#define NOME_ADIPOSO "Adiposo"
#define NOME_FIBROSO "Fibroso"

// Sezione nomi t. epiteliale

#define NOME_EPITELIALE "Epiteliale"
#define NOME_MONOSTRATIFICATI "Monostratificato"
#define NOME_PLURISTRATIFICATI "Pluristratificati"
#define NOME_CILINDRICO "Cilindrico"
#define NOME_CUBICO "Cubico"
#define NOME_CUBICO_GHIANDOLARE "Ghiandolare"
#define NOME_PAVIMENTOSO_SEMPLICE "Pavimentoso Semplice"
#define NOME_CUBICO_SEMPLICE "Cubico Semplice"
#define NOME_CILINDRICO_SEMPLICE "Cilindrico Semplice"
#define NOME_PAVIMENTOSO_PLURISTRATIFICATO "Pavimentoso Pluristratificato"
#define NOME_CUBICO_PLURISTRATIFICATO "Cubico Pluristratificato"
#define NOME_CILINDRICO_PLURISTRATIFICATO "Cilindrico Pluristratificato"
#define NOME_CILINDRICO_PLURISTRATIFICATO_CILIATO "Cilindrico Pluristratificato Ciliato"
#define NOME_CILINDRICO_SEMPLICE_CILIATO "Cilindrico Semplice Ciliato"

/*-------------------------------------------------------------------------*/

// extra

chiave *cilindrico_pseudostratificato_ciliato, *cilindrico_pseudostratificato_fake,
*cilindrico_semplice_ciliato, *non_pavimentosi, *cilindro_fake, *cubico_semplice_fake,
*cubico_pluri_fake, *cubico_pluri_ghiandolare, *cubico_pluri, *cilindrico_pluristratificato,
*cilindrico_pluristratificato_fake, *cilindrico_pluristratificato_ciliato, *cilindrico_semplice,
*sottogruppo_pluri;

// gruppo specifico:

chiave *pavimentoso_semplice,
        *pavimentoso_pluristratificato,
        *cubico_ghiandolare, *cubico_semplice;

// altro gruppo

chiave *cilindrico , *cubico;

// gruppo intermedio:

chiave *monostratificati, *pluristratificati;

// gruppo generale:

chiave *epiteliale;

/*-------------------------------------------------------------------------*/

// gruppo specifico:

chiave *lasso, *cartilagineo, *osseo, *emopoietico, *adiposo, *fibroso;

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
