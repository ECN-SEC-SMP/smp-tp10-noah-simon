#include "factorielle.h"
#include <gtest/gtest.h>

/**
 * @brief Construct a new TEST object with ASSERT_EQ
 * 
 * @note DISABLED_ permet de désactiver un test
 */
TEST(DISABLED_Factorielle, TestBase_ASSERT) {
    ASSERT_EQ(1, factorielle(0));
    ASSERT_EQ(1, factorielle(1));
    ASSERT_EQ(2, factorielle(2));
}

/**
 * @brief Construct a new TEST object with EXPECT_EQ
 * 
 */
TEST(DISABLED_Factorielle, TestValeurs_EXPECT) {
    EXPECT_EQ(6, factorielle(3));
    EXPECT_EQ(24, factorielle(4));
    EXPECT_EQ(120, factorielle(5));
}

