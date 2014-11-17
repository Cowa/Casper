#ifndef AUTOMATON_HPP
#define AUTOMATON_HPP

#include <vector>
#include "Cell.hpp"

class Automaton
{
  private:
    std::vector<std::vector<Cell> > cells;
    
  public:
    Automaton(int longueur, int largeur);
};

#endif //AUTOMATON_HPP
