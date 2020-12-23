//
// Creato da Marco il 16/12/2020.
// Contribuenti: Gabriele, Emiliano, Andrea, Luca.
//
#include <stdlib.h>
#include <stdio.h>
#include "chiavi.h"
#include "windows.h"
#include "tessuti.h"
#include <strings.h>

#define YES_BUTTON 1
#define NO_BUTTON 2
#define TEXT_BOX 3
#define BOX_IMG 4
#define BOX_CATEGORIA 5
#define BOTTONI_COORDINATE_Y 410
#define GRANDEZZA_BOTTONI_X 120
#define GRANDEZZA_BOTTONI_Y 40
#define GRANDEZZA_DOMANDA_X 180
#define GRANDEZZA_DOMANDA_Y 80
#define GRANDEZZA_IMG_X 460
#define GRANDEZZA_IMG_Y 300
#define TESSUTO_FORMAT "Tessuto Identificato: %s"
#define DOMANDA_FORMAT "Categoria confermata: %s\nVerranno fatte ulteriori domande per identificare la tipologia specifica."
#define CATEGORIA_IDENTIFICATA "Categoria Identificata"
#define TESSUTO_TROVATO "Tessuto Trovato"
#define CATEGORIA_ASSENTE "Categoria Corrente: (nessuna)"
#define CATEGORIA_CORRENTE_FORMAT "Categoria Corrente: %s"

FILE *fptr;
HWND principale;
HWND bottone_si;
HWND bottone_no;
HWND testo_domanda;
HWND testo_categoria;
HWND box_img;
HBITMAP img_tessuto;
chiave **gruppi_generali;
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

void entra_sottocategoria(HWND);

void tessuto_identificato(HWND);

void aggiorna_immagine();

void scrivi_su_file(chiave *);

bool penultima_immagine();

/*-----------------------------------------------------------------------------------------*/

/**
 * https://docs.microsoft.com/it-it/windows/win32/learnwin32/writing-the-window-procedure
 */
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

/**
 * https://docs.microsoft.com/it-it/windows/win32/api/winbase/nf-winbase-winmain
 */
int APIENTRY WinMain(HINSTANCE hInst, HINSTANCE hInstPrev, PSTR cmdline, int cmdshow) {
    crea_tessuti();
    alloca_gruppi_generali();

    stampa_chiave(nervoso, 0);
    stampa_chiave(muscolare, 0);
    stampa_chiave(connettivo, 0);
    stampa_chiave(epiteliale, 0);

    SYSTEMTIME st;
    GetLocalTime(&st);
    WCHAR buf[100];
    wsprintfW(buf, L"output-%.2u-%.2u-%.2u.txt", st.wHour, st.wMinute, st.wSecond);
    char buf_[100];
    sprintf(buf_, "%ws", buf);
    fptr = fopen(buf_, "w");
    if (fptr == NULL) {
        exit(EOF);
    }

    WNDCLASSW windowsClass = {0};

    windowsClass.hbrBackground = CreateSolidBrush(RGB(255, 255, 179));
    windowsClass.hCursor = LoadCursor(NULL, IDC_ARROW);
    windowsClass.hInstance = hInst;
    windowsClass.lpszClassName = L"Chiavi Dicotomiche";
    windowsClass.lpfnWndProc = MainWindowProdecure;

    if (!RegisterClassW(&windowsClass)) {
        return EXIT_FAILURE;
    }

    principale = CreateWindowW(L"Chiavi Dicotomiche", L"Chiavi Dicotomiche",
                               (WS_OVERLAPPEDWINDOW ^ WS_THICKFRAME) | WS_VISIBLE | WS_BORDER,
                               100, 100, 500, 500,
                               NULL, NULL, NULL, NULL);

    MSG message = {0};

    //   FreeConsole();

    while (GetMessage(&message, NULL, (UINT) NULL, (UINT) NULL)) {
        TranslateMessage(&message);
        DispatchMessage(&message);
    }

    fclose(fptr);
    return EXIT_SUCCESS;
}

void scrivi_su_file(chiave *c) {
    fprintf(fptr, "%d.bmp -> %s\n", numero_img_corrente, c->nome);
}

/**
 * Crea tutte le finestre usate in questo programma.
 * @param hwnd La finestra principale.
 */
