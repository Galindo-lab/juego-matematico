
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

#include "../consts.h"
#include "../globals.h"
#include "../tools.h"

#define ACCEPTABLE_ERROR 3
#define ADD              0
#define SUB              1
#define DIV              2
#define MUL              3

float game_op_add(float a, float b){return a + b;}
float game_op_sub(float a, float b){return a - b;}
float game_op_div(float a, float b){return a / b;}
float game_op_mul(float a, float b){return a * b;}

char game_operations[4] = {'+','-','*','/'};

float (*game_op[]) (float, float) = {
     game_op_add, game_op_sub,
     game_op_mul, game_op_div,
};

void game_loop()
{
    float
        a,b,res,ans;          /* a y b, variables
                                 * res, resultado
                                 * ans, respuesta */
    int
        op,                     /* operacion */
        multip,                 /* multiplicador de puntos */
        nq = 1,                 /* numero de pregunta */
        ptos;                   /* puntos */

    clock_t
        begin,                  /* tiempo inicio */
        end;                    /* tiempo final */

    long int
        time_spent;             /* diferencia entre los dos
                                 * tiempos */


    do{


        a = (float)(rand()%(10*Global.difficulty+1)); /* genera 2 numeros */
        b = (float)(rand()%(10*Global.difficulty+1)); /* aletoreos */

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

        printf("\n\nPregunta numero %d\n", nq);
        printf("%.2f %c %.2f\n", a, game_operations[op], b); /* mostrar la
                                                              * ecuacion */

        begin = clock();        /* Tiempo inicial */
        printf("Cual es el resultado?: ");
        scanf("%f",&ans);
        end = clock();          /* tiempo final */
        time_spent = (long int) ((end - begin)*1E5) / CLOCKS_PER_SEC;

        if ( prc_error(ans,res) <= ACCEPTABLE_ERROR ) /* determina el error
                                                       * entre lo ingresado, si
                                                       * el error es menos de
                                                       * 0.5 decimas, entonces
                                                       * cuenta como el mismo
                                                       * numero*/
        {
            switch(op)          /* multiplica los puntos si la operancion es
                                 * multiplicaion o divicion */
            {
                case DIV: multip = 10; break;
                case MUL: multip =  5; break;
                default:  multip =  1;
            }

            /* Si el jugador se tarda de 2 a 3 segundos, se restará 50 pts por cada segundo.
             * Si el jugador se tarda de 4 a 8 segundos, se restará 100pts por cada segundo.
             * Si el jugador tarda más de 8 segundos y contesta correctamente, no se sumarán
             * puntos. */

            ptos = 1000;

            printf("tomo %ld secs\n",time_spent);
            ptos -= 50 * (( time_spent > 2 && time_spent < 4) ? time_spent : 0);
            ptos -= 100 * (( time_spent > 4 && time_spent < 8) ? time_spent : 0);
            ptos = ( time_spent > 8) ? 0 : ptos ;

            Global.score += ptos * multip; /* añade 1000 al score del jugador */
            Global.hits++;

            printf("Correcto!!!\n");
            printf("La puntuacion actual es de: %d\n", Global.score);
        }
        else
        {
            Global.score -= 100;
            printf("Fallo!!\n");
            Global.fails++;
        }

        nq++;                   /* incrementar el numero de pregunta */

    }while( nq <= Global.nquestions );
    Global.state = GAME_OVER;
}

