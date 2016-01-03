#include <windows.h>
#include <stdlib.h>
#include <string.h>

LRESULT CALLBACK WndProc(HWND, UINT, WPARAM, LPARAM);
BOOL InitWindowsClass(HINSTANCE hInstance);
BOOL InitWindows(HINSTANCE hInstance, int nCmdShow);

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInst, LPSTR lpszCmdLine, int nCmdShow) {
	MSG Msg;
	if (!InitWindowsClass(hInstance)) return FALSE;
	if (!InitWindows(hInstance, nCmdShow)) return FALSE;
	while(GetMessage(&Msg, NULL, 0, 0)) {
		TranslateMessage(&Msg);
		DispatchMessage(&Msg);
	}
	return Msg.wParam;
}

LRESULT CALLBACK WndProc(HWND hwnd, UINT message, WPARAM wParam, LPARAM lParam) {

	HDC hDc;
	HBRUSH hBrush;
	HPEN hPen;
	PAINTSTRUCT PtStr;
	

	switch(message) {
	case WM_PAINT:
		hDc = BeginPaint(hwnd, &PtStr);
		SetMapMode(hDc, MM_ANISOTROPIC);
		/************************************************************************/
		/* Set the pen                                                                     */
		/************************************************************************/
		hPen = (HPEN)GetStockObject(BLACK_PEN);
		hBrush = (HBRUSH)GetStockObject(DKGRAY_BRUSH);
		SelectObject(hDc, hBrush);
		SelectObject(hDc, hPen);
		RoundRect(hDc, 50, 120, 100, 200, 15, 15);
		return 0;
	case WM_DESTROY:
		PostQuitMessage(0);
		return 0;
	default:
		return DefWindowProc(hwnd, message, wParam, lParam);
	}
	return (0);
}

BOOL InitWindows(HINSTANCE hInstance, int nCmdShow) {
	HWND hwnd;
	char lpszClassName[]="´°¿Ú";
	char lpszTitle[] = "My_Windows";
	hwnd = CreateWindow(
		lpszClassName,
		lpszTitle,
		WS_OVERLAPPEDWINDOW,
		CW_USEDEFAULT,
		CW_USEDEFAULT,
		CW_USEDEFAULT,
		CW_USEDEFAULT,
		NULL,
		NULL,
		hInstance,
		NULL
		);
	if (!hwnd) return FALSE;
	ShowWindow(hwnd, nCmdShow);
	UpdateWindow(hwnd);
	return TRUE;
}

BOOL InitWindowsClass(HINSTANCE hInstance) {
	WNDCLASS wndclass;
	char lpszClassName[]="´°¿Ú";
	char lpszTitle[] = "My_Windows";
	
	wndclass.style = 0;
	wndclass.lpfnWndProc = WndProc;
	wndclass.cbClsExtra = 0;
	wndclass.cbWndExtra = 0;
	wndclass.hInstance = hInstance;
	wndclass.hIcon = LoadIcon(NULL, IDI_APPLICATION);
	wndclass.hCursor = LoadCursor(NULL, IDC_ARROW);
	wndclass.hbrBackground = (HBRUSH)GetStockObject(WHITE_BRUSH);
	
	wndclass.lpszMenuName = NULL;
	wndclass.lpszClassName = lpszClassName;

	if(!RegisterClass(&wndclass)) {
		MessageBeep(0);
		return FALSE;
	} else {
		return TRUE;
	}
}