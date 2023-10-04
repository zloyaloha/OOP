#include <gtest/gtest.h>
#include "brackets_check.h"

TEST(test_01, basic_test_set)
{
    ASSERT_TRUE(CheckBrackets("()")==true);
}

TEST(test_02, basic_test_set)
{
    ASSERT_TRUE(CheckBrackets("()))))")==false);
}

TEST(test_03, basic_test_set)
{
    ASSERT_ANY_THROW(CheckBrackets("(0"));
}
TEST(test_04, basic_test_set)
{
    ASSERT_TRUE(CheckBrackets("")==true);
}
TEST(test_05, basic_test_set)
{
    ASSERT_TRUE(CheckBrackets("(())()()(())")==true);
}
TEST(test_06, basic_test_set)
{
    ASSERT_TRUE(CheckBrackets("))(())")==false);
}

int main(int argc, char **argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}