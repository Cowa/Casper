#ifndef STATE_CELL_HPP
#define STATE_CELL_HPP

#include <string>

class Cell; //Inclusion circulaire

class StateCell
{
  public:
    virtual std::string toString() const = 0;
    virtual StateCell* iterate(Cell const* cell) = 0;
};

class EmptyCell : public StateCell
{
  private:
    EmptyCell();
    
    static EmptyCell* instance;
    
  public:
    static EmptyCell* emptyCell();
    
    virtual std::string toString() const;
    virtual StateCell* iterate(Cell const* cell);
};

class AliveCell : public StateCell
{
  private:
    AliveCell();
    
    static AliveCell* instance;
    
  public:
    static AliveCell* aliveCell();
    
    virtual std::string toString() const;
    virtual StateCell* iterate(Cell const* cell);
};

#endif //STATE_CELL_HPP
