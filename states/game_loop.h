
#include<stdio.h>
#include<stdlib.h>

#include "../consts.h"
#include "../globals.h"
#include "../tools.h"

#define ACCEPTABLE_ERROR 0.5

float game_op_add(float a, float b){return a + b;}
float game_op_sub(float a, float b){return a - b;}
float game_op_div(float a, float b){return a / b;}
float game_op_mul(float a, float b){return a * b;}

char game_operations[4] = {'+','-','*','/'};

float (*game_op[]) (float, float) = {
     game_op_add, game_op_sub,
     game_op_mul, game_op_div,
};

void game_loop(){
    float a,b,res,ans;
    int op;

    do{
        a = (float)(rand()%(10*Global.difficulty+1)); /* genera 2 numeros
                                                       * aletoreos */
        b = (float)(rand()%(10*Global.difficulty+1));

        /* selecciona la operacion,
         * sí la dificultad es 0 solo aparecen sumas y restas
         * sí la dificultad es 1 aparecen multiplicaiones
         * sí la dificultad es 2 aparecen diviciones */

        op = rand() % (2 + (Global.difficulty/2) + (Global.difficulty/3) );
        /*                    ^                       ^
                              |                       |
                              |                       +--- retorna 1 si la
                              |                            dificultad es < 3
                              |
                              +--- retorna 1 sí la dificultad es mayor a 2 */

        res = round2(game_op[op](a,b)); /* resultado de la operacion y lo
                                         * redondea a 2 decimales */

        printf("%.2f %c %.2f\n\n", a, game_operations[op], b); /* mostrar la
                                                                * ecuacion */
        printf("Cual es el resultado?: ");
        scanf("%f",&ans);

        if ( (ans - res) <= ACCEPTABLE_ERROR ) /* determina el error entre
                                                * lo ingresado, si el error es
                                                * menos de 0.5 decimas,
                                                * entonces cuenta como el mismo
                                                * numero */
        {
            printf("Correcto!!!\n");
            Global.score += 1000; /* añade 1000 al score del jugador */
        }
        else
        {
            break;
        }

    }while(1);


    printf("peasants\n");
    getchar();
    Global.state = MAIN_MENU;
}

