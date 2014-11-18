#include "../../include/core/Tore.hpp"
#include "../../include/core/StateCell.hpp"

Tore::Tore(int height, int width) : cells_(height, std::vector<Cell*>(width, NULL))
{  
  int maxLine = height-1;
  int maxColumn = width-1;  
  
  
  //Initialisation
  
  for(unsigned int line = 0; line < cells_.size(); line++)
  {
    for(unsigned int column = 0; column < cells_[line].size(); column++)
    {
      cells_[line][column] = new Cell(StateCell::init());
    }
  }
  
  
  //Neighbors
  
  //For line = 0
  
    //For column = 0
  cells_[0][0]->setNorth(cells_[maxLine][0]);
  cells_[0][0]->setNorthEast(cells_[maxLine][1]);
  cells_[0][0]->setEast(cells_[0][1]);
  cells_[0][0]->setSouthEast(cells_[1][1]);
  cells_[0][0]->setSouth(cells_[1][0]);
  cells_[0][0]->setSouthWest(cells_[1][maxColumn]);
  cells_[0][0]->setWest(cells_[0][maxColumn]);
  cells_[0][0]->setNorthWest(cells_[maxLine][maxColumn]);
  
    //For column = maxColumn
  cells_[0][maxColumn]->setNorth(cells_[maxLine][maxColumn]);
  cells_[0][maxColumn]->setNorthEast(cells_[maxLine][0]);
  cells_[0][maxColumn]->setEast(cells_[0][0]);
  cells_[0][maxColumn]->setSouthEast(cells_[1][0]);
  cells_[0][maxColumn]->setSouth(cells_[1][maxColumn]);
  cells_[0][maxColumn]->setSouthWest(cells_[1][maxColumn-1]);
  cells_[0][maxColumn]->setWest(cells_[0][maxColumn-1]);
  cells_[0][maxColumn]->setNorthWest(cells_[maxLine][maxColumn-1]);
    
    //From column = 1 to column = maxColumn -1
  for(unsigned int column=1; column < cells_[0].size() -1; column++)
  {
    cells_[0][column]->setNorth(cells_[maxLine][column]);
    cells_[0][column]->setNorthEast(cells_[maxLine][column+1]);
    cells_[0][column]->setEast(cells_[0][column+1]);
    cells_[0][column]->setSouthEast(cells_[1][column+1]);
    cells_[0][column]->setSouth(cells_[1][column]);
    cells_[0][column]->setSouthWest(cells_[1][column-1]);
    cells_[0][column]->setWest(cells_[0][column-1]);
    cells_[0][column]->setNorthWest(cells_[maxLine][column-1]);
  }
  
  //For line = maxLine
  
    //For column = 0
  cells_[maxLine][0]->setNorth(cells_[maxLine-1][0]);
  cells_[maxLine][0]->setNorthEast(cells_[maxLine-1][1]);
  cells_[maxLine][0]->setEast(cells_[maxLine][1]);
  cells_[maxLine][0]->setSouthEast(cells_[0][1]);
  cells_[maxLine][0]->setSouth(cells_[0][0]);
  cells_[maxLine][0]->setSouthWest(cells_[0][maxColumn]);
  cells_[maxLine][0]->setWest(cells_[maxLine][maxColumn]);
  cells_[maxLine][0]->setNorthWest(cells_[maxLine-1][maxColumn]);
  
    //For column = maxColumn
  cells_[maxLine][maxColumn]->setNorth(cells_[maxLine-1][maxColumn]);
  cells_[maxLine][maxColumn]->setNorthEast(cells_[maxLine-1][0]);
  cells_[maxLine][maxColumn]->setEast(cells_[maxLine][0]);
  cells_[maxLine][maxColumn]->setSouthEast(cells_[0][0]);
  cells_[maxLine][maxColumn]->setSouth(cells_[0][maxColumn]);
  cells_[maxLine][maxColumn]->setSouthWest(cells_[0][maxColumn-1]);
  cells_[maxLine][maxColumn]->setWest(cells_[maxLine][maxColumn-1]);
  cells_[maxLine][maxColumn]->setNorthWest(cells_[maxLine-1][maxColumn]);
  
    //From column = 1 to column = maxColumn-1
  for(unsigned int column=1; column < cells_[0].size() -1; column++)
  {
    cells_[maxLine][column]->setNorth(cells_[maxLine-1][column]);
    cells_[maxLine][column]->setNorthEast(cells_[maxLine-1][column+1]);
    cells_[maxLine][column]->setEast(cells_[maxLine][column+1]);
    cells_[maxLine][column]->setSouthEast(cells_[0][column+1]);
    cells_[maxLine][column]->setSouth(cells_[0][column]);
    cells_[maxLine][column]->setSouthWest(cells_[0][column-1]);
    cells_[maxLine][column]->setWest(cells_[maxLine][column-1]);
    cells_[maxLine][column]->setNorthWest(cells_[maxLine-1][column-1]);
  }
  
  
  //From line = 1 to line = maxLine -1
  
  for(unsigned int line=1; line < cells_.size() -1; line++)
  {
    //For column = 0
    cells_[line][0]->setNorth(cells_[line-1][0]);
    cells_[line][0]->setNorthEast(cells_[line-1][1]);
    cells_[line][0]->setEast(cells_[line][1]);
    cells_[line][0]->setSouthEast(cells_[line+1][1]);
    cells_[line][0]->setSouth(cells_[line+1][0]);
    cells_[line][0]->setSouthWest(cells_[line+1][maxColumn]);
    cells_[line][0]->setWest(cells_[line][maxColumn]);
    cells_[line][0]->setNorthWest(cells_[line-1][maxColumn]);
  
    //For column = maxColumn
    cells_[line][maxColumn]->setNorth(cells_[line-1][maxColumn]);
    cells_[line][maxColumn]->setNorthEast(cells_[line-1][0]);
    cells_[line][maxColumn]->setEast(cells_[line][0]);
    cells_[line][maxColumn]->setSouthEast(cells_[line+1][0]);
    cells_[line][maxColumn]->setSouth(cells_[line+1][maxColumn]);
    cells_[line][maxColumn]->setSouthWest(cells_[line+1][maxColumn-1]);
    cells_[line][maxColumn]->setWest(cells_[line][maxColumn-1]);
    cells_[line][maxColumn]->setNorthWest(cells_[line-1][maxColumn-1]);
    
    //From column = 1 to column = maxColumn -1
    for(unsigned int column=1; column < cells_[line].size() -1; column++)
    {
      cells_[line][column]->setNorth(cells_[line-1][column]);
      cells_[line][column]->setNorthEast(cells_[line-1][column+1]);
      cells_[line][column]->setEast(cells_[line][column+1]);
      cells_[line][column]->setSouthEast(cells_[line+1][column+1]);
      cells_[line][column]->setSouth(cells_[line+1][column]);
      cells_[line][column]->setSouthWest(cells_[line+1][column-1]);
      cells_[line][column]->setWest(cells_[line][column-1]);
      cells_[line][column]->setNorthWest(cells_[line-1][column-1]);
    }
  }
}

void Tore::iterate()
{
  for(unsigned int line = 0; line < cells_.size(); line++)
  {
    for(unsigned int column = 0; column < cells_[line].size(); column++)
    {
      cells_[line][column]->iterate();
    }
  }
  
  for(unsigned int line = 0; line < cells_.size(); line++)
  {
    for(unsigned int column = 0; column < cells_[line].size(); column++)
    {
      cells_[line][column]->apply();
    }
  }
}

const Cell& Tore::cell(int line, int column)
{
  return *cells_[line][column];
}
