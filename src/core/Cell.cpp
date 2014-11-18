#include "../../include/core/Cell.hpp"

Cell::Cell(StateCell* s) : state(s)
{}

std::string Cell::getStringState() const
{
  return state->toString();
}

void Cell::iterate()
{
  state = state->iterate(this);
}

bool Cell::isState(StateCell* otherState) const
{
  return state->isState(otherState);
}

const StateCell* Cell::getState() const
{
  return state;
}

const Cell& Cell::getNorth() const
{
  return *north;
}

const Cell& Cell::getNorthEast() const
{
  return *northEast;
}

const Cell& Cell::getEast() const
{
  return *east;
}

const Cell& Cell::getSouthEast() const
{
  return *southEast;
}

const Cell& Cell::getSouth() const
{
  return *south;
}

const Cell& Cell::getSouthWest() const
{
  return *southWest;
}

const Cell& Cell::getWest() const
{
  return *west;
}

const Cell& Cell::getNorthWest() const
{
  return *northWest;
}
    

std::vector<Cell const*> Cell::getNeighbors() const
{
  std::vector<Cell const*> neighbors;
  neighbors.reserve(8);
  neighbors.push_back(north);
  neighbors.push_back(northEast);
  neighbors.push_back(east);
  neighbors.push_back(southEast);
  neighbors.push_back(south);
  neighbors.push_back(southWest);
  neighbors.push_back(west);
  neighbors.push_back(northWest);
  
  return neighbors;
}
    
    

void Cell::setNorth(Cell* cell)
{
  north = cell;
}

void Cell::setNorthEast(Cell* cell)
{
  northEast = cell;
}

void Cell::setEast(Cell* cell)
{
  east = cell;
}

void Cell::setSouthEast(Cell* cell)
{
  southEast = cell;
}

void Cell::setSouth(Cell* cell)
{
  south = cell;
}

void Cell::setSouthWest(Cell* cell)
{
  southWest = cell;
}

void Cell::setWest(Cell* cell)
{
  west = cell;
}

void Cell::setNorthWest(Cell* cell)
{
  northWest = cell;
}
