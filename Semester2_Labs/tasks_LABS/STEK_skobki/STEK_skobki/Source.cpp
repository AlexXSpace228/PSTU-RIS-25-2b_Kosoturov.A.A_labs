#include <iostream>
#include <stack>
#include <string>
#include <clocale>

bool isValid(const std::string& s) {
    std::stack<char> st;

    for (char c : s) {
        if (c == '(' || c == '{' || c == '[') {
            st.push(c);
        }
        else if (c == ')' || c == '}' || c == ']') {
            if (st.empty()) return false;

            char top = st.top();
            st.pop();

            if ((c == ')' && top != '(') ||
                (c == '}' && top != '{') ||
                (c == ']' && top != '[')) {
                return false;
            }
        }
    }

    return st.empty();
}

int main() {
    setlocale(LC_ALL, "RU");
    
    std::string s;
    getline(std::cin, s);

    if (isValid(s)) {
        std::cout << "Правильно\n";
    }
    else {
        std::cout << "Неправильно\n";
    }

    return 0;
}