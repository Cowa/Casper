#include "../../include/core/StateCell.hpp"
#include "../../include/core/Cell.hpp"

StateCell::EmptyCell::EmptyCell()
{}

StateCell::EmptyCell* StateCell::EmptyCell::instance_ = new EmptyCell();

std::string StateCell::EmptyCell::toString() const
{
  return "0";
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
