#ifndef UTILITIES_H
 #define UTILITIES_H

 #include <SDL2/SDL.h>
 #include <SDL2/SDL_image.h>


/*********************************************************
 * namespace uts :                                       *
 * ---------------                                       *
 * regroupe un ensemble de fonctions utiles au programme *
 *********************************************************/

namespace uts {
   SDL_Texture* load_img (const char* path, SDL_Renderer *renderer);
}

#endif
