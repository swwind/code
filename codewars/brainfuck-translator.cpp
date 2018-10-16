#include <iostream>

#include <string> // std::string
#include <cstring>

int type[100020];
int num[100020];
int top, dep;

#define ERROR "Error!"
#define indent__(x) std::string((x) * 2, ' ')

std::string brainfuck_to_c(std::string source_code) {

	memset(type, 0, sizeof type);
	memset(num, 0, sizeof num);
	top = dep = 0;

	const char *st = source_code.c_str();
	int len = source_code.length();
	for (int i = 0; i < len; i++) {
		if (top && type[top] < 3 && !num[top]) top --;
		if (st[i] == '+' || st[i] == '-') {
			if (type[top] == 1) {
				num[top] += st[i] == '+' ? 1 : -1;
			} else {
				type[++ top] = 1;
				num[top] = st[i] == '+' ? 1 : -1;
			}
		} else if (st[i] == '>' || st[i] == '<') {
			if (type[top] == 2) {
				num[top] += st[i] == '>' ? 1 : -1;
			} else {
				type[++ top] = 2;
				num[top] = st[i] == '>' ? 1 : -1;
			}
		} else {
			type[++ top] = 3;
			if (st[i] == ',')
				num[top] = 1;
			else if (st[i] == '.')
				num[top] = 2;
			else if (st[i] == '[')
				num[top] = 3;
			else if (st[i] == ']') {
				if (top > 1 && type[top - 1] == 3 && num[top - 1] == 3) // last is '['
					top -= 2;
				else
					num[top] = 4;
			} else top --;
		}
	}
	std::string res = "";
	for (int i = 1; i <= top; i++) {

		if (type[i] == 1) {
			if (!num[i])
				continue;
			res += indent__(dep);
			if (num[i] < 0)
				res += "*p -= " + std::to_string(-num[i]) + ";";
			else
				res += "*p += " + std::to_string(num[i]) + ";";
		} else if (type[i] == 2) {
			if (!num[i])
				continue;
			res += indent__(dep);
			if (num[i] < 0)
				res += "p -= " + std::to_string(-num[i]) + ";";
			else
				res += "p += " + std::to_string(num[i]) + ";";
		} else if (type[i] == 3) {
			if (num[i] == 1)  {
				res += indent__(dep) + "*p = getchar();";
			} else if (num[i] == 2) {
				res += indent__(dep) + "putchar(*p);";
			} else if (num[i] == 3) {
				res += indent__(dep) + "if (*p) do {";
				dep ++;
			} else if (num[i] == 4) {
				if (!dep)
					return ERROR;
				res += indent__(-- dep) + "} while (*p);";
			}
 		}
		res += '\n';
	}
	if (dep) return ERROR;
	return res;
}

void DoTest(std::string a, std::string res) {
	a = brainfuck_to_c(a);
	if (a == res) puts("Passed");
	else {
		puts("Faild");
		printf("Your output:<<");
		std::cout << a;
		puts(">>");
		printf("Answer:<<");
		std::cout << res;
		puts(">>");
	}
}
int main(int argc, char const *argv[]) {
  DoTest("++++", "*p += 4;\n");
  DoTest("----", "*p -= 4;\n");
  
  DoTest(">>>>", "p += 4;\n");
  DoTest("<<<<", "p -= 4;\n");
  
  DoTest(".", "putchar(*p);\n");
  DoTest(",", "*p = getchar();\n");
  
  DoTest("[[[]]", "Error!");
  
  DoTest("[][]", "");
  
  DoTest("[.]", "if (*p) do {\n  putchar(*p);\n} while (*p);\n");

  DoTest("++<<[]>>++", "*p += 4;\n");

  DoTest("++5++", "*p += 4;\n");

  std::string str;
  std::cin >> str;
  std::cout << brainfuck_to_c(str);
	return 0;
}