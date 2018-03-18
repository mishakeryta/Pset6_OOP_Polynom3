

#ifndef POLYNOM_HPP
#define POLYNOM_HPP
#include <sstream>
#include <string>
#include <math.h>
class Polynom
{
        
        private:
        double valA;
        double valB;
        double valC;
        std::string Polynom :: NumberToStr(double val) const;
        public:
        Polynom();
        Polynom(double val);
        Polynom(double valA ,double valB ,double valC );
        void SetABC(double valA,double valB,double valC);
        void SetA(double valA){this->valA = valA;}
        double GetA() const {return valA;}
        void SetB(double valB){this->valB = valB;}
        double GetB() const {return valB;}
        void SetC(double valC) {this->valC = valC;}
        double GetC() const { return valC;}
        double FindValue(double valX) const;
        double FindDerivativeValue(double valX) const;
        double FindIntegralValue(double leftScope,double rightScope) const;
        double FindPrimitiveValue(double valX,double valConst) const;
        int  FindRoots(double& root1, double& root2) const;
        static Polynom MinusPolynoms(const Polynom& pol1,const Polynom& pol2);
        static Polynom PlusPolynoms(const Polynom& pol1,const Polynom& pol2);
        std :: string ToString() const;
};
#endif
