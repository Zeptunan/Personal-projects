#include <string>
#include <cmath>
#include <iostream>
#include <sstream>

using std::endl; 
using std::cout;
using std::cin;
using std::getline;


double addition_subtraction(std::string numbers, double result) {  
    std::istringstream stream(numbers);
    double num;

    while(stream >> num) {
        result += num;
    }

    return result;
}


double multiplication(std::string numbers, double result) {
    std::istringstream stream(numbers);
    double num;

    while(stream >> num) {
        result *= num;
    }

    return result;
}


double division(double a, double b) {
    double result = 0;
    result = a/b;
    return result;
}


double hypotenuse(double a, double b) {
    return sqrt((a * a) + (b * b)); 
}

double missing_side(double a, double c){
    return sqrt((c * c) - (a * a));
}

int factorial(int f, int res){
    res = 1;
    for(; f > 0; f--) {
        res *= f;
    }
    return res; 
}

void calculator() {
    while (true){
        cout << "What would you like to do?" << endl; 
        cout << "addition/subtraction = 1" << endl << 
        "multiplications = 2" << endl << "division = 3" << endl 
        << "Square root = 4" << endl << "factorial = 5" << endl 
        << "enter any other number to quit" << endl << "choice: "; 
        int choice, f, res; 
        cin >> choice; 
        std::string numbers;
        double result, start_value, a, b, c;
        cin.ignore();
        if(choice == 1) {
            result = 0;
            cout << "choose the numbers you would like to add: "; 
            getline(cin, numbers); 
            result = addition_subtraction(numbers, result);
            cout << "The result is: " << result << "\n\n\n";
        }else if(choice == 2) {
            result = 0;
            cout << "choose the numbers you would like to multiply: ";
            result = 1.0; 
            getline(cin, numbers); 
            result = multiplication(numbers, result);
            cout << "The result is: " << result << "\n\n\n"; 
        }else if(choice == 3) {
            cout << "choose the numerator: ";
            getline(cin, numbers);
            result = 0;
            a = addition_subtraction(numbers, result);
            cout << "choose the denominator: "; 
            getline(cin, numbers); 
            result = 0;
            b = addition_subtraction(numbers, result);
            while(b == 0) {
                cout << "Error: Division by zero is not allowed." << endl << "Choos new denominator: ";
                getline(cin, numbers); 
                b = addition_subtraction(numbers, result);
            }
            result = division(a, b);
            cout << "The result is: " << result << "\n\n\n"; 
        }else if(choice == 4) {
            cout << "calculate the hypotenuse = 1" << endl
            << "calculate missing side = 2" << endl;
            cout << "choice: ";
            cin >> choice;
            if(choice == 1){
                result = 0;
                cout << "choose the length of side a: ";
                cin >> a;
                cout << "choose the length of side b: ";
                cin >> b;
                result = hypotenuse(a,b);
                cout << "the hypotenuse is: " << result << "\n\n\n";
            }else if(choice == 2) {
                result = 0;
                cout << "choose the hypotenuse: ";
                cin >> c;
                cout << "choose one side: ";
                cin >> a;
                result = missing_side(a,c);
                cout << "the length of the missing side is: " << result << "\n\n\n";
            }
        }else if(choice == 5) {
            cout << "enter factorial number: ";
            cin >> f; 
            res = factorial(f, res);
            cout << "the factorial for " << f << " is: " << res << "\n\n\n";
        }else if(choice < 1 || choice > 5) {
            cout << "Exiting calculator. Goobye";
            break;
        }   
    }   
}

int main() {
    calculator();
    return 0;
}
