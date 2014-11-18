#include "../../include/core/Cell.hpp"

Cell::Cell(AbstractStateCell* s) : state_(s)
{}

std::string Cell::getStringState() const
{
  return state_->toString();
}

void Cell::iterate()
{
  nextState_ = state_->iterate(this);
}

void Cell::apply()
{
  if(nextState_ != NULL)
  {
    state_ = nextState_;
    nextState_ = NULL;
  }
}

bool Cell::isState(AbstractStateCell* otherState) const
{
  return state_->isState(otherState);
}

const AbstractStateCell* Cell::state() const
{
  return state_;
}

const Cell& Cell::north() const
{
  return *north_;
}

const Cell& Cell::northEast() const
{
  return *northEast_;
}

const Cell& Cell::east() const
{
  return *east_;
}

const Cell& Cell::southEast() const
{
  return *southEast_;
}

const Cell& Cell::south() const
{
  return *south_;
}

const Cell& Cell::southWest() const
{
  return *southWest_;
}

const Cell& Cell::west() const
{
  return *west_;
}

const Cell& Cell::northWest() const
{
  return *northWest_;
}
    

std::vector<Cell const*> Cell::neighbors() const
{
  std::vector<Cell const*> neighbors;
  neighbors.reserve(8);
  neighbors.push_back(north_);
  neighbors.push_back(northEast_);
  neighbors.push_back(east_);
  neighbors.push_back(southEast_);
  neighbors.push_back(south_);
  neighbors.push_back(southWest_);
  neighbors.push_back(west_);
  neighbors.push_back(northWest_);
  
  return neighbors;
}
    
    

void Cell::setNorth(Cell* cell)
{
  north_ = cell;
}

void Cell::setNorthEast(Cell* cell)
{
  northEast_ = cell;
}

void Cell::setEast(Cell* cell)
{
  east_ = cell;
}

void Cell::setSouthEast(Cell* cell)
{
  southEast_ = cell;
}

void Cell::setSouth(Cell* cell)
{
  south_ = cell;
}

void Cell::setSouthWest(Cell* cell)
{
  southWest_ = cell;
}

void Cell::setWest(Cell* cell)
{
  west_ = cell;
}

void Cell::setNorthWest(Cell* cell)
{
  northWest_ = cell;
}
