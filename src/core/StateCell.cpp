#include "../../include/core/StateCell.hpp"

#include <random> //c++11


StateCell::EmptyCell* StateCell::emptyCell()
{
  return EmptyCell::instance_;
}

StateCell::AliveCell* StateCell::aliveCell()
{
  return AliveCell::instance_;
}

AbstractStateCell* StateCell::init()
{
  std::random_device rand;
  
  if(rand()%3 == 0) //1/3 aliveCell
  {
    return aliveCell();
  }
  else //2/3 emptyCell
  {
    return emptyCell();
  }
}
