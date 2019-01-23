#include <cstdio>
#include <string>

struct A {
  int a = 3;
  std::string b = "";
  int c = 5;
};

  int main() {
    A myStruct;
    myStruct.b = "hello";
    printf("Print the results from the struct 1. %d, 2. %s, 3. %d\n", myStruct.a, myStruct.b.c_str(), myStruct.c);
  }
