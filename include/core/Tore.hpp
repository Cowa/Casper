#ifndef TORE_HPP
#define TORE_HPP

#include <vector>
#include "Cell.hpp"

class Tore
{
  private:
    std::vector<std::vector<Cell*> > cells;
    
  public:
    Tore(int height, int width);
    
    void iterate();
    
    const Cell& getCell(int line, int column);
};

#endif //TORE_HPP
