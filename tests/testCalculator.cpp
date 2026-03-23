#include "Calculator.h"
#include "factorielle.h"
#include <gtest/gtest.h>


//test div EXPECT DOUBLE
TEST(Calculator, Test_div_EXPECT_DOUBLE) {
    Calculator Test_div_EXPECT_DOUBLE;
    //EXPECT_DOUBLE_EQ(val , fonction à testé)
    EXPECT_DOUBLE_EQ(2, Test_div_EXPECT_DOUBLE.div(4,2)); 
}

//test div EXPECT NEAR
TEST(Calculator, Test_div_EXPECT_NEAR) {
    Calculator Test_div_EXPECT_NEAR;
    //EXPECT_DOUBLE_EQ(EXPECTED , ACTUAL, ABSOLUTE_RANGE)
    EXPECT_NEAR (2.333, Test_div_EXPECT_NEAR.div(7,3), 0.001);
}

//test div ASSERT EXIT
TEST(Calculator, Test_div_ASSERT_EXIT) {
    Calculator Test_div_ASSERT_EXIT;
    //EXPECT_DOUBLE_EQ(statement , predicate, expected_message)
    ASSERT_EXIT(Test_div_ASSERT_EXIT.div(7,0),::testing::ExitedWithCode(255),"Error: Division by 0 not possible");
}

//--------TEST----------
TEST(Calculator, test_factorielle) {
    Calculator test_factorielle;
    //cas classique :
    EXPECT_EQ(120, test_factorielle.factorielle(5)); 
    //cas 0;
    EXPECT_EQ(1, test_factorielle.factorielle(0)); 
    //Cas 1;
    EXPECT_EQ(1, test_factorielle.factorielle(1));
}


TEST(Calculator, test_div) {
    Calculator test_div;
    //div negatifs :
    EXPECT_EQ(-2, test_div.div(10,-5)); 
    // 0 au numérateur;
    EXPECT_EQ(0, test_div.div(0,2)); 
}

TEST(Calculator, test_add) {
    Calculator calc;

    // ++
    EXPECT_EQ(8, calc.add(5, 3));

    // +-
    EXPECT_EQ(2, calc.add(5, -3));

    // -+
    EXPECT_EQ(-2, calc.add(-5, 3));

    // --
    EXPECT_EQ(-8, calc.add(-5, -3));
}

TEST(Calculator, test_sub) {
    Calculator calc;

    // ++
    EXPECT_EQ(2, calc.sub(5, 3));

    // +-
    EXPECT_EQ(8, calc.sub(5, -3));

    // -+
    EXPECT_EQ(-8, calc.sub(-5, 3));

    // --
    EXPECT_EQ(-2, calc.sub(-5, -3));
}