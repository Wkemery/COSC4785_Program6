/*
 * Node.cpp
 * Author: Wyatt Emery
 * Date: DEC 2017
 *
 * COSC 4785, Homework6
 *
 */

#include<iostream>
using namespace std;
#include"Node.h"
#include<cstdlib>

bool PDebug = false; //prints leaves on true
bool EasyReading = false; /* on true, adds extra new lines for easy reading of 
output*/

extern vector<Type*> extraTypes;

Type numLiteralType("", "int", 0, "", false);
Type nullType("", "null", 0, "", false);

string nameMangle(string funcName, vector<string>* funcParamTypes)
{
  funcName.insert(0, to_string(funcName.size())); //prepend size of funcname
  funcName.insert(0, "_Z"); //prepend _Z
  if(funcParamTypes == 0) return funcName;
  for(unsigned int i = 0; i < funcParamTypes->size(); i++)
  {
    funcName.append(to_string(funcParamTypes->at(i).size()));
    funcName.append(funcParamTypes->at(i));
  }
  return funcName;
}

string nameUnMangle(string mangledName)
{
  if(mangledName.substr(0, 2) != "_Z") return mangledName;
  mangledName.erase(0, 2); //erase _Z
  int pos = mangledName.find_first_not_of("01231456789");
  //function name starts at pos
  int funclength = stoi(mangledName.substr(0, pos));
  
  return mangledName.substr(pos, funclength);
}


/******************************************************************************/

Node::Node(string value, string name, int kind)
:_value(value), _nodeName(name), _kind(kind), _err(false), _lineNumber(0)
{}

Node::~Node()
{
  for(unsigned int i = 0; i < _subNodes.size(); i++)
  {
    delete _subNodes[i];
  }
}
void Node::setErr() 
{
  _err = true;
}

bool Node::getErr() {return _err;}

int Node::getNodeKind(void) const {return _kind;}

string Node::getNodeName(void) const
{
  return _nodeName;
}

string Node::getValue(void) const {return _value;}

Type* Node::getTypeCheck(SymTable* table) {return 0;}

void Node::buildTable(SymTable* table) {return;}

void Node:: setLineNumber(int linenum) { _lineNumber = linenum;}

bool Node::typeCheck(SymTable* table) {return true;}

int Node::getLineNumber(){return _lineNumber;}

/******************************************************************************/

ClassDec::ClassDec(string value, Node* node1):Node(value, "ClassDec")
{
  _subNodes.push_back(node1);
  if(node1->getErr()) _err = true;
}

void ClassDec::buildTable(SymTable* table)
{
  int ret;
  Type* mytype = new Type("", "", 0, _value);
  //add yourself to root table
  ret = table->insert(_value, mytype);
  if(ret == -1)
  {
    cerr << "Type Error: Class \"" << _value << "\" Declared Twice" 
    << " Line " << _lineNumber << endl;
    return;
  }
  
  //create a new symbol table - my symbol table 
  SymTable* myTable = new SymTable(table, _value);
  ret = table->addChild(myTable);
  if(ret == -1)
  {
    //should never happen
    cerr << "Type Error: Class \"" << _value << "\" Declared Twice" 
    << " Line " << _lineNumber << endl;
    return;
  }
  //call build table on your child - the classbody
  _subNodes[0]->buildTable(myTable);
}

bool ClassDec::typeCheck(SymTable* table)
{
  return _subNodes[0]->typeCheck(table);
}

void ClassDec::print(ostream* out)
{
  if(_err) return;
  
  *out << "<ClassDec> --> class " << (PDebug ? _value : "ID") << " <ClassBody>" << endl;
  
  if(EasyReading) *out << endl;
  for(unsigned int i = 0; i < _subNodes.size(); i++)
  {
    _subNodes[i]->print(out);
  }
  
  if(EasyReading) *out << endl;
}

/******************************************************************************/

ClassBody::ClassBody(int kind):Node("", "ClassBody", kind)
{}

ClassBody::ClassBody(Node* node1, int kind):Node("", "ClassBody", kind)
{
  _subNodes.push_back(node1);
}

ClassBody::ClassBody(Node* node1, Node* node2, int kind)
:Node("", "ClassBody", kind)
{
  _subNodes.push_back(node1);
  
  _subNodes.push_back(node2);
}

ClassBody::ClassBody(Node* node1, Node* node2, Node* node3, int kind)
:Node("", "ClassBody", kind)
{
  _subNodes.push_back(node1);
  
  _subNodes.push_back(node2);
  
  _subNodes.push_back(node3);
}

bool ClassBody::typeCheck(SymTable* table)
{
  bool ret = true;
  for(unsigned int i = 0; i < _subNodes.size(); i++)
  {
    bool temp = _subNodes[i]->typeCheck(table);
    if(!temp) ret = false;
  }
  return ret;
}

void ClassBody::buildTable(SymTable* table) 
{
  // call build table on all children, which are Rnodes
  for(unsigned int i = 0; i < _subNodes.size(); i++)
  {
    _subNodes[i]->buildTable(table);
  }
}

void ClassBody::print(ostream* out)
{
  if(_err) return;
  
  *out << "<ClassBody> --> {";
    
    switch(_kind)
    {
      case CLASSBODYEMPTY:
      {
        break;
      }
      case CLASSBODYVAR:
      {
        if(_subNodes[0]->getErr()) *out << "<ErrNode>";
        else if(_subNodes[0]->getNodeName()== "RNode") *out << "<VarDecs>";
        else *out << "<" << _subNodes[0]->getNodeName() << ">";
        break;
      }
      case CLASSBODYVARCON:
      {
        if(_subNodes[0]->getErr()) *out << "<ErrNode> ";
        else if(_subNodes[0]->getNodeName()== "RNode") *out << "<VarDecs> ";
        else *out << "<" << _subNodes[0]->getNodeName() << "> ";
        
        if(_subNodes[1]->getErr()) *out << "<ErrNode>";
        else if(_subNodes[1]->getNodeName()== "RNode") *out << "<ConstructorDecs>";
        else *out << "<" << _subNodes[1]->getNodeName() << ">";
        break;
      }
      case CLASSBODYVARCONMET:
      {
        
        if(_subNodes[0]->getErr()) *out << "<ErrNode> ";
        else if(_subNodes[0]->getNodeName()== "RNode") *out << "<VarDecs> ";
        else *out << "<" << _subNodes[0]->getNodeName() << "> ";
        
        if(_subNodes[1]->getErr()) *out << "<ErrNode> ";
        else if(_subNodes[1]->getNodeName()== "RNode") *out << "<ConstructorDecs> ";
        else *out << "<" << _subNodes[1]->getNodeName() << "> ";
        
        if(_subNodes[2]->getErr()) *out << "<ErrNode>";
        else if(_subNodes[2]->getNodeName()== "RNode") *out << "<MethodDecs>";
        else *out << "<" << _subNodes[2]->getNodeName() << ">";
        
        break;
      }
      case CLASSBODYCONMET:
      {
        if(_subNodes[0]->getErr()) *out << "<ErrNode> ";
        else if(_subNodes[0]->getNodeName()== "RNode") *out << "<ConstructorDecs> ";
        else *out << "<" << _subNodes[0]->getNodeName() << "> ";
        
        if(_subNodes[1]->getErr()) *out << "<ErrNode>";
        else if(_subNodes[1]->getNodeName()== "RNode") *out << "<MethodDecs>";
        else *out << "<" << _subNodes[1]->getNodeName() << ">";
        
        break;
      }
      case CLASSBODYMET:
      {
        if(_subNodes[0]->getErr()) *out << "<ErrNode>";
        else if(_subNodes[0]->getNodeName()== "RNode") *out << "<MethodDecs>";
        else *out << "<" << _subNodes[0]->getNodeName() << ">";
        break;
      }
      case CLASSBODYCON:
      {
        if(_subNodes[0]->getErr()) *out << "<ErrNode>";
        else if(_subNodes[0]->getNodeName()== "RNode") *out << "<ConstructorDecs>";
        else *out << "<" << _subNodes[0]->getNodeName() << ">";
        break;
      }
      case CLASSBODYVARMET:
      {
        if(_subNodes[0]->getErr()) *out << "<ErrNode> ";
        else if(_subNodes[0]->getNodeName()== "RNode") *out << "<VarDecs>";
        else *out << "<" << _subNodes[0]->getNodeName() << "> ";
        
        if(_subNodes[1]->getErr()) *out << "<ErrNode>";
        else if(_subNodes[1]->getNodeName()== "RNode") *out << "<MethodDecs>";
        else *out << "<" << _subNodes[1]->getNodeName() << ">";
        
        break;
      }
      default:
      {
        cerr << "FATAL ERROR ClassBody" << endl;
        exit(1);
      }
    }
    
    *out << "}" << endl;
    for(unsigned int i = 0; i < _subNodes.size(); i++)
    {
      _subNodes[i]->print(out);
    }
}
/******************************************************************************/

