#include <cstdio>

class c1 {
  int i = 0;
  c1(){}
public:
  c1(int value) : i(value) {} ;
  void setValue(int const & value ) { i = value; }
  int getValue() { return i; }
};

int main(int argc, char const *argv[])
{
  c1 number = c1(20);
  printf("The number is %d\n", number.getValue());
  return 0;
}
