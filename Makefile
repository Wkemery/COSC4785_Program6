##############################
# Makefile
# Author: Wyatt Emery
# Date: NOV 21, 2017
#
# COSC 4786, Homework 6
# 
##############################

CXX=g++
CXXFLAGS=-ggdb -Wall -std=c++11
FLEX=flex++
FLEXFLAGS=--warn
YACC=bison
YACCFLAGS=--report=state -W -d -v

.PHONY: clean tar

program6: program6.cpp program6_lex.cpp program6_bison.c program6_bison.h \
	Lexeme.cpp Node.cpp Lexeme.h Node.h SymTable.h SymTable.cpp
	${CXX} ${CXXFLAGS} program6.cpp program6_lex.cpp Lexeme.cpp program6_bison.c \
	Node.cpp SymTable.cpp -o program6

program6_lex.cpp: program6.lpp
	${FLEX} ${FLEXFLAGS} program6.lpp

program6_bison.c: program6.y
	${YACC} ${YACCFLAGS} -o program6_bison.c program6.y


tar: program6.cpp program6.lpp Lexeme.cpp Lexeme.h Makefile
	tar -cf wemery_HW6.tar program6.cpp program6.lpp Lexeme.cpp Lexeme.h \
	program6.y Node.h Node.cpp SymTable.h SymTable.cpp program6_readme.txt \
	program6.pdf Makefile

clean: 
	/bin/rm -f *.o core.* *.output program6 program6_lex.cpp wemery_HW6.tar \
    program6_bison.c program6_bison.h