void crea_finestre(HWND hwnd) {
    bottone_si = CreateWindow(TEXT("BUTTON"), TEXT("Si"),
                              WS_CHILD | WS_VISIBLE,
                              110, BOTTONI_COORDINATE_Y, GRANDEZZA_BOTTONI_X, GRANDEZZA_BOTTONI_Y,
                              hwnd, (HMENU) YES_BUTTON, NULL, NULL
    );

    bottone_no = CreateWindow(TEXT("BUTTON"), TEXT("No"),
                              WS_CHILD | WS_VISIBLE,
                              250, BOTTONI_COORDINATE_Y, GRANDEZZA_BOTTONI_X, GRANDEZZA_BOTTONI_Y,
                              hwnd, (HMENU) NO_BUTTON, NULL, NULL
    );

    testo_domanda = CreateWindow(TEXT("STATIC"), TEXT(chiave_corrente->domanda_chiave->testo),
                                 WS_CHILD | WS_VISIBLE | WS_BORDER,
                                 10, 10, GRANDEZZA_DOMANDA_X, GRANDEZZA_DOMANDA_Y,
                                 hwnd, (HMENU) TEXT_BOX, NULL, NULL
    );

    box_img = CreateWindowW(L"STATIC", NULL,
                            WS_CHILD | WS_VISIBLE | WS_BORDER | SS_BITMAP,
                            10, 95, GRANDEZZA_IMG_X, GRANDEZZA_IMG_Y,
                            hwnd, (HMENU) BOX_IMG, NULL, NULL
    );


    testo_categoria = CreateWindow(TEXT("STATIC"), TEXT(CATEGORIA_ASSENTE),
                                   WS_CHILD | WS_VISIBLE | WS_BORDER,
                                   20 + GRANDEZZA_DOMANDA_X, 10, GRANDEZZA_DOMANDA_X, GRANDEZZA_DOMANDA_Y,
                                   hwnd, (HMENU) BOX_CATEGORIA, NULL, NULL);

    aggiorna_immagine();
}

/**
 * Aggiorna il display dell'immagine corrente.
 */
void aggiorna_immagine() {
    SendMessage(box_img, STM_SETIMAGE, IMAGE_BITMAP, (LPARAM) img_tessuto);
}

/**
 * Controlla la corretta assegnazione delle chiavi princiali.
 * Il programma si chiudera con un codice d'errore predefinito
 * se riscontrati dei problemi.
 * @param chiave La chiave
 * @param indice L' indice.
 */
void controllo_assegnazione_chiavi_generali(struct chiave *chiave, int indice) {
    if (chiave == NULL) {
        exit(ERRORE_CREAZIONE_CHIAVE);
    } else {
        gruppi_generali[indice] = chiave;
    }
}

/**
 * Alloca i gruppi generali.
 */
void alloca_gruppi_generali() {
    gruppi_generali = malloc(sizeof(struct chiave) * TESSUTI_GENERALI);
    if (gruppi_generali == NULL) {
        exit(ERRORE_RAGGRUPPAMENTO);
    } else {
        struct chiave *chiavi[] = {nervoso, muscolare, connettivo, epiteliale};
        chiave_corrente = chiavi[0];
        for (int t = 0; t < TESSUTI_GENERALI; ++t) {
            controllo_assegnazione_chiavi_generali(chiavi[t], t);
        }
    }
}

/**
 * Entra in una sottocategoria
 * @param hwnd Finestra principale
 */
void entra_sottocategoria(HWND hwnd) {
    char *categoria_trovata = malloc(sizeof(char) * (strlen(DOMANDA_FORMAT) + strlen(chiave_corrente->nome)));
    sprintf(categoria_trovata, DOMANDA_FORMAT, chiave_corrente->nome);

    int buttonPress = MessageBox(hwnd, TEXT(categoria_trovata), TEXT(CATEGORIA_IDENTIFICATA),
                                 MB_OK | MB_ICONQUESTION);

    if (buttonPress == IDOK) {
        gruppi_generali = chiave_corrente->sottotipi;
        num_chiave_corrente = 0;
        chiave_corrente = gruppi_generali[0];


        SetWindowText(testo_domanda, TEXT(chiave_corrente->domanda_chiave->testo));
        SetWindowText(testo_categoria, TEXT(chiave_corrente->padrone->nome));
    }
}

/**
 * Notifica l'utente della corretta identificazione di un tessuto.
 * @param hwnd Finestra principale.
 */
