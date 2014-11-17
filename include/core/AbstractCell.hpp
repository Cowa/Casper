#ifndef ABSTRACT_CELL_HPP
#define ABSTRACT_CELL_HPP

#include <string>
#include "StateCell.hpp"

class AbstractCell
{
  private:
    AbstractCell* north;
    AbstractCell* northEast;
    AbstractCell* east;
    AbstractCell* southEast;
    AbstractCell* south;
    AbstractCell* southWest;
    AbstractCell* west;
    AbstractCell* northWest;
    
    StateCell* state;
    
  public:
    AbstractCell(StateCell* s);
    
    std::string getStringState() const;
    
    void iterate();
  
    void setNorth(AbstractCell* cell);
    void setNorthEast(AbstractCell* cell);
    void setEast(AbstractCell* cell);
    void setSouthEast(AbstractCell* cell);
    void setSouth(AbstractCell* cell);
    void setSouthWest(AbstractCell* cell);
    void setWest(AbstractCell* cell);
    void setNorthWest(AbstractCell* cell);
};

#endif //ABSTRACT_CELL_HPP
