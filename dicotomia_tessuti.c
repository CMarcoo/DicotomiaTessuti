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

LRESULT CALLBACK MainWindowProdecure(HWND, UINT, WPARAM, LPARAM);

int APIENTRY WinMain(HINSTANCE hInst, HINSTANCE hInstPrev, PSTR cmdline, int cmdshow) {
    WNDCLASSW windowsClass = {0};

    windowsClass.hbrBackground = CreateSolidBrush(RGB(255, 209, 121));
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

LRESULT CALLBACK MainWindowProdecure(HWND hwnd, UINT msg, WPARAM wparam, LPARAM lparam) {
    switch (msg) {
        case WM_CREATE: {

            HWND yesButton = CreateWindow(TEXT("BUTTON"), TEXT("Si"),
                         WS_CHILD | WS_VISIBLE,
                         110, 330, 120, 40,
                         hwnd, (HMENU) YES_BUTTON, NULL, NULL
            );

            HWND noButton = CreateWindow(TEXT("BUTTON"), TEXT("No"),
                         WS_CHILD | WS_VISIBLE,
                         250, 330, 120, 40,
                         hwnd, (HMENU) NO_BUTTON, NULL, NULL
            );

            HWND staticText = CreateWindow(TEXT("STATIC"), TEXT("Il tessuto presenta delle fibre?"),
                         WS_CHILD | WS_VISIBLE | WS_BORDER,
                         10, 10, 450, 300,
                         hwnd, (HMENU) TEXT_BOX, NULL, NULL
            );
        }
            break;

        case WM_COMMAND: {

            switch (LOWORD(wparam)) {
                case YES_BUTTON:
                    break;
                case NO_BUTTON:
                    break;
                default:
                    break;
            }
        }
            break;
        case WM_DESTROY:
            PostQuitMessage(EXIT_SUCCESS);
            break;
        default:
            return DefWindowProcW(hwnd, msg, wparam, lparam);
    }
}