Statement::Statement(Node* node1, Node* node2, int kind)
:Node("", "Statement", kind)
{
  _subNodes.push_back(node1);
  if(node1->getErr()) _err = true;
  
  _subNodes.push_back(node2);
  if(node2->getErr()) _err = true;
  
}
Statement::Statement(Node* node1, int kind):Node("", "Statement", kind)
{
  _subNodes.push_back(node1);
  if(node1->getErr()) _err = true;
}

Statement::Statement(int kind):Node("", "Statement", kind)
{}

void Statement::buildTable(SymTable* table)
{
  int ret;
  int childi = -1;
  if(_kind == STMNTWHILE) childi = 1;
  if(_kind == STMNTCOND) childi = 0;
  if(_kind == STMNTBLOCK) 
  {
    childi = 0;
    //create a new scope
    int randname = rand();
    
    string name = to_string(randname);
    
    SymTable* myTable = new SymTable(table, name);
    ret = table->addChild(myTable);
    if(ret == -1)
    {
      cerr << "Fatal Internal Error!" << endl;
      exit(1);
      return;
    }
    _myTable = myTable;
    _subNodes[childi]->buildTable(myTable);
  }
  else
  {
    _myTable = table;
    if(childi != -1) _subNodes[childi]->buildTable(table);
  }
  
}

bool Statement::typeCheck(SymTable* table)
{
  switch(_kind)
  {
    case STMNTNAMEEXP:
    {
      //get type/type check  name 
      Type* nameType = ((Name*)_subNodes[0])->getTypeCheck(_myTable, "");
      if(nameType == 0) return false;
  
      //get type of expression
      Type* expType = _subNodes[1]->getTypeCheck(_myTable);
      if(expType == 0) return false;
      
      //compare types
      
      if(nameType->getlval() == "")
      {
        cerr << "Type Error: "  << "Invalid L value" 
        << " Line " << _lineNumber << endl;
        return false;
      }
      if(expType->getrval() == "") 
      {
        cerr << "Type Error: "  << "Invalid R value" 
        << " Line " << _lineNumber << endl;
        return false;
      }
      
      if(nameType->getlval() == "int")
      {
        if(expType->getrval() != "int")
        {
          cerr << "Type Error: "  << "Type Mismatch" 
          << " Line " << _lineNumber << endl;
          return false;
        }
      }
      else
      {
        //Know lval is a class type so null is always valid
        if(expType->getrval() == "null") return true;
        
        if(nameType->getlval() != expType->getrval())
        {
          cerr << "Type Error: "  << "Type Mismatch" 
          << " Line " << _lineNumber << endl;
          return false;
        }
      }

      break;
    }
    case STMNTNAMEARGL:
    {
      //function call
      
      //get the types of the arguments 
      Type* argsType = _subNodes[1]->getTypeCheck(_myTable);
      if(argsType == 0) return false;
      
      //get type of function name from symbol table
      string funcName = ((Name*)_subNodes[0])->getFuncName();
      Type* classType = _myTable->getClassType();
      if(classType == 0)
      {
        cerr << "FATAL Internal Error" << endl;
        exit(1);
      }
      if(funcName == "this" || funcName == classType->getlval())
      {
        cerr << "Type Error: "  << "Direct Constructor call" 
        << " Line " << _lineNumber << endl;
        return false;      
      }
      
      string mangledFuncName = nameMangle(funcName, argsType->getParams());
      Type* funcType = ((Name*)_subNodes[0])->getTypeCheck(_myTable, mangledFuncName);
      if(funcType == 0) return false;
      
      //compare each type one by one
      for(unsigned int i = 0; i < funcType->getParams()->size(); i++)
      {
        if(funcType->getParams()->at(i) != argsType->getParams()->at(i))
        {
          cerr << "Type Error: "  << "Function call Parameter Type mismatch" 
          << " Line " << _lineNumber << endl;
          return false;
        }
      }
      
//       delete argsType;
      return true;
    }
    case STMNTPRNTARGL:
    {
      //get the types of the arguments 
      Type* argsType = _subNodes[0]->getTypeCheck(_myTable);
      if(argsType == 0) return false;
      
      //compare each type one by one
      for(unsigned int i = 0; i < argsType->getParams()->size(); i++)
      {
        if(argsType->getParams()->at(i) != "int")
        {
          cerr << "Type Error: "  << "All parameters for Print() must be"
          << " of type int" 
          << " Line " << _lineNumber << endl;
          return false;
        }
      }
      
      return true;
      
    }
    case STMNTWHILE:
    {
      //type check expression/get type of expression
      //type of exp must be int
      Type* expType = _subNodes[0]->getTypeCheck(_myTable);
      if(expType == 0) return false;
      if(expType->getrval() != "int")
      {
        cerr << "Type Error: "  << "Expression Does Not Evaluate to Boolean" 
        << " Line " << _lineNumber << endl;
        return false;
      }
      
      //type check Statement
      _subNodes[1]->typeCheck(_myTable);
      break;
    }
    case SMTNTRETURN:
    {
      // get the function name from SymTable _value
      Type* funcType = _myTable->lookup(_myTable->findFunc());
      if(funcType == 0) return false;
      // still give blocks random names, but rely on mangling, every func starts with _Z
      
      Type* expType = 0;
      //if there is not an expression type is void
      if(_subNodes.size() == 0)
      {
        expType =  new Type("", "void");
      }
      else
      {
        //get type of expression
        expType = _subNodes[0]->getTypeCheck(_myTable);
        if(expType == 0) return false;
      }

      
      // check function ret type matches type of the expression
      if(funcType->getrval() != expType->getrval())
      {
        cerr << "Type Error: "  << "Return Statement does not match function return type" 
        << " Line " << _lineNumber << endl;
        return false;
      }
      break;
    }
    case STMNTCOND:
    {
      //type check CondStatement
      return _subNodes[0]->typeCheck(_myTable);
    }
    case STMNTBLOCK:
    {
      //typecheck block
      return _subNodes[0]->typeCheck(_myTable);
    }
    case STMNTNAMEEMPTY:
    {
      //empty param list function call
      //get type of function name from symbol table
      string funcName = ((Name*)_subNodes[0])->getFuncName();
      Type* classType = _myTable->getClassType();
      if(classType == 0)
      {
        cerr << "FATAL Internal Error" << endl;
        exit(1);
      }
      if(funcName == "this" || funcName == classType->getClassType())
      {
        cerr << "Type Error: "  << "Direct Constructor call" 
        << " Line " << _lineNumber << endl;
        return false;      
      }
      
      string mangledFuncName = nameMangle(funcName, 0);
      
      Type* funcType = ((Name*)_subNodes[0])->getTypeCheck(_myTable, mangledFuncName);
      if(funcType == 0) return false;
      break;
    }
  }
  
  return true;
}

