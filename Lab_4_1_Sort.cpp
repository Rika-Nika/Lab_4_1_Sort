// Lab_4_1_Sort.cpp : Определяет точку входа для приложения.
//
#pragma comment(linker,"\"/manifestdependency:type='win32' \
name='Microsoft.Windows.Common-Controls' version='6.0.0.0' \
processorArchitecture='*' publicKeyToken='6595b64144ccf1df' language='*'\"")

#include "framework.h"
#include "Lab_4_1_Sort.h"
#include <stdio.h>
#include <io.h>
#include <fcntl.h>
#include"WindowHelper.hpp"
#define MAX_LOADSTRING 100

// Глобальные переменные:
HINSTANCE hInst;                                // текущий экземпляр
WCHAR szTitle[MAX_LOADSTRING];                  // Текст строки заголовка
WCHAR szWindowClass[MAX_LOADSTRING];            // имя класса главного окна

LPCWSTR SMALL_FILE = L"Small.txt";
LPCWSTR MEDIUM_FILE = L"Medium.txt";
LPCWSTR LARGE_FILE = L"Large.txt";
const char* PATH_SMALL_FILE  = "Small.txt";
const char* PATH_MEDIUM_FILE = "Medium.txt";
const char* PATH_LARG_FILE = "Large.txt";

const char* PATH_FILE = nullptr;


SizeSeq sizeSeq  = SizeSeq::LARGE;
         
HWND hInputSeqButton = nullptr;
HWND hStartButton = nullptr;

HWND hGetSeqButton = nullptr;
HWND hSaveSeqButton = nullptr;
//ИД
HWND hGrpButtonsID = nullptr;
HWND hLoadButton = nullptr;
HWND hLoadPathButton = nullptr;
HWND hGeneratorButton = nullptr;
//Длина последовательности
HWND hGrpButtonsLength = nullptr;
HWND hSmallButton = nullptr;
HWND hMediumButton = nullptr;
HWND hLargeButton = nullptr;
//Алгоритм 1
HWND hGrpButtonsAlg1 = nullptr;
HWND hSortQuick1Button = nullptr;
HWND hSortPyramid1Button = nullptr;
HWND hSortShell1Button = nullptr;
//Тип последовательности 1
HWND hGrpButtonsSeq1 = nullptr;
HWND hArrayList1Button = nullptr;
HWND hLinkedlists1Button = nullptr;
//Алгоритм 2
HWND hGrpButtonsAlg2 = nullptr;
HWND hSortQuick2Button = nullptr;
HWND hSortPyramid2Button = nullptr;
HWND hSortShell2Button = nullptr;
//Тип последовательности 2
HWND hGrpButtonsSeq2 = nullptr;
HWND hArrayList2Button = nullptr;
HWND hLinkedlists2Button = nullptr;
HWND hInputButtonLabel = nullptr;
HWND hOutputButtonLabel1 = nullptr;
HWND hOutpuSeqtButton1 = nullptr;
HWND hOutputButtonLabel2 = nullptr;
HWND hOutpuSeqtButton2 = nullptr;



// Отправить объявления функций, включенных в этот модуль кода:
ATOM                MyRegisterClass(HINSTANCE hInstance);
BOOL                InitInstance(HINSTANCE, int);
LRESULT CALLBACK    WndProc(HWND, UINT, WPARAM, LPARAM);
INT_PTR CALLBACK    About(HWND, UINT, WPARAM, LPARAM);

