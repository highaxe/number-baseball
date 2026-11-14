#include <stdio.h>
#include <windows.h>
#include "menu.c"
#include "result_screen.c"

int main() {
	
	// 한글 깨짐 제거
	SetConsoleOutputCP(CP_UTF8);
	
	menu();

	return 0;
}
