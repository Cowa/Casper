#ifndef ABSTRACT_STATE_CELL_HPP
#define ABSTRACT_STATE_CELL_HPP

/** \file AbstractStateCell.hpp
  * \brief Contient la classe AbstractStateCell
  * \author RIOU Matthieu
  */

#include <string>
#include <iostream>


class Cell; //Inclusion circulaire

/** \class AbstractStateCell
 *
 *  \brief Définit l'état abstrait d'une cellule
 *  Définit les méthodes obligatoires pour un état
 */
class AbstractStateCell
{
  public:
  
    /** \brief Renvoie la chaîne correspondante à l'état
      *
      * \return La chaîne de caractère correspondante à l'état courant
      */
    virtual std::string toString() const = 0;
    
    /** \brief Renvoie le prochain état pour une cellule donnée
      *
      * \param cell La cellule pour laquelle on veut passer à l'état suivant
      * \return L'état suivant
      */
    virtual AbstractStateCell* iterate(Cell const* cell) = 0;
    
    /** \brief Vérifie si l'état courant est le même que l'état passé en paramètre
      *
      * \param state L'état avec lequel on souhaite comparer
      * \return Vrai si l'état courant est le même, faux sinon
      */
    virtual bool isState(AbstractStateCell* state) const;
};

/** \brief Surcharge l'operateur de flux <<
  *
  * \param flux Le flux vers lequel on veut envoyer l'état
  * \param state L'état qu'on souhaite envoyer dans le flux
  * \return Le flux, contenant l'état
  */
std::ostream &operator<<( std::ostream &flux, AbstractStateCell const& state);

#endif //ABSTRACT_STATE_CELL_HPP
