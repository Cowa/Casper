#include "../../include/core/StateCell.hpp"
#include "../../include/core/Cell.hpp"

bool AbstractStateCell::isState(AbstractStateCell* state) const
{
  return state == this; //All state are singletons, so if state has the same class as this, it is the same instance
}

StateCell::EmptyCell::EmptyCell()
{}

StateCell::EmptyCell* StateCell::EmptyCell::instance_ = new EmptyCell();

StateCell::EmptyCell* StateCell::emptyCell()
{
  return EmptyCell::instance_;
}

std::string StateCell::EmptyCell::toString() const
{
  return "EmptyCell";
}

AbstractStateCell* StateCell::EmptyCell::iterate(Cell const* cell)
{
  int nbAliveNeighbors(0);
  std::vector<Cell const*> neighbors = cell->neighbors();
  
  for(int i = 0; i < neighbors.size(); i++)
  {
    if(neighbors[i]->isState(aliveCell()))
    {
      nbAliveNeighbors++;
    }
  }
  
  if(nbAliveNeighbors > 2)
    return aliveCell();
  else
    return emptyCell();  
}


StateCell::AliveCell::AliveCell()
{}

StateCell::AliveCell* StateCell::AliveCell::instance_ = new AliveCell();

StateCell::AliveCell* StateCell::aliveCell()
{
  return AliveCell::instance_;
}

std::string StateCell::AliveCell::toString() const
{
  return "AliveCell";
}

AbstractStateCell* StateCell::AliveCell::iterate(Cell const* cell)
{
  int nbAliveNeighbors(0);
  std::vector<Cell const*> neighbors = cell->neighbors();
  
  for(int i = 0; i < neighbors.size(); i++)
  {
    if(neighbors[i]->isState(aliveCell()))
    {
      nbAliveNeighbors ++;
    }
  }
  
  if(nbAliveNeighbors < 2) //Solitude
    return emptyCell();
  else if(nbAliveNeighbors > 3) //Surpopulation
    return emptyCell();
  else
    return aliveCell();
}
