
#include<stdio.h>
#include<stdlib.h>

#include "../consts.h"
#include "../globals.h"
#include "../tools.h"

void game_over()
{

    printf("Resultado:\n");
    printf(" Acertaste el: %d/%d \n", Global.hits,Global.nquestions);
    printf(" Fallaste el: %d/%d \n", Global.fails,Global.nquestions);
    Global.state = MAIN_MENU;
}
