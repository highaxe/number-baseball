#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// FR_004: 사용자 입력 유효성 검증
// 반환값:
//   1 = 유효한 입력
//   0 = 유효하지 않은 입력

int validate_input(const char *input, int digit_len) {
    int len = (int)strlen(input);
    int used[10] = {0}; // 1~9 숫자 중복 체크용 배열

    // 1. 글자 수 확인
    if (len != digit_len) {
        printf("잘못된 입력입니다. %d자리 숫자를 입력해주세요.\n", digit_len);
        return 0;
    }

    // 2. 1~9 문자 확인 및 중복 숫자 확인
    for (int i = 0; i < len; i++) {
        char ch = input[i];

        // '1' ~ '9'만 허용 ('0', 공백, 알파벳, 특수문자 불가)
        if (ch < '1' || ch > '9') {
            printf("잘못된 입력입니다. 1~9 사이의 숫자만 입력해주세요.\n");
            return 0;
        }

        int num = ch - '0';
        if (used[num] == 1) {
            printf("잘못된 입력입니다. 중복되지 않는 숫자를 입력해주세요.\n");
            return 0;
        }
        used[num] = 1;
    }

    return 1;
}