#include "../../include/core/Automaton.hpp"
#include <iostream>

Automaton::Automaton(int longueur, int largeur) : tore(longueur, largeur)
{
  //Example
  std::cout << "Iteration 1 : " << tore.getCell(0,0).getStringState() << std::endl;
  tore.iterate();
  std::cout << "Iteration 2 : " << tore.getCell(0,0).getStringState() << std::endl;
  tore.iterate();
  std::cout << "Iteration 3 : " << tore.getCell(0,0).getStringState() << std::endl;
}

