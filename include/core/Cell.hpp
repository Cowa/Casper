#ifndef CELL_HPP
#define CELL_HPP

#include <vector>
#include <string>
#include "StateCell.hpp"

class Cell
{
  private:
    Cell* north_;
    Cell* northEast_;
    Cell* east_;
    Cell* southEast_;
    Cell* south_;
    Cell* southWest_;
    Cell* west_;
    Cell* northWest_;
    
    StateCell* state_;
    StateCell* nextState_;
    
  public:
    Cell(StateCell* s);
    
    std::string getStringState() const;
    
    void iterate();
    void apply();
    bool isState(StateCell* otherState) const;
    
    const StateCell* state() const;
    
    const Cell& north() const;
    const Cell& northEast() const;
    const Cell& east() const;
    const Cell& southEast() const;
    const Cell& south() const;
    const Cell& southWest() const;
    const Cell& west() const;
    const Cell& northWest() const;
    
    std::vector<Cell const*> neighbors() const;
  
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
