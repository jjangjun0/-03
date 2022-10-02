#include <stdio.h>
#include <stdlib.h>

#define M 20
#define N 10
char arr[M][3][N];
char arr_student_information[M][3][N] = {
	{ { "Sophia" }, { "20220001" }, { "98" } },
	{ { "Olivia" }, { "20220010" }, { "96" } },
	{ { "Riley" }, { "20220002" }, { "88" } },
	{ { "Emma" }, { "20220015" }, { "77" } },
	{ { "Ava" }, { "20220009" }, { "82" } },
	{ { "Isabella" }, { "20220014" }, { "93" } },
	{ { "Aria" }, { "20220020" }, { "84" } },
	{ { "Amelia" }, { "20220005" }, { "79" } },
	{ { "Mia" }, { "20220016" }, { "90" } },
	{ { "Liam" }, { "20220008" }, { "80" } },
	{ { "Noah" }, { "20220012" }, { "89" } },
	{ { "Jackson" }, { "20220004" }, { "99" } },
	{ { "Aiden" }, { "20220018" }, { "78" } },
	{ { "Elijah" }, { "20220017" }, { "83" } },
	{ { "Grayson" }, { "20220003" }, { "92" } },
	{ { "Lucas" }, { "20220013" }, { "71" } },
	{ { "Oliver" }, { "20220007" }, { "72" } },
	{ { "Caden" }, { "20220019" }, { "68" } },
	{ { "Mateo" }, { "20220011" }, { "96" } },
	{ { "David" }, { "20220006" }, { "76" } }
};

void initialize_arr(void);	// 초기화
void print_arr(char arr[M][3][N]);
void change_line(int, char arr[][3][N]);

void Sort_up(int, char arr[][3][N]);
void Sort_down(int, char arr[][3][N]);
void Name_search(char arr[][3][N]);

int main(void)
{
	int num, start = 1;
	while (start) {
		initialize_arr();	// arr배열 초기화

		printf("1. 이름 오름차순 출력\t\t2. 학번 오름차순 출력\n");
		printf("3. 점수 내림차순 출력\t\t4. 이름 검색\n");
		printf("5. 종료\n\n");
		printf("번호를 선택하세요 : ");
		scanf_s("%d", &num);
		printf("\n");
		switch (num) {
		case 1:
			Sort_up(0, arr);	// Name_up
			break;
		case 2:
			Sort_up(1, arr);	// Number_up
			break;
		case 3:
			Sort_down(2, arr);	// Score_down
			break;
		case 4:
			Name_search(arr);
			break;
		case 5:
			start = 0;			// while(0)
			break;
		default:
			printf("다시 입력하시오.\n");
			break;
		}
	}

	return 0;
}
void initialize_arr(void)
{
	for (int i = 0; i < M; i++) {
		for (int j = 0; j < 3; j++) {
			strcpy(arr[i][j], arr_student_information[i][j]);
		}
	}
}
void print_arr(char arr[M][3][N])
{
	printf("이름\t\t학번\t\t점수\n");
	for (int m = 0; m < M; m++) {
		for (int i = 0; i < 3; i++) {
			printf("%s\t", arr[m][i]);
			if (strlen(arr[m][i]) < 8) {
				printf("\t");
			}
		}
		printf("\n");
	}
}
void change_line(int n, char arr[M][3][N])
{
	char temp[N];
	for (int j = 0; j < 3; j++) {
		strcpy(temp, arr[n][j]);
		strcpy(arr[n][j], arr[n + 1][j]);
		strcpy(arr[n + 1][j], temp);
	}
	return;
}
void Sort_up(int x, char arr[M][3][N])
{
	int n;

	for (int i = 0; i < M; i++) {		// Insertion Sort
		n = i;
		while (strcmp(arr[n][x], arr[n + 1][x]) > 0) {
			if (n > M - 2) break;		// 무한 루프 방지
			change_line(n, arr);
			n--;
		}
	}
	print_arr(arr);
	printf("\n");
	return;
}
void Sort_down(int y, char arr[M][3][N])
{
	int n;

	for (int i = 0; i < M; i++) {
		n = i;
		while (strcmp(arr[n][y], arr[n + 1][y]) < 0) {
			change_line(n, arr);
			n--;
			if (n < 0) break;		// 무한 루프 방지
		}
	}
	print_arr(arr);
	printf("\n");
	return;
}
void Name_search(char arr[M][3][N])
{
	char name_temp[N];
	printf("이름을 입력하세요 : ");
	scanf_s("%s", name_temp, sizeof(name_temp));
	printf("\n");
	printf("이름\t\t학번\t\t점수\n");
	for (int i = 0; i < M; i++) {
		if (strcmp(name_temp, arr[i][0]) == 0) {
			for (int j = 0; j < 3; j++) {
				printf("%s\t", arr[i][j]);
				if (strlen(arr[i][j]) < 8) {
					printf("\t");
				}
			}
			printf("\n");
		}
	}
	printf("\n");
	return;
}