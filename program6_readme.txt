# COSC4785_Program5
Valid input:
  The Decaf grammar as it is described in the document

new expression:
I chose to not allow something like
int [][][] x;
x = new int[][][];

are parenthesis optional? yes
Based off of my questions to you, I chose to implement the following:
This is type check correct:
A x;
x = new A;
this is also type check correct
EG
A x;
x = new A();
  
When I create nodes, I give almost all of them a _kind. It is an integer value 
with macros defined in the Node.h file. I don't necessarily need all of them. 
However, I am using them because the have been quite helpful with printing the 
parse tree, and building the symbol table and type checking 
  
One final note: I do allow an empty input because it makes sense to me.
