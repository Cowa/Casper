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