void tessuto_identificato(HWND hwnd) {
    char *tessuto_trovato_msg = malloc(sizeof(char) * (strlen(TESSUTO_FORMAT) + strlen(chiave_corrente->nome)));
    sprintf(tessuto_trovato_msg, TESSUTO_FORMAT, chiave_corrente->nome);
    int buttonPress = MessageBox(hwnd, TEXT(tessuto_trovato_msg), TEXT(TESSUTO_TROVATO),
                                 MB_OK | MB_ICONINFORMATION);
    if (buttonPress == IDOK) {
        scrivi_su_file(chiave_corrente);
        numero_img_corrente += 1;
        carica_immagine(hwnd, numero_img_corrente, true);
        aggiorna_immagine();

        num_chiave_corrente = 0;
        alloca_gruppi_generali();
        SetWindowText(testo_domanda, TEXT(chiave_corrente->domanda_chiave->testo));
        SetWindowText(testo_categoria, TEXT(CATEGORIA_ASSENTE));
    }
}

bool penultima_immagine() {
    int num_chiavi_totali_correnti;

    if (chiave_corrente->padrone == NULL) {
        num_chiavi_totali_correnti = TESSUTI_GENERALI;
        if (num_chiavi_totali_correnti - 1 == num_chiave_corrente) {
            return true;
        } else {
            return false;
        }
    } else {
        num_chiavi_totali_correnti = chiave_corrente->padrone->num_sottotipi;

        if (num_chiavi_totali_correnti - 1 == num_chiave_corrente) {
            return true;
        } else {
            return false;
        }
    }
}

/**
 * Gestisci il click del pulsante 'SI'
 * @param main La finestra principale.
 */
void clickSi(HWND main) {
    if (chiave_corrente->num_sottotipi != NO_SOTTOTIPI) {
        entra_sottocategoria(main);
    } else {
        tessuto_identificato(main);
    }
}

/**
 * Gestisci il click del pulsante 'NO'
 * @param main Finestra principale.
 */
void clickNo(HWND main) {
    num_chiave_corrente++;
    chiave_corrente = gruppi_generali[num_chiave_corrente];

    if (penultima_immagine()) {
        clickSi(main);
    } else {
        SetWindowText(testo_domanda, TEXT(chiave_corrente->domanda_chiave->testo));
    }
}

/**
 * Gestisci il click di un pulsante.
 * @param wparam Il pulsante cliccato.
 * @param main La finestra principale.
 */
void clickPulsante(WPARAM wparam, HWND main) {
    switch (LOWORD(wparam)) {
        case YES_BUTTON:
            if (testo_domanda != NULL) {
                clickSi(main);
            }
            break;
        case NO_BUTTON:
            if (testo_domanda != NULL) {
                clickNo(main);
            }
            break;
        default:
            break;
    }
}

/**
 * Trova il numero di cifre di un numero intero.
 * @param numero Il numero.
 * @return Le sue cifre.
 */
int numero_cifre(int numero) {
    int n = numero;
    int c = 0;
    while (n != 0) {
        n /= 10;
        c++;
    }
    return c;
}

/**
 * Carica un immagine di tipo bitmap.
 * @param hwnd Finestra principale.
 * @param numero_immagine Numero della immagine
 * @param termina Se questo valore è vero il programma
 *        si terminerà se non si trova una immagine
 */
void carica_immagine(HWND hwnd, int numero_immagine, bool termina) {
    const char *formato_img = "immagini\\%d.bmp";
    char *nome_immagine = malloc(sizeof(char) * (strlen(formato_img) + numero_cifre(numero_immagine)));
    sprintf(nome_immagine, formato_img, numero_immagine);
    img_tessuto = (HBITMAP) LoadImage(NULL, nome_immagine, IMAGE_BITMAP, 450, 300, LR_LOADFROMFILE);
    if (img_tessuto == NULL) {
        if (termina) {
            exit(IMMAGINE_ASSENTE);
        }
        const char *format_errore = "Impossibile trovare immagine: <<%s>>\n Errore %lu";
        char *errore = malloc(sizeof(char) * (strlen(format_errore) + strlen(nome_immagine)));
        sprintf(errore, format_errore, nome_immagine, GetLastError());
        MessageBox(hwnd, TEXT(errore), TEXT("Errore immagine"), MB_OK | MB_ICONWARNING);
        carica_immagine(hwnd, numero_immagine + 1, true);
    }
}
