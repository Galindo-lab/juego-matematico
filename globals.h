
#ifndef GLOBALS_H
#define GLOBALS_H

struct globals{
    int score,                  /* puntuacion del jugador */
        hight_score,            /* maxima puntuacion */
        difficulty,             /* dificultad */
        state,                  /* indica el estado del juego */
        nquestions,             /* numero de preguntas */
        hits,                   /* aciertos */
        fails;                  /* fallas */
};

struct globals Global = {0};

#endif
