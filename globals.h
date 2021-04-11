
#ifndef GLOBALS_H
#define GLOBALS_H

struct global{
    char name[10];              /* nombre del jugador */

    int score,                  /* puntuacion del jugador */
        hight_score,            /* maxima puntuacion */
        difficulty,             /* dificultad */
        state;                  /* indica el estado del juego*/

};

struct global Global = {0};

#endif
