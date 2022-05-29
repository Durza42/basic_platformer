#include <SDL2/SDL.h>
#include "Game.h"

int main (int argc, char** argv) {

   Game game;
   game.main_loop();

   return EXIT_SUCCESS;
}
