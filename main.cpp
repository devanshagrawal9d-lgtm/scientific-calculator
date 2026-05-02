#include <bits/stdc++.h>
using namespace std;

stack<string> history;

void addHistory(string entry) {
    if (history.size() >= 10) {
        stack<string> temp;
        int count = 0;
        while (!history.empty()) {
            temp.push(history.top());
            history.pop();
        }
        temp.pop();
        while (!temp.empty()) {
            history.push(temp.top());
            temp.pop();
        }
    }
    history.push(entry);
}

void viewHistory() {
    if (history.empty()) { cout << "No history yet!\n"; return; }
    stack<string> temp = history;
    vector<string> entries;
    while (!temp.empty()) {
        entries.push_back(temp.top());
        temp.pop();
    }
    reverse(entries.begin(), entries.end());
    cout << "\n--- Calculation History ---\n";
    for (int i = 0; i < entries.size(); i++)
        cout << i + 1 << ". " << entries[i] << endl;
    cout << "---------------------------\n";
}

void clearHistory() {
    while (!history.empty()) history.pop();
    cout << "History cleared!\n";
}

class Calculator {
public:
    void basic() {
        double a, b;
        char op;
        cout << "Enter expression (e.g. 5 + 3): ";
        cin >> a >> op >> b;
        double result;
        string entry;
        switch (op) {
            case '+': result = a + b; break;
            case '-': result = a - b; break;
            case '*': result = a * b; break;
            case '/':
                if (b == 0) 
                {
                    cout << "Error: Division by zero!\n"; return; 
                }
                result = a / b; break;
            default: cout << "Invalid operator!\n"; return;
        }
        cout << "= " << result << endl;
        entry = to_string(a) + " " + op + " " + to_string(b) + " = " + to_string(result);
        addHistory(entry);
    }

    void power() {
        double base, exp;
        cout << "Enter base: "; 
        cin >> base;
        cout << "Enter exponent: "; 
        cin >> exp;
        double result = pow(base, exp);
        cout << "= " << result << endl;
        addHistory(to_string(base) + "^" + to_string(exp) + " = " + to_string(result));
    }

    void squareRoot() {
        double n, root;
        cout << "Enter number: "; 
        cin >> n;
        cout << "Enter root (2 for square, 3 for cube, etc.): "; 
        cin >> root;
        if (n < 0 && (int)root % 2 == 0) { 
            cout << "Error: Even root of negative number!\n"; 
            return; 
        }
        double result = pow(n, 1.0 / root);
        cout << "= " << result << endl;
        addHistory(to_string(root) + "rt(" + to_string(n) + ") = " + to_string(result));
    }

    void logarithm() {
        double n, base;
        cout << "Enter number: "; 
        cin >> n;
        if (n <= 0) 
        { 
            cout << "Error: Invalid input!\n";
            return; 
        }
        cout << "Enter base (10 for log, 2.718 for ln, 2 for log2, etc.): "; 
        cin >> base;
        if (base <= 0 || base == 1) { cout << "Error: Invalid base!\n"; return; }
        double result = log(n) / log(base);
        cout << "= " << result << endl;
        addHistory("log" + to_string(base) + "(" + to_string(n) + ") = " + to_string(result));
    }

    void trigonometry() {
        double angle;
        cout << "Enter angle in degrees: "; 
        cin >> angle;
        double rad = angle * M_PI / 180;
        cout << "sin = " << sin(rad) << endl;
        cout << "cos = " << cos(rad) << endl;
        cout << "tan = " << tan(rad) << endl;
        addHistory("trig(" + to_string(angle) + "deg)");
    }

    void factorial() {
        int n;
        cout << "Enter number: "; 
        cin >> n;
        if (n < 0) { cout << "Error: Negative number!\n"; return; }
        long long result = 1;
        for (int i = 1; i <= n; i++) result *= i;
        cout << "= " << result << endl;
        addHistory(to_string(n) + "! = " + to_string(result));
    }
};

int main() {
    Calculator calc;
    int choice;
    do {
        cout << "\n=== Scientific Calculator ===\n";
        cout << "1. Basic (+, -, *, /)\n";
        cout << "2. Power (x^y)\n";
        cout << "3. Square Root\n";
        cout << "4. Logarithm\n";
        cout << "5. Trigonometry\n";
        cout << "6. Factorial\n";
        cout << "7. View History\n";
        cout << "8. Clear History\n";
        cout << "0. Exit\n";
        cout << "Choice: "; cin >> choice;
        switch (choice) {
            case 1: calc.basic(); break;
            case 2: calc.power(); break;
            case 3: calc.squareRoot(); break;
            case 4: calc.logarithm(); break;
            case 5: calc.trigonometry(); break;
            case 6: calc.factorial(); break;
            case 7: viewHistory(); break;
            case 8: clearHistory(); break;
            case 0: cout << "Goodbye!\n"; break;
            default: cout << "Invalid choice!\n";
        }
    } while (choice != 0);
    return 0;
}