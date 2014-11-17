#ifndef STATE_CELL_HPP
#define STATE_CELL_HPP

#include <string>

class StateCell
{
  public:
    virtual StateCell* iterate() = 0;
};

class EmptyCell : public StateCell
{
  private:
    EmptyCell();
    
    static EmptyCell* instance;
    
  public:
    static EmptyCell* emptyCell();
    
    virtual StateCell* iterate();
};

class AliveCell : public StateCell
{
  private:
    AliveCell();
    
    static AliveCell* instance;
    
  public:
    static AliveCell* aliveCell();
    
    virtual StateCell* iterate();
};

#endif //STATE_CELL_HPP
