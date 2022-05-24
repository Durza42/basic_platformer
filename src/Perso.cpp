#include "Perso.h"


/*******************************************************************
 * perso :                                                         *
 * -------                                                         *
 * constructeur par défaut de de la classe Perso                   *
 * C'est cette fonction qui sera appelée à la création de l'objet, *
 * si aucun argument n'est spécifié.                               *
 *******************************************************************/

Perso::Perso () :
       m_look { NULL },
       m_pos { 400, 300, PERSO_WIDTH, PERSO_HEIGHT },
       m_dir { 1, 0 },
       m_moove { 0, 0 },
       m_can_jump { true } {

}


/*******************************************************************
 * perso :                                                         *
 * -------                                                         *
 * constructeur de la classe Perso                                 *
 * C'est cette fonction qui sera appelée à la création de l'objet, *
 * si le chemin de son image est spécifiée en argument             *
 *******************************************************************/

Perso::Perso (const char* path, SDL_Renderer* renderer) :
       m_look { uts::load_img (path, renderer) },
       m_pos { 400, 300, PERSO_WIDTH, PERSO_HEIGHT },
       m_dir { 1, 0 },
       m_moove { 0, 0 },
       m_can_jump { true } {

}


/**********************************************************************
 * ~Perso :                                                           *
 * ------                                                             *
 * destructeur de la classe Perso                                     *
 * C'est cette fonction qui sera appelée à la suppression de l'objet. *
 **********************************************************************/

Perso::~Perso () {
// TODO
//   SDL_DestroyTexture (m_look);
}


/***********************************
 * print :                         *
 * -------                         *
 * affiche le personnage à l'écran *
 ***********************************/

void Perso::print (SDL_Renderer* renderer) {
   SDL_RenderCopy (renderer, m_look, NULL, &m_pos);
}


/********************************
 * go_right :                   *
 * ----------                   *
 * fait aller le perso à droite *
 ********************************/

void Perso::go_right () {
   m_moove += (Vector){ MOOVE_ADD, 0 };
}


/********************************
 * go_left :                    *
 * ----------                   *
 * fait aller le perso à gauche *
 ********************************/

void Perso::go_left () {
   m_moove += (Vector){ -MOOVE_ADD, 0 };
}


/************************
 * jump :               *
 * ----------           *
 * fait sauter le perso *
 ************************/

void Perso::jump () {

      // si il peut bien sauter
   if (m_can_jump)
      m_moove += (Vector){ 0, JUMP_ADD };
}


/**********************************************
 * moove_x :                                  *
 * ---------                                  *
 * fait bouger le perso sur l'axe des absices *
 * (en prenant en compte les blocs et autres) *
 **********************************************/

void Perso::moove_x (const Grid & grid) {

      // il ne bougera pas en x
   if (m_moove.get_x () == 0)
      return;

      // ce rectangle représente tout le chemin parcouru par le perso entre son point de départ et son point d'arrivée.
      // Si il y a un bloc dans ce rectangle, c'est qu'en bougeant il le traverserait.
   SDL_Rect no_blocs_zone { m_pos.x, m_pos.y, int(m_moove.get_x ()) + m_pos.w, m_pos.h };

      // TODO
   if (grid.has_col(no_blocs_zone)) { // le perso ne peut juste pas avancer.
      if (m_moove.get_x() > 0) // on le place juste devant le mur
         m_pos.x += m_pos.x % BLOC_GRID_SIZE;
      else
         m_pos.x -= m_pos.x % BLOC_GRID_SIZE;
   }
   else {
      m_pos.x += m_moove.get_x();
   }
}


/************************************************
 * moove_y :                                    *
 * ---------                                    *
 * fait bouger le perso sur l'axe des ordonnées *
 * (en prenant en compte les blocs et autres)   *
 ************************************************/

void Perso::moove_y (const Grid & grid) {

      // ne bougera pas en y
   if (m_moove.get_y () == 0)
      return;

      // ce rectangle représente tout le chemin parcouru par le perso entre son point de départ et son point d'arrivée.
      // Si il y a un bloc dans ce rectangle, c'est qu'en bougeant il le traverserait.
   SDL_Rect no_blocs_zone { m_pos.x, m_pos.y, m_pos.w, int(m_moove.get_y ()) + m_pos.h };

   if (grid.has_col(no_blocs_zone)) { // le perso ne peut juste pas avancer.
/*
      if (m_moove.get_y() > 0) // on le place juste devant le mur
         m_pos.y += m_pos.y % BLOC_GRID_SIZE;
      else
         m_pos.y -= m_pos.y % BLOC_GRID_SIZE;
*/
   }
   else {
      m_pos.y += m_moove.get_y();
   }
}

/**********************************************
 * loose_speed :                              *
 * -------------                              *
 * immobilise fluidement le perso quand plus  *
 * aucune touche de mouvement n'est appuillée *
 **********************************************/

void Perso::loose_speed () {

      // on divise sa vitesse horizontale par deux
   m_moove /= (Vector){ 1.5, 0 };

      // si il ne bouge presque plus en X
   if (m_moove.get_x () < 1 && m_moove.get_x () > -1)
      m_moove.set_x (0); // on le rend immobile
}


/*************************************************
 * fall :                                        *
 * -------------                                 *
 * fait tomber le personnage (simule la gravité) *
 *************************************************/

void Perso::fall (const Grid & grid) {

   if (m_moove.get_y () == 0) {

         // hitbox du perso plus 1 en hauteur (pour tester si il touche le sol)
      SDL_Rect hitbox { m_pos.x, m_pos.y, m_pos.w, m_pos.h + 1 };

      if (grid.has_col (hitbox)) {
         m_can_jump = true;
         return;
      }
   }
   else {

         // ce rectangle représente tout le chemin parcouru par le perso entre son point de départ et son point d'arrivée.
         // Si il y a un bloc dans ce rectangle, c'est qu'en bougeant il le traverserait.
      SDL_Rect no_blocs_zone { m_pos.x, m_pos.y, m_pos.w, m_pos.h + int(m_moove.get_y ()) };

      if (!grid.has_col (no_blocs_zone)) {
         m_can_jump = false;
         m_moove += (Vector){ 0, GRAVITY_ADD };
      }
      else {
         m_pos.y = ((no_blocs_zone.y + no_blocs_zone.h) / BLOC_GRID_SIZE * BLOC_GRID_SIZE) - m_pos.h;
         m_moove.set_y (0);
         m_can_jump = true;
      }
   }
}


/************************************
 * moove :                          *
 * -------                          *
 * fait bouger le perso en fonction *
 * de son vecteur mouvement         *
 ************************************/

bool Perso::moove (const Grid & grid) {

      // on fait tomber le perso
   fall (grid);

      // si le perso est toujours immobile
   if (m_moove.get_x () == 0 && m_moove.get_y () == 0)
      return false; // il ne se déplace pas

      // on fait bouger le perso sur l'axe X
   moove_x (grid);

      // on fait bouger le perso sur l'axe Y
   moove_y (grid);

      // on baisse sa vitesse
   loose_speed ();

   return true;
}
