#ifndef GAME_H
 #define GAME_H

 #include "Context.h"
 #include "Input.h"

class Game
{

  public:

   Game ();
   ~Game ();

   void main_loop ();
   bool manage_input ();
   void refresh ();

  private:

      // gestion de l'entrée utilisateur
   Input m_input;

      // gestion de la couche de base : fenêtres, renderer, etc.
   Context m_context;

      // menu du haut
   Top_menu m_top_menu;
};

#endif
