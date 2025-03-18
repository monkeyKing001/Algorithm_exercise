#include <bits/stdc++.h>

using namespace std;
int n, m;

void ex_(void){
  cout << "0";
  exit(0);
}
int calculateBracketValue(const string& str) {
    stack<char> brackets;
    int result = 0, value = 1;

    for (size_t i = 0; i < str.length(); i++) {
        char ch = str[i];

        if (ch == '(') {
            brackets.push(ch);
            value *= 2;  // '(' contributes a multiplier of 2
        } 
        else if (ch == '[') {
            brackets.push(ch);
            value *= 3;  // '[' contributes a multiplier of 3
        } 
        else if (ch == ')') {
            if (brackets.empty() || brackets.top() != '(') return 0; // Invalid sequence

            if (i > 0 && str[i - 1] == '(') result += value; // Add value only if it's a direct match
            brackets.pop();
            value /= 2; // Undo multiplier
        } 
        else if (ch == ']') {
            if (brackets.empty() || brackets.top() != '[') return 0; // Invalid sequence

            if (i > 0 && str[i - 1] == '[') result += value; // Add value only if it's a direct match
            brackets.pop();
            value /= 3; // Undo multiplier
        }
    }

    return brackets.empty() ? result : 0; // Ensure all brackets are closed
}
int	main(int argc, char **argv)
{
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  string inputs;
  cin >> inputs;
  cout << calculateBracketValue(inputs) << endl;
  return (0);
}

