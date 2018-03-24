 #include "Polynom.hpp"


 //������������� ���� ����� � ��������� ��� ,��  ���������� �������������  �� ��
 //�� 11 ��������



int Polynom::numOfPolynom= 0;
std::string  Polynom::NumberToStr(double val) const
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
double  StrToNumber(std::string str)
{
	double val = 0;
	if(str == "+" || str == "")
	{
		val =1;
	}
	else if(str == "-")
	{
        val -1;
	}
	else
	{
		std :: istringstream stream(str);
		stream>>val;
		if(stream.fail())
		{
			throw std::string("Some error");
		}
    }
    return val;
}
 Polynom :: Polynom(double valA , double valB, double valC)
{
        ++numOfPolynom;
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


 Polynom :: Polynom(const Polynom& polynom):valA(polynom.GetA()),valB(polynom.GetB()),valC(polynom.GetC())
 {
    ++numOfPolynom;
 }
 Polynom :: Polynom()
 {
        ++numOfPolynom;
        valA = valB = valC = 0;
 }

 Polynom :: Polynom(double val)
 {
        ++numOfPolynom;
        valA = valB = valC = val;
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

Polynom Polynom::operator !()
{
        return Polynom(-this->GetA(),-this->GetB(),-this->GetC());
}
double Polynom::operator()(double valX)
{
        return valX*valX*valA + valX*valB + valC;
}
double Polynom::operator[](int index)
{
        switch(index)
        {
                case 0:return valA;
                case 1:return valB;
                case 2:return valC;
                default: throw int(0);
        }
}
Polynom Polynom::operator+(const Polynom&  polynom2)const
{
        return Polynom(valA+ polynom2.GetA(),valB + polynom2.GetB(),
        valC + polynom2.GetC());
}
Polynom Polynom::operator-(const Polynom&  polynom2)const
{
        return Polynom(valA -  polynom2.GetA(),valB - polynom2.GetB(),
        valC - polynom2.GetC());
}
Polynom operator*(double val,const Polynom& polynom)
{
        return Polynom(val * polynom.GetA(),val*polynom.GetB(),val*polynom.GetC());
}
void operator<<(std::string& str,const Polynom& polynom)
{
        str = str + polynom.ToString();
}
void operator>>(const Polynom& polynom,std::string& str)
{
        str = str + polynom.ToString();
}
void operator<<(Polynom& polynom,const std::string& str)
{
	polynom.SetABC(0,0,0);
	std::string format = "";
	for(int i = 0;i<str.length();++i)
	{
			if(str[i] != ' ')
			{
				format += str[i];
            }
	}
	

	for(int index = 0;index<format.length();)
	{
		std::string tmpForDigits = "";
		std::string tmp = "";
		if(format[index] =='+' || format[index] == '-')
		{
			tmpForDigits += format[index];
			++index;
		}
		else
		{
			if(index != 0)
			{
				throw std::string("Bad format");
            }
        }
		ConDigits(tmpForDigits,format,index);
		double tmpVal = StrToNumber(tmpForDigits);
		ConNonDigits(tmp,format,index);
		polynom.AddToK(tmp,tmpVal);
    }
}
void ConDigits(std::string& destination,const std::string& source,int& index)
{
	if(source == "") return;
    if(source[index] == '-' || source[index] == '+') throw std::string("Bad format");
	while(index < source.length() && isdigit(source[index]))
	{
		destination += source[index];
		++index;
	}
}
void ConNonDigits(std::string& destination,const std::string& source,int& index)
{
	if(source == "") return;
		while(index < source.length() && !isdigit(source[index])
		&& source[index] != '-' && source[index] != '+')
		{
			destination += source[index];
			++index;
		}
}
Polynom& Polynom::AddToK(const std::string& strMember,double val)
{
	do
    {
		if (strMember == "x*x" || strMember == "x^2")
		{
			valA += val;
			break;
		}
		if (strMember == "x")
		{
			valB += val;
			break;
		}
		if (strMember == "")
		{
			valC += val;
			break;
		}
		throw std::string("I dont know what is it " + strMember);
		}
	while (0);
	return *this;
}
Polynom::~Polynom()
{
        --numOfPolynom;
}
 int Polynom::GetNumOfObj()
{
        return numOfPolynom;
}
bool operator ==(const Polynom& pol1, const Polynom& pol2)
{
	if(pol1.GetA() == pol2.GetA() && pol1.GetB() == pol2.GetB()
	&& pol1.GetC() == pol2.GetC())
	return true;
    return false;
}














