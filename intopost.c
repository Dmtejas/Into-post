void infixToPostfix(char *infix, char *postfix) {
    int i = 0, k = 0;
    char symbol;

    // Loop through each character in the infix expression
    while ((symbol = infix[i++]) != '\0') {
        if (isOperand(symbol)) {
            postfix[k++] = symbol;  // If operand, add to postfix expression
        } 
        else if (symbol == '(') {
            push(symbol);  // Push '(' to the stack
        } 
        else if (symbol == ')') {
            while (!isEmpty() && peek() != '(') {
                postfix[k++] = pop();  // Pop operators from the stack until '('
            }
            pop();  // Pop the '(' from the stack
        } 
        else if (isOperator(symbol)) {
            while (!isEmpty() && precedence(peek()) >= precedence(symbol)) {
                postfix[k++] = pop();  // Pop operators from the stack based on precedence
            }
            push(symbol);  // Push the current operator to the stack
        }
    }

    // Pop any remaining operators from the stack and add them to the postfix expression
    while (!isEmpty()) {
        postfix[k++] = pop();
    }

    postfix[k] = '\0';  // Null-terminate the postfix expression
}