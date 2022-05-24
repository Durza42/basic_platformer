#include "Game.h"

/* ##################################################################
   # TODO: delete textures at destructors (!!! fuites mémoires !!!) #
   ################################################################## */


#include "Vector.h"
#include <iostream>

/***************************************************
 * main :                                          *
 * ------                                          *
 * C'est ici que commence l'exécution du programme *
 ***************************************************/

   // sous windows, la fonction main doit s'appeller WinMain.
#ifdef __WIN32__
int WinMain () {
#else
int main () {
#endif

   Game game;
   game.main_loop ();

   return EXIT_SUCCESS;
}
