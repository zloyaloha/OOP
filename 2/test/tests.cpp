#include <gtest/gtest.h>
#include "eleven.h"
#include "help.h"
//construct block

TEST(test_1_1, basic_test_set) {   
    Eleven el1{'1', '1', '1'}, el2("111");
    ASSERT_TRUE(el2.Equals(el1)==true);
}
TEST(test_1_2, basic_test_set) {   
    Eleven el1{'0','1','1'}, el2{"011"};
    ASSERT_TRUE(el2.Equals(el1)==true);
}
TEST(test_1_3, basic_test_set) {   
    Eleven el1(3,'1'), el2{'1','1','1'};
    ASSERT_TRUE(el2.Equals(el1)==true);
}
TEST(test_1_4, basic_test_set) {   
    Eleven el1{'0', '0', '0', '0'}, el2{"000000000"};
    ASSERT_TRUE(el2.Equals(el1)==true);
}
TEST(test_1_5, basic_test_set) {   
    Eleven el1{'0','0','1'}, el2{"00001"};
    ASSERT_TRUE(el2.Equals(el1)==true);
}

//equal block
TEST(test_2_1, basic_test_set) {   
    Eleven el1{'1','1','1'}, el2{'1','1','1'};
    ASSERT_TRUE(el2.Equals(el1)==true);
}

TEST(test_2_2, basic_test_set) {   
    Eleven el1{'1','1','3'}, el2{'1','1','1'};
    ASSERT_TRUE(el2.Equals(el1)==false);
}

TEST(test_2_3, basic_test_set) {   
    Eleven el1{'1','1'}, el2{'1','1','1'};
    ASSERT_TRUE(el2.Equals(el1)==false);
}

TEST(test_2_4, basic_test_set) {   
    Eleven el1, el2;
    ASSERT_TRUE(el2.Equals(el1)==true);
}

TEST(test_2_5, basic_test_set) {   
    Eleven el1 {'0'}, el2{'0','0'};
    ASSERT_TRUE(el2.Equals(el1)==true);
}

// more block

TEST(test_3_1, basic_test_set) {   
    Eleven el1{'1', '2', '3'}, el2{'2','3','1'};
    ASSERT_TRUE(el2.More(el1)==true);
}

TEST(test_3_2, basic_test_set) {   
    Eleven el1{'2', '3', '1'}, el2{'1','2','3'};
    ASSERT_TRUE(el2.More(el1)==false);
}

TEST(test_3_3, basic_test_set) {   
    Eleven el1{'1', '2', '3'}, el2{'2','3'};
    ASSERT_TRUE(el2.More(el1)==false);
}

TEST(test_3_4, basic_test_set) {   
    Eleven el1{'1', '2', '3'}, el2{'1','2','3'};
    ASSERT_TRUE(el2.More(el1)==false);
}

TEST(test_3_5, basic_test_set) {   
    Eleven el1{'0', '0', '0'}, el2{'0','0','0'};
    ASSERT_TRUE(el2.More(el1)==false);
}

TEST(test_3_6, basic_test_set) {   
    Eleven el1{'0', '0', '1'}, el2{'0','2','0'};
    ASSERT_TRUE(el2.More(el1)==true);
}

TEST(test_3_7, basic_test_set) {   
    Eleven el1{'1'}, el2{'2','3'};
    ASSERT_TRUE(el2.More(el1)==true);
}

TEST(test_3_8, basic_test_set) {   
    Eleven el1, el2;
    ASSERT_TRUE(el2.More(el1)==false);
}

// less block

TEST(test_4_1, basic_test_set) {   
    Eleven el1{'1', '2', '3'}, el2{'2','3','1'};
    ASSERT_TRUE(el2.Less(el1)==false);
}

TEST(test_4_2, basic_test_set) {   
    Eleven el1{'1', '2', '3'}, el2{'2','3'};
    ASSERT_TRUE(el2.Less(el1)==true);
}

TEST(test_4_3, basic_test_set) {   
    Eleven el1{'1', '2', '3'}, el2{'3','2','1'};
    ASSERT_TRUE(el2.Less(el1)==false);
}