int APIENTRY wWinMain(_In_ HINSTANCE hInstance,
                     _In_opt_ HINSTANCE hPrevInstance,
                     _In_ LPWSTR    lpCmdLine,
                     _In_ int       nCmdShow)
{
    UNREFERENCED_PARAMETER(hPrevInstance);
    UNREFERENCED_PARAMETER(lpCmdLine);

    // TODO: Разместите код здесь.

    // Инициализация глобальных строк
    LoadStringW(hInstance, IDS_APP_TITLE, szTitle, MAX_LOADSTRING);
    LoadStringW(hInstance, IDC_LAB41SORT, szWindowClass, MAX_LOADSTRING);
    MyRegisterClass(hInstance);

    // Выполнить инициализацию приложения:
    if (!InitInstance (hInstance, nCmdShow))
    {
        return FALSE;
    }

    HACCEL hAccelTable = LoadAccelerators(hInstance, MAKEINTRESOURCE(IDC_LAB41SORT));

    MSG msg;

    // Цикл основного сообщения:
    while (GetMessage(&msg, nullptr, 0, 0))
    {
        if (!TranslateAccelerator(msg.hwnd, hAccelTable, &msg))
        {
            TranslateMessage(&msg);
            DispatchMessage(&msg);
        }
    }

    return (int) msg.wParam;
}



//
//  ФУНКЦИЯ: MyRegisterClass()
//
//  ЦЕЛЬ: Регистрирует класс окна.
//
ATOM MyRegisterClass(HINSTANCE hInstance)
{
    WNDCLASSEXW wcex;

    wcex.cbSize = sizeof(WNDCLASSEX);

    wcex.style          = CS_HREDRAW | CS_VREDRAW;
    wcex.lpfnWndProc    = WndProc;
    wcex.cbClsExtra     = 0;
    wcex.cbWndExtra     = 0;
    wcex.hInstance      = hInstance;
    wcex.hIcon          = LoadIcon(hInstance, MAKEINTRESOURCE(IDI_LAB41SORT));
    wcex.hCursor        = LoadCursor(nullptr, IDC_ARROW);
    wcex.hbrBackground  = (HBRUSH)(COLOR_WINDOW+0);
    wcex.lpszMenuName = nullptr;// (IDC_LAB41SORT);
    wcex.lpszClassName  = szWindowClass;
    wcex.hIconSm        = LoadIcon(wcex.hInstance, MAKEINTRESOURCE(IDI_SMALL));

    return RegisterClassExW(&wcex);
}

