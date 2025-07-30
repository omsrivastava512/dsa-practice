// 1. Check balanced parentheses
bool isBalanced(string expr);

// 2. Check balanced parentheses with different types (), [], {}
bool isBalancedMultiple(string expr);

// 3. Convert infix to postfix
string infixToPostfix(string infix);

// 4. Convert infix to prefix
string infixToPrefix(string infix);

// 5. Convert postfix to infix
string postfixToInfix(string postfix);

// 6. Convert prefix to infix
string prefixToInfix(string prefix);

// 7. Evaluate postfix expression
int evaluatePostfix(string postfix);

// 8. Evaluate prefix expression
int evaluatePrefix(string prefix);

// 9. Evaluate infix expression
int evaluateInfix(string infix);

// Helper functions:
int precedence(char op);
bool isOperator(char c);
bool isOperand(char c);
int performOperation(int a, int b, char op);