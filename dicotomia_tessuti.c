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

HFONT hfont;
LOGFONT lf;

#define YES_BUTTON 1
#define NO_BUTTON 2
#define TEXT_BOX 3
#define BOX_IMG 4

HWND principale;
HWND bottoneSi;
HWND bottoneNo;
HWND testoDomanda;
HWND box_img;
HBITMAP img_tessuto;
chiave **gruppiGenerali;
chiave *chiave_corrente;
int num_chiave_corrente = 0;
int numero_img_corrente = 1;

/*-----------------------------------------------------------------------------------------*/

LRESULT CALLBACK MainWindowProdecure(HWND, UINT, WPARAM, LPARAM);

void controllo_assegnazione_chiavi_generali(struct chiave *, int);

void alloca_gruppi_generali();

void clickSi(HWND);

void clickNo(HWND);

void clickPulsante(WPARAM, HWND);

void carica_immagine(HWND, int, bool);

int numero_cifre(int);

void crea_finestre(HWND);

void aggiorna_immagine();

/*-----------------------------------------------------------------------------------------*/

LRESULT CALLBACK MainWindowProdecure(HWND hwnd, UINT msg, WPARAM wparam, LPARAM lparam) {
    switch (msg) {
        case WM_CREATE:
            carica_immagine(hwnd, 1, true);
            aggiorna_immagine();
            crea_finestre(hwnd);
            break;
        case WM_COMMAND:
            clickPulsante(wparam, hwnd);
            break;
        case WM_DESTROY:
            PostQuitMessage(EXIT_SUCCESS);
            break;
        default:
            return DefWindowProcW(hwnd, msg, wparam, lparam);
    }

    return 0;
}

int APIENTRY WinMain(HINSTANCE hInst, HINSTANCE hInstPrev, PSTR cmdline, int cmdshow) {
    crea_tessuti();
    alloca_gruppi_generali();

    WNDCLASSW windowsClass = {0};

    windowsClass.hbrBackground = CreateSolidBrush(RGB(205, 235, 230));
    windowsClass.hCursor = LoadCursor(NULL, IDC_ARROW);
    windowsClass.hInstance = hInst;
    windowsClass.lpszClassName = L"Chiavi Dicotomiche";
    windowsClass.lpfnWndProc = MainWindowProdecure;

    if (!RegisterClassW(&windowsClass)) {
        return EXIT_FAILURE;
    }

    principale = CreateWindowW(L"Chiavi Dicotomiche", L"Chiavi Dicotomiche",
                               WS_OVERLAPPEDWINDOW | WS_VISIBLE | WS_BORDER | WS_THICKFRAME,
                               100, 100, 500, 500,
                               NULL, NULL, NULL, NULL);

    MSG message = {0};

    while (GetMessage(&message, NULL, (UINT) NULL, (UINT) NULL)) {
        TranslateMessage(&message);
        DispatchMessage(&message);
    }

    return EXIT_SUCCESS;
}

void crea_finestre(HWND hwnd) {
    bottoneSi = CreateWindow(TEXT("BUTTON"), TEXT("Si"),
                             WS_CHILD | WS_VISIBLE,
                             110, 400, 120, 40,
                             hwnd, (HMENU) YES_BUTTON, NULL, NULL
    );

    bottoneNo = CreateWindow(TEXT("BUTTON"), TEXT("No"),
                             WS_CHILD | WS_VISIBLE,
                             250, 400, 120, 40,
                             hwnd, (HMENU) NO_BUTTON, NULL, NULL
    );

    testoDomanda = CreateWindow(TEXT("STATIC"), TEXT(chiave_corrente->domanda_chiave->testo),
                                WS_CHILD | WS_VISIBLE | WS_BORDER,
                                10, 10, 180, 80,
                                hwnd, (HMENU) TEXT_BOX, NULL, NULL
    );

    box_img = CreateWindowW(L"STATIC", NULL,
                            WS_CHILD | WS_VISIBLE | WS_BORDER | SS_BITMAP,
                            10, 95, 450, 300,
                            hwnd, (HMENU) BOX_IMG, NULL, NULL
    );

    aggiorna_immagine();
}

void aggiorna_immagine() {
    SendMessage(box_img, STM_SETIMAGE, IMAGE_BITMAP, (LPARAM) img_tessuto);
}

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
            num_chiave_corrente = 0;
            chiave_corrente = gruppiGenerali[0];
            SetWindowText(testoDomanda, TEXT(chiave_corrente->domanda_chiave->testo));
        }
    } else {
        char *tessuto_trovato_msg = malloc(sizeof(char) * (strlen(tessuto_format) + strlen(nome_tessuto_corrente)));
        sprintf(tessuto_trovato_msg, tessuto_format, nome_tessuto_corrente);
        int buttonPress = MessageBox(main, TEXT(tessuto_trovato_msg), TEXT("Tessuto trovato"),
                                     MB_OK | MB_ICONINFORMATION);
        if (buttonPress == IDOK) {
            numero_img_corrente += 1;
            carica_immagine(main, numero_img_corrente, true);
            aggiorna_immagine();

            num_chiave_corrente = 0;
            alloca_gruppi_generali();
            SetWindowText(testoDomanda, TEXT(chiave_corrente->domanda_chiave->testo));
            // DestroyWindow(main);
        }
    }
}

void clickNo(HWND main) {
    int num_chiavi_totali_correnti = (chiave_corrente->num_sottotipi) - 1;
    if (num_chiavi_totali_correnti == num_chiave_corrente) {
        int buttonPress = MessageBox(main, TEXT("Tessuto assente"), TEXT("Non e' stato trovato alcun tessuto"),
                                     MB_OK | MB_ICONWARNING);
        if (buttonPress == IDOK) {
            DestroyWindow(main);
        }
    } else {
        num_chiave_corrente += 1;
        chiave_corrente = gruppiGenerali[num_chiave_corrente];
        SetWindowText(testoDomanda, TEXT(chiave_corrente->domanda_chiave->testo));
    }
}

void clickPulsante(WPARAM wparam, HWND main) {
    switch (LOWORD(wparam)) {
        case YES_BUTTON:
            if (testoDomanda != NULL) {
                clickSi(main);
            }
            break;
        case NO_BUTTON:
            if (testoDomanda != NULL) {
                clickNo(main);
            }
            break;
        default:
            break;
    }
}

int numero_cifre(int numero) {
    int n = numero;
    int c = 0;
    while (n != 0) {
        n /= 10;
        c++;
    }
    return c;
}

void carica_immagine(HWND hwnd, int numero_immagine, bool termina) {
    const char *formato_img = "%d.bmp";
    char *nome_immagine = malloc(sizeof(char) * (strlen(formato_img) + numero_cifre(numero_immagine)));
    sprintf(nome_immagine, formato_img, numero_immagine);
    img_tessuto = (HBITMAP) LoadImage(NULL, nome_immagine, IMAGE_BITMAP, 450, 300, LR_LOADFROMFILE);
    if (img_tessuto == NULL) {
        const char *format_errore = "Impossibile trovare immagine: <<%s>>\n Errore %lu";
        char *errore = malloc(sizeof(char) * (strlen(format_errore) + strlen(nome_immagine)));
        sprintf(errore, format_errore, nome_immagine, GetLastError());
        MessageBox(hwnd, TEXT(errore), TEXT("Errore immagine"), MB_OK | MB_ICONWARNING);
        carica_immagine(hwnd, numero_immagine + 1, true);
        if (termina) {
            exit(IMMAGINE_ASSENTE);
        }
    }
}
