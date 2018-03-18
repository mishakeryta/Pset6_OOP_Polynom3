 #include "Polynom.hpp"


 //Конвертування було взято з інтернету так ,як  звичайного конвертування  не має
 //не 11 стандарт





std::string Polynom :: NumberToStr(double val) const
{
        std :: ostringstream stream;
        stream<<val;
        if (stream.fail())
        {
                return "fail";
        }
        std :: string  result(stream.str());
        return result;

}
 Polynom :: Polynom(double valA , double valB, double valC)
 {
        this->valA = valA;
        this->valB = valB;
        this->valC = valC;
 }
 void Polynom :: SetABC(double valA,double valB,double valC)
 {
        this->valA = valA;
        this->valB = valB;
        this->valC = valC;
 }
 Polynom :: Polynom()
 {
        valA = valB = valC = 0;
 }

 Polynom :: Polynom(double val)
 {
        valA = valB = valC = val;
 }

  double Polynom :: FindValue(double valX) const
 {
        return valX*valX*valA + valX*valB + valC;
 }

  double Polynom :: FindDerivativeValue(double valX) const
 {
        return valX*2*valA + valB;
 }

 double Polynom :: FindPrimitiveValue(double valX,double valConst) const
 {
        return  (valX*valX*valX*valA)/3 +(valX*valX*valB)/2 + valC*valX;
 }
 double Polynom :: FindIntegralValue(double leftScope, double rightScope) const
 {
        if(leftScope>rightScope)
        {
                double tmp = leftScope;
                leftScope = rightScope;
                rightScope = tmp;
        }
        return FindPrimitiveValue(rightScope,0) - FindPrimitiveValue(leftScope,0);
 }

Polynom Polynom :: MinusPolynoms(const Polynom& pol1,const Polynom& pol2)
{
        Polynom result(pol1.GetA() - pol2.GetA(),pol1.GetB() - pol2.GetB(),pol1.GetC() - pol2.GetC());
        return result;
}
Polynom Polynom :: PlusPolynoms(const Polynom& pol1,const Polynom& pol2)
{
        Polynom result(pol1.GetA() + pol2.GetA(),pol1.GetB() + pol2.GetB(),pol1.GetC() + pol2.GetC());

        return result;
}

int  Polynom :: FindRoots(double&root1,double &root2)  const
{
        double valD =  valB*valB - 4*valA*valC;
        if(valD < 0) return -1;
        root1 = (- valB + sqrt(valD)) / (2 * valA);
        root2 = (- valB - sqrt(valD)) / (2 * valA);
        return 1;
}



std :: string  Polynom :: ToString() const
{
        std :: string result = "";
        bool wasNoNull = 0;
        if(valA)
        {
                wasNoNull = 1;
                if(valA<0)
                {
                        result += " - ";
                }
                if(fabs(valA) != 1)
                {
                        result += NumberToStr(fabs(valA));
                }
                result += "X^2";
                if(valB > 0)
                {
                        result += " + ";
                }

        }
        if(valB <0 )
        {
                result += " - ";
        }

        if(valB)
        {
                wasNoNull = 1;
                if(fabs(valB) != 1)
                {
                        result += NumberToStr(fabs(valB));
                }
                result += "X";
                if(valC > 0)
                {
                        result += " + ";
                }
        }
        if(valC < 0)
        {
                result += " - ";
        }
        if(valC)
        {
                result += NumberToStr(fabs(valC));
        }
        else if(!wasNoNull)
        {
                result += " 0 ";
        }
        return result;
}









