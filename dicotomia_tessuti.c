//
// Created by marco on 16/12/2020.
//
#include <stdlib.h>
#include <stdio.h>
#include "chiavi.h"
#include "windows.h"
#include "tessuti.h"
#include <strings.h>

static inline void stampa_chiave_annidato(struct chiave *c) {
    stampa_chiave(c, 0);
}

chiave **gruppiGenerali;

chiave *chiave_corrente;
int numeroChiaveCorrente = 0;

void controllo_assegnazione_chiavi_generali(struct chiave *chiave, int indice) {
    if (chiave == NULL) {
        exit(ERRORE_CREAZIONE_CHIAVE);
    } else {
        gruppiGenerali[indice] = chiave;
    }
}

void alloca_gruppi_generali() {
    gruppiGenerali = malloc(sizeof(struct chiave) * TESSUTI_GENERALI);
    if (gruppiGenerali == NULL) {
        exit(ERRORE_RAGGRUPPAMENTO);
    } else {
        struct chiave *chiavi[4] = {nervoso, muscolare, epiteliale, connettivo};
        chiave_corrente = chiavi[0];
        for (int i = 0; i < TESSUTI_GENERALI; ++i) {
            controllo_assegnazione_chiavi_generali(chiavi[i], i);
        }
    }
}

LRESULT CALLBACK MainWindowProdecure(HWND, UINT, WPARAM, LPARAM);

HFONT hfont;
LOGFONT lf;

int APIENTRY WinMain(HINSTANCE hInst, HINSTANCE hInstPrev, PSTR cmdline, int cmdshow) {
    crea_tessuti();
    alloca_gruppi_generali();

    WNDCLASSW windowsClass = {0};

    windowsClass.hbrBackground = CreateSolidBrush(RGB(255, 205, 110));
    windowsClass.hCursor = LoadCursor(NULL, IDC_ARROW);
    windowsClass.hInstance = hInst;
    windowsClass.lpszClassName = L"Chiavi Dicotomiche";
    windowsClass.lpfnWndProc = MainWindowProdecure;

    if (!RegisterClassW(&windowsClass)) {
        return EXIT_FAILURE;
    }

    CreateWindowW(L"Chiavi Dicotomiche", L"Chiavi Dicotomiche",
                  WS_OVERLAPPEDWINDOW | WS_VISIBLE | WS_BORDER | WS_THICKFRAME,
                  100, 100, 500, 500,
                  NULL, NULL, NULL, NULL);

    MSG message = {0};

    while (GetMessage(&message, NULL, NULL, NULL)) {
        TranslateMessage(&message);
        DispatchMessage(&message);
    }

    return EXIT_SUCCESS;
}

#define YES_BUTTON 1
#define NO_BUTTON 2
#define TEXT_BOX 3

HWND yesButton;
HWND noButton;
HWND questionText;

void creaFinestre(HWND hwnd) {
    yesButton = CreateWindow(TEXT("BUTTON"), TEXT("Si"),
                             WS_CHILD | WS_VISIBLE,
                             110, 330, 120, 40,
                             hwnd, (HMENU) YES_BUTTON, NULL, NULL
    );

    noButton = CreateWindow(TEXT("BUTTON"), TEXT("No"),
                            WS_CHILD | WS_VISIBLE,
                            250, 330, 120, 40,
                            hwnd, (HMENU) NO_BUTTON, NULL, NULL
    );

    questionText = CreateWindow(TEXT("STATIC"), TEXT(chiave_corrente->domanda_chiave->testo),
                                WS_CHILD | WS_VISIBLE | WS_BORDER,
                                10, 10, 450, 300,
                                hwnd, (HMENU) TEXT_BOX, NULL, NULL
    );

    SendMessage(questionText, WM_SETFONT, (WPARAM) hfont, TRUE);
}

void clickSi(HWND main) {
    const char *tessuto_format = "Tessuto Identificato: %s";
    const char *domanda_format = "Categoria confermata: %s\nVerranno fatte ulteriori domande per identificare la tipologia specifica.";
    const char *nome_tessuto_corrente = chiave_corrente->nome;

    if (chiave_corrente->num_sottotipi != NO_SOTTOTIPI) {

        char *categoria_trovata = malloc(sizeof(char) * (strlen(domanda_format) + strlen(chiave_corrente->nome)));
        sprintf(categoria_trovata, domanda_format, chiave_corrente->nome);
        int buttonPress = MessageBox(main, TEXT(categoria_trovata), TEXT("Categoria identificata"),
                                     MB_YESNO | MB_ICONQUESTION);
        if (buttonPress == IDYES) {
            gruppiGenerali = chiave_corrente->sottotipi;
            numeroChiaveCorrente = 0;
            chiave_corrente = gruppiGenerali[0];
            SetWindowText(questionText, TEXT(chiave_corrente->domanda_chiave->testo));
        }
    } else {
        char *tessuto_trovato_msg = malloc(sizeof(char) * (strlen(tessuto_format) + strlen(nome_tessuto_corrente)));
        sprintf(tessuto_trovato_msg, tessuto_format, nome_tessuto_corrente);
        int buttonPress = MessageBox(main, TEXT(tessuto_trovato_msg), TEXT("Tessuto trovato"),
                                     MB_OK | MB_ICONINFORMATION);
        if (buttonPress == IDOK) {
            DestroyWindow(main);
        }
    }
}

void clickNo(HWND main) {
    int num_chiavi_totali_correnti = (chiave_corrente->num_sottotipi) - 1;
    if (num_chiavi_totali_correnti == numeroChiaveCorrente) {
        int buttonPress = MessageBox(main, TEXT("Tessuto assente"), TEXT("Non e' stato trovato alcun tessuto"),
                                     MB_OK | MB_ICONWARNING);
        if (buttonPress == IDOK) {
            DestroyWindow(main);
        }
    } else {
        numeroChiaveCorrente += 1;
        chiave_corrente = gruppiGenerali[numeroChiaveCorrente];
        SetWindowText(questionText, TEXT(chiave_corrente->domanda_chiave->testo));
    }
}

void clickPulsante(WPARAM wparam, HWND main) {
    switch (LOWORD(wparam)) {
        case YES_BUTTON:
            if (questionText != NULL) {
                clickSi(main);
            }
            break;
        case NO_BUTTON:
            if (questionText != NULL) {
                clickNo(main);
            }
            break;
        default:
            break;
    }
}

LRESULT CALLBACK MainWindowProdecure(HWND hwnd, UINT msg, WPARAM wparam, LPARAM lparam) {
    switch (msg) {
        case WM_CREATE:
            creaFinestre(hwnd);
            break;
        case WM_COMMAND:
            clickPulsante(wparam, hwnd);
            break;
        case WM_DESTROY:
            PostQuitMessage(EXIT_SUCCESS);
            break;
        default:
            break;
    }
    return DefWindowProcW(hwnd, msg, wparam, lparam);
}