#include <iostream>
#include <cmath>
#include <vector>
#include <iomanip>
#include "custom_functions.cpp"
#define double long double
#define endl '\n'
using namespace std;
const double epsilon = 0.0001;
double calculateStandardDeviation(double correctAnswer, double algorithmAnswer) {
    double mean = (correctAnswer + algorithmAnswer) / 2.0;
    double stdDev = sqrt((pow(correctAnswer - mean, 2) + pow(algorithmAnswer - mean, 2)) / 2.0);
    return stdDev;
}
double bolcano_koshi(double A, double B)
{  
    cout << "Enter the highest degree of a polynomial \n";
    int deg;
    cin >> deg;
    Polinomial function = Polinomial(deg);
    int leftsign = function.calculate(A) >= 0 ? 1 : -1;
    int rightsign = function.calculate(B) >= 0 ? 1 : -1;
    if(leftsign == rightsign)
    {
        cout << "No roots on [" << A << ", " << B << ']' << '\n';
        return 0;
    }
    while (true)
    {
        double mid = (A + B) / 2.0;
        double result = function.calculate(mid);
        bool condition = leftsign == -1 && rightsign == 1 ? result < 0 : result >= 0;
        if(condition)
        {
            A = mid;
        }
        else
        {
            B = mid;
        }
        if(abs(B - A) <= epsilon)
        {
            cout << "Standard Deviation: " << calculateStandardDeviation(mid, 1) << endl;
            return mid;
        }
    }
    
    return 0;
}
void bolcano_koshi_init()
{
    double A, B;
    cout << "Enter the left and right boundaries of the uncertainty  \n";
    cin >> A >> B;

  
    cout << bolcano_koshi(A, B);
}
int main()
{
    cout << fixed << setprecision(20);
    bolcano_koshi_init();
}
