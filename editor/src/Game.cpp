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
