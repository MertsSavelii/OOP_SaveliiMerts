#ifndef OCTAGON_H
#define OCTAGON_H

#include <iostream>

#include "figure.h"
#include "point.h"

class Octagon : public Figure {
public:
    Octagon();
    Octagon(Point a, Point b, Point c, Point d, Point e, Point f, Point g, Point h);

    friend std::istream& operator>>(std::istream& is,  Octagon& obj);
    friend std::ostream& operator<<(std::ostream& os, const Octagon& obj);

    virtual ~Octagon();

    size_t VertexesNumber();
    double Area();
    Octagon& operator=(const Octagon& other);
    bool operator==(const Octagon& other);

private:
    Point a_, b_, c_, d_, e_, f_, g_, h_;
};

#endif