#include <stdio.h>
#include <string.h>

// FR_012 : 게임 중도 종료
// FR_004 보다 먼저 판별할 것.

int is_game_quit(const char *input) {
    if (input == NULL) {
        return 0;
    }

    // 입력창에 'q'를 입력했는지 판별 (FR_004보다 먼저 판별 필수)
    if (strcmp(input, "q") == 0) {
        printf("\n게임을 중도 포기하였습니다. 메인 메뉴로 복귀합니다.\n");
        printf("참고 : 포기한 판은 결과 화면에 표시되지 않으며 전적에도 저장되지 않습니다.\n");
        return 1;
    }

    return 0;
}