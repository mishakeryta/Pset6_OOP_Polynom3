#ifndef POLYNOM_HPP
#define POLYNOM_HPP
#include <sstream>
#include <string>
#include <math.h>
class Polynom
{
        
       
        public:
        Polynom();
        Polynom(double val);
        Polynom(double valA ,double valB ,double valC );
        void SetABC(double valA,double valB,double valC);
        Polynom& SetA(double valA){this->valA = valA; return *this;}
        double GetA() const {return valA;}
        Polynom& SetB(double valB){this->valB = valB; return *this;}
        double GetB() const {return valB;}
        Polynom& SetC(double valC) {this->valC = valC; return *this;}
        double GetC() const { return valC;}
        double FindDerivativeValue(double valX) const;
        double FindIntegralValue(double leftScope,double rightScope) const;
        double FindPrimitiveValue(double valX,double valConst) const;
        int  FindRoots(double& root1, double& root2) const;
        std :: string ToString() const;
        Polynom operator!();
        double operator()(double val);
        double operator[](int index);
        Polynom operator+(const Polynom& polynom2);
        Polynom operator-(const Polynom& polynom2);

 //       ~Polynom() { --count; }
        private:
        double valA;
        double valB;
        double valC;
       // static int count;
        std::string Polynom :: NumberToStr(double val) const;
};
#endif

