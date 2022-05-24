#ifndef GRID_H
 #define GRID_H

 #include <SDL2/SDL.h>
 #include <vector>
 #include "Tileset.h"

 #define BLOC_GRID_SIZE 25

/*****************************************
 * classe Grid :                         *
 * -------------                         *
 * classe gérant la grille de collision. *
 *****************************************/

class Grid {

  public:

   Grid ();
   ~Grid ();

   void load (std::vector<std::vector<char>> & grid, Tileset tileset); // TODO: réfléchir à un meilleur moyen de chargement. Référence, puis copier-coller ? Vraiment ? Ou passer direct le flux du fichier ?

   void print (SDL_Renderer* renderer);
   void automap (Tileset tileset); // <- TODO

   bool has_col (SDL_Rect & r) const;

  private:

      // une grille (2D) de caractères : 'X' pour un mur, '.' pour du vide, etc. Voir "../data/lvls_config/aide.lvl" pour la liste complète.
   std::vector<std::vector<char>> m_col_grid;

      // la grille qui apparaitra à l'écran
   std::vector<std::vector<SDL_Texture*>> m_look_grid; 
};

#endif
