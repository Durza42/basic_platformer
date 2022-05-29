#include "Top_menu.h"

Top_menu::Top_menu (SDL_Renderer* renderer) :
          m_hitboxes { { 0, 0, 130, TOP_MENU_HEIGHT },
                       { 130, 0, 130, TOP_MENU_HEIGHT } },
          m_look { uts::load_img("../data/top_menu.jpg", renderer) },
          m_global_hitbox { 0, 0, 130 * 2, TOP_MENU_HEIGHT },
          m_menus_hitboxes { { 0, 25, 200, 300 },
                             { 130, 25, 200, 300 }, },
          m_menus_looks { { uts::load_img("../data/top_menu_fichier.jpg") },
                          { uts::load_img("../data/top_menu_edition.jpg") } },
          m_iMenu { -1 }
{
   
}

Top_menu::~Top_menu () {
   
}

bool Top_menu::click (SDL_Point mouse)
{
   m_iMenu = -1;
   for (size_t i = 0 ; i < m_hitboxes.size() ; ++i)
   {
      if (SDL_PointInRect(m_hitboxes[i], mouse))
      {
         int m_iMenu = i;
         return true;
      }
   }
}

void Top_menu::print (SDL_Renderer* renderer)
{
   SDL_Rendercopy(renderer, m_look, NULL, &m_global_hitbox);
   if (m_iMenu != -1)
      SDL_Rendercopy(renderer, m_menus_looks[m_iMenu], NULL, &m_menus_hitbox[m_iMenu]);
}
