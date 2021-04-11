
#include<stdio.h>
#include<stdlib.h>

#include "../consts.h"
#include "../globals.h"
#include "../tools.h"

void main_menu()
{

    do{
        printf("\n 1. Facil\n");
        printf(" 2. Medio\n");
        printf(" 3. Dificil\n");
        printf("===============\n");
        printf(" 0. Salir\n\n");

        printf("Dificultad (1-3):");
        scanf("%i",&Global.difficulty);

        printf("%d\n", Global.difficulty);

        switch (Global.difficulty)
        {
            case 0:
                Global.state  = EXIT_SCREEN;
                break;
            case 1:
            case 2:
            case 3:
                do{
                    printf("\nnumero de preguntas:");
                    scanf("%i",&Global.nquestions);
                }while(Global.nquestions <= 0);
                Global.state = GAME_LOOP;
                break;
            default:
                printf("No existe esa opcion\n");
        }
    }while(Global.difficulty != 0 && Global.difficulty > 3);





}
