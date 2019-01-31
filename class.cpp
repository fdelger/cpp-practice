#include <string>
#include <cstdio>
#include <iostream>

class c1 {
  int i = 0;
public:
  c1(int x) : i(x) {}
  void setValue(int const & value ) { i = value; } // reference variable ensures we don't make an unnecessary copy
  int getValue(); // You can have both methods with same name bc one is const-safe and other isn't.
  int getValue() const; // Adding const at the end ensures this is safe to use for const variables
  ~c1();
  c1(const c1 &obj); // Copy constructor
  c1 operator + ( const c1 & ) const; // Returns by value because to add a + b a new object with result is needed
  c1 & operator = (const c1 &); // The equal side returns by refernce because a new object isn't required
  operator std::string ();
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

c1 & c1::operator = (const c1 & rhs) {
  puts("overloaded operator =");
  if (this != &rhs) { // don't confuse this & with the one used for reference in arguments.
    i = rhs.getValue();
  }
}

c1 c1::operator + (const c1 & rhs) const {}

c1::operator std::string() {
  return std::to_string(this->getValue());
}

int main(int argc, char const *argv[])
{
  c1 number (25);
  c1 * pointerNum = &number;
  c1 number2 = number;
  c1 number3(10);

  number.setValue(20);
  printf("The number is %d\n", number.getValue());
  number3.setValue(10);
  number2 = number3;
  printf("The number is %d\n", number2.getValue());

  std::string s = "The number, string use, is ";
  s += number3;
  std::cout << s << std::endl; 

  printf("The pointed number is %d\n", pointerNum->getValue()); // remember: can't do pointerNum->object.function(), just ->function().

  return 0;
}
