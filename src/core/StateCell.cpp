#include "../../include/core/StateCell.hpp"

EmptyCell::EmptyCell()
{}

EmptyCell* EmptyCell::instance = new EmptyCell();

EmptyCell* EmptyCell::emptyCell()
{
  return instance;
}

std::string EmptyCell::toString() const
{
  return "EmptyCell";
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

std::string AliveCell::toString() const
{
  return "AliveCell";
}

StateCell* AliveCell::iterate()
{
  return EmptyCell::emptyCell();
}
