#ifndef AUTOMATON_HPP
#define AUTOMATON_HPP

#include <vector>
#include "Tore.hpp"

class Automaton
{
  private:
    Tore tore;
    
  public:
    Automaton(int longueur, int largeur);
};

#endif //AUTOMATON_HPP
