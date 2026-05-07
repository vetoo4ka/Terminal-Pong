#include <stdio.h>

void logic(int ball_x, int ball_y, int paddle_left_y, int paddle_right_y);
void field(int ball_x, int ball_y, int paddle_left_y, int paddle_right_y);
void count(int score_1, int score_2);
int paddle_left(int paddle_left_y, char input);
int paddle_right(int paddle_right_y, char input);
void winner(int score_1, int score_2);

int main() {
    int ball_x = 40;
    int ball_y = 13;
    int paddle_left_y = 13;
    int paddle_right_y = 13;
    logic(ball_x, ball_y, paddle_left_y, paddle_right_y);
    return 0;
}

void field(int ball_x, int ball_y, int paddle_left_y, int paddle_right_y) {  // ОТРИСОВКА ПОЛЯ

    for (int y = 0; y <= 26; y++) {
        for (int x = 0; x <= 81; x++) {
            if (x == 0 || y == 0 || x == 81 || y == 26)
                printf("%c", '*');
            else if (x == ball_x && y == ball_y)
                printf("%c", 'O');
            else if (x == 1 && (y == paddle_left_y || y == paddle_left_y + 1 || y == paddle_left_y - 1)) {
                printf("%c", '|');
            } else if (x == 80 &&
                       (y == paddle_right_y || y == paddle_right_y + 1 || y == paddle_right_y - 1)) {
                printf("%c", '|');
            } else
                printf("%c", ' ');
        }
        printf("\n");
    }
}

void count(int score_1, int score_2) {  // ОТРИСОВКА СЧЕТА ИГРОКОВ
    for (int y = 0; y < 3; y++) {
        for (int x = 0; x <= 81; x++) {
            if (x == 0 && y == 2)
                printf("PLAYER 1: %d", score_1);
            else if (x == 40 && y == 2)
                printf("PLAYER 2: %d", score_2);
            else
                printf("%c", ' ');
        }
        printf("\n");
    }
}

void logic(int ball_x, int ball_y, int paddle_left_y, int paddle_right_y) {
    int score_1 = 0;
    int score_2 = 0;
    int x = 1;
    int y = 1;
    while (score_1 != 21 || score_2 != 21) {
        ball_x = 40;
        ball_y = 13;
        x = x * -1;
        if (score_1 == 21 || score_2 == 21) {
            winner(score_1, score_2);
            break;
        }
        while (ball_x <= 80 && ball_x >= 0) {
            field(ball_x, ball_y, paddle_left_y, paddle_right_y);
            count(score_1, score_2);
            char c;
            scanf("%c", &c);
            paddle_right_y = paddle_right(paddle_right_y, c);
            paddle_left_y = paddle_left(paddle_left_y, c);
            if (ball_y == 1) {
                y = 1;
            } else if (ball_y == 25) {
                y = -1;
            }
            if (ball_x == 2 &&
                (ball_y == paddle_left_y || ball_y == paddle_left_y + 1 || ball_y == paddle_left_y - 1)) {
                x = 1;
            }
            if (ball_x == 79 &&
                (ball_y == paddle_right_y || ball_y == paddle_right_y + 1 || ball_y == paddle_right_y - 1)) {
                x = -1;
            }
            ball_x = ball_x + x;
            ball_y = ball_y + y;
            if (ball_x == 1) {
                score_2 = score_2 + 1;
            } else if (ball_x == 80) {
                score_1 = score_1 + 1;
            }
        }
    }
}

int paddle_right(int paddle_right_y, char input) {  // управление ракетками 1

    if (input == 'M' || input == 'm') {
        if (paddle_right_y < 24) {
            paddle_right_y++;
        }
    } else if (input == 'K' || input == 'k') {
        if (paddle_right_y > 2) {
            paddle_right_y--;
        }
    }
    if (input == ' ') {
    }
    return paddle_right_y;
}

int paddle_left(int paddle_left_y, char input) {  // управление ракетками 2

    if (input == 'A' || input == 'a') {
        if (paddle_left_y > 2) {
            paddle_left_y--;
        }
    } else if (input == 'Z' || input == 'z') {
        if (paddle_left_y < 24) {
            paddle_left_y++;
        }
    }
    if (input == ' ') {
    }
    return paddle_left_y;
}
void winner(int score_1, int score_2) {
    if (score_1 == 21) {
        printf("THE PLAYER 1 WINS!!!");
        printf(" WIN WIN! REALLY COOL!");
    }

    if (score_2 == 21) {
        printf("THE PLAYER 2 WINS!!!");
        printf(" WIN WIN! REALLY COOL!");
    }
}
