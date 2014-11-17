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

bool Cell::isState(StateCell* state) const
{
  return state->isState(state);
}

const StateCell& Cell::getState() const
{
  return *state;
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
