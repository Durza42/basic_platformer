#ifndef TOP_MENU_H
 #define TOP_MENU_H

 #include <SDL2/SDL.h>
 #include <vector>

 #include "utilities.h"

 #define TOP_MENU_HEIGHT 25

using std::vector;

class Top_menu
{

  public:

   Top_menu (SDL_Renderer* renderer);
   ~Top_menu ();

   bool click (SDL_Point mouse);
   void print (SDL_Renderer* renderer);

  private:

   vector<SDL_Rect> m_hitboxes;

   SDL_Texture m_look;
   SDL_Rect m_global_hitbox;

   vector<SDL_Rect> m_menus_hitboxes;
   vector<SDL_Texture> m_menus_looks;

   int m_iMenu;
};

#endif
