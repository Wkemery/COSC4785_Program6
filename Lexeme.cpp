/*
 * Lexeme.cpp
 * Author: Wyatt Emery
 * Date: DEC 2017
 *
 * COSC 4785, Homework6
 *
 */

#include<iostream>
using namespace std;
#include"Lexeme.h"
#include"Node.h"
#include"program6_bison.h"
void setToken(char* yytext, int lineno, int column)
{
  
  if(yytext != NULL) yylval.token->value = yytext;
  else yylval.token->value = "";
//   cerr << "yylval.token->value = " << yylval.token->value << endl;;
  
  yylval.token->line = lineno;
  yylval.token->column = column;
}