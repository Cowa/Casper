#include "../../include/core/StateCell.hpp"

StateCell::EmptyCell* StateCell::emptyCell()
{
  return EmptyCell::instance_;
}

StateCell::AliveCell* StateCell::aliveCell()
{
  return AliveCell::instance_;
}
