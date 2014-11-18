#include "../../include/core/StateCell.hpp"
#include "../../include/core/Cell.hpp"

bool StateCell::isState(StateCell* state) const
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
  int nbAliveNeighbors(0);
  std::vector<Cell const*> neighbors = cell->getNeighbors();
  
  for(int i = 0; i < neighbors.size(); i++)
  {
    if(neighbors[i]->isState(AliveCell::aliveCell()))
    {
      nbAliveNeighbors++;
    }
  }
  
  if(nbAliveNeighbors > 2)
    return AliveCell::aliveCell();
  else
    return EmptyCell::emptyCell();  
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
  int nbAliveNeighbors(0);
  std::vector<Cell const*> neighbors = cell->getNeighbors();
  
  for(int i = 0; i < neighbors.size(); i++)
  {
    if(neighbors[i]->isState(AliveCell::aliveCell()))
    {
      nbAliveNeighbors ++;
    }
  }
  
  if(nbAliveNeighbors < 2) //Solitude
    return EmptyCell::emptyCell();
  else if(nbAliveNeighbors > 3) //Surpopulation
    return EmptyCell::emptyCell();
  else
    return AliveCell::aliveCell();
}
