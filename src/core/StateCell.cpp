#include "../../include/core/StateCell.hpp"
#include "../../include/core/Cell.hpp"

bool StateCell::isState(StateCell* state)
{
  return state == this; //All state are singletons, so if state has the same class as this, it is the same instance
}

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

StateCell* EmptyCell::iterate(Cell const* cell)
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

StateCell* AliveCell::iterate(Cell const* cell)
{
  return EmptyCell::emptyCell();
}
