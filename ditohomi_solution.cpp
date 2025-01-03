#include <iostream>
#include <cmath>
#include <vector>
#define double long double
#define endl '\n'
using namespace std;
struct Polinomial
{
    Polinomial() = default;
    vector<double> coefs;
    Polinomial(int deg)
    {
        this->coefs.resize(deg + 1, 0);
        for(int i = 0; i < this->coefs.size(); i++)
        {
            cout << "Enter coefficient " << i + 1 << '\n';
            cin >> coefs[i];
        }
    }
    double calculate(double x)
    {
        double result = 0;
        for(int i = 0; i < this->coefs.size(); i++)
        {
            result += coefs[i] * pow(x, i);
        }
        return result;
    }
};
double ditohomy(double A, double B, double epsilon)
{
    int deg;
    cout << "Enter Polinomial deg \n";
    cin >> deg;
    Polinomial polinom = Polinomial(deg);
    while (true)
    {
        double y = (A - epsilon + B) / 2.0;
        double z = (A + epsilon + B) / 2.0;
        double a_next = 0;
        double b_next = 0;
        if(polinom.calculate(y) <= polinom.calculate(z))
        {
            a_next = A;
            b_next = z;
        }else
        {
            a_next = y;
            b_next = B;
        }
        double L2_power = (b_next - a_next);
        if(L2_power <= epsilon)
        {
            return (a_next + b_next) / 2.0;
        }
        A = a_next;
        B = b_next;
    }
    return 0;
}
void ditohomy_init()
{
    double A, B;
    cout << "Enter the left and right boundaries of the uncertainty  \n";
    cin >> A >> B;

    double epsilon;
    cout << "Enter epsilon \n";
    cin >> epsilon;
    cout << ditohomy(A, B, epsilon);
}
int main()
{
    ditohomy_init();
}
