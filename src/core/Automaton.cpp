#include "../../include/core/Automaton.hpp"
#include <iostream>

Automaton::Automaton(int height, int width) : tore_(height, width)
{
  //Example
  std::cout << "Iteration 0 : " << std::endl;
  std::cout << tore_ << std::endl;
  tore_.iterate();
  std::cout << "Iteration 1 : " << std::endl;
  std::cout << tore_ << std::endl;
  tore_.iterate();
  std::cout << "Iteration 2 : " << std::endl;
  std::cout << tore_ << std::endl;
}

