// From Bill Weinman's course, changes added for my own practice.
#include <cstdio>
#include <memory>
#include <utility>
#include <iostream>

void message (const char * s) {
  printf("\n%s\n", s);
  fflush(stdout);
}

void disp (std::unique_ptr<int> & ptr) {
  if(ptr)
    std::cout << "The value of the pointer is: " << *ptr << std::endl;
  else
    puts("null");
  fflush(stdout);
}

int main( int argc, char ** argv) {
  message("create unique pointer");
  std::unique_ptr<int> ptrA = std::make_unique<int>(1); // dynamic storage, not the use of makeunique. Cant do new Int (1) with make unique.
  std::unique_ptr<int> ptrC (new int (3));
  disp(ptrA);
  disp(ptrC);
  ptrC = std::move(ptrA);
  disp(ptrC);
  message("make a second unique ptr");
  auto ptrB = std::make_unique<int>(2); // static storage, note auto use.
  message("Print A, should be null because I moved it to ptrC");
  disp(ptrA);
  disp(ptrB);
  return 0;
}
