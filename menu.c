#include <stdbool.h>

// 게임 숫자 자릿수
int number_digit = 3;
// 볼 숨기기
bool hide_ball = false;
// 스트라이크 숨기기
bool hide_strike = false;

/*
int menu() 반환값

1 - 싱글 플레이 모드 시작
2 - 컴퓨터 대전 모드 시작
3 - 시간제한 모드 시작
4 - 플레이 기록 화면
 */
int menu() {

	while (1) {

		printf("싱글 플레이 모드 - [1]\n");
		printf("컴퓨터 대전 모드 - [2]\n");
		printf("시간제한 모드 - [3]\n");
		putchar('\n');
		
		printf("플레이 기록 - [4]\n");
		putchar('\n');

		printf("자릿수 설정 - [5 <자릿수>]\n");
		printf("볼 숨기기 - [6]\n");
		printf("스트라이크 숨기기 - [7]\n");
		putchar('\n');

		int n;
		scanf("%d", &n);
		if (n >= 1 && n <= 4) {
			return n;
		}
		if (n == 5) {
			// 자릿수를 저장하는 전역변수 필요
			scanf("%d", &number_digit);
			printf("자릿수 = %d\n", number_digit);
			continue;
		}
		if (n == 6) {
			if (hide_ball == false) hide_ball = true;
			else hide_ball = false;
			printf("볼 숨기기 = %s\n", hide_ball ? "True" : "False");
			continue;
		}
		if (n == 7) {
			if (hide_strike == false) hide_strike = true;
			else hide_strike = false;
			printf("스트라이크 숨기기 = %s\n", hide_strike ? "True" : "False");
			continue;
		}
		
	}
}
