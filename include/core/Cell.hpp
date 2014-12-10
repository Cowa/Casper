#ifndef CELL_HPP
#define CELL_HPP

/** \file Cell.hpp
  * \brief Contient la classe Cell
  * \author RIOU Matthieu
  */
  
#include <iostream>
#include <vector>
#include <string>
#include "StateCell.hpp"

/** \class Cell
  *
  * \brief Définie une cellule
  * Une cellule est une case du tore, on différencie la cellule de ce qui se trouve dedans (représenté par son Etat state)
  */
class Cell
{
  private:
  
    /** \brief La cellule au dessus de la cellule courante, dans le Tore
      */
    Cell* north_;
    
    /** \brief La cellule au dessus à droite de la cellule courante, dans le Tore
      */
    Cell* northEast_;
    
    /** \brief La cellule à droite de la cellule courante, dans le Tore
      */
    Cell* east_;
    
    /** \brief La cellule en dessous à droite de la cellule courante, dans le Tore
      */
    Cell* southEast_;
    
    /** \brief La cellule en dessous de la cellule courante, dans le Tore
      */
    Cell* south_;
    
    /** \brief La cellule en dessous à gauche de la cellule courante, dans le Tore
      */
    Cell* southWest_;
    
    /** \brief La cellule à gauche de la cellule courante, dans le Tore
      */
    Cell* west_;
    
    /** \brief La cellule au dessus à gauche de la cellule courante, dans le Tore
      */
    Cell* northWest_;
    
    
    /** \brief L'état courant de sa cellule
      *
      * L'état représente le contenu de la cellule
      */
    AbstractStateCell* state_;
    
    /** \brief Le prochain état de la cellule
      *
      * Permet de stocker le prochain état de la cellule, déterminé lors de l'appel de la méthode iterate, mais effectivement appliqué lors de l'appel de la méthode apply
      */
    AbstractStateCell* nextState_;
    
  public:
  
    /** Constructeur de Cell
      *
      * \param s L'état initial de la cellule
      */
    Cell(AbstractStateCell* s);
    
    /** Récupère une chaîne de caractère correspondante à l'état courant de la cellule
      * 
      * \return La chaîne de caractère
      */
    std::string getStringState() const;
    
    
    /** \brief Détermine le prochain état de la cellule
      * 
      * \post nextState_ != NULL
      */
    void iterate();
    
    /** \brief Applique le nouvel état
      *
      * \pre Un nouvel état d'abord avoir été déterminé avec la méthode iterate
      */
    void apply();
    
    /** \brief Compare l'état courant de la cellule avec l'état passé en paramètre
      *
      * \param otherState L'état à comparer
      * \return Vrai si les états sont les mêmes, faux sinon
      */
    bool isState(AbstractStateCell* otherState) const;
    
    /** \brief Getter sur l'état courant de la cellule
      *
      * \return L'état courant de la cellule
      */
    const AbstractStateCell& state() const;
    
    
    
    /** \brief Getter sur la cellule au dessus de la cellule courante, dans le Tore
      *
      * \return La cellule au dessus de la cellule courante, dans le Tore
      */
    const Cell& north() const;
    
    /** \brief Getter sur la cellule au dessus à droite de la cellule courante, dans le Tore
      *
      * \return La cellule au dessus à droite de la cellule courante, dans le Tore
      */
    const Cell& northEast() const;
    
    /** \brief Getter sur la cellule à droite de la cellule courante, dans le Tore
      *
      * \return La cellule à droite de la cellule courante, dans le Tore
      */
    const Cell& east() const;
    
    /** \brief Getter sur la cellule en dessous à droite de la cellule courante, dans le Tore
      *
      * \return La cellule en dessous à droite de la cellule courante, dans le Tore
      */
    const Cell& southEast() const;
    
    /** \brief Getter sur la cellule en dessous de la cellule courante, dans le Tore
      *
      * \return La cellule en dessous de la cellule courante, dans le Tore
      */
    const Cell& south() const;
    
    /** \brief Getter sur la cellule en dessous à gauche de la cellule courante, dans le Tore
      *
      * \return La cellule en dessous à gauche de la cellule courante, dans le Tore
      */
    const Cell& southWest() const;
    
    /** \brief Getter sur la cellule à gauche de la cellule courante, dans le Tore
      *
      * \return La cellule à gauche de la cellule courante, dans le Tore
      */
    const Cell& west() const;
    
    /** \brief Getter sur la cellule au dessus à gauche de la cellule courante, dans le Tore
      *
      * \return La cellule au dessus à gauche de la cellule courante, dans le Tore
      */
    const Cell& northWest() const;
    
    
    /** \brief Getter sur les voisines de la cellule courante
      *
      * \return Un vector contenant les cellules voisines (north, northEast, east, southEast, south, southWest, west, northWest)
      */
    std::vector<Cell const*> neighbors() const;
  
  
    /** \brief Setter sur la cellule au dessus de la cellule courante, dans le Tore
      *
      * \param La cellule au dessus de la cellule courante, dans le Tore
      */
    void setNorth(Cell* cell);
    
    /** \brief Setter sur la cellule au dessus à droite de la cellule courante, dans le Tore
      *
      * \param La cellule au dessus à droite de la cellule courante, dans le Tore
      */
    void setNorthEast(Cell* cell);
    
    /** \brief Setter sur la cellule à droite de la cellule courante, dans le Tore
      *
      * \param La cellule à droite de la cellule courante, dans le Tore
      */
    void setEast(Cell* cell);
    
    /** \brief Setter sur la cellule en dessous à droite de la cellule courante, dans le Tore
      *
      * \param La cellule en dessous à droite de la cellule courante, dans le Tore
      */
    void setSouthEast(Cell* cell);
    
    /** \brief Setter sur la cellule en dessous de la cellule courante, dans le Tore
      *
      * \param La cellule en dessous de la cellule courante, dans le Tore
      */
    void setSouth(Cell* cell);
    
    /** \brief Setter sur la cellule en dessous à gauche de la cellule courante, dans le Tore
      *
      * \param La cellule en dessous à gauche de la cellule courante, dans le Tore
      */
    void setSouthWest(Cell* cell);
    
    /** \brief Setter sur la cellule à gauche de la cellule courante, dans le Tore
      *
      * \param La cellule à gauche de la cellule courante, dans le Tore
      */
    void setWest(Cell* cell);
    
    /** \brief Setter sur la cellule au dessus à gauche de la cellule courante, dans le Tore
      *
      * \param La cellule au dessus à gauche de la cellule courante, dans le Tore
      */
    void setNorthWest(Cell* cell);
    
    friend std::ostream &operator<<( std::ostream &flux, Cell const& cell);
};

/** \brief Surcharge de l'operateur de flux <<
  *
  * \param flux Le flux vers lequel on veut envoyer la cellule
  * \param cell La cellule qu'on souhaite envoyer dans le flux
  * \return Le flux, contenant la cellule
  */
std::ostream &operator<<( std::ostream &flux, Cell const& cell);

#endif //CELL_HPP
