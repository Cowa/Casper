#ifndef STATE_CELL_HPP
#define STATE_CELL_HPP

#include <string>
#include <vector>
#include "AbstractStateCell.hpp"

namespace StateCell
{
  class EmptyCell : public AbstractStateCell
  {
    private:
      EmptyCell();
      
      static EmptyCell* instance_;
      
    public:
      static EmptyCell* emptyCell();
      
      virtual std::string toString() const;
      virtual AbstractStateCell* iterate(Cell const* cell);
  };

  class AliveCell : public AbstractStateCell
  {
    private:
      AliveCell();
      
      static AliveCell* instance_;
      
    public:
      static AliveCell* aliveCell();
      
      virtual std::string toString() const;
      virtual AbstractStateCell* iterate(Cell const* cell);
  };
  
  AbstractStateCell* init();
};

#endif //STATE_CELL_HPP
