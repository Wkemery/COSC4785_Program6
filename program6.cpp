/*
 * program6.cpp
 * Author: Wyatt Emery
 * Date: DEC 2017
 *
 * COSC 4785, Homework6
 *
 */

#include<iostream>
#include<FlexLexer.h>
#include<string>
#include<map>
#include<cstdlib>
#include"Lexeme.h"
#include"Node.h"
#include"program6_bison.h"
using namespace std;

yyFlexLexer scanner;
vector<Node*> forest;
vector<Type*> extraTypes;

int main()
{
  
  yyparse();
  if(forest.size() > 0) cout << endl << endl;
  SymTable* symbolTable = new SymTable(0, "Root");
  for(unsigned int i = 0; i < forest.size(); i++)
  {
//     if(forest[i] != 0) forest[i]->print(&cout);
    if(forest[i] != 0) forest[i]->buildTable(symbolTable);
  }
    
  for(unsigned int i = 0; i < forest.size(); i++)
  {
    //do typecheck here. 
    if(forest[i] != 0) forest[i]->typeCheck(symbolTable);
  }
  
  
  symbolTable->print(&cout, 0);
  
  delete symbolTable;
  for(unsigned int i = 0; i < extraTypes.size(); i++)
  {
    delete extraTypes[i];
  }
  
  for(unsigned int i = 0; i < forest.size(); i++)
  {
    delete forest[i];
  }
  
  return 0;
  
}
