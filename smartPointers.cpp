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
    puts("null"); // try not to mix use of cstdio with iostream, probably.
  fflush(stdout);
}

int main( int argc, char ** argv) {
  message("create unique pointer");
  std::unique_ptr<int> ptrA = std::make_unique<int>(1); // make_unique better than using the new operator. try not to use new/delete.
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

  message("try to move into a null reference");
  ptrB = std::move(ptrA);
  disp(ptrA);
  disp(ptrB);
  disp(ptrC);

  message("reset ptrB from null reference to a number");
  ptrB.reset(new int(5));
  disp(ptrB);
  return 0;
}
