#ifndef TORE_HPP
#define TORE_HPP

/** \file Tore.hpp
  * \brief Contient la classe Tore
  * \author RIOU Matthieu
  */
  
#include <iostream>
#include <vector>
#include "Cell.hpp"

/** \class Tore
  *
  * \brief Définie un Tore contenant des Cell
  * Un Tore est une grille dont les bords sont "repliés sur eux mêmes". 
  * Ainsi les voisines de droites des cellules de la dernière colonne sont les cellules de la première colonne, et inversement.
  * De même pour le haut et le bas
  */
class Tore
{
  private:
  
    /** \brief La grille de cellule
      * On utilise un vector de vector de Cell*, sous la forme cells_[ligne][colonne]
      */
    std::vector<std::vector<Cell*> > cells_;
    
  public:
  
    /** \brief Constructeur de Tore
      *
      * \param height La hauteur du Tore : le nombre de lignes
      * \param width La largeur du Tore : le nombre de colonnes
      */
    Tore(int height, int width);
    
    /** \brief Passe à l'état suivant du Tore
      *
      * Chaque cellule passe donc à son état suivant
      */
    void iterate();
    
    /** \brief Getter sur les cellules
      *
      * \param line La ligne de la cellule voulue
      * \param column La colonne de la cellule voulue
      */
    const Cell& cell(int line, int column) const;
    
    friend std::ostream &operator<<( std::ostream &flux, Tore const& tore);
};

/** \brief Surcharge l'operateur de flux <<
  *
  * \param flux Le flux vers lequel on veut envoyer le tore
  * \param tore Le tore qu'on souhaite envoyer dans le flux
  * \return Le flux, contenant le tore
  */
std::ostream &operator<<( std::ostream &flux, Tore const& tore);

#endif //TORE_HPP
