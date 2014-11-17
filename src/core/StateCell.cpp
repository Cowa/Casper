#include "../../include/core/StateCell.hpp"

EmptyCell::EmptyCell()
{}

EmptyCell* EmptyCell::instance = new EmptyCell();

EmptyCell* EmptyCell::emptyCell()
{
  return instance;
}

StateCell* EmptyCell::iterate()
{
  return AliveCell::aliveCell();
}


AliveCell::AliveCell()
{}

AliveCell* AliveCell::instance = new AliveCell();

AliveCell* AliveCell::aliveCell()
{
  return instance;
}

StateCell* AliveCell::iterate()
{
  return EmptyCell::emptyCell();
}
