#include "../../include/core/StateCell.hpp"
#include "../../include/core/Cell.hpp"

bool StateCell::isState(StateCell* state) const
{
  return state == this; //All state are singletons, so if state has the same class as this, it is the same instance
}

EmptyCell::EmptyCell()
{}

EmptyCell* EmptyCell::instance_ = new EmptyCell();

EmptyCell* EmptyCell::emptyCell()
{
  return instance_;
}

std::string EmptyCell::toString() const
{
  return "EmptyCell";
}

StateCell* EmptyCell::iterate(Cell const* cell)
{
  int nbAliveNeighbors(0);
  std::vector<Cell const*> neighbors = cell->neighbors();
  
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

AliveCell* AliveCell::instance_ = new AliveCell();

AliveCell* AliveCell::aliveCell()
{
  return instance_;
}

std::string AliveCell::toString() const
{
  return "AliveCell";
}

StateCell* AliveCell::iterate(Cell const* cell)
{
  int nbAliveNeighbors(0);
  std::vector<Cell const*> neighbors = cell->neighbors();
  
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
