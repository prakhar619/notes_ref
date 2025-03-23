#include "2_modularity.h"
//Implementation

Vector1::Vector1(int s):elem{new double[s]}, sz{s} {}
double& Vector1::operator[](int i) { return elem[i];}
int Vector1::size() { return sz ;}
