#ifndef AUTOMATON_HPP
#define AUTOMATON_HPP

/** \file Automaton.hpp
  * \brief Contient la classe Automaton
  * \author RIOU Matthieu
  */
  
#include <vector>
#include "Tore.hpp"

/** \class Automaton
  *
  * \brief Définit un automate
  */
class Automaton
{
  private:

    /** \brief Le tore de l'automate
      */
    Tore tore_;
    
  public:
  
    /** \brief Constructeur de Automaton
      * 
      * \param height La hauteur de l'automate
      * \param width La largeur de l'automate
      */
    Automaton(int height, int width);
};

#endif //AUTOMATON_HPP