TEST(test_4_4, basic_test_set) {   
    Eleven el1{'3', '2', '1'}, el2{'1','2','3'};
    ASSERT_TRUE(el2.Less(el1)==true);
}

TEST(test_4_5, basic_test_set) {   
    Eleven el1{'1'}, el2{'2','3'};
    ASSERT_TRUE(el2.Less(el1)==false);
}

TEST(test_4_6, basic_test_set) {   
    Eleven el1, el2;
    ASSERT_TRUE(el2.Less(el1)==false);
}

TEST(test_4_7, basic_test_set) {   
    Eleven el1{'1', '1', '1'}, el2{'1','1','1'};
    ASSERT_TRUE(el2.Less(el1)==false);
}

TEST(test_4_8, basic_test_set) {   
    Eleven el1{'0', '0', '0', '0'}, el2{'0','0','0'};
    ASSERT_TRUE(el2.Less(el1)==false);
}

// int / char

TEST(test_5_1, basic_test_set) {   
    ASSERT_TRUE(CharToInt('A') == 10);
}
TEST(test_5_2, basic_test_set) {   
    ASSERT_TRUE(CharToInt('5') == 5);
}
TEST(test_5_3, basic_test_set) {   
    ASSERT_TRUE(IntToChar(5) == '5');
}
TEST(test_5_4, basic_test_set) {   
    ASSERT_TRUE(IntToChar(10) == 'A');
}

// adding

TEST(test_6_1, basic_test_set) {   
    ASSERT_TRUE((Adding('7', '7').first == '3' && Adding('7', '7').second == '1'));
}

TEST(test_6_2, basic_test_set) {   
    ASSERT_TRUE((Adding('1', '3').first == '4' && Adding('1', '3').second == '0'));
}

TEST(test_6_3, basic_test_set) {   
    ASSERT_TRUE((Adding('0', '0').first == '0' && Adding('0', '0').second == '0'));
}

TEST(test_6_4, basic_test_set) {   
    ASSERT_TRUE((Adding('A', 'A').first == '9' && Adding('A', 'A').second == '1'));
}

TEST(test_6_5, basic_test_set) {   
    ASSERT_TRUE((Adding('6', '5').first == '0' && Adding('6', '5').second == '1'));
}

// add

TEST(test_7_1, basic_test_set) {   
    Eleven el1{'1', '1', '1'}, el2{'1','1','1'}, el3("222");
    ASSERT_TRUE(el3.Equals(el1.Add(el2)) == true);
}

TEST(test_7_3, basic_test_set) {   
    Eleven el1{'7', '7', '7'}, el2{'7','7','7'}, el3("1443");
    ASSERT_TRUE(el3.Equals(el1.Add(el2)) == true);
}

TEST(test_7_4, basic_test_set) {   
    Eleven el1{"AAA"}, el2{"AAA"}, el3("1AA9");
    ASSERT_TRUE(el3.Equals(el1.Add(el2)) == true);
}

TEST(test_7_5, basic_test_set) {   
    Eleven el1{"000"}, el2{"000"}, el3("0");
    ASSERT_TRUE(el3.Equals(el1.Add(el2)) == true);
}

TEST(test_7_6, basic_test_set) {   
    Eleven el1{"1345"}, el2{"45678A"}, el3("458024");
    ASSERT_TRUE(el3.Equals(el1.Add(el2)) == true);
}

TEST(test_7_7, basic_test_set) {   
    Eleven el1{"921844AA"}, el2{"78495"}, el3("92251994");
    ASSERT_TRUE(el3.Equals(el1.Add(el2)) == true);
}

TEST(test_7_8, basic_test_set) {   
    Eleven el1{"1010101AA98777"}, el2{"777666555333"}, el3("10878686542AAA");
    ASSERT_TRUE(el3.Equals(el1.Add(el2)) == true);
}

TEST(test_7_9, basic_test_set) {   
    Eleven el1{"00000"}, el2{"000"}, el3("0");
    ASSERT_TRUE(el3.Equals(el1.Add(el2)) == true);
}


int main(int argc, char **argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}

// 4 5 6 7 8 A
//     1 3 4 5
//     8 0 2 4