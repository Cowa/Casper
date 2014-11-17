#ifndef CELL_HPP
#define CELL_HPP

class AbstractCell
{
  private:
    AbstractCell* north;
    AbstractCell* northEast;
    AbstractCell* east;
    AbstractCell* southEast;
    AbstractCell* south;
    AbstractCell* southWest;
    AbstractCell* west;
    AbstractCell* northWest;
    
  public:
    void setNorth(AbstractCell* cell);
    void setNorthEast(AbstractCell* cell);
    void setEast(AbstractCell* cell);
    void setSouthEast(AbstractCell* cell);
    void setSouth(AbstractCell* cell);
    void setSouthWest(AbstractCell* cell);
    void setWest(AbstractCell* cell);
    void setNorthWest(AbstractCell* cell);
};

#endif //CELL_HPP
