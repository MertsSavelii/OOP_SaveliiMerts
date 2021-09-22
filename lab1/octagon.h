#ifndef OCTAGON_H
#define OCTAGON_H

#include <figure.h>

#include <iostream>


class Octagon : public Figure {
public:
    Octagon();
    Octagon(double a, double b, double c);
    Octagon(std::istream &is);
    Octagon(const Octagon& other);

    virtual ~Octagon();

    void Print();
    double Square();
    

private:
    double len_a, len_b, len_c;
};

#endif
