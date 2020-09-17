#include <iostream>
using namespace std;

int NOD(int n1,int n2);


class Rational
{
public:
        int a;
        int b;

    void setA(int n)
    {
        a = n;
    }
    void setB(int n)
    {
        b = n;
    }
    int getA()
    {
        return a;
    }

    int getB()
    {
        return b;
    }

    void reduce ();

    Rational(){}

   Rational(int n1, int n2)
    {
       a = n1;
       b = n2;
    }
    ~Rational(){}
    void printRes()
    {
        cout << a << " " << b << endl;
    }
    //+ operator overloading
    Rational operator+(const Rational& right)
    {
        Rational ans;
        ans.a = (this->a * right.b) + (this->b * right.a);
        ans.b = (this->b * right.b);
        ans.reduce();
        return ans;
    }
    //- operator overloading
    Rational operator-(const Rational& right)
    {
        Rational ans;
        ans.a = (this->a * right.b) - (this->b * right.a);
        ans.b = (this->b * right.b);
        ans.reduce();
        return ans;
    }
    //* operator overloading
    Rational operator*(const Rational& right)
    {
        Rational ans;
        ans.a = (this->a * right.a);
        ans.b = (this->b * right.b);
        ans.reduce();
        return ans;
    }
    //* operator overloading
    Rational operator/(const Rational& right)
    {
        Rational ans;
        ans.a = (this->a * right.b);
        ans.b = (this->b * right.a);
        ans.reduce();
        return ans;
    }
    //> operator overloading
    bool operator>(const Rational& right)
    {
        return ((this->a * right.b) > (this->a * right.b));
    }
    //< operator overloading
    bool operator>(const Rational& right)
    {
        return ((this->a * right.b) < (this->a * right.b));
    }
    //= operator overloading
    bool operator>(const Rational& right)
    {
        return ((this->a * right.b) = (this->a * right.b));
    }
    //>= operator overloading
    bool operator>(const Rational& right)
    {
        return ((this->a * right.b) >= (this->a * right.b));
    }
    //<= operator overloading
    bool operator>(const Rational& right)
    {
        return ((this->a * right.b) <= (this->a * right.b));
    }
};

void Rational::reduce()
{
    int a = this->a;
    int b = this->b;
    if(a == 0) //That or segmentation fault
    {
        this->b = 1;
        return;
    }
    int k = NOD(a,b);
    this->a = int(a/k);
    this->b = int(b/k);
}

//Algorithm for finding NOD
int NOD(int n1, int n2)
{

  int div;
  if (n1 == n2)
    return n1;
  int d = n1 - n2;
  if (d < 0)
  {
    d = -d;
    div = NOD(n1, d);
  }
  else
  {
    div = NOD(n2, d);
  }
  return div;

}

int main()
{
    Rational n1(1,2);
    Rational n2(2,4);
    Rational n3;

    n3 = n1 - n2;
    n3.printRes();
    n3.reduce();
    n3.printRes();
    return 0;
}