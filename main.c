
#include<stdio.h>
#include<stdlib.h>
#include<math.h>

#include "consts.h"
#include "globals.h"
#include "tools.h"

#include "states/main_menu.h"
#include "states/game_loop.h"

int main() {
    void (*state[]) () = {
         main_menu,             /* estados del juego */
         game_loop,             /* cada uno esta en su */
                                /* archivo correspondiente */
    };

    //Global.state = GAME_LOOP;

    while(1)
    {
        state[Global.state]();
    }

    return 0;
}
