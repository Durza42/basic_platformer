#ifndef UTILITIES_H
 #define UTILITIES_H

 #include <SDL2/SDL.h>
 #include <SDL2/SDL_ttf.h>
 #include <SDL2/SDL_image.h>


/*********************************************************
 * namespace uts :                                       *
 * ---------------                                       *
 * regroupe un ensemble de fonctions utiles au programme *
 *********************************************************/

namespace uts {
   SDL_Texture* str_to_text (const char *str, TTF_Font* font, SDL_Renderer* renderer);
   SDL_Texture* load_img (const char* path, SDL_Renderer *renderer);
}

#endif
