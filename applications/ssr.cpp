#include <cstdlib>
#include <iostream>
#include <fstream>

std::string head(const char* file) {
  std::ifstream fin(file);
  std::string str;
  fin >> str;
  fin.close();
  return str;
}

std::string exec(const char* cmd) {
  char buffer[128];
  std::string result = "";
  FILE* pipe = popen(cmd, "r");
  if (!pipe) throw std::runtime_error("popen() failed!");
  try {
    while (fgets(buffer, sizeof buffer, pipe) != NULL) {
      result += buffer;
    }
  } catch (...) {
    pclose(pipe);
    throw;
  }
  pclose(pipe);
  return result;
}

std::string curl(const std::string url) {
  std::string cmd = "curl -s \"";
  cmd += url;
  cmd += "\"";
  return exec(cmd.c_str());
}

int main(int argc, const char *argv[]) {
  bool has_curl = !system("curl --version > /dev/null");

  if (!has_curl) {
    std::cerr << "curl not found" << std::endl;
    return 1;
  }

  std::string subscribe = head("subsribe");
  std::string get = curl(subscribe);

  std::cout << get << std::endl;
}
