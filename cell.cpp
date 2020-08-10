#include "cell.hpp"

Cell::Cell(): is_exposed_(false), is_flagged_(false) {};

Cell::~Cell() {};

Cell::Cell(const Cell& other):
  is_exposed_(other.is_exposed_),
  is_flagged_(other.is_flagged_) {}