//
//   ФУНКЦИЯ: InitInstance(HINSTANCE, int)
//
//   ЦЕЛЬ: Сохраняет маркер экземпляра и создает главное окно
//
//   КОММЕНТАРИИ:
//
//        В этой функции маркер экземпляра сохраняется в глобальной переменной, а также
//        создается и выводится главное окно программы.
//
BOOL InitInstance(HINSTANCE hInstance, int nCmdShow)
{
   hInst = hInstance; // Сохранить маркер экземпляра в глобальной переменной

   HWND hWnd = CreateWindowW(szWindowClass, L"Тестирование алгоритмов сортировки", WS_OVERLAPPEDWINDOW,
      250, 250, 725, 650, nullptr, nullptr, hInstance, nullptr);

   if (!hWnd)
   {
      return FALSE;
   }

   ShowWindow(hWnd, nCmdShow);
   UpdateWindow(hWnd);

   return TRUE;
}
//BOOL CreateConsole(void)
//{
//    FreeConsole(); //на всякий случай
//    if (AllocConsole())
//    {
//        int hCrt = _open_osfhandle((long)
//            GetStdHandle(STD_OUTPUT_HANDLE), _O_TEXT);
//        *stdout = *(::_fdopen(hCrt, "w"));
//        ::setvbuf(stdout, NULL, _IONBF, 0);
//        *stderr = *(::_fdopen(hCrt, "w"));
//        ::setvbuf(stderr, NULL, _IONBF, 0);
//        return TRUE;
//    }
//    return FALSE;
//}
//
//  ФУНКЦИЯ: WndProc(HWND, UINT, WPARAM, LPARAM)
//
//  ЦЕЛЬ: Обрабатывает сообщения в главном окне.
//
//  WM_COMMAND  - обработать меню приложения
//  WM_PAINT    - Отрисовка главного окна
//  WM_DESTROY  - отправить сообщение о выходе и вернуться
//
//
LRESULT CALLBACK WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{

    switch (message)
    {
    case WM_CREATE:
    {

         hStartButton = CreateWindow(
            L"BUTTON",  // Predefined class; Unicode assumed 
            L"Начать тест",      // Button text , 
            WS_CHILD | WS_VISIBLE | BS_PUSHBUTTON, 245, 530, 220, 50, hWnd, (HMENU)10000 , NULL, NULL);

         hGetSeqButton = CreateWindow(
            L"BUTTON",  // Predefined class; Unicode assumed 
            L"Создать последовательность",      // Button text , 
            WS_CHILD | WS_VISIBLE | BS_PUSHBUTTON, 10, 530, 220, 50, hWnd, (HMENU)9999, NULL, NULL);
         hSaveSeqButton = CreateWindow(
            L"BUTTON",  // Predefined class; Unicode assumed 
            L"Сохранить отчет",      // Button text , 
            WS_CHILD | WS_VISIBLE | BS_PUSHBUTTON, 480, 530, 220, 50, hWnd, (HMENU)9998, NULL, NULL);
        //ИД
         hGrpButtonsID = CreateWindowEx(WS_EX_WINDOWEDGE,
            L"BUTTON",
            L"Исходные данные:",
            WS_VISIBLE | WS_CHILD | BS_GROUPBOX,// <----BS_GROUPBOX does nothing on the grouping 
            10, 10,
            320, 70,
            hWnd,
            (HMENU)8000,
            hInst, NULL);
         hLoadButton = CreateWindowEx(WS_EX_WINDOWEDGE,
            L"BUTTON",
            L"Загрузить из файла",
            WS_VISIBLE | WS_CHILD | BS_AUTORADIOBUTTON | WS_GROUP,  // <---- WS_GROUP group the following radio buttons 1st,2nd button 
            20, 30,
            155, 20,
            hWnd, //<----- Use main window handle
            (HMENU)10001,
            hInst, NULL);
        SendMessage(hLoadButton, BM_SETCHECK, BST_CHECKED, 0);
         hLoadPathButton = CreateWindowEx(WS_EX_WINDOWEDGE,
            L"edit",
            LARGE_FILE,
            WS_CHILD | WS_VISIBLE | WS_BORDER | ES_LEFT,  // <---- WS_GROUP group the following radio buttons 1st,2nd button 
            180, 30,
            140, 20,
            hWnd, //<----- Use main window handle
            (HMENU)10002,
            hInst, NULL);
         
         hGeneratorButton = CreateWindowEx(WS_EX_WINDOWEDGE,
            L"BUTTON",
            L"Генератор",
            WS_VISIBLE | WS_CHILD | BS_AUTORADIOBUTTON,  // Styles 
            20, 50,
            300, 20,
            hWnd,
            (HMENU)10003,
            hInst, NULL);
        //Длина последовательности
         hGrpButtonsLength = CreateWindowEx(WS_EX_WINDOWEDGE,
            L"BUTTON",
            L"Длина последовательности:",
            WS_VISIBLE | WS_CHILD | BS_GROUPBOX,// <----BS_GROUPBOX does nothing on the grouping 
            10, 90,
            320, 90,
            hWnd,
            NULL,
            hInst, NULL);
         hSmallButton = CreateWindowEx(WS_EX_WINDOWEDGE,
            L"BUTTON",
            L"Small",
            WS_VISIBLE | WS_CHILD | BS_AUTORADIOBUTTON | WS_GROUP,  // <---- WS_GROUP group the following radio buttons 1st,2nd button 
            20, 110,
            300, 20,
            hWnd, //<----- Use main window handle
            (HMENU)10004,
            hInst, NULL);

         hMediumButton = CreateWindowEx(WS_EX_WINDOWEDGE,
            L"BUTTON",
            L"Medium",
            WS_VISIBLE | WS_CHILD | BS_AUTORADIOBUTTON,  // Styles 
            20, 130,
            300, 20,
            hWnd,
            (HMENU)10005,
            hInst, NULL);
         hLargeButton = CreateWindowEx(WS_EX_WINDOWEDGE,
            L"BUTTON",
            L"Large",
            WS_VISIBLE | WS_CHILD | BS_AUTORADIOBUTTON,  // Styles 
            20, 150,
            300, 20,
            hWnd,
            (HMENU)10006,
            hInst, NULL);
        SendMessage(hLargeButton, BM_SETCHECK, BST_CHECKED, 0);
        PATH_FILE = PATH_LARG_FILE;
        //Алгоритм 1
         hGrpButtonsAlg1 = CreateWindowEx(WS_EX_WINDOWEDGE,
            L"BUTTON",
            L"Алгоритм 1:",
            WS_VISIBLE | WS_CHILD | BS_GROUPBOX,// <----BS_GROUPBOX does nothing on the grouping 
            340, 10,
            170, 90,
            hWnd,
            NULL,
            hInst, NULL);
         hSortQuick1Button = CreateWindowEx(WS_EX_WINDOWEDGE,
            L"BUTTON",
            L"SortQuick",
            WS_VISIBLE | WS_CHILD | BS_AUTORADIOBUTTON | WS_GROUP,  // <---- WS_GROUP group the following radio buttons 1st,2nd button 
            350, 30,
            150, 20,
            hWnd, //<----- Use main window handle
            (HMENU)10007,
            hInst, NULL);

         hSortPyramid1Button = CreateWindowEx(WS_EX_WINDOWEDGE,
            L"BUTTON",
            L"SortPyramid",
            WS_VISIBLE | WS_CHILD | BS_AUTORADIOBUTTON,  // Styles 
            350, 50,
            150, 20,
            hWnd,
            (HMENU)10008,
            hInst, NULL);
         hSortShell1Button = CreateWindowEx(WS_EX_WINDOWEDGE,
            L"BUTTON",
            L"SortShell",
            WS_VISIBLE | WS_CHILD | BS_AUTORADIOBUTTON,  // Styles 
            350, 70,
            150, 20,
            hWnd,
            (HMENU)10009,
            hInst, NULL);
        SendMessage(hSortQuick1Button, BM_SETCHECK, BST_CHECKED, 0);

        //Тип последовательности 1
         hGrpButtonsSeq1 = CreateWindowEx(WS_EX_WINDOWEDGE,
            L"BUTTON",
            L"Последовательность 1:",
            WS_VISIBLE | WS_CHILD | BS_GROUPBOX,// <----BS_GROUPBOX does nothing on the grouping 
            340, 110,
            170, 70,
            hWnd,
            NULL,
            hInst, NULL);
         hArrayList1Button = CreateWindowEx(WS_EX_WINDOWEDGE,
            L"BUTTON",
            L"ArrayList",
            WS_VISIBLE | WS_CHILD | BS_AUTORADIOBUTTON | WS_GROUP,  // <---- WS_GROUP group the following radio buttons 1st,2nd button 
            350, 130,
            150, 20,
            hWnd, //<----- Use main window handle
            (HMENU)10010,
            hInst, NULL);
        SendMessage(hArrayList1Button, BM_SETCHECK, BST_CHECKED, 0);
         hLinkedlists1Button = CreateWindowEx(WS_EX_WINDOWEDGE,
            L"BUTTON",
            L"Linkedlists",
            WS_VISIBLE | WS_CHILD | BS_AUTORADIOBUTTON,  // Styles 
            350, 150,
            150, 20,
            hWnd,
            (HMENU)10011,
            hInst, NULL);

        //Алгоритм 2
         hGrpButtonsAlg2 = CreateWindowEx(WS_EX_WINDOWEDGE,
            L"BUTTON",
            L"Алгоритм 2:",
            WS_VISIBLE | WS_CHILD | BS_GROUPBOX,// <----BS_GROUPBOX does nothing on the grouping 
            520, 10,
            170, 90,
            hWnd,
            NULL,
            hInst, NULL);
         hSortQuick2Button = CreateWindowEx(WS_EX_WINDOWEDGE,
            L"BUTTON",
            L"SortQuick",
            WS_VISIBLE | WS_CHILD | BS_AUTORADIOBUTTON | WS_GROUP,  // <---- WS_GROUP group the following radio buttons 1st,2nd button 
            530, 30,
            150, 20,
            hWnd, //<----- Use main window handle
            (HMENU)10012,
            hInst, NULL);

         hSortPyramid2Button = CreateWindowEx(WS_EX_WINDOWEDGE,
            L"BUTTON",
            L"SortPyramid",
            WS_VISIBLE | WS_CHILD | BS_AUTORADIOBUTTON,  // Styles 
            530, 50,
            150, 20,
            hWnd,
            (HMENU)10013,
            hInst, NULL);
         hSortShell2Button = CreateWindowEx(WS_EX_WINDOWEDGE,
            L"BUTTON",
            L"SortShell",
            WS_VISIBLE | WS_CHILD | BS_AUTORADIOBUTTON,  // Styles 
            530, 70,
            150, 20,
            hWnd,
            (HMENU)10014,
            hInst, NULL);
        SendMessage(hSortQuick2Button, BM_SETCHECK, BST_CHECKED, 0);
        //Тип последовательности 2
         hGrpButtonsSeq2 = CreateWindowEx(WS_EX_WINDOWEDGE,
            L"BUTTON",
            L"Последовательность 2:",
            WS_VISIBLE | WS_CHILD | BS_GROUPBOX,// <----BS_GROUPBOX does nothing on the grouping 
            520, 110,
            170, 70,
            hWnd,
            NULL,
            hInst, NULL);
         hArrayList2Button = CreateWindowEx(WS_EX_WINDOWEDGE,
            L"BUTTON",
            L"ArrayList",
            WS_VISIBLE | WS_CHILD | BS_AUTORADIOBUTTON | WS_GROUP,  // <---- WS_GROUP group the following radio buttons 1st,2nd button 
            530, 130,
            150, 20,
            hWnd, //<----- Use main window handle
            (HMENU)10015,
            hInst, NULL);

         hLinkedlists2Button = CreateWindowEx(WS_EX_WINDOWEDGE,
            L"BUTTON",
            L"Linkedlists",
            WS_VISIBLE | WS_CHILD | BS_AUTORADIOBUTTON,  // Styles 
            530, 150,
            150, 20,
            hWnd,
            (HMENU)10016,
            hInst, NULL);
        SendMessage(hLinkedlists2Button, BM_SETCHECK, BST_CHECKED, 0);
         hInputButtonLabel = CreateWindowEx(WS_EX_WINDOWEDGE,
            L"Static",
            L"Входная последовательность",
            WS_CHILD | WS_VISIBLE |  ES_LEFT| ES_READONLY,
            10, 185,
            220, 30,
            hWnd, 
            (HMENU)10017,
            hInst, NULL);
        hInputSeqButton = CreateWindowEx(WS_EX_WINDOWEDGE,
            L"edit",
            L"Input Seq",
            WS_VSCROLL | WS_BORDER | WS_VISIBLE | WS_CHILD | ES_MULTILINE ,
            10, 225,
            220, 300,
            hWnd, //<----- Use main window handle
            (HMENU)10018,
            hInst, NULL);
         hOutputButtonLabel1 = CreateWindowEx(WS_EX_WINDOWEDGE,
            L"Static",
            L"Отсортированная последовательность 1",
            WS_CHILD | WS_VISIBLE | ES_LEFT | ES_READONLY,
            245, 185,
            220, 30,
            hWnd,
            (HMENU)10019,
            hInst, NULL);
         hOutpuSeqtButton1 = CreateWindowEx(WS_EX_WINDOWEDGE,
            L"edit",
            L"Output Seq1",
            WS_VSCROLL | WS_BORDER | WS_VISIBLE | WS_CHILD | ES_MULTILINE,
            245, 225,
            220, 300,
            hWnd, //<----- Use main window handle
            (HMENU)10020,
            hInst, NULL);

         hOutputButtonLabel2 = CreateWindowEx(WS_EX_WINDOWEDGE,
            L"Static",
            L"Отсортированная последовательность 2",
            WS_CHILD | WS_VISIBLE | ES_LEFT | ES_READONLY,
            480, 185,
            220, 30,
            hWnd,
            (HMENU)10021,
            hInst, NULL);
         hOutpuSeqtButton2 = CreateWindowEx(WS_EX_WINDOWEDGE,
            L"edit",
            L"Output Seq2",
            WS_VSCROLL | WS_BORDER | WS_VISIBLE | WS_CHILD | ES_MULTILINE,
            480, 225,
            220, 300,
            hWnd, //<----- Use main window handle
            (HMENU)10022,
            hInst, NULL);


    }
        break;

    case WM_COMMAND:
        {
            int wmId = LOWORD(wParam);
            int len = 0;
            // Разобрать выбор в меню:
            switch (wmId)
            {
            case IDM_ABOUT:
                DialogBox(hInst, MAKEINTRESOURCE(IDD_ABOUTBOX), hWnd, About);
                break;
            case IDM_EXIT:
                DestroyWindow(hWnd);
                break;
            case 10004:
                SetWindowText(hLoadPathButton, SMALL_FILE);
                sizeSeq = SizeSeq::SMALL;
                PATH_FILE = PATH_SMALL_FILE;
                break;
            case 10005:
                SetWindowText(hLoadPathButton, MEDIUM_FILE);
                sizeSeq = SizeSeq::MEDIUM;
                PATH_FILE = PATH_MEDIUM_FILE;
                break;
            case 10006:
                SetWindowText(hLoadPathButton, LARGE_FILE);
                sizeSeq = SizeSeq::LARGE;
                PATH_FILE = PATH_LARG_FILE;
                break;
            case 9999:
                //TCHAR path[20];
                //len = GetWindowText(hLoadPathButton, path, 20);
                getSeq(hInputSeqButton, sizeSeq, IsDlgButtonChecked(hWnd, 10003), PATH_FILE);
                break;

            case 10000:
                startTest(hInputSeqButton, hOutpuSeqtButton1);
                break;


            default:
                return DefWindowProc(hWnd, message, wParam, lParam);
            }
        }
        break;
    case WM_PAINT:
        {
            PAINTSTRUCT ps;
            HDC hdc = BeginPaint(hWnd, &ps);

            // TODO: Добавьте сюда любой код прорисовки, использующий HDC...
            EndPaint(hWnd, &ps);
        }
        break;
    case WM_DESTROY:
        PostQuitMessage(0);
        break;
    default:

        return DefWindowProc(hWnd, message, wParam, lParam);
    }
    return 0;
}

// Обработчик сообщений для окна "О программе".
INT_PTR CALLBACK About(HWND hDlg, UINT message, WPARAM wParam, LPARAM lParam)
{
    UNREFERENCED_PARAMETER(lParam);
    switch (message)
    {
    case WM_INITDIALOG:
        return (INT_PTR)TRUE;

    case WM_COMMAND:
        if (LOWORD(wParam) == IDOK || LOWORD(wParam) == IDCANCEL)
        {
            EndDialog(hDlg, LOWORD(wParam));
            return (INT_PTR)TRUE;
        }
        break;
    }
    return (INT_PTR)FALSE;
}

