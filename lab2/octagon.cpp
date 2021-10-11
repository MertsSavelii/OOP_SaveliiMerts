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
    std::cout << "Default octagon created" << std::endl;
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
  std::cout << "Octagon created" << std::endl;
}

std::istream& operator>>(std::istream& is, Octagon& obj) {
    is >> a_ >> b_ >> c_ >> d_ >> e_ >> f_ >> g_ >> h_;
      obj.len_a = a_.dist(b_); 
      obj.len_b = b_.dist(c_);
      obj.len_c = c_.dist(d_);
      obj.len_d = d_.dist(e_);
      obj.len_e = e_.dist(f_);
      obj.len_f = f_.dist(g_);
      obj.len_g = g_.dist(h_);
      obj.len_h = h_.dist(a_);
      obj.InPoint = a_.MidDot(c_);
  std::cout << "Octagon created via istream" << std::endl;
}

Octagon::Octagon(const Octagon& other)
    : Octagon(other.len_a, other.len_b, other.len_c, other.len_d, other.len_e, other.len_f,
              other.len_g, other.len_h, other.InPoint) {
    std::cout << "Made copy of octagon" << std::endl; 

}

size_t Octagon::VertexesNumber() {
    return 8;
}

std::ostream& operator<<(std::ostream& os, const Octagon& obj) {
    os << "Octagon: ";
    os <<  a_ << " ";
    os <<  b_ << " ";
    os <<  c_ << " ";
    os <<  d_ << " ";
    os <<  e_ << " ";
    os <<  f_ << " ";
    os <<  g_ << " ";
    os <<  h_ << " ";
    //os << std::endl; хз надо ли?
}

double Octagon::Area() {


  /*return 0.5 * abs((a_.getX() * b_.getY() + b_.getX() * c_.getY() + c_.getX() * d_.getY() + d_.getX() * e_.getY() + e_.getX() * f_.getY() +
    f_.getX() * g_.getY() + g_.getX() * h_.getY() + h_.getX() * a_.getY() - (b_.getX() * a_.getY() + c_.getX() * b_.getY() + 
    d_.getX() * c_.getY() + e_.getX() * d_.getY() + f_.getX() * e_.getY() + g_.getX() * f_.getY() + h_.getX() * g_.getY() +
    a_.getX() * h_.getY())));*/




    double Ia = InPoint.dist(a_);
    double Ib = InPoint.dist(b_);
    double Ic = InPoint.dist(c_);
    double Id = InPoint.dist(d_);
    double Ie = InPoint.dist(e_);
    double If = InPoint.dist(f_);
    double Ig = InPoint.dist(g_);
    double Ih = InPoint.dist(h_);
   
    double Pa = (len_a + Ia + Ib) / 2.0;
    double Pb = (len_b + Ib + Ic) / 2.0;
    double Pc = (len_c + Ic + Id) / 2.0;
    double Pd = (len_d + Id + Ie) / 2.0;
    double Pe = (len_e + Ie + If) / 2.0;
    double Pf = (len_f + If + Ig) / 2.0;
    double Pg = (len_g + Ig + Ih) / 2.0;
    double Ph = (len_h + Ih + Ia) / 2.0;

     Pa = sqrt(abs(Pa * (Pa - len_a) * (Pa - Ia) * (Pa - Ib)));
     Pb = sqrt(abs(Pb * (Pb - len_b) * (Pa - Ib) * (Pa - Ic)));
     Pc = sqrt(abs(Pc * (Pc - len_c) * (Pc - Ic) * (Pc - Id)));
     Pd = sqrt(abs(Pd * (Pd - len_d) * (Pd - Id) * (Pd - Ie)));
     Pe = sqrt(abs(Pe * (Pe - len_e) * (Pe - Ie) * (Pe - If)));
     Pf = sqrt(abs(Pf * (Pf - len_f) * (Pf - If) * (Pf - Ig)));
     Pg = sqrt(abs(Pg * (Pg - len_g) * (Pg - Ig) * (Pg - Ih)));
     Ph = sqrt(abs(Ph * (Ph - len_h) * (Ph - Ih) * (Ph - Ia)));

    double OctArea = Pa + Pb + Pc + Pd + Pe + Pf + Pg + Ph;
    return OctArea;
}

Octagon& Octagon::operator=(const Octagon& other) {
  if (this == &other)
    return *this;

  len_a = other.len_a;
  len_b = other.len_b;
  len_c = other.len_c;
  len_d = other.len_d;
  len_e = other.len_e;
  len_f = other.len_f;
  len_g = other.len_g;
  len_h = other.len_h;
  InPoint = other.InPoint;

  std::cout << "Octagon copied" << std::endl;
  
  return *this;
}

bool Octagon::operator==(const Octagon& other) {
    if(len_a != other.len_a) return false;
    if(len_b != other.len_b) return false;
    if(len_c != other.len_c) return false;
    if(len_d != other.len_d) return false;
    if(len_e != other.len_e) return false;
    if(len_f != other.len_f) return false;
    if(len_g != other.len_g) return false;
    if(len_h != other.len_h) return false;
    if(InPoint != other.InPoint) return false;

    return true;
}


Octagon::~Octagon() {
    std::cout << "Octagon deleted" << std::endl;
}
