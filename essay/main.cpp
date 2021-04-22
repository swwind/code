#include <bits/stdc++.h>

namespace Nhotyp {

typedef uint64_t int48_t;

namespace AST {

enum ExpressionType {
  NumberExpression,
  VariableExpression,
  FunctionExpression,
};

struct Expression {
  ExpressionType type;
  int48_t value;
  std::string name;
  std::vector<Expression*> args;
};

Expression *getNumberExpression(int48_t value) {
  Expression *expression = new Expression();
  expression->type = NumberExpression;
  expression->value = value;
  return expression;
}
Expression *getVariableExpression(std::string name) {
  Expression *expression = new Expression();
  expression->type = VariableExpression;
  expression->name = name;
  return expression;
}
Expression *getFunctionExpression(std::string name, std::vector<Expression*> args) {
  Expression *expression = new Expression();
  expression->type = FunctionExpression;
  expression->name = name;
  expression->args = args;
  return expression;
}

enum StatementType {
  IfStatement,
  LetStatement,
  WhileStatement,
  PrintStatement,
  ReturnStatement,
};

struct Statement {
  StatementType type;
  std::string name;
  Expression *expression;
  std::vector<Statement*> statements;
  std::vector<std::string> arguments;
};

Statement *getIfStatement(Expression *expression, std::vector<Statement*> statements) {
  Statement *statement = new Statement();
  statement->type = IfStatement;
  statement->expression = expression;
  statement->statements = statements;
  return statement;
}
Statement *getLetStatement(std::string name, Expression *expression) {
  Statement *statement = new Statement();
  statement->type = LetStatement;
  statement->name = name;
  statement->expression = expression;
  return statement;
}
Statement *getWhileStatement(Expression *expression, std::vector<Statement*> statements) {
  Statement *statement = new Statement();
  statement->type = WhileStatement;
  statement->expression = expression;
  statement->statements = statements;
  return statement;
}
Statement *getPrintStatement(std::vector<std::string> arguments) {
  Statement *statement = new Statement();
  statement->type = PrintStatement;
  statement->arguments = arguments;
  return statement;
}
Statement *getReturnStatement(Expression *expression) {
  Statement *statement = new Statement();
  statement->type = ReturnStatement;
  statement->expression = expression;
  return statement;
}

enum FunctionType {
  NativeFunction,
  CustomFunction,
};

struct Function {
  FunctionType type;
  int argc;
  std::string name;
  std::vector<std::string> argv;
  std::vector<Statement*> statements;
  std::function<int48_t(std::vector<int48_t>)> func;
};

Function *getNativeFunction(std::string name, int argc, std::function<int48_t(std::vector<int48_t>)> func) {
  Function *function = new Function();
  function->type = NativeFunction;
  function->name = name;
  function->argc = argc;
  function->func = func;
  return function;
}
Function *getCustomFunction(std::string name, int argc, std::vector<std::string> argv, std::vector<Statement*> statements) {
  Function *function = new Function();
  function->type = CustomFunction;
  function->name = name;
  function->argc = argc;
  function->argv = argv;
  function->statements = statements;
  return function;
}

struct Program {
  std::map<std::string, Function*> fns;
};

} // namespace AST

namespace Compiler {

int now, len;
std::string code;
std::map<std::string, int> declaredFunctions;

static std::vector<AST::Function*> nativeFunctions = {
  AST::getNativeFunction("+", 2, [] (const std::vector<int48_t> vec) -> int48_t {
    return vec[0] + vec[1];
  }),
  AST::getNativeFunction("-", 2, [] (const std::vector<int48_t> vec) -> int48_t {
    return vec[0] - vec[1];
  }),
  AST::getNativeFunction("*", 2, [] (const std::vector<int48_t> vec) -> int48_t {
    return vec[0] * vec[1];
  }),
  AST::getNativeFunction("*", 2, [] (const std::vector<int48_t> vec) -> int48_t {
    return vec[0] * vec[1];
  }),
  AST::getNativeFunction("%", 2, [] (const std::vector<int48_t> vec) -> int48_t {
    return vec[0] % vec[1];
  }),

  AST::getNativeFunction("==", 2, [] (const std::vector<int48_t> vec) -> int48_t {
    return vec[0] == vec[1];
  }),
  AST::getNativeFunction("<", 2, [] (const std::vector<int48_t> vec) -> int48_t {
    return vec[0] < vec[1];
  }),
  AST::getNativeFunction(">", 2, [] (const std::vector<int48_t> vec) -> int48_t {
    return vec[0] > vec[1];
  }),
  AST::getNativeFunction("<=", 2, [] (const std::vector<int48_t> vec) -> int48_t {
    return vec[0] <= vec[1];
  }),
  AST::getNativeFunction(">=", 2, [] (const std::vector<int48_t> vec) -> int48_t {
    return vec[0] >= vec[1];
  }),
  AST::getNativeFunction("!=", 2, [] (const std::vector<int48_t> vec) -> int48_t {
    return vec[0] != vec[1];
  }),

  AST::getNativeFunction("and", 2, [] (const std::vector<int48_t> vec) -> int48_t {
    return bool(vec[0]) && bool(vec[1]);
  }),
  AST::getNativeFunction("or", 2, [] (const std::vector<int48_t> vec) -> int48_t {
    return bool(vec[0]) || bool(vec[1]);
  }),
  AST::getNativeFunction("xor", 2, [] (const std::vector<int48_t> vec) -> int48_t {
    return bool(vec[0]) ^ bool(vec[1]);
  }),
  AST::getNativeFunction("not", 1, [] (const std::vector<int48_t> vec) -> int48_t {
    return !bool(vec[0]);
  }),

  AST::getNativeFunction("scan", 0, [] (const std::vector<int48_t> vec) -> int48_t {
    int48_t value;
    std::cin >> value;
    return value;
  }),
};

bool isEOF() {
  return now >= len;
}
bool isSpace() {
  return code[now] == '\n' || code[now] == ' ' || code[now] == '\t' || code[now] == '\r';
}
bool wrapped = false;
void skipSpace() {
  wrapped = false;
  while (!isEOF() && isSpace()) {
    if (code[now ++] == '\n') {
      wrapped = true;
    }
  }
}

std::string nextWord() {
  std::string word = "";
  while (!isEOF() && !isSpace()) {
    word += code[now ++];
  }
  skipSpace();
  return word;
}

bool is(std::string word) {
  int last = now;
  std::string next = nextWord();
  now = last;
  return next == word;
}

void except(std::string word) {
  int last = now;
  std::string next = nextWord();
  if (next != word) {
    std::cerr << "except `" << word << "` but `" << next << "` found at position " << last << std::endl;
    exit(1);
  }
}

bool isNumber(std::string str) {
  for (size_t i = 0; i < str.length(); ++ i) {
    if (!i && str.length() > 1 && str[i] == '-') continue;
    if (str[i] < '0' || str[i] > '9') return false;
  }
  return true;
}

int48_t parseNumber(std::string str) {
  bool negative = false;
  int48_t value = 0;
  for (size_t i = 0; i < str.length(); ++ i) {
    if (!i && str[i] == '-') {
      negative = 1;
      continue;
    }
    value = value * 10 + str[i] - '0';
  }
  return negative ? - value : value;
}

AST::Expression *parseExpression() {
  std::string first = nextWord();

  if (isNumber(first)) {
    return AST::getNumberExpression(parseNumber(first));
  }

  auto result = declaredFunctions.find(first);
  if (result != declaredFunctions.end()) {
    std::vector<AST::Expression*> args;
    for (int i = 0; i < result->second; ++ i) {
      args.push_back(parseExpression());
    }
    return AST::getFunctionExpression(first, args);
  }

  return AST::getVariableExpression(first);
}

AST::Statement *parseStatement() {
  std::string first = nextWord();

  if (first == "if") {
    AST::Expression *expression = parseExpression();
    except("then");
    std::vector<AST::Statement*> statements;
    while (!is("end")) {
      statements.push_back(parseStatement());
    }
    except("end");
    except("if");
    return AST::getIfStatement(expression, statements);
  }

  if (first == "let") {
    std::string name = nextWord();
    except("=");
    AST::Expression *expression = parseExpression();
    return AST::getLetStatement(name, expression);
  }

  if (first == "while") {
    AST::Expression *expression = parseExpression();
    except("do");
    std::vector<AST::Statement*> statements;
    while (!is("end")) {
      statements.push_back(parseStatement());
    }
    except("end");
    except("while");
    return AST::getWhileStatement(expression, statements);
  }

  if (first == "print") {
    std::vector<std::string> arguments;
    while (!wrapped) {
      arguments.push_back(nextWord());
    }
    return AST::getPrintStatement(arguments);
  }

  if (first == "return") {
    AST::Expression *expression = parseExpression();
    return AST::getReturnStatement(expression);
  }

  std::cerr << "unknown statement: " << first << std::endl;
  exit(1);
}

AST::Function *parseFunction() {
  except("function");
  std::string name = nextWord();
  std::vector<std::string> argv;
  while (!is("as")) {
    argv.push_back(nextWord());
  }
  except("as");

  declaredFunctions.insert(std::make_pair(name, argv.size()));

  std::vector<AST::Statement*> statements;
  while (!is("end")) {
    statements.push_back(parseStatement());
  }
  except("end");
  except("function");
  return AST::getCustomFunction(name, argv.size(), argv, statements);
}

AST::Program *compile(std::string code) {
  Compiler::code = code;
  AST::Program *program = new AST::Program();

  len = code.length();
  declaredFunctions.clear();

  for (auto function : nativeFunctions) {
    declaredFunctions.insert(std::make_pair(function->name, function->argc));
    program->fns.insert(std::make_pair(function->name, function));
  }

  while (!isEOF()) {
    AST::Function *function = parseFunction();
    program->fns.insert(std::make_pair(function->name, function));
  }

  return program;
}

} // namespace Compiler

namespace Runner {

AST::Program *program;

struct Env {
  std::map<std::string, int48_t> vars;
};

int48_t invokeExpression(Env *env, AST::Expression* expression);
int48_t invokeStatement(Env *env, AST::Statement* statement);
int48_t invokeFunction(std::string name, std::vector<int48_t> args);

int48_t invokeExpression(Env *env, AST::Expression* expression) {
  if (expression->type == AST::ExpressionType::NumberExpression) {
    return expression->value;
  }

  if (expression->type == AST::ExpressionType::VariableExpression) {
    return env->vars[expression->name];
  }

  if (expression->type == AST::ExpressionType::FunctionExpression) {
    std::vector<int48_t> args;
    for (auto exp : expression->args) {
      args.push_back(invokeExpression(env, exp));
    }
    return invokeFunction(expression->name, args);
  }

  std::cerr << "unkown ExpressionType: " << expression->type << std::endl;
  exit(1);
}

int48_t invokeStatement(Env *env, AST::Statement* statement) {
  if (statement->type == AST::StatementType::IfStatement) {
    if (invokeExpression(env, statement->expression)) {
      for (auto stm : statement->statements) {
        invokeStatement(env, stm);
      }
    }
    return 0;
  }

  if (statement->type == AST::StatementType::LetStatement) {
    env->vars[statement->name] = invokeExpression(env, statement->expression);
    return 0;
  }

  if (statement->type == AST::StatementType::WhileStatement) {
    while (invokeExpression(env, statement->expression)) {
      for (auto stm : statement->statements) {
        invokeStatement(env, stm);
      }
    }
    return 0;
  }

  if (statement->type == AST::StatementType::PrintStatement) {
    for (size_t i = 0; i < statement->arguments.size(); ++ i) {
      std::cout << env->vars[statement->arguments[i]] << " \n"[i + 1 == statement->arguments.size()];
    }
    return 0;
  }

  if (statement->type == AST::StatementType::ReturnStatement) {
    return invokeExpression(env, statement->expression);
  }

  std::cerr << "unkown StatementType: " << statement->type << std::endl;
  exit(1);
}

int48_t invokeFunction(std::string name, std::vector<int48_t> args) {
  auto result = program->fns.find(name);
  if (result == program->fns.end()) {
    std::cerr << "function `" << name << "` not found" << std::endl;
    exit(1);
  }

  AST::Function *function = result->second;

  if (function->argc != args.size()) {
    std::cerr << "function `" << name << "` called with " << args.size() << " argument(s), but " << function->argc << " argument(s) wanted" << std::endl;
    exit(1);
  }

  if (function->type == AST::FunctionType::NativeFunction) {
    return function->func(args);
  }

  if (function->type == AST::FunctionType::CustomFunction) {
    Env env;
    for (size_t i = 0; i < function->argv.size(); ++ i) {
      env.vars[function->argv[i]] = args[i];
    }

    int48_t ret;
    for (auto stm : function->statements) {
      ret = invokeStatement(&env, stm);
    }
    return ret;
  }

  std::cerr << "unkown FunctionType: " << function->type << std::endl;
  exit(1);
}

void run(AST::Program *program) {
  Runner::program = program;
  invokeFunction("main", { });
}

} // namespace Runner

} // namespace Nhotyp

int main() {

  std::string code;
  std::string line;

  while (getline(std::cin, line)) {
    if (line == "################") {
      // EOF
      break;
    }

    bool isComment = true;
    for (size_t i = 0; i < line.length(); ++ i) {
      if (line[i] == ' ' || line[i] == '\t') continue;
      isComment = line[i] == '#';
      break;
    }

    if (!isComment) {
      code += line;
      code += '\n';
    }
  }

  Nhotyp::AST::Program *program = Nhotyp::Compiler::compile(code);
  Nhotyp::Runner::run(program);

}
