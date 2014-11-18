#ifndef STATE_CELL_HPP
#define STATE_CELL_HPP

#include <string>

class Cell; //Inclusion circulaire

class AbstractStateCell
{
  public:
    virtual std::string toString() const = 0;
    virtual AbstractStateCell* iterate(Cell const* cell) = 0;
    virtual bool isState(AbstractStateCell* state) const;
};

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
};

#endif //STATE_CELL_HPP
