#ifndef STATE_CELL_HPP
#define STATE_CELL_HPP

#include <iostream>
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
      friend EmptyCell* emptyCell(); //Fonction amie car non appartenant à la classe, mais au namespace StateCell(simplifie l'écriture)
      
      virtual std::string toString() const;
      virtual AbstractStateCell* iterate(Cell const* cell);
  };

  class AliveCell : public AbstractStateCell
  {
    private:
      AliveCell();
      
      static AliveCell* instance_;
      
    public:
      friend AliveCell* aliveCell();  //Fonction amie car non appartenant à la classe, mais au namespace StateCell(simplifie l'écriture)
      
      virtual std::string toString() const;
      virtual AbstractStateCell* iterate(Cell const* cell);
  };
  
  EmptyCell* emptyCell();
  AliveCell* aliveCell();
  
  AbstractStateCell* init();
};

#endif //STATE_CELL_HPP
