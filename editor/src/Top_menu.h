/*
 * Top_menu.h
 * This file is part of 'basic platformer template'
 *
 * Copyright (C) 2022 - Durza42
 *
 * 'basic platformer template' is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 *
 * 'basic platformer template' is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with 'basic platformer template'. If not, see <http://www.gnu.org/licenses/>.
 */


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