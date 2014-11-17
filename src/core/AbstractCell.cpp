#include "../../include/core/AbstractCell.hpp"

void AbstractCell::setNorth(AbstractCell* cell)
{
  north = cell;
}

void AbstractCell::setNorthEast(AbstractCell* cell)
{
  northEast = cell;
}

void AbstractCell::setEast(AbstractCell* cell)
{
  east = cell;
}

void AbstractCell::setSouthEast(AbstractCell* cell)
{
  southEast = cell;
}

void AbstractCell::setSouth(AbstractCell* cell)
{
  south = cell;
}

void AbstractCell::setSouthWest(AbstractCell* cell)
{
  southWest = cell;
}

void AbstractCell::setWest(AbstractCell* cell)
{
  west = cell;
}

void AbstractCell::setNorthWest(AbstractCell* cell)
{
  northWest = cell;
}
