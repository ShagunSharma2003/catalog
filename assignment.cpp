#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

class Polynomial {
private:
    vector<int> coefficients;
public:
    
    Polynomial(const vector<int>& coeffs) {
        coefficients = coeffs;
    }

    void display() const {
        int degree = coefficients.size() - 1;
        for (int i = 0; i < coefficients.size(); ++i) {
            if (coefficients[i] != 0) {
                if (i != 0 && coefficients[i] > 0) cout << " + ";
                cout << coefficients[i];
                if (degree - i > 0) cout << "x^" << degree - i;
            }
        }
        cout << endl;
    }
    int evaluate(int x) const {
        int result = 0;
        int degree = coefficients.size() - 1;
        for (int i = 0; i < coefficients.size(); ++i) {
            result += coefficients[i] * pow(x, degree - i);
        }
        return result;
    }
};

int main() {
   
    vector<int> coeffs = {3, 2, 1};
    Polynomial p(coeffs);

    cout << "The polynomial is: ";
    p.display();

    int x = 2;
    cout << "Evaluating the polynomial at x = " << x << " gives: " 
         << p.evaluate(x) << endl;

    return 0;
}
