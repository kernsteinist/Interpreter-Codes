# Interpreter-Codes

the codes are C version of the tutorial which you can reach from  (https://ruslanspivak.com). i'll convert the python codes in tutorials to c codes.  

# Calc1.c - Addition  
understanding on token, lexical analysis. 

A token is an object that has a type and a value.
For example, for the string “3” the type of the token will be INTEGER and the corresponding value will be integer 3.

The process of breaking the input string into tokens is called lexical analysis.

Valid expressions for Calc1 : ( simple addition operation interpreter )

![alt text](https://image.ibb.co/j1Fx26/1.jpg)

we'll develop this code later. in this way this interpreter only can  add up digits not numbers.

# Calc2.c  - Addition & Subtraction

understanding on lexeme, parser.

A lexeme is a sequence of characters that form a token.

Token   | Sample Lexemes
--------|---------------
INTEGER | 342, 9, 0, 17, 1
PLUS    | +
MINUS   | -


The process of finding the structure in the stream of tokens, or put differently, the process of recognizing a phrase in the stream of tokens is called parsing. The part of an interpreter or compiler that performs that job is called a parser.

by the way, we fixed below issues.

1. Handle whitespace characters anywhere in the input string
2. Consume multi-digit integers from the input
3. Subtract two integers (currently it can only add integers)

# Calc3.c - The restriction is removed.

maybe you realized that we cannot add up a lot of number in old version of our calculator. we fixed the issue in this version and  we can add as many numbers as we want to.
