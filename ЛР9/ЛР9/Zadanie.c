#include <stdio.h>
#include <locale.h>
#include <stdlib.h>

#define ROW 9
#define COL 9

#define N_1 5

int z_1(int r, int c);
int z_1_3(int r, int c);
int z_2(long long num);
char z_3(int r, int c, int H, int L1, int L2, char sym);

int main() {
    setlocale(LC_ALL, "ru_RU.UTF-8");

    int row, col;
    int result;

    //Задание 1
    printf("Задание 1\n\n");
    for (row = 1; row <= ROW; ++row)
    {
        for (col = 1; col <= COL; col++)
        {
            result = z_1(row, col);
            printf("%5d", result);
        }
        printf("\n");
    }
    printf("\n");
    system("pause");

    //Задание 1.2
    printf("\nЗадание 1.2\n\n");
    for (row = 1; row <= ROW; ++row)
    {
        for (col = 1; col <= row; col++)
        {
            result = z_1(row, col);
            printf("%5d", result);
        }
        printf("\n");
    }
    printf("\n");
    system("pause");

    //Задание 1.3
    printf("\nЗадание 1.3\n\n");
    for (row = 1; row <= N_1; ++row)
    {
        for (col = 1; col <= (N_1 - row + 1); col++)
        {
            result = z_1_3(row, col);
            printf("%5d", result);
        }
        printf("\n");
    }
    printf("\n");
    system("pause");

    //Задание 2
    printf("\nЗадание 2\n\n");

    long long input_number;
    int result_2;

    while (1)
    {
        char a;

        printf("Введите длинное целое число: ");
        if (scanf("%lld", &input_number) != 1) {
            printf("Ошибка ввода! Ожидалось целое число.\n");
            return 1;
        }

        result_2 = z_2(input_number);

        if (result_2 == 1) {
            printf("Результат: В числе ЕСТЬ рядом расположенные одинаковые цифры.\n");
        }
        else {
            printf("Результат: В числе НЕТ рядом расположенных одинаковых цифр.\n");
        }

        printf("\n");

        while (getchar() != '\n');

        printf("Продолжить? (Да - y, нет - n): ");
        if ((a = getchar()) == 'n') break;

    }

    //Задание 3
    printf("\nЗадание 3\n\n");

    int H, L1, L2;
    char sym;
    char result_3;

    while (1) {
        char choice;

        printf("Введите символ для рисования контура: ");
        scanf(" %c", &sym);

        printf("Введите полувысоту фигуры (количество строк вверх/вниз от центра): ");
        if (scanf("%d", &H) != 1 || H <= 0) {
            printf("Ошибка ввода размера!\n");
            while (getchar() != '\n');
            continue;
        }

        printf("Введите длину левого крыла (в символах): ");
        if (scanf("%d", &L1) != 1 || L1 <= 0) {
            printf("Ошибка ввода размера!\n");
            while (getchar() != '\n');
            continue;
        }

        printf("Введите длину правого крыла (в символах): ");
        if (scanf("%d", &L2) != 1 || L2 <= 0) {
            printf("Ошибка ввода размера!\n");
            while (getchar() != '\n');
            continue;
        }

        printf("\nВаша фигура:\n\n");

        for (int row = 0; row <= 2 * H; row++) {
            for (int col = 0; col <= L1 + L2; col++) {

                result_3 = z_3(row, col, H, L1, L2, sym);

                printf("%c", result_3);
            }
            printf("\n"); 
        }

        printf("\n");
        while (getchar() != '\n'); 

        printf("Продолжить? (Да - y, нет - n): ");
        if ((choice = getchar()) == 'n') {
            break;
        }
    }

    system("pause");
    return 0;
}

int z_1(int r, int c) {
    return r * c;
}

int z_1_3(int r, int c) {
    return 1;
}

int z_2(long long num) {
    if (num < 0) num = -num;

    int prev_digit = -1;

    while (num > 0) {
        int current_digit = num % 10;

        if (current_digit == prev_digit) {
            return 1;
        }

        prev_digit = current_digit;
        num /= 10;
    }

    return 0;
}
char z_3(int r, int c, int H, int L1, int L2, char sym) {
    int left_contour_col;
    int right_contour_col;

    if (r <= H) {
        //Верхняя половина дельтоида
        left_contour_col = L1 - (r * L1 + H / 2) / H;
        right_contour_col = L1 + (r * L2 + H / 2) / H;
    }
    else {
        //Нижняя половина дельтоида
        int relative_row = r - H;
        left_contour_col = (relative_row * L1 + H / 2) / H;
        right_contour_col = L1 + L2 - (relative_row * L2 + H / 2) / H;
    }

    //Если текущий столбец совпадает с вычисленной границей — возвращаем символ
    if (c == left_contour_col || c == right_contour_col) {
        return sym;
    }

    //В противном случае возвращаем пустоту (пробел)
    return ' ';
}