#include <iostream>
#include <string>
#include <exception>

using namespace std;

class Empty
{};

class Error
{
    double a, b, c;
public:
    Error(double a, double b, double cc)
        : a(a), b(b), c(c)
    {}

    double What() 
    { 
        if (a == 0 || b == 0 || c == 0) 
            cout << "error"; 
        else 
            return sqrt(((a + b + c) / 2) * ((a + b + c) / 2 - a) * 
                ((a + b + c) / 2 - b) * ((a + b + c) / 2 - c));
    }
};

class E : 
    public exception
{
    string message;
public:
    E(string message)
        : message(message)
    {}
    string What() { return message; }
};

double Area1(double a, double b, double c)
{
    if ((a == 0 || b == 0 || c == 0) && (a >= b + c && b >= a + c && c >= a + b))
        throw 1;

    return sqrt(((a + b + c) / 2) * ((a + b + c) / 2 - a) *
        ((a + b + c) / 2 - b) * ((a + b + c) / 2 - c));
}

double Area2(double a, double b, double c) 
{
    if ((a == 0 || b == 0 || c == 0) && (a >= b + c && b >= a + c && c >= a + b))
        throw 1.0;

    return sqrt(((a + b + c) / 2) * ((a + b + c) / 2 - a) *
        ((a + b + c) / 2 - b) * ((a + b + c) / 2 - c));
}

double Area3(double a, double b, double c) 
{
    if ((a == 0 || b == 0 || c == 0) && (a >= b + c && b >= a + c && c >= a + b))
        throw '1';

    return sqrt(((a + b + c) / 2) * ((a + b + c) / 2 - a) *
        ((a + b + c) / 2 - b) * ((a + b + c) / 2 - c));
}

double Area4(double a, double b, double c) 
{
    if ((a == 0 || b == 0 || c == 0) && (a >= b + c && b >= a + c && c >= a + b))
        throw Empty();

    return sqrt(((a + b + c) / 2) * ((a + b + c) / 2 - a) *
        ((a + b + c) / 2 - b) * ((a + b + c) / 2 - c));
}

double Area5(double a, double b, double c)
{
    if (a < 0 || b < 0 || c < 0)
        throw Error(a, b, c);

    return sqrt(((a + b + c) / 2) * ((a + b + c) / 2 - a) *
        ((a + b + c) / 2 - b) * ((a + b + c) / 2 - c));
}

double Area6(double a, double b, double c)
{
    if ((a < 0 && b < 0) || (c < 0))
        throw E("too small ");

    return sqrt(((a + b + c) / 2) * ((a + b + c) / 2 - a) *
        ((a + b + c) / 2 - b) * ((a + b + c) / 2 - c));
}

void FU()
{
    cout << "unexpected error! - bad_exception" << endl;
    throw;
}

void FT()
{
    cout << "unknown error! - terminate" << endl;
    abort();
}

int main()
{
    set_unexpected(FU);
    //set_terminate(FT);

    double x, y, z;
    cout << "x = "; cin >> x;
    cout << "y = "; cin >> y;
    cout << "z = "; cin >> z;
    cout << endl;

    try
    {
        cout << Area1(x, y, z) << endl;
        cout << Area2(x, y, z) << endl;
        cout << Area3(x, y, z) << endl;
        cout << Area4(x, y, z) << endl;
        cout << Area5(x, y, z) << endl;
        cout << Area6(x, y, z) << endl;
    }

    catch (int)
    {
        cout << " catch (int) <= Area1()" << endl;
    }

    catch (double)
    {
        cout << " catch (double) <= Area2()" << endl;
    }

    catch (char)
    {
        cout << " catch (char) <= Area3()" << endl;
    }

    catch (Empty)
    {
        cout << " catch (Empty) <= Area4()" << endl;
    }

    catch (Error& e)
    {
        cout << e.What() << endl;
    }

    catch (bad_exception a)
    {
        cout <<  a.what() << endl;
    }
   
    /*catch (E e)
    {
     cout << e.What() << endl;
    }*/

    return 0;
}