void Statement::print(ostream* out)
{
  if(_err) return;
  
  *out << "<Statement> --> ";
  switch(_kind)
  {
    case STMNTNAMEEXP:
    {
      *out << "<Name> = <Expression> ;";
      break;
    }
    case STMNTNAMEARGL:
    {
      *out << "<Name> ";
      if(_subNodes.size() == 2) *out << "<Name> (<ArgList>) ;";
      else *out << "() ;";
      break;
    }
    case STMNTPRNTARGL:
    {
      *out << "print ";
      if(_subNodes.size() == 1 ) *out << "(<ArgList>) ;";
      else *out << "() ;";
      break;
    }
    case STMNTWHILE:
    {
      *out << "while (<Expression>) <Statement> ";
      break;
    }
    case SMTNTRETURN:
    {
      *out << "return ";
      if(_subNodes.size() == 1) *out << "<Expression> ";
      *out << ";";
      break;
    }
    case STMNTCOND:
    {
      *out << "<ConditionalStatement>";
      break;
    }
    case STMNTBLOCK:
    {
      *out << "<Block>";
      break;
    }
    case STMNTVARDEC:
    {
      *out << "<VarDec>";
      break;
    }
    case STMNTSEMI:
    {
      *out << ";";
      break;
    }
    case STMNTNAMEEMPTY:
    {
      *out << "<Name>()";
      break;
    }
    default:
    {
      cerr << "FATAL ERROR!! Statement" << endl;
      exit(1);
    }
  }
  
  *out << endl;
  for(unsigned int i = 0; i < _subNodes.size(); i++)
  {
    _subNodes[i]->print(out);
  }
  
  if(EasyReading) *out << endl << endl;
  
}
/******************************************************************************/
Block::Block(int kind):Node("", "Block", kind)
{}

Block::Block(Node* node1, int kind):Node("", "Block", kind)
{
  _subNodes.push_back(node1);
}

Block::Block(Node* node1, Node* node2, int kind):Node("", "Block", kind)
{
  _subNodes.push_back(node1);
  
  _subNodes.push_back(node2);
}
void Block::buildTable(SymTable* table)
{
  for(unsigned int i = 0; i < _subNodes.size(); i++)
  {
    // call buildTable on children, only up to 2 Rnodes
    _subNodes[i]->buildTable(table);
  }
}

bool Block::typeCheck(SymTable* table)
{
  //call typeCheck on all mychildren
  bool ret = true;
  for(unsigned int i = 0; i < _subNodes.size(); i++)
  {
    bool temp = _subNodes[i]->typeCheck(table);
    if(!temp) ret = false;
  }
  return ret;
}

void Block::print(ostream* out)
{
  if(_err) return;
  
  *out << "<Block> --> {";
    switch(_kind)
    {
      case BLOCKVARDEC:
      {
        if(_subNodes[0]->getErr()) *out << "<ErrNode>";
        else if(_subNodes[0]->getNodeName()== "RNode") 
          *out << "<VarDecs>";
        else *out << " <" << _subNodes[0]->getNodeName() << ">";
        break;
      }
      case BLOCKSTMNT:
      {
        if(_subNodes[0]->getErr()) *out << "<ErrNode>";
        else if(_subNodes[0]->getNodeName()== "RNode") 
          *out << "<Statements>";
        else 
        {
          *out << "<" <<  _subNodes[0]->getNodeName() << ">";
        }
        break;
      }
      case BLOCKVARSTMNT:
      {
        if(_subNodes[0]->getErr()) *out << "<ErrNode> ";
        else if(_subNodes[0]->getNodeName()== "RNode") 
          *out << "<VarDecs>";
        else 
        {
          *out << "<" <<  _subNodes[0]->getNodeName() << "> ";
        }
        
        if(_subNodes[1]->getErr()) *out << "<ErrNode>";
        else if(_subNodes[1]->getNodeName()== "RNode") 
          *out << "<Statements>";
        else 
        {
          *out << "<" <<  _subNodes[1]->getNodeName() << ">";
        }
        
        break;
      }
      case BLOCKEMPTY:
      {
        break;
      }
      default:
      {
        cerr << "FATAL ERROR Block" <<endl;
        exit(1);
      }
    }
    
    *out << "}" << endl;
    for(unsigned int i = 0; i < _subNodes.size(); i++)
    {
      _subNodes[i]->print(out);
    }
}

/******************************************************************************/

RNode::RNode(int kind) : Node("", "RNode", kind) {}

void RNode::add(Node* child)
{
  _subNodes.push_back(child);
}

void RNode::buildTable(SymTable* table)
{
  //call build table on all my children
  for(unsigned int i = 0; i < _subNodes.size(); i++)
  {
    _subNodes[i]->buildTable(table);
  }
}

vector<string>* RNode::getParamTypes() const
{
  vector<string>* ret = new vector<string>;
  for(unsigned int i = 0; i < _subNodes.size(); i++)
  {
    ret->push_back(((Param*)_subNodes[i])->getType());
  }
  
  return ret;
}

vector<string>* RNode::getParamNames() const
{
  vector<string>* ret = new vector<string>;
  for(unsigned int i = 0; i < _subNodes.size(); i++)
  {
    ret->push_back(((Param*)_subNodes[i])->getParamName());
    
  }
  return ret;
}

Type* RNode::getTypeCheck(SymTable* table)
{
  //TODO: Don't really like this function, myabe get rid of it...
  if(_kind == RECARG)
  {
    //get all arg types
    vector<string>* argTypes = new vector<string>();
    for(unsigned int i = 0; i < _subNodes.size(); i++)
    {
      argTypes->push_back(_subNodes[i]->getTypeCheck(table)->getrval());
    }
    return new Type("","",argTypes, "", true);
  }
  if(_kind == RECBRACKEXP)
  {
    //have a bunch of children. all of which are expressions
    string type = "";
    for(unsigned int i = 0; i < _subNodes.size(); i++)
    {
      Type* expType = _subNodes[i]->getTypeCheck(table);
      if(expType == 0) return 0;
      
      //expression must evaluate to int, x = new A[expression]
      
      if(expType->getrval() != "int")
      {
        cerr << "Type Error: "  << "Expression must evaluate to integer within []" 
        << " Line " << _lineNumber << endl;
        return 0;
      }
      type.append("[]");
    }
    return new Type("", type, 0, "", true);
  }
  return 0;
}

bool RNode::typeCheck(SymTable* table)
{
  //call typeCheck on all mychildren
  bool ret = true;
  for(unsigned int i = 0; i < _subNodes.size(); i++)
  {
    bool temp = _subNodes[i]->typeCheck(table);
    if(!temp) ret = 0;
  }
  return ret;
}

void RNode::print(ostream* out)
{
  switch(_kind)
  {
    case RECVARDEC:
    {
      *out << "<VarDecs> --> " << _subNodes.size() << " <VarDec>" << endl;
      break;
    }
    case RECSTMNT:
    {
      *out << "<Statements> --> " << _subNodes.size() << " <Statement>" << endl;
      break;
    }
    case RECCONDEC:
    {
      *out << "<ConstructorDecs> --> " << _subNodes.size() << " <ConstructorDec>" << endl;
      break;
    }
    case RECMETDEC:
    {
      *out << "<MethodDecs> --> " << _subNodes.size() << " <MethodDec>" << endl;
      break;
    }
    case RECPARAM:
    {
      *out << "<ParamList> --> " << _subNodes.size() << " <Param>" << endl; 
      break;
    }
    case RECARG:
    {
      *out << "<ArgList> --> " << _subNodes.size() << " <Expression>" << endl;
      break;
    }
    case RECBRACKEXP:
    {
      *out << "<BracketedExpression> --> " << _subNodes.size() << " <Expression>" 
      << endl;
      break;
    }
    default:
    {
      cerr << "Fatal Error RNode!" << endl;
      exit(1);
    }
  }
  
  for(unsigned int i = 0; i < _subNodes.size(); i++)
  {
    _subNodes[i]->print(out);
  }
  if(EasyReading) *out << endl;
  
}
/******************************************************************************/

