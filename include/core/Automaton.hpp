#ifndef AUTOMATON_HPP
#define AUTOMATON_HPP

#include <vector>
#include "Tore.hpp"

class Automaton
{
  private:
    Tore tore_;
    
  public:
    Automaton(int height, int width);
};

#endif //AUTOMATON_HPP
