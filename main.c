#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

void printArrayInTable( int* array, int N){
    printf("\n------------------\n");
    for( int i = 0; i < N; i++ ){
        for( int j = 0; j < N; j++ ){
            printf("%3d  ", array[i*N+j]  );// *((array+i*N) + j)
        }
        printf("\n");
    }
    printf("--------------------\n");
}

int main() {
    int min = 12, max = 16; // Интервал размер на масив А
    int N; // размер на масива N x N
    bool exit_flag = false, emptyArray = true;
    printf(" ==== курсово задание Крисиян Костов ==== \n"
           "Въведете размер на матрицата ( Стойността трябва да е между [ %d, %d ] ): ", min, max);
    scanf("%d", &N);

    if (N > max || N < min) {
        printf("\nГрешна стойност! ( Интервалът е [ %d , %d ] )\n", min, max);
        return 0;
    }

    printf("define A[%d][%d]\n", N, N );
    int A[N][N];
    int B[N-1];

    while( !exit_flag ) {
        printf("\n\t[1] ръчно попълване на масива\n\t"
               "[2] Автоматично попълване\n\t"
               "[3] Заместване на стойностите в А\n\t"
               "[4] Формирай нов масив B с елементи от под главния диагонал на масив А\n\t"
               "[E] Изход\n "
               "Въведи >_ ");

        char req;
        scanf("%c", &req);

        switch ( req ){
            case '1': // manual input
                for( int i = 0; i < N; i++ ){
                    for( int j = 0; j < N; j++){
                        printf("cell[ ");
                        int cellVal; scanf("%d", &cellVal );
                        A[i][j] = cellVal;
                        printf("], ");
                    }
                    printf("\n");
                }

                printf("\nУспешно завършихте!\n");
                emptyArray = false;
                printArrayInTable(&A, N);
                break;

            case '2': // set default value
                for( int i = 0; i < N; i++ ){
                    for( int j = 0; j < N; j++){
                        A[i][j] = (rand() % (201))-100; // generate randum in interval [ -100, 100]
                    }
                }
                printf("Успешно попълнен!\n");
                emptyArray = false;
                printArrayInTable(&A, N);
                break;

            case '3': // replace A
                if( emptyArray ){
                    printf("Първо трябва да попълните масив А! Изберете опция за попълване.");
                }
                else{
                    for( int i = 0; i < N; i++ ){
                        for( int j = 0; j < N; j++){
                            if( A[i][j] > 0 ) {
                                A[i][j] = 10;
                            }else if( A[i][j] < 0){
                                A[i][j] = -10;
                            }
                            // ако e 0 не го пипай!
                        }
                    }
                    printf("Успешно презаписан!\n");
                    printArrayInTable(&A, N);
                }
                break;

            case '4': // diagonal element in array B
                if( emptyArray ){
                    printf("Първо трябва да попълните масив А! Изберете опция за попълване.");
                }
                else {
                    int j = 0;
                    for( int i = 1;  i < N; i++ ){
                        B[i-1] = A[i][j];
                        j++;
                    }

                    printf("\nB array:");
                    for( int i = 0; i < N-1 ; i ++ ){
                        printf(" [%d] ", B[i]);
                    }
                }
                break;

            case 'E': // exit
            case 'e':
                exit_flag = true;
                printf("\n<Изход>\n");
                break;

            default: // error
                printf("\nГрешна входна стойност!\nВижте отново менюто:\n");
        }

    }
    return 0;
}


