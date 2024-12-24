int precedence(char ch) {
    if (ch == '+' || ch == '-') 
        return 1;
    if (ch == '*' || ch == '/') 
        return 2;
    if (ch == '^') 
        return 3;
    return 0;
}