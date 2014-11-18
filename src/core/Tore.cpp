#include "../../include/core/Tore.hpp"
#include "../../include/core/StateCell.hpp"

Tore::Tore(int height, int width) : cells(height, std::vector<Cell*>(width, NULL))
{  
  int maxLine = height-1;
  int maxColumn = width-1;  
  
  
  //Initialisation
  
  for(unsigned int line = 0; line < cells.size(); line++)
  {
    for(unsigned int column = 0; column < cells[line].size(); column++)
    {
      cells[line][column] = new Cell(EmptyCell::emptyCell());
    }
  }
  
  
  //Neighbors
  
  //For line = 0
  
    //For column = 0
  cells[0][0]->setNorth(cells[maxLine][0]);
  cells[0][0]->setNorthEast(cells[maxLine][1]);
  cells[0][0]->setEast(cells[0][1]);
  cells[0][0]->setSouthEast(cells[1][1]);
  cells[0][0]->setSouth(cells[1][0]);
  cells[0][0]->setSouthWest(cells[1][maxColumn]);
  cells[0][0]->setWest(cells[0][maxColumn]);
  cells[0][0]->setNorthWest(cells[maxLine][maxColumn]);
  
    //For column = maxColumn
  cells[0][maxColumn]->setNorth(cells[maxLine][maxColumn]);
  cells[0][maxColumn]->setNorthEast(cells[maxLine][0]);
  cells[0][maxColumn]->setEast(cells[0][0]);
  cells[0][maxColumn]->setSouthEast(cells[1][0]);
  cells[0][maxColumn]->setSouth(cells[1][maxColumn]);
  cells[0][maxColumn]->setSouthWest(cells[1][maxColumn-1]);
  cells[0][maxColumn]->setWest(cells[0][maxColumn-1]);
  cells[0][maxColumn]->setNorthWest(cells[maxLine][maxColumn-1]);
    
    //From column = 1 to column = maxColumn -1
  for(unsigned int column=1; column < cells[0].size() -1; column++)
  {
    cells[0][column]->setNorth(cells[maxLine][column]);
    cells[0][column]->setNorthEast(cells[maxLine][column+1]);
    cells[0][column]->setEast(cells[0][column+1]);
    cells[0][column]->setSouthEast(cells[1][column+1]);
    cells[0][column]->setSouth(cells[1][column]);
    cells[0][column]->setSouthWest(cells[1][column-1]);
    cells[0][column]->setWest(cells[0][column-1]);
    cells[0][column]->setNorthWest(cells[maxLine][column-1]);
  }
  
  //For line = maxLine
  
    //For column = 0
  cells[maxLine][0]->setNorth(cells[maxLine-1][0]);
  cells[maxLine][0]->setNorthEast(cells[maxLine-1][1]);
  cells[maxLine][0]->setEast(cells[maxLine][1]);
  cells[maxLine][0]->setSouthEast(cells[0][1]);
  cells[maxLine][0]->setSouth(cells[0][0]);
  cells[maxLine][0]->setSouthWest(cells[0][maxColumn]);
  cells[maxLine][0]->setWest(cells[maxLine][maxColumn]);
  cells[maxLine][0]->setNorthWest(cells[maxLine-1][maxColumn]);
  
    //For column = maxColumn
  cells[maxLine][maxColumn]->setNorth(cells[maxLine-1][maxColumn]);
  cells[maxLine][maxColumn]->setNorthEast(cells[maxLine-1][0]);
  cells[maxLine][maxColumn]->setEast(cells[maxLine][0]);
  cells[maxLine][maxColumn]->setSouthEast(cells[0][0]);
  cells[maxLine][maxColumn]->setSouth(cells[0][maxColumn]);
  cells[maxLine][maxColumn]->setSouthWest(cells[0][maxColumn-1]);
  cells[maxLine][maxColumn]->setWest(cells[maxLine][maxColumn-1]);
  cells[maxLine][maxColumn]->setNorthWest(cells[maxLine-1][maxColumn]);
  
    //From column = 1 to column = maxColumn-1
  for(unsigned int column=1; column < cells[0].size() -1; column++)
  {
    cells[maxLine][column]->setNorth(cells[maxLine-1][column]);
    cells[maxLine][column]->setNorthEast(cells[maxLine-1][column+1]);
    cells[maxLine][column]->setEast(cells[maxLine][column+1]);
    cells[maxLine][column]->setSouthEast(cells[0][column+1]);
    cells[maxLine][column]->setSouth(cells[0][column]);
    cells[maxLine][column]->setSouthWest(cells[0][column-1]);
    cells[maxLine][column]->setWest(cells[maxLine][column-1]);
    cells[maxLine][column]->setNorthWest(cells[maxLine-1][column-1]);
  }
  
  
  //From line = 1 to line = maxLine -1
  
  for(unsigned int line=1; line < cells.size() -1; line++)
  {
    //For column = 0
    cells[line][0]->setNorth(cells[line-1][0]);
    cells[line][0]->setNorthEast(cells[line-1][1]);
    cells[line][0]->setEast(cells[line][1]);
    cells[line][0]->setSouthEast(cells[line+1][1]);
    cells[line][0]->setSouth(cells[line+1][0]);
    cells[line][0]->setSouthWest(cells[line+1][maxColumn]);
    cells[line][0]->setWest(cells[line][maxColumn]);
    cells[line][0]->setNorthWest(cells[line-1][maxColumn]);
  
    //For column = maxColumn
    cells[line][maxColumn]->setNorth(cells[line-1][maxColumn]);
    cells[line][maxColumn]->setNorthEast(cells[line-1][0]);
    cells[line][maxColumn]->setEast(cells[line][0]);
    cells[line][maxColumn]->setSouthEast(cells[line+1][0]);
    cells[line][maxColumn]->setSouth(cells[line+1][maxColumn]);
    cells[line][maxColumn]->setSouthWest(cells[line+1][maxColumn-1]);
    cells[line][maxColumn]->setWest(cells[line][maxColumn-1]);
    cells[line][maxColumn]->setNorthWest(cells[line-1][maxColumn-1]);
    
    //From column = 1 to column = maxColumn -1
    for(unsigned int column=1; column < cells[line].size() -1; column++)
    {
      cells[line][column]->setNorth(cells[line-1][column]);
      cells[line][column]->setNorthEast(cells[line-1][column+1]);
      cells[line][column]->setEast(cells[line][column+1]);
      cells[line][column]->setSouthEast(cells[line+1][column+1]);
      cells[line][column]->setSouth(cells[line+1][column]);
      cells[line][column]->setSouthWest(cells[line+1][column-1]);
      cells[line][column]->setWest(cells[line][column-1]);
      cells[line][column]->setNorthWest(cells[line-1][column-1]);
    }
  }
}

void Tore::iterate()
{
  for(unsigned int line = 0; line < cells.size(); line++)
  {
    for(unsigned int column = 0; column < cells[line].size(); column++)
    {
      cells[line][column]->iterate();
    }
  }
  
  for(unsigned int line = 0; line < cells.size(); line++)
  {
    for(unsigned int column = 0; column < cells[line].size(); column++)
    {
      cells[line][column]->apply();
    }
  }
}

const Cell& Tore::getCell(int line, int column)
{
  return *cells[line][column];
}
