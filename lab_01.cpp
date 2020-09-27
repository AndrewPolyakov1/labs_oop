#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>
#include <stdexcept>
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
        if ( this->b == 0 || right.a == 0 ) {
        throw std::invalid_argument( "Received zero value when dividing" );
    }
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
    bool operator<(const Rational& right)
    {
        return ((this->a * right.b) < (this->a * right.b));
    }
    //= operator overloading
    bool operator==(const Rational& right)
    {
        return ((this->a * right.b) == (this->a * right.b));
    }
    //>= operator overloading
    bool operator>=(const Rational& right)
    {
        return ((this->a * right.b) >= (this->a * right.b));
    }
    //<= operator overloading
    bool operator<=(const Rational& right)
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
    n1 = abs(n1);
    n2 = abs(n2);
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
    ifstream input;
    input.open ("output.t");
    if(!input.is_open())
    {
        cout << "Error opening file" << endl;
        return -1;
    }

    int counter = 0;
    int a1, a2, b1, b2;
    string line;
    Rational a, b, c;
    while (getline(input, line))
    {
        counter++;
        input >> a1 >> a2 >> b1 >> b2;
        if((a2 > 0) && (b2 > 0))
        {
        a.setA(a1);
        a.setB(a2);
        b.setA(b1);
        b.setB(b2);

        //tests
        printf("Test [ %d ]: \n",counter);
        try
        {
            c = a + b;
        }
        catch(const std::exception& e)
        {
            std::cerr << e.what() << '\n';
        }
        printf("%d/%d + %d/%d = %d/%d; \n", a1, a2, b1, b2, c.getA(),c.getB());

        try
        {
            c = a - b;
        }
        catch(const std::exception& e)
        {
            std::cerr << e.what() << '\n';
        }
        printf("%d/%d - %d/%d = %d/%d; \n", a1, a2, b1, b2, c.getA(),c.getB());

        try
        {
            c = a * b;
        }
        catch(const std::exception& e)
        {
            std::cerr << e.what() << '\n';
        }
        printf("%d/%d * %d/%d = %d/%d; \n", a1, a2, b1, b2, c.getA(),c.getB());

        try
        {
            c = a / b;
        }
        catch(const std::exception& e)
        {
            std::cerr << e.what() << '\n';
        }
        printf("%d/%d / %d/%d = %d/%d; \n", a1, a2, b1, b2, c.getA(),c.getB());


        }
        else
        {
           cout << "Test " << counter << " error: division by zero" << endl;
        }


    }
    return 0;
}