CondStatement::CondStatement(Node* node1, Node* node2, int kind)
:Node("", "CondStatement", kind)
{
  _subNodes.push_back(node1);
  if(node1->getErr()) _err = true;
  
  _subNodes.push_back(node2);
  if(node2->getErr()) _err = true;
}

CondStatement::CondStatement(Node* node1, Node* node2, Node* node3, int kind)
:Node("", "CondStatement", kind)
{
  _subNodes.push_back(node1);
  if(node1->getErr()) _err = true;
  
  _subNodes.push_back(node2);
  if(node2->getErr()) _err = true;
  
  _subNodes.push_back(node3);
  if(node3->getErr()) _err = true;
}

void CondStatement::buildTable(SymTable* table)
{
  for(unsigned int i = 1; i < _subNodes.size(); i++)
  {
    _subNodes[i]->buildTable(table);
  }
} 

bool CondStatement::typeCheck(SymTable* table)
{
  //type check/get type of expression child
  Type* expType = _subNodes[0]->getTypeCheck(table);
  if(expType == 0) return false;
  
  if((expType->getrval() != "bool") && (expType->getrval() != "int"))
  {
    cerr << "Type Error: "  << "Expression Does Not Evaluate to Boolean" 
    << " Line " << _lineNumber << endl;
    return false;
  }
  
  //type check Statement child/children
  bool stmnt1ret = _subNodes[1]->typeCheck(table);
  if(!stmnt1ret) return false;
  
  if(_kind == CONDSTMNTELSE)
  {
    bool stmnt2ret = _subNodes[2]->typeCheck(table);
    if(!stmnt2ret) return false;
  }
    
  return true;
}

void CondStatement::print(ostream* out)
{
  if(_err) return;
  
  *out << "<ConditionalStatement> --> ";
  switch(_kind)
  {
    case CONDSTMNT:
    {
      *out << "if (<Expression>) <Statement>";
      break;
    }
    case CONDSTMNTELSE:
    {
      *out << "if (<Expression>) <Statement> else <Statement>";
      break;
    }
    default:
    {
      cerr << "FATAL ERROR!! CondStatement" << endl;
      exit(1);
    }
  }
  *out << endl;
  for(unsigned int i = 0; i < _subNodes.size(); i++)
  {
    _subNodes[i]->print(out);
  }
}

/******************************************************************************/
Name::Name(string value, int kind):Node(value, "Name", kind)
{}
Name::Name(Node* name, string value, int kind):Node(value, "Name", kind)
{
  _subNodes.push_back(name);
  if(name->getErr()) _err = true;
  
}

Name::Name(Node* name, Node* expression, int kind):Node("", "Name", kind)
{
  _subNodes.push_back(name);
  if(name->getErr()) _err = true;
  
  _subNodes.push_back(expression);
  if(expression->getErr()) _err = true;
  
}

string Name::getFuncName()
{
  if(_kind == NAMEDOTID || _kind == NAMEID || _kind == NAMETHIS)
    return _value;
  return "";
}

Type* Name::getTypeCheck(SymTable* table, string mangledName = "")
{
  switch(_kind)
  {  
    case NAMETHIS:
    {
//       Type* ret = table->getClassType();
//       if(ret == 0)
//       {
//         cerr << "FATAL internal Error" << endl;
//         exit(1);
//       }
//       
//       if(mangledName == "")
//       {
//         return new Type(ret->getClassType(), ret->getClassType(), 0, "", true);
//       }
      return new Type("", "this", 0, "", true);
//       else
//       {
//         ret = table->lookup(mangledName);
//         if(ret == 0)
//         {
//           cerr << "Type Error: " << " No Matching Constructor Declaration" 
//           << " Line " << _lineNumber << endl;
//         }
//         return ret;
//       }
    }
    case NAMEID:
    {
      Type* ret = 0;
      
      if(mangledName == "")
      {
        ret = table->lookup(_value);
        if(ret == 0)
        {
          cerr << "Type Error: \""  << _value << "\" Unrecognized Identfier" 
          << " Line " << _lineNumber << endl;
        }
      }
      else
      {
        ret = table->lookup(mangledName);
        if(ret == 0)
        {
          cerr << "Type Error: \""  << _value << "\" No Matching Function Declaration" 
          << " Line " << _lineNumber << endl;
        }
      }
      
      return ret;
    }
    case NAMEDOTID:
    {
      Type* nameType = ((Name*)_subNodes[0])->getTypeCheck(table, "");
      if(nameType == 0) return 0;
      if(nameType->getrval() == "this") 
        nameType = table->getClassType();
      if(nameType == 0) return 0;
      
      if(nameType->getlval() == "")
      {
        cerr << "Type Error: \""  << _value << "\" Invalid L value" 
        << " Line " << _lineNumber << endl;
        return 0;
      }
      if(mangledName == "") 
        return table->lookup(nameType->getlval(), _value, _lineNumber);
      
      if(nameUnMangle(mangledName) == nameType->getlval())
      {
        cerr << "Type Error: " << "Direct Constructor call" 
        << " Line " << _lineNumber << endl;
        return 0;
      }
      return table->lookup(nameType->getlval(), mangledName, _lineNumber);
    }
    case NAMEEXP:
    {
      Type* nameType = ((Name*)_subNodes[0])->getTypeCheck(table, "");
      if(nameType == 0) return 0;
      if(nameType->getrval() == "this") 
      {
        cerr << "Type Error: " << "Array Access using \"this\" is not allowed" 
        << " Line " << _lineNumber << endl;
        return 0;
      }
      if(nameType == 0) return 0;
      
      Type* expType = _subNodes[1]->getTypeCheck(table);
      if(expType == 0) return 0;
      
      if(expType->getrval() != "int")
      {
        cerr << "Type Error: "  << "Expression must evaluate to integer within []" 
        << " Line " << _lineNumber << endl;
        return 0;
      }
      
      //remove 1 set of [] from type
      string type = nameType->getlval();
      unsigned int arrayPos = type.find_last_of("[");
      if(arrayPos > type.length())
      {
        cerr << "Type Error: "  << "Invalid Dimensions on Array access" 
        << " Line " << _lineNumber << endl;
        return 0;
      }
      type = type.substr(0, arrayPos);
      
      //the type of name[expression] is the type of name minus the brackets
      return new Type(type, type, 0, "", true);
      
    }
    case NAMEIDEXP:
    {
    
      Type* idType =  table->lookup(_value);
      if(idType == 0) return 0;
      
      Type* expType = _subNodes[0]->getTypeCheck(table);
      if(expType == 0) return 0;
      
      if(expType->getrval() != "int")
      {
        cerr << "Type Error: "  << "Expression must evaluate to integer within []" 
        << " Line " << _lineNumber << endl;
        return 0;
      }
      
      //remove 1 [] from type
      string type = idType->getlval();
      unsigned int arrayPos = type.find_last_of("[");
      if(arrayPos > type.length())
      {
        cerr << "Type Error: "  << "\"" << _value << "\" not of array type" 
        << " Line " << _lineNumber << endl;
        return 0;
      }
     
     type = type.substr(0, arrayPos);
     
      //the type of id[expression] is the type of id minus the brackets
      return new Type(type, type, 0, "", true);
    }
  }
  
  return 0;
}

void Name::print(ostream* out)
{
  if(_err) return;
  
  *out << "<Name> --> ";
  switch(_kind)
  {  
    case NAMETHIS:
    {
      *out << _value;
      break;
    }
    case NAMEID:
    {
      *out << (PDebug ? _value : "ID");
      break;
    }
    case NAMEDOTID:
    {
      *out << "<Name>." << (PDebug ? _value : "ID");
      break;
    }
    case NAMEEXP:
    {
      *out << "<Name> [<Expression>]";
      break;
    }
    case NAMEIDEXP:
    {
      *out << (PDebug ? _value : "ID") << " [<Expression>]";
      break;
    }
    default:
    {
      cerr << "FATAL ERROR!! NAME" << endl;
      exit(1);
    }
  }
  *out << endl;
  for(unsigned int i = 0; i < _subNodes.size(); i++)
  {
    _subNodes[i]->print(out);
  }
  
}
/******************************************************************************/

