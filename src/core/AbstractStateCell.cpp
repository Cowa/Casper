#include "../../include/core/AbstractStateCell.hpp"

bool AbstractStateCell::isState(AbstractStateCell* state) const
{
  return state == this; //All state are singletons, so if state has the same class as this, it is the same instance
}
