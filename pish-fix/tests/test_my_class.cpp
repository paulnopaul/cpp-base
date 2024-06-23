#include <gtest/gtest.h>

#include "my_class.h"

TEST(MyClassTest, SayHello) {
  MyClass obj;
  int a = 40, b = 2;
  EXPECT_EQ(obj.sum(a, b), 42);
}
