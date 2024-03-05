#include <stdio.h>
#include <stdlib.h>

void saddlepoint(int row, int col, int arr[row][col]) {
    int minRowIndex[row]; 
    int maxColIndex[col]; 

    // Инициализация индексов первыми элементами
    for (int i = 0; i < row; i++)
        minRowIndex[i] = 0;
    for (int j = 0; j < col; j++)
        maxColIndex[j] = 0;

    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++) {
            if (arr[i][j] < arr[i][minRowIndex[i]]) {
                minRowIndex[i] = j;
            }
            if (arr[j][i] > arr[maxColIndex[j]][i]) {
                maxColIndex[j] = j;
            }
        }
    }

    for (int i = 0; i < row; i++) {
        int colIndex = minRowIndex[i];
        if (maxColIndex[colIndex] == i) {
            printf("%d %d\n", i, colIndex);
            return;
        }
    }

    printf("none\n");
    return;
}

int main() {
    int row, col;
    scanf("%d%d", &row, &col);
    int array[row][col];

    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++)
            scanf("%d", &array[i][j]);
    }
    saddlepoint(row, col, array);
    return 0;
}
