
#include<stdio.h>
#include<stdlib.h>

#include "../consts.h"
#include "../globals.h"
#include "../tools.h"

void main_menu()
{
    printf("numero de preguntas:");
    scanf("%i",&Global.nquestions);
    printf("Dificultad (1-3):");
    scanf("%i",&Global.difficulty);
    getchar();
    Global.state = GAME_LOOP;
}
