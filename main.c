#include <stdio.h>
#include <stdbool.h>
#include <windows.h>
#include "start_screen.c"
#include "result_screen.c"
#include "judge.c"
#include "game_option.c"
#include "single_play.c"
#include "random_number.c"
#include "game_quit.c"
#include "input_validation.c"
#include "save_history.c"
#include "turn_limit.c"
#include "show_history.c"

bool debug = false;

int main() {
	

	// 한글 깨짐 제거
	SetConsoleOutputCP(CP_UTF8);
	

	menu();

	return 0;
}