Expression::Expression(Node* next, int kind):Node("", "Expression", kind)
{
  _subNodes.push_back(next);
  if(next->getErr()) _err = true;
  
}

Expression::Expression(string value, int kind):Node(value, "Expression", kind)
{}

Expression::Expression(Node* unaryop, Node* expression, int kind)
:Node("", "Expression", kind)
{
  _subNodes.push_back(unaryop);
  if(unaryop->getErr()) _err = true;
  

  _subNodes.push_back(expression);
  if(expression->getErr()) _err = true;
  
}

Expression::Expression(Node* expression1, Node* op, Node* expression2, int kind)
:Node("", "Expression", kind)
{
  _subNodes.push_back(expression1);
  if(expression1->getErr()) _err = true;
  
  _subNodes.push_back(op);
  if(op->getErr()) _err = true;
  
  _subNodes.push_back(expression2);
  if(expression2->getErr()) _err = true;
  
}

Type* Expression::getTypeCheck(SymTable* table)
{
  switch(_kind)
  {
    case EXPNUM:
    {
      return &numLiteralType;
    }
    case EXPNULL:
    {
      return &nullType;
    }
    case EXPREAD:
    {
      return &numLiteralType;
    }
    case EXPUNARY:
    {
      Type* expType = _subNodes[1]->getTypeCheck(table);
      if(expType->getrval() != "int")
      {
        cerr << "Type Error: "  << "Expression must be of type int" 
        << " Line " << _lineNumber << endl;
        return 0;
      }
      if(expType == 0) return 0;
      
      return expType;
    }
    case EXPRELATION:
    {
      Type* expType1 = _subNodes[0]->getTypeCheck(table);
      if(expType1 == 0) return 0;
      
      Type* expType2 = _subNodes[2]->getTypeCheck(table);
      
      if(expType2 == 0) return 0;
      
      if((_subNodes[1]->getValue() == "==") || (_subNodes[1]->getValue() == "!="))
      {
        if((expType1->getrval() != "int") || (expType2->getrval() != "int"))
        {
          cerr << "Type Error: "  << "Expressions must be of type int" 
          << " Line " << _lineNumber << endl;
          return 0;
        }
      }
      else
      {
        if((expType1->getrval() == "int" && expType2->getrval() != "int") ||
          (expType2->getrval() == "int" && expType1->getrval() != "int"))
        {
          cerr << "Type Error: "  << "Expressions must be of the same type - int" 
          << " Line " << _lineNumber << endl;
          return 0;
        }
        else if((expType1->getrval() != "null") && (expType2->getrval() != "null"))
        {
          cerr << "Type Error: "  << "Object References can only be compared to null" 
          << " Line " << _lineNumber << endl;
          return 0;
        }
      }
      
      return &numLiteralType;
    }
    case EXPPRODUCT:
    case EXPSUMOP:
    {
      Type* expType1 = _subNodes[0]->getTypeCheck(table);
      if(expType1 == 0) return 0;
      
      Type* expType2 = _subNodes[2]->getTypeCheck(table);
      
      if(expType2 == 0) return 0;

      
      if((_subNodes[1]->getValue() == "&&") 
        || (_subNodes[1]->getValue() == "||"))
      {
        if((expType1->getrval() != "int") || (expType2->getrval() != "int"))
        {
          cerr << "Type Error: "  << "Expressions must be of type int" 
          << " Line " << _lineNumber << endl;
          return 0;
        }
      }
      else
      {
        if(expType1->getrval() == "int")
        {
          if(expType2->getrval() != "int")
          {
            cerr << "Type Error: "  << "Expressions must be of the same type" 
            << " Line " << _lineNumber << endl;
            return 0;
          }
          return expType1;
        }
        else if(expType1->getrval() == "null")
        {
          if(expType2->getrval() == "int")
          {
            cerr << "Type Error: "  << "Expressions must be of the same type" 
            << " Line " << _lineNumber << endl;
            return 0;
          }
          return expType2;
        }
        else
        {
          //Know exptype1 is a class type so null is always valid
          if(expType2->getrval() == "null") return expType1;
          
          if(expType1->getrval() != expType2->getrval())
          {
            cerr << "Type Error: "  << "Expressions must be of the same type" 
            << " Line " << _lineNumber << endl;
            return 0;
          }
          return expType1;
        } 
      }
    }
    case EXPPAREN:
    {
      return _subNodes[0]->getTypeCheck(table);
    }
    case EXPNEW:
    {
      return _subNodes[0]->getTypeCheck(table);
    }
    case EXPNAME:
    {
      return ((Name*)_subNodes[0])->getTypeCheck(table, "");
    }
    case EXPNAMEARG:
    {
      //function call
      
      //get the types of the arguments 
      Type* argsType = _subNodes[1]->getTypeCheck(table);
      if(argsType == 0) return 0;
      
      //get type of function name from symbol table
      string mangledFuncName = nameMangle(((Name*)_subNodes[0])->getFuncName(), argsType->getParams());
      Type* funcType = ((Name*)_subNodes[0])->getTypeCheck(table, mangledFuncName);
      if(funcType == 0) return 0;
      
      //compare function type with arguments passed
      if(argsType->getParams()->size() != funcType->getParams()->size())
      {
        cerr << "Type Error: "  << "Function paramter type mismatch" 
        << " Line " << _lineNumber << endl;
        return 0;
      }
      
      //compare each type one by one
      for(unsigned int i = 0; i < funcType->getParams()->size(); i++)
      {
        if(funcType->getParams()->at(i) != argsType->getParams()->at(i))
        {
          cerr << "Type Error: "  << "Function paramter type mismatch" 
          << " Line " << _lineNumber << endl;
          return 0;
        }
      }
      
//       delete argsType;
      
      return funcType;
    }
    case EXPNAMEEMPTY:
    {
      //empty param list function call
      //get type of function name from symbol table
      string mangledFuncName = nameMangle(((Name*)_subNodes[0])->getFuncName(), 0);
      Type* funcType = ((Name*)_subNodes[0])->getTypeCheck(table, mangledFuncName);
      if(funcType == 0) return 0;
      
      return funcType;
    }
  }
  return 0;
}

void Expression::print(ostream* out)
{
  if(_err) return;
  
  *out << "<Expression> --> ";
  switch(_kind)
  {
    case EXPNUM:
    {
      *out << (PDebug ? _value : "NUM");
      break;
    }
    case EXPNULL:
    {
      *out << _value;
      break;
    }
    case EXPREAD:
    {
      *out << _value;
      break;
    }
    case EXPUNARY:
    {
      *out << "<UnaryOp> <Expression>";
      break;
    }
    case EXPRELATION:
    {
      *out << "<Expression> <RelationOp> <Expression>";
      break;
    }
    case EXPPRODUCT:
    {
      *out << "<Expression> <ProductOp> <Expression>";
      break;
    }
    case EXPSUMOP:
    {
      *out << "<Expression> <SumOp> <Expression>";
      break;
    }
    case EXPPAREN:
    {
      *out << "(<Expression>)";
      break;
    }
    case EXPNEW:
    {
      *out << "<NewExpression>";
      break;
    }
    case EXPNAME:
    {
      *out << "<Name>";
      break;
    }
    case EXPNAMEARG:
    {
      *out << "<Name>(<ArgList>)";
      break;
    }
    case EXPNAMEEMPTY:
    {
      *out << "<Name>()";
      break;
    }
    default:
      cerr << "FATAL ERROR!!" << endl;
      exit(1);
  }
  *out << endl;
  
  for(unsigned int i = 0; i < _subNodes.size(); i++)
  {
    _subNodes[i]->print(out);
  }
  
  if(EasyReading) *out << endl;
}

