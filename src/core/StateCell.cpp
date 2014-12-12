#include "../../include/core/StateCell.hpp"

#include <random> //c++11

AbstractStateCell* StateCell::init()
{
  std::random_device rand;
  
  if(rand()%3 == 0) //1/3 aliveCell
  {
    return AliveCell::aliveCell();
  }
  else //2/3 emptyCell
  {
    return EmptyCell::emptyCell();
  }
}
