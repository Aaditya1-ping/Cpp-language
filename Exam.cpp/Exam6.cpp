#include <iostream>
#include <string> 
using namespace std;

class MathOperations {
public:
   
    double divide(float numerator, float denominator) {
        if (denominator == 0) {
            throw "Error: Division by zero is not allowed."; 
        }
        return numerator / denominator;
    }
};

int main() {
    MathOperations math;
    float num, den;

    cout << "Enter numerator: ";
    cin >> num;

    cout << "Enter denominator: ";
    cin >> den;

    try {
        float result = math.divide(num, den);
        cout << "Result: " << result << endl;
    } catch (const char* e) {
        cout << e << endl;
    }


}
/*
Output:
Enter numerator: 25
Enter denominator: 5
Result: 5

*/