/******************************************************************************/

Param::Param(Node* node1, string value)
:Node(value, "Param")
{
  _subNodes.push_back(node1);
  if(node1->getErr()) _err = true;
}

string Param::getType() const
{
  return ((TypeNode*)_subNodes[0])->getType();
}

string Param::getParamName() const { return _value; }

void Param::print(ostream* out)
{
  if(_err) return;
  
  *out << "<Param> --> " << " <TypeNode> " << (PDebug ? _value : "ID");
  
  *out << endl;
  for(unsigned int i = 0; i < _subNodes.size(); i++)
  {
    _subNodes[i]->print(out);
  }
}
/******************************************************************************/

NewExpression::NewExpression(int kind):Node("int", "NewExpression", kind) {}
NewExpression::NewExpression(string value, int kind)
:Node(value, "NewExpression", kind) {}

NewExpression::NewExpression(Node* node1, int kind)
:Node("int", "NewExpression", kind)
{
  _subNodes.push_back(node1);
  if(node1->getErr()) _err = true;
}

NewExpression::NewExpression(Node* node1, Node* node2, int kind)
:Node("int", "NewExpression", kind)
{
  _subNodes.push_back(node1);
  if(node1->getErr()) _err = true;
  
  _subNodes.push_back(node2);
  if(node2->getErr()) _err = true;
}

NewExpression::NewExpression(string simpletype, Node* arglist, int kind)
:Node(simpletype, "NewExpression", kind)
{
  _subNodes.push_back(arglist);
  if(arglist->getErr()) _err = true;
  
}

NewExpression::NewExpression(string simpletype, Node* type2, Node* brackexp, int kind)
:Node(simpletype, "NewExpression", kind)
{
  _subNodes.push_back(type2);
  if(type2->getErr()) _err = true;
  
  _subNodes.push_back(brackexp);
  if(brackexp->getErr()) _err = true;
}

Type* NewExpression::getTypeCheck(SymTable* table)
{
  switch(_kind)
  {
    case NEWEXPARG:
    {
      //constructor call
      
      //doesn't make sense for int, int has no constructor, int here is syntax error
      
      //check to see if type even exists
      if(!table->classLookup(_value))
      {
        cerr << "Type Error: "  << "Type \"" << _value << "\" Not Declared"
        << " Line " << _lineNumber << endl;
        return 0;
      }
      
      //type exists, check to see call matches a Constructor in the class
      
      //get the types of the arguments 
      Type* argsType = _subNodes[0]->getTypeCheck(table);
      if(argsType == 0) return 0;
      
      //get type of constructor from symbol table
      string mangledConsName = nameMangle(_value, argsType->getParams());
      Type* consType = table->lookup(_value, mangledConsName, _lineNumber);
      if(consType == 0) return 0;
      
      //compare function type with arguments passed
      if(argsType->getParams()->size() != consType->getParams()->size())
      {
        cerr << "Type Error: "  << "Function paramter type mismatch" 
        << " Line " << _lineNumber << endl;
        return 0;
      }
      
      //compare each type one by one
      for(unsigned int i = 0; i < consType->getParams()->size(); i++)
      {
        if(consType->getParams()->at(i) != argsType->getParams()->at(i))
        {
          cerr << "Type Error: "  << "Function paramter type mismatch" 
          << " Line " << _lineNumber << endl;
          return 0;
        }
      }
      
//       delete argsType;
      
      return new Type("", _value);
    }
    case NEWEXPBRACK:
    {
      //child is an RNode
      Type* expBrackType = _subNodes[0]->getTypeCheck(table);
      if(expBrackType == 0) return 0;
      
      if(_value != "int")
      {
        // check to see if type exists
        if(!table->classLookup(_value))
        {
          cerr << "Type Error: "  << "Type \"" << _value << "\" Not Declared"
          << " Line " << _lineNumber << endl;
          return 0;
        }
      }
      //default constructor always exists
      //type exists or is an int
      
      string type = _value;
      //add on all []s
      type.append(expBrackType->getrval());
      
      return new Type("", type, 0, "", true);
    }
    case NEWEXPBRACKMULTI:
    {
      //two children 
      //first is RNode
      Type* expBrackType = _subNodes[0]->getTypeCheck(table);
      if(expBrackType == 0) return 0;
      
      //second is Multibracks
      string multibracksType = ((Multibracks*)_subNodes[1])->getType();
      if(multibracksType != "[]")
      {
        cerr << "Type Error: "  << " Invalid number of Dimensions Allocated"
        << " Line " << _lineNumber << endl;
        return 0;
      }
      
      if(_value != "int")
      {
        // check to see if type exists
        if(!table->classLookup(_value))
        {
          cerr << "Type Error: "  << "Type \"" << _value << "\" Does not Exist"
          << " Line " << _lineNumber << endl;
          return 0;
        }
      }
      
      //type exists or is an int
      string type = _value;
      type.append(expBrackType->getrval());
      type.append(multibracksType);

      return new Type("", type, 0, "", true);
    }
    case NEWEXPMULTI:
    {
      cerr << "Type Error: "  << "Invalid number of Dimensions Allocated"
      << " Line " << _lineNumber << endl;
      return 0;
    }
    case NEWEXPEMPTY:
    {
      //assuming x = new A is allowed, but not x = new int;
      
      if(_value == "int")
      {
        cerr << "Type Error: "  << "Cannot create reference of primitive type int"
        << " Line " << _lineNumber << endl;
        return 0;
      }
      return new Type("", _value, 0, "", true);
    }
    case NEWEXPPAREN:
    {
      //default constructor call, default consructor always exists
      
      //check to see if type even exists
      if(!table->classLookup(_value))
      {
        cerr << "Type Error: "  << "Type \"" << _value << "\" Does not Exist"
        << " Line " << _lineNumber << endl;
        return 0;
      }
      
      //type exists, default constructor always exists
      return new Type("", _value, 0, "", true);
    }
  }
  return 0;
}

void NewExpression::print(ostream* out)
{
  if(_err) return;
  
  if(_value == "int") *out << "<NewExpression> --> new int ";
  else *out << "<NewExpression> --> new " << (PDebug ? _value : "ID") << " ";
  
  switch(_kind)
  {
    case NEWEXPARG:
    {
      *out << "(<ArgList>)";
      break;
    }
    case NEWEXPBRACK:
    {
      *out << "<[Expression]>";
      break;
    }
    case NEWEXPBRACKMULTI:
    {
      *out << "[<BracketedExpression>] <RecursiveBrackets>";
      break;
    }
    case NEWEXPMULTI:
    {
      *out << "<RecursiveBrackets>";
      break;
    }
    case NEWEXPEMPTY:
    {
      break;
    }
    case NEWEXPPAREN:
    {
      *out << "()";
      break;
    }
    default:
    {
      cerr << "FATAL ERROR!!! NewExpression" << endl;
      exit(1);
    }
  }
  
  *out << endl;
  for(unsigned int i = 0; i < _subNodes.size(); i++)
  {
    _subNodes[i]->print(out);
    
  }
}


/******************************************************************************/

ConstructorDec::ConstructorDec(string value, Node* node1, Node* node2, int kind)
:Node(value, "ConstructorDec", kind)
{
  _subNodes.push_back(node1);
  
  _subNodes.push_back(node2);
}

ConstructorDec::ConstructorDec(string value, Node* node1, int kind)
:Node(value, "ConstructorDec", kind)
{
  _subNodes.push_back(node1);
}

void ConstructorDec::buildTable(SymTable* table)
{
  // get parameter types from param list child
  int ret;
  vector<string>* paramTypes = 0;
  vector<string>* paramNames = 0;
  string myRetType;
  
  int paramChildi = -1;
  int blockChildi = -1;
  
  if(table->getValue() != _value)
  {
    cerr << "Type Error: "  << "Constructor \"" << _value << "\" Differs from Class Name \""
    << table->getValue() << "\" Line " << _lineNumber << endl;
    return;
  }
  
  if(_kind == CONSTDEC)
  {
    paramChildi = 0;
    blockChildi = 1;
  }
  if(_kind == CONSTDECEMPTY)
  {
    blockChildi = 0;
  }
  
  if(paramChildi >= 0 )
  {
    paramTypes = ((RNode*)_subNodes[paramChildi])->getParamTypes();
    paramNames = ((RNode*)_subNodes[paramChildi])->getParamNames();
  }
  
  //create mytype
  Type* myType = new Type("", "void", paramTypes);
  ret = table->insert(nameMangle(_value, paramTypes), myType);
  if(ret == -1)
  {
    cerr << "Type Error: "  << "Constructor \"" << _value << "\" Declared Twice"
    << " Line " << _lineNumber << endl;
    return;
  }
  //create my symbol table
  SymTable* myTable = new SymTable(table, nameMangle(_value, paramTypes));
  ret = table->addChild(myTable);
  if(ret == -1)
  {
    //shouldn't get this error because the first one should stop it
    cerr << "Type Error: "  << "Constructor \"" << _value << "\" Declared Twice"
    << " Line " << _lineNumber << endl;
    return;
  }
  //add my paramters to my table for the code in the block, if I have any
  if(paramChildi >= 0)
  {
    for(unsigned int i = 0; i < paramTypes->size(); i++)
    {
      Type* paramType = new Type(paramTypes->at(i), paramTypes->at(i));
      ret = myTable->insert(paramNames->at(i), paramType);
      if(ret == -1)
      {
        cerr << "Type Error: Local variable \"" << paramNames->at(i) <<  "\" declared twice" 
        << " Line " << _lineNumber << endl;
        return;
      }
    }
  }
  
  //call buildTable on my child - the block
  _subNodes[blockChildi]->buildTable(myTable);
  
  delete paramNames;
}

bool ConstructorDec::typeCheck(SymTable* table)
{
  int blockChildi = -1;
  int paramChildi = -1;
  
  if(_kind == CONSTDEC)
  {
    blockChildi = 1;
    paramChildi = 0;
  }
  if(_kind == CONSTDECEMPTY)
  {
    blockChildi = 0;
  }
  
  
  if(paramChildi != -1)
  {
    //validate paramter types
    vector<string>* paramTypes = ((RNode*)_subNodes[paramChildi])->getParamTypes();
    for(unsigned int i = 0; i < paramTypes->size(); i++)
    {
      string type = paramTypes->at(i);
      
      //remove any []
      unsigned int arrayPos = type.find_first_of("[");
      if(arrayPos < type.length())
        type = type.substr(0,arrayPos);
      
      if(type != "int")
      {
        if(!table->classLookup(type))
        {
          cerr << "Type Error: Invalid Type \"" << type 
          << "\" Line " << _lineNumber << endl;
          return false;
        }
      }
    }
    
    delete paramTypes;
  }
  
  return _subNodes[blockChildi]->typeCheck(table);
  
}

void ConstructorDec::print(ostream* out)
{
  if(_err) return;
  
  *out << "<ConstructorDec> --> " << (PDebug ? _value : "ID");
  
  switch(_kind)
  {
    case CONSTDEC:
    {
      *out << "(<ParamList>)";
      break;
    }
    case CONSTDECEMPTY:
    {
      *out << "()";
      break;
    }
    default:
    {
      cerr << "FATAL ERROR ConstructorDec" << endl;
      exit(1);
    }
  }
  
  if(_subNodes.size() > 0) 
    *out << " <" << _subNodes[_subNodes.size() - 1]->getNodeName() << ">" << endl;
  
  for(unsigned int i = 0; i < _subNodes.size(); i++)
  {
    _subNodes[i]->print(out);
    
  }
  if(EasyReading) *out << endl;
}

/******************************************************************************/

MethodDec::MethodDec(Node* node1, string value, Node* node2, Node* node3, int kind)
:Node(value, "MethodDec", kind)
{
  _subNodes.push_back(node1);
  
  _subNodes.push_back(node2);
  
  _subNodes.push_back(node3);
}

MethodDec::MethodDec(Node* node1, string value, Node* node2, int kind)
:Node(value, "MethodDec", kind)
{
  _subNodes.push_back(node1);
  
  _subNodes.push_back(node2);
}

MethodDec::MethodDec(string value, Node* node1, Node* node2, int kind)
:Node(value, "MethodDec", kind)
{
  _subNodes.push_back(node1);
  
  _subNodes.push_back(node2);
}

MethodDec::MethodDec(string value, Node* node1, int kind)
:Node(value, "MethodDec", kind)
{
  _subNodes.push_back(node1);      
}

void MethodDec::buildTable(SymTable* table)
{
  // get parameter types from param list child
  vector<string>* paramTypes = 0;
  vector<string>* paramNames = 0;
  string myRetType;
  int ret;

  int paramChildi = -1;
  int typeChildi = -1;
  int blockChildi = -1;
  switch(_kind)
  {
    case METHODDECVOID:
    {
      paramChildi = 0;
      blockChildi = 1;
      break;
    }
    case METHODDECTYPE:
    {
      typeChildi = 0;
      paramChildi = 1;
      blockChildi = 2;
      break;
    }
    case METHODDECTYPEEMPTY:
    {
      typeChildi = 0;
      blockChildi = 1;
      break;
    }
    case METHODDECVOIDEMPTY:
    {
      blockChildi = 0;
      break; 
    }
  }
  
  if(paramChildi >= 0 )
  {
    paramTypes = ((RNode*)_subNodes[paramChildi])->getParamTypes();
    paramNames = ((RNode*)_subNodes[paramChildi])->getParamNames();
  }
  
  if(typeChildi >= 0)
    myRetType = ((TypeNode*)_subNodes[0])->getType();
  else myRetType = "void";
  
  if(_value == "main")
  {
    //This is main and has special requirements
    if (paramChildi >=0 )
    {
      cerr << "Type Error: "  << "main() must be declared with 0 arguments"
      << " Line " << _lineNumber << endl;
      return;
    }
    
    if (myRetType != "int" && myRetType != "void")
    {
      cerr << "Type Error: "  << "main() must have return type int or void"
      << " Line " << _lineNumber << endl;
      return;
    }
    
    //increment main count
    table->incMain();
    if(table->getMain() > 1)
    {
      cerr << "Type Error: "  << "Redeclaration of main()"
      << " Line " << _lineNumber << endl;
      return;
    }
  }
  //create mytype
  Type* myType = new Type("", myRetType, paramTypes);
  ret = table->insert(nameMangle(_value, paramTypes), myType);
  if(ret == -1)
  {
    cerr << "Type Error: "  << "Method \"" << _value << "\" Declared Twice"
    << " Line " << _lineNumber << endl;
    return;
  }
  
  //create my symbol table
  SymTable* myTable = new SymTable(table, nameMangle(_value, paramTypes));
  ret = table->addChild(myTable);
  if(ret == -1)
  {
    cerr << "Type Error: "  << "Method \"" << _value << "\" Declared Twice"
    << " Line " << _lineNumber << endl;
    return;
  }
  
  //add my paramters to my table for the code in the block, if I have any
  if(paramChildi >= 0)
  {
    for(unsigned int i = 0; i < paramTypes->size(); i++)
    {
      Type* paramType = new Type(paramTypes->at(i), paramTypes->at(i));
      ret = myTable->insert(paramNames->at(i), paramType);
      if(ret == -1)
      {
        cerr << "Type Error: Local variable \"" << paramNames->at(i) <<  "\" declared twice" 
        << " Line " << _lineNumber << endl;
        return;
      }
    }
  }
  
  //call buildTable on my child - the block
  _subNodes[blockChildi]->buildTable(myTable);
  
  delete paramNames;
  
}

bool MethodDec::typeCheck(SymTable* table)
{
  int typeChildi = -1;
  int paramChildi = -1;
  int blockChildi = -1;
  switch(_kind)
  {
    case METHODDECVOID:
    {
      paramChildi = 0;
      blockChildi = 1;
      break;
    }
    case METHODDECTYPE:
    {
      typeChildi = 0;
      paramChildi = 1;
      blockChildi = 2;
      break;
    }
    case METHODDECTYPEEMPTY:
    {
      typeChildi = 0;
      blockChildi = 1;
      break;
    }
    case METHODDECVOIDEMPTY:
    {
      blockChildi = 0;
      break; 
    }
  }
  
  if(typeChildi!= -1)
  {
    // need to validate type
    //get my type from my child typenode
    string type = ((TypeNode*)_subNodes[typeChildi])->getType();
    
    //remove any []
    unsigned int arrayPos = type.find_first_of("[");
    if(arrayPos < type.length())
      type = type.substr(0, arrayPos);
    
    if(type != "int")
    {
      if(!table->classLookup(type))
      {
        cerr << "Type Error: Invalid Type \"" << type << "\""
        << " Line " << _lineNumber << endl;
        return false;
      }
    }
  }
  
  if(paramChildi != -1)
  {
    //validate paramter types
    vector<string>* paramTypes = ((RNode*)_subNodes[paramChildi])->getParamTypes();
    for(unsigned int i = 0; i < paramTypes->size(); i++)
    {
      string type = paramTypes->at(i);
      
      //remove any []
      unsigned int arrayPos = type.find_first_of("[");
      if(arrayPos < type.length())
        type = type.substr(0, arrayPos);
      
      if(type != "int")
      {
        if(!table->classLookup(type))
        {
          cerr << "Type Error: Invalid Type \"" << type << "\"" 
          << " Line " << _lineNumber << endl;
          return false;
        }
      }
    }
    
    delete paramTypes;
  }
  
  return _subNodes[blockChildi]->typeCheck(table);
}

void MethodDec::print(ostream* out)
{
  if(_err) return;
  
  *out << "<MethodDec> --> "; 
  switch(_kind)
  {
    case METHODDECVOID:
    {
      *out << "void " << (PDebug ? _value : "ID") << " (<ParameterList>) "; 
      break;
    }
    case METHODDECTYPE:
    {
      *out << "<TypeNode> " << (PDebug ? _value : "ID") << " (<ParameterList>) ";
      break;
    }
    case METHODDECTYPEEMPTY:
    {
      *out << "<TypeNode> " << (PDebug ? _value : "ID") << " () ";
      break;
    }
    case METHODDECVOIDEMPTY:
    {
      *out << "void " << (PDebug ? _value : "ID") << " () ";
      break;
    }
    default:
    {
      cerr << "FATAL ERROR MethodDec" << endl;
      exit(1);
    }
  }
  if(_subNodes.size() > 0) 
    *out << "<" << _subNodes[_subNodes.size() - 1]->getNodeName() << ">" << endl;
  for(unsigned int i = 0; i < _subNodes.size(); i++)
  {
    _subNodes[i]->print(out);
    
  }
  if(EasyReading) *out << endl;
}

/******************************************************************************/

VarDec::VarDec(Node* node1, string value): Node(value, "VarDec")
{
  _subNodes.push_back(node1);
  if(node1->getErr()) _err = true;
}

void VarDec::buildTable(SymTable* table)
{
  int ret;
  _myTable = table;
  //get my type from my child typenode
  string type = ((TypeNode*)_subNodes[0])->getType();
  //create mytype
  Type* mytype = new Type(type, type);
  if(type == "int") mytype->setInit("0");
  else mytype->setInit("null");
  // add myself to symbol table
  ret = table->insert(_value, mytype);
  if(ret == -1) 
  {
    cerr << "Type Error: local variable \"" << _value <<  "\" declared twice" 
    << " Line " << _lineNumber << endl;
    return;
  }
}

bool VarDec::typeCheck(SymTable* table)
{
  // need to validate type
  //get my type from my child typenode
  string type = ((TypeNode*)_subNodes[0])->getType();
  
  //remove any []
  unsigned int arrayPos = type.find_first_of("[");
  if(arrayPos < type.length())
    type = type.substr(0, arrayPos);
  
  if(type != "int")
  {
    if(!_myTable->classLookup(type))
    {
      cerr << "Type Error: Invalid Type \"" << type 
      << "\" Line " << _lineNumber << endl;
      _myTable->remove(_value);
      return false;
    }
  }
  return true;
}

void VarDec::print(ostream* out)
{
  if(_err) return;
  
  *out << "<VarDec> --> <TypeNode> " << (PDebug ? _value : "ID") << " ;" << endl;
  for(unsigned int i = 0; i < _subNodes.size(); i++)
  {
    _subNodes[i]->print(out);
    
  }
}

/******************************************************************************/

TypeNode::TypeNode(string value, int kind):Node(value, "TypeNode", kind)
{}

TypeNode::TypeNode(string value, Node* node1, int kind):Node(value, "TypeNode", kind)
{
  _subNodes.push_back(node1);
  if(node1->getErr()) _err = true;
}

string TypeNode::getType()
{
  string mytype = "";
  mytype.append(_value);
  string temp;
  if(_subNodes.size() > 0) temp = ((Multibracks*)_subNodes[0])->getType();
  mytype.append(temp);
  return mytype;
}

void TypeNode::print(ostream* out)
{
  if(_err) return;
  
  *out << "<TypeNode> --> ";
  switch(_kind)
  {
    case TYPE:
    {
      *out << (PDebug ? _value : "ID");
      break;
    }
    case TYPEBRACKS:
    {
      *out << (PDebug ? _value : "ID") << " <RecursiveBrackets>"; 
      break;
    }
    default:
    {
      cerr << "FATAL ERROR Type" << endl;
      exit(1);
    }
  }
  
  *out << endl;
  for(unsigned int i = 0; i < _subNodes.size(); i++)
  {
    _subNodes[i]->print(out);
    
  }
}
/******************************************************************************/

Multibracks::Multibracks():Node("", "Multibracks")
{}

void Multibracks::add()
{
  _count++;
}

string Multibracks::getType(void)
{
  string ret;
  for(int i = 0; i < _count; i++)
  {
    ret.append("[]");
  }
  return ret;
}

void Multibracks::print(ostream* out)
{
  if(_err) return;
  
  *out << "<RecursiveBrackets> --> ";
  for(int i = 0; i < _count; i++)
  {
    *out << "[]";
  }
  * out << endl;
}


/******************************************************************************/

UnaryOp::UnaryOp(string value):Node(value, "UnaryOp")
{}
void UnaryOp::print(ostream* out)
{
  if(_err) return;
  
  *out << "<UnaryOp> --> " << _value << endl;
}


/******************************************************************************/

RelationOp::RelationOp(string value):Node(value, "RelationOp")
{}

void RelationOp::print(ostream* out)
{
  if(_err) return;
  
  *out << "<RelationOp> --> " << _value << endl;
}

/******************************************************************************/

ProductOp::ProductOp(string value):Node(value, "ProductOp")
{}

void ProductOp::print(ostream* out)
{
  if(_err) return;
  
  *out << "<ProductOp> --> " << _value << endl;
}

/******************************************************************************/

SumOp::SumOp(string value):Node(value, "SumOp")
{}

void SumOp::print(ostream* out)
{
  if(_err) return;
  
  *out << "<SumOp> --> " << _value << endl;
}

/******************************************************************************/
ErrNode::ErrNode():Node("", "ErrNode")
{
  _err = true;
}
void ErrNode::print(ostream* out)
{
  return;
}

