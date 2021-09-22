#include <iostream>
#include "triangle.h"
#include "point.h"

using namespace std;
int main()
{
    Triangle puk(cin);
    puk.Print();
    cout<<puk.Square()<<endl;
}