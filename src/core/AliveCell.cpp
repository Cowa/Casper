#include "../../include/core/StateCell.hpp"
#include "../../include/core/Cell.hpp"

StateCell::AliveCell::AliveCell()
{}

StateCell::AliveCell* StateCell::AliveCell::instance_ = new AliveCell();

std::string StateCell::AliveCell::toString() const
{
  return "1";
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
