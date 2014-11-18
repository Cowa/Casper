#ifndef TORE_HPP
#define TORE_HPP

#include <iostream>
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
    
    friend std::ostream &operator<<( std::ostream &flux, Tore const& tore);
};

std::ostream &operator<<( std::ostream &flux, Tore const& tore);

#endif //TORE_HPP
