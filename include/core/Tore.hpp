#ifndef TORE_HPP
#define TORE_HPP

#include <vector>
#include "Cell.hpp"

class Tore
{
  private:
    std::vector<std::vector<Cell*> > cells_;
    
  public:
    Tore(int height, int width);
    
    void iterate();
    
    const Cell& cell(int line, int column);
};

#endif //TORE_HPP
