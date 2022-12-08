#include <iostream>
#include <sstream>

using namespace std;

//greatest common divisor function
int gcd(int n, int m) {
    while (m != 0) {
        int t = m;
        m = n % m;
        n = t;
    }
    return n;
}

//least common multiple function
int lcm(int n, int m) {
    return m == 0 ? throw invalid_argument("the second number is zero, abort") : (m / gcd(n, m)) * n;
}

enum Number {
    first_number,
    second_number
};

string stringBuild(Number number = first_number) {
    return number == first_number ? "Input the first number: " : "Input the second number: ";
}

//ASCII
constexpr int digitsStart = 47;
constexpr int digitsEnd = 58;

int inputNumber() {

    string myString, parsed;
    do {
        getline(cin, myString);
        istringstream iss(myString);
        do {
            string subs;
            iss >> subs;

            //checks if char is a digit and adds it to a parsed string
            for (char &c: subs) {
                if (c > digitsStart && c < digitsEnd) {
                    parsed.push_back(c);
                }
            }
        } while (iss);
    } while (parsed.empty());
    return atoi(parsed.c_str());
}

int main() {
    int n, m;

    cout << stringBuild(first_number) << endl;
    n = inputNumber();
    cout << stringBuild(second_number) << endl;
    m = inputNumber();

    cout << "The numbers you entered are: " << n << " and " << m << endl;
    cout << "Greatest common divisor is: " << gcd(n, m) << endl;
    cout << "Least common multiple is: " << lcm(n, m) << endl;

    return 0;
}
