#ifndef CELL_HPP
#define CELL_HPP

#include <vector>
#include <string>
#include "StateCell.hpp"

class Cell
{
  private:
    Cell* north;
    Cell* northEast;
    Cell* east;
    Cell* southEast;
    Cell* south;
    Cell* southWest;
    Cell* west;
    Cell* northWest;
    
    StateCell* state;
    StateCell* nextState;
    
  public:
    Cell(StateCell* s);
    
    std::string getStringState() const;
    
    void iterate();
    void apply();
    bool isState(StateCell* otherState) const;
    
    const StateCell* getState() const;
    
    const Cell& getNorth() const;
    const Cell& getNorthEast() const;
    const Cell& getEast() const;
    const Cell& getSouthEast() const;
    const Cell& getSouth() const;
    const Cell& getSouthWest() const;
    const Cell& getWest() const;
    const Cell& getNorthWest() const;
    
    std::vector<Cell const*> getNeighbors() const;
  
    void setNorth(Cell* cell);
    void setNorthEast(Cell* cell);
    void setEast(Cell* cell);
    void setSouthEast(Cell* cell);
    void setSouth(Cell* cell);
    void setSouthWest(Cell* cell);
    void setWest(Cell* cell);
    void setNorthWest(Cell* cell);
};

#endif //CELL_HPP
