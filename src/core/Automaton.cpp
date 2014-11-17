#include "../../include/core/Automaton.hpp"

Automaton::Automaton(int longueur, int largeur) : cells(longueur, std::vector<Cell>(largeur))
{}
