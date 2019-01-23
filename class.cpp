#include <cstdio>

class c1 {
  int i = 0;
public:
  c1(){}
  void setValue(int const & value ) { i = value; } // reference variable ensures we don't make an unnecessary copy
  int getValue(); // You can have both methods with same name bc one is const-safe and other isn't.
  int getValue() const; // Adding const at the end ensures this is safe to use for const variables
  ~c1();
  c1(const c1 &obj);
};

c1::c1(const c1 &rhs) {
  puts("we are using the copy operator");
  this->i = rhs.i;
}

int c1::getValue() {
  puts("Const-unsafe variant");
  return i;
}

int c1::getValue() const {
  puts("safe variant");
  return i;
}

c1::~c1() {
  puts("Destructor called");
}


int main(int argc, char const *argv[])
{
  c1 number;
  number.setValue(20);
  printf("The number is %d\n", number.getValue());

  const c1 number2 = number;
  printf("The number is %d\n", number2.getValue());
  
  return 0;
}
