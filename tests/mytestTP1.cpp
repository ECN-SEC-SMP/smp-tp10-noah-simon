#include "factorielle.h"
#include <gtest/gtest.h>

TEST(DISABLED_FactorialTest, ZeroValue) {
  EXPECT_EQ(1,factorielle(0));
}

TEST(DISABLED_FactorialTest, StandardValues) {
  EXPECT_EQ(1,factorielle(1));
  EXPECT_EQ(120,factorielle(5));
}

