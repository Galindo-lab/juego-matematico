
#include<stdio.h>
#include<stdlib.h>
#include<math.h>

#include "consts.h"
#include "globals.h"
#include "tools.h"

#include "states/main_menu.h"
#include "states/game_loop.h"
#include "states/game_over.h"
#include "states/exit_screen.h"

int main() {
    void (*state[]) () = {
         main_menu,             /* estados del juego */
         game_loop,             /* cada uno esta en su */
         game_over,             /* archivo correspondiente */
         exit_screen            /* salida */
    };

    while(Global.state != EXIT_SCREEN)
    {
        state[Global.state]();
    }

    return 0;
}
