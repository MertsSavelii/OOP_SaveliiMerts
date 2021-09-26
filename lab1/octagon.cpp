#include "octagon.h"

#include <cmath>

static Point a_, b_, c_, d_, e_, f_, g_, h_;

Octagon::Octagon()
    : len_a(0.0),
    len_b(0.0),
    len_c(0.0),
    len_d(0.0),
    len_e(0.0),
    len_f(0.0),
    len_g(0.0),
    len_h(0.0),
    InPoint(0,0) {
  //std::cout << "Default octagon created" << std::endl;
}

Octagon::Octagon(double a, double b, double c, double d, double e, double f, double g,
                 double h, Point In)
    : len_a(a),
    len_b(b),
    len_c(c),
    len_d(d),
    len_e(e),
    len_f(f),
    len_g(g),
    len_h(h),
    InPoint(In) {
  //std::cout << "Octagon created" << std::endl;
}

Octagon::Octagon(std::istream &is) { 
    is >> a_ >> b_ >> c_ >> d_ >> e_ >> f_ >> g_ >> h_;
      len_a = a_.dist(b_); 
      len_b = b_.dist(c_);
      len_c = c_.dist(d_);
      len_d = d_.dist(e_);
      len_e = e_.dist(f_);
      len_f = f_.dist(g_);
      len_g = g_.dist(h_);
      len_h = h_.dist(a_);
      InPoint = a_.MidDot(c_);
  //std::cout << "Octagon created via istream" << std::endl;
}

Octagon::Octagon(const Octagon& other)
    : Octagon(other.len_a, other.len_b, other.len_c, other.len_d, other.len_e, other.len_f,
              other.len_g, other.len_h, other.InPoint) {
  //std::cout << "Made copy of octagon" << std::endl; 

}

size_t Octagon::VertexesNumber() {
    return 8;
}

void Octagon::Print(std::ostream& os) {
    os << "Octagon: ";
    os <<  a_ << " ";
    os <<  b_ << " ";
    os <<  c_ << " ";
    os <<  d_ << " ";
    os <<  e_ << " ";
    os <<  f_ << " ";
    os <<  g_ << " ";
    os <<  h_ << " ";
    os << std::endl;
}

double Octagon::Area() {
    double Ia = InPoint.dist(a_);
    double Ib = InPoint.dist(b_);
    double Ic = InPoint.dist(c_);
    double Id = InPoint.dist(d_);
    double Ie = InPoint.dist(e_);
    double If = InPoint.dist(f_);
    double Ig = InPoint.dist(g_);
    double Ih = InPoint.dist(h_);
    Triangle Ta(len_a, Ia, Ib);
    Triangle Tb(len_b, Ib, Ic);
    Triangle Tc(len_c, Ic, Id);
    Triangle Td(len_d, Id, Ie);
    Triangle Te(len_e, Ie, If);
    Triangle Tf(len_f, If, Ig);
    Triangle Tg(len_g, Ig, Ih);
    Triangle Th(len_h, Ih, Ia);
    double OctArea = Ta.Area() + Tb.Area() + Tc.Area() + Td.Area() + Te.Area() + Tf.Area()
                     + Tg.Area() + Th.Area();
    return OctArea;
}

Octagon::~Octagon() {
    //std::cout << "Octagon deleted" << std::endl;
}
