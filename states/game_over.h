
#include<stdio.h>
#include<stdlib.h>

#include "../consts.h"
#include "../globals.h"
#include "../tools.h"

void game_over()
{
    printf("Resultado: %d pts.\n",Global.score);
    printf(" Acertaste el: %d/%d \n", Global.hits,Global.nquestions);
    printf(" Fallaste el: %d/%d \n", Global.fails,Global.nquestions);

    Global.score = 0;
    Global.nquestions = 0;
    Global.hits = 0;
    Global.fails = 0;

    Global.state = MAIN_MENU;
}
