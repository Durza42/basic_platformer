/*
 * Game.cpp
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

 
#include "Game.h"

Game::Game ()
{
   
}

Game::~Game ()
{
   
}

void Game::main_loop ()
{
   while (manage_input())
   {
      
   }
}

bool Game::manage_input ()
{
   if (m_input.update())
      refresh(); // on ne rafraichit que si quelque-chose a bougé

   if (m_input.request_close())
      return false;

   if (m_input.mouse_is_clicked())
      m_top_menu.click(m_input.get_mouse_pos);
}

void Game::refresh ()
{
   m_top_menu.print();
}
