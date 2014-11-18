#ifndef CELL_HPP
#define CELL_HPP

#include <iostream>
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
    
    AbstractStateCell* state_;
    AbstractStateCell* nextState_;
    
  public:
    Cell(AbstractStateCell* s);
    
    std::string getStringState() const;
    
    void iterate();
    void apply();
    bool isState(AbstractStateCell* otherState) const;
    
    const AbstractStateCell& state() const;
    
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
    
    friend std::ostream &operator<<( std::ostream &flux, Cell const& cell);
};

std::ostream &operator<<( std::ostream &flux, Cell const& cell);

#endif //CELL_HPP
