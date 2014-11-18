#ifndef ABSTRACT_STATE_CELL_HPP
#define ABSTRACT_STATE_CELL_HPP

#include <string>

class Cell; //Inclusion circulaire

class AbstractStateCell
{
  public:
    virtual std::string toString() const = 0;
    virtual AbstractStateCell* iterate(Cell const* cell) = 0;
    virtual bool isState(AbstractStateCell* state) const;
};

std::ostream &operator<<( std::ostream &flux, AbstractStateCell const& state);

#endif //ABSTRACT_STATE_CELL_HPP
