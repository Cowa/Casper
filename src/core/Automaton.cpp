#include "../../include/core/Automaton.hpp"
#include <iostream>

Automaton::Automaton(int height, int width) : tore_(height, width)
{
  //Example
  std::cout << "Iteration 1 : " << tore_.cell(0,0).getStringState() << std::endl;
  tore_.iterate();
  std::cout << "Iteration 2 : " << tore_.cell(0,0).getStringState() << std::endl;
  tore_.iterate();
  std::cout << "Iteration 3 : " << tore_.cell(0,0).getStringState() << std::endl;
}

