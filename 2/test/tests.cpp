#include <gtest/gtest.h>
#include "eleven.h"
#include "help.h"
//construct block

TEST(test_1_1, basic_test_set) {   
    Eleven el1{'1', '1', '1'}, el2("111");
    ASSERT_TRUE(el2 == el1);
}
TEST(test_1_2, basic_test_set) {   
    Eleven el1{'0','1','1'}, el2{"011"};
    ASSERT_TRUE(el2 == el1);
}
TEST(test_1_3, basic_test_set) {   
    Eleven el1(3,'1'), el2{'1','1','1'};
    ASSERT_TRUE(el2 == el1);
}
TEST(test_1_4, basic_test_set) {   
    Eleven el1{'0', '0', '0', '0'}, el2{"000000000"};
    ASSERT_TRUE(el2 == el1);
}
TEST(test_1_5, basic_test_set) {   
    Eleven el1{'0','0','1'}, el2{"00001"};
    ASSERT_TRUE(el2 == el1);
}

TEST(test_1_6, basic_test_set) {
    ASSERT_THROW(Eleven el(10, 'K'), std::range_error);
}

TEST(test_1_7, basic_test_set) {
    ASSERT_THROW(Eleven el("1F23A"), std::range_error);
}

TEST(test_1_8, basic_test_set) {
    ASSERT_THROW(Eleven el({'K', 'A', 'R'}), std::range_error);
}

TEST(test_1_9, basic_test_set) {
    Eleven el{"12571"};
    Eleven el1(el);
    ASSERT_TRUE(el1 == el == true);
}

TEST(test_1_10, basic_test_set) {
    Eleven el3{"12571"};
    Eleven el2{"12571"};
    Eleven el1(std::move(el2));
    ASSERT_TRUE(el3 == el1 == true);
}

//equal block
TEST(test_2_1, basic_test_set) {   
    Eleven el1{'1','1','1'}, el2{'1','1','1'};
    ASSERT_TRUE(el2 == el1==true);
}

TEST(test_2_2, basic_test_set) {   
    Eleven el1{'1','1','3'}, el2{'1','1','1'};
    ASSERT_TRUE(el2 == el1==false);
}

TEST(test_2_3, basic_test_set) {   
    Eleven el1{'1','1'}, el2{'1','1','1'};
    ASSERT_TRUE(el2 == el1==false);
}

TEST(test_2_4, basic_test_set) {   
    Eleven el1, el2;
    ASSERT_TRUE(el2 == el1==true);
}

TEST(test_2_5, basic_test_set) {   
    Eleven el1 {'0'}, el2{'0','0'};
    ASSERT_TRUE(el2 == el1==true);
}

TEST(test_2_6_basic_test_set_Test, basic_test_set) {   
    Eleven el1{"11111"}, el2{"00001"};
    ASSERT_TRUE(el2 != el1);
}

TEST(test_2_7, basic_test_set) {   
    Eleven el1{"123A3AA98"}, el2{"123A3AA98"};
    ASSERT_TRUE(el2 != el1 == false);
}

TEST(test_2_8, basic_test_set) {   
    Eleven el1{'0','0','0'}, el2{"0"};
    ASSERT_TRUE(el2 != el1 == false);
}

TEST(test_2_9, basic_test_set) {   
    Eleven el1{"0000002323"}, el2{"002323"};
    ASSERT_TRUE(el2 != el1 == false);
}



// more block

TEST(test_3_1, basic_test_set) {   
    Eleven el1{'1', '2', '3'}, el2{'2','3','1'};
    ASSERT_TRUE(el2 > el1);
}

TEST(test_3_2, basic_test_set) {   
    Eleven el1{'2', '3', '1'}, el2{'1','2','3'};
    ASSERT_TRUE(el2 > el1 == false);
}

TEST(test_3_3, basic_test_set) {   
    Eleven el1{'1', '2', '3'}, el2{'2','3'};
    ASSERT_TRUE(el2 > el1 == false);
}

TEST(test_3_4, basic_test_set) {   
    Eleven el1{'1', '2', '3'}, el2{'1','2','3'};
    ASSERT_TRUE(el2 > el1 == false);
}

TEST(test_3_5, basic_test_set) {   
    Eleven el1{'0', '0', '0'}, el2{'0','0','0'};
    ASSERT_TRUE(el2 > el1 == false);
}

TEST(test_3_6, basic_test_set) {   
    Eleven el1{'0', '0', '1'}, el2{'0','2','0'};
    ASSERT_TRUE(el2 > el1);
}

TEST(test_3_7, basic_test_set) {   
    Eleven el1{'1'}, el2{'2','3'};
    ASSERT_TRUE(el2 > el1);
}

TEST(test_3_8, basic_test_set) {   
    Eleven el1, el2;
    ASSERT_TRUE(el2 > el1 == false);
}

TEST(test_3_9, basic_test_set) {   
    Eleven el1("AA67891"), el2("AA67891");
    ASSERT_TRUE(el2 >= el1);
}
TEST(test_3_10, basic_test_set) {   
    Eleven el2("7893442"), el1{"7893441"};
    ASSERT_TRUE(el1 >= el2 == false);
}
TEST(test_3_11, basic_test_set) {   
    Eleven el1{"80912A"}, el2{"AAAA"};
    ASSERT_TRUE(el2 >= el1 == false);
}
TEST(test_3_12, basic_test_set) {   
    Eleven el1{'0', '0', '0'}, el2{'0','0','0', '0'};
    ASSERT_TRUE(el2 >= el1);
}
TEST(test_3_13, basic_test_set) {   
    Eleven el1{'0', '0', '1'}, el2{'0','0','0', '2'};
    ASSERT_TRUE(el2 >= el1);
}


// less block

TEST(test_4_1, basic_test_set) {   
    Eleven el1{'1', '2', '3'}, el2{'2','3','1'};
    ASSERT_TRUE(el2 < el1==false);
}

TEST(test_4_2, basic_test_set) {   
    Eleven el1{'1', '2', '3'}, el2{'2','3'};
    ASSERT_TRUE(el2 < el1);
}

TEST(test_4_3, basic_test_set) {   
    Eleven el1{'1', '2', '3'}, el2{'3','2','1'};
    ASSERT_TRUE(el2 < el1 == false);
}

TEST(test_4_4, basic_test_set) {   
    Eleven el1{'3', '2', '1'}, el2{'1','2','3'};
    ASSERT_TRUE(el2 < el1);
}

TEST(test_4_5, basic_test_set) {   
    Eleven el1{'1'}, el2{'2','3'};
    ASSERT_TRUE(el2 < el1 == false);
}

TEST(test_4_6, basic_test_set) {   
    Eleven el1, el2;
    ASSERT_TRUE(el2 < el1 == false);
}

TEST(test_4_7, basic_test_set) {   
    Eleven el1{'1', '1', '1'}, el2{'1','1','1'};
    ASSERT_TRUE(el2 < el1 == false);
}

TEST(test_4_8, basic_test_set) {   
    Eleven el1{'0', '0', '0', '0'}, el2{'0','0','0'};
    ASSERT_TRUE(el2 < el1 == false);
}

TEST(test_4_9, basic_test_set) {   
    Eleven el1("43561"), el2("32A1");
    ASSERT_TRUE(el2 <= el1);
}

TEST(test_4_10, basic_test_set) {   
    Eleven el1("111AAA721"), el2("111AAA721");
    ASSERT_TRUE(el2 <= el1);
}

TEST(test_4_11, basic_test_set) {   
    Eleven el1("6345281A"), el2("AAA67111A24");
    ASSERT_TRUE(el2 <= el1 == false);
}

TEST(test_4_12, basic_test_set) {   
    Eleven el1("0001"), el2("0000001");
    ASSERT_TRUE(el2 <= el1);
}

TEST(test_4_13, basic_test_set) {   
    Eleven el1("000"), el2("000000");
    ASSERT_TRUE(el2 <= el1);
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
    ASSERT_TRUE((Adding('7', '7', '7').first == 'A' && Adding('7', '7', '7').second == '1'));
}

TEST(test_6_2, basic_test_set) {   
    ASSERT_TRUE((Adding('1', '3', '2').first == '6' && Adding('1', '3', '2').second == '0'));
}

TEST(test_6_3, basic_test_set) {   
    ASSERT_TRUE((Adding('0', '0', '0').first == '0' && Adding('0', '0', '0').second == '0'));
}


// plus

TEST(test_7_1, basic_test_set) {   
    Eleven el1{'1', '1', '1'}, el2{'1','1','1'}, el3("222");
    ASSERT_TRUE((el3 == el1 + el2));
}

TEST(test_7_2, basic_test_set) {   
    Eleven el1{'7', '7', '7'}, el2{'7','7','7'}, el3("1443");
    ASSERT_TRUE((el3 == el1 + el2));
}

TEST(test_7_3, basic_test_set) {   
    Eleven el1{"AAA"}, el2{"AAA"}, el3("1AA9");
    ASSERT_TRUE((el3 == el1 + el2));
}

TEST(test_7_4, basic_test_set) {   
    Eleven el1{"000"}, el2{"000"}, el3("0");
    ASSERT_TRUE((el3 == el1 + el2));
}

TEST(test_7_5, basic_test_set) {   
    Eleven el1{"1345"}, el2{"45678A"}, el4("1379255"), el3("A21231");
    ASSERT_TRUE((el4 == el1 + el2 + el3));
}

TEST(test_7_6, basic_test_set) {   
    Eleven el1{"921844AA"}, el2{"78495"}, el3("92251994");
    ASSERT_TRUE((el3 == el1 + el2));
}

TEST(test_7_7, basic_test_set) {   
    Eleven el1{"1010101AA98777"}, el2{"777666555333"}, el3("10878686542AAA");
    ASSERT_TRUE((el3 == el1 + el2));
}

TEST(test_7_8, basic_test_set) {   
    Eleven el1{"00000"}, el2{"000"}, el3("0");
    ASSERT_TRUE((el3 == el1 + el2));
}

// substruction

TEST(test_8_1, basic_test_set) {   
    ASSERT_TRUE(Substruction('8', '3', '4').first == '1' && Substruction('8', '3', '4').second == '0');
}

TEST(test_8_2, basic_test_set) {   
    ASSERT_TRUE(Substruction('1', '8', '1').first == '3' && Substruction('1', '8', '1').second == '1');
}

TEST(test_8_3, basic_test_set) {   
    ASSERT_TRUE(Substruction('9', 'A', '0').first == 'A' && Substruction('9', 'A', '0').second == '1');
}

TEST(test_8_4, basic_test_set) {   
    ASSERT_TRUE(Substruction('0', '0', '1').first == 'A' && Substruction('0', '0', '1').second == '1');
}

TEST(test_8_5, basic_test_set) {   
    ASSERT_TRUE(Substruction('3', '3', '0').first == '0' && Substruction('3', '3', '0').second == '0');
}

// minus

TEST(test_9_1, basic_test_set) {   
    Eleven el1{'1', '1', '1'}, el2{'1','1','1'}, el3("0");
    ASSERT_TRUE((el3 == el1 - el2));
}

TEST(test_9_2, basic_test_set) {   
    Eleven el1{'1', '2', '3'}, el2{'1','2','3'}, el3("0");
    ASSERT_TRUE((el3 == el1 - el2));
}

TEST(test_9_3, basic_test_set) {   
    Eleven el1{"1234AA1227"}, el2{"AAA123677"}, el3("235978660");
    ASSERT_TRUE((el3 == el1 - el2));
}

TEST(test_9_4, basic_test_set) {   
    Eleven el1{"123455AA"}, el2{"3217"}, el3("987"), el4("12341507");
    ASSERT_TRUE((el1 - el2 - el3 == el4));
}

TEST(test_9_5, basic_test_set) {   
    Eleven el1{"2134"}, el2{"1234523"};
    ASSERT_THROW(el1 - el2, std::underflow_error);
}

TEST(test_9_6, basic_test_set) {   
    Eleven el1{"0"}, el2{"0"}, el3 = el2;
    ASSERT_TRUE(el1 - el2 == el3);
}

// copy

TEST(test_10_1, basic_test_set) {   
    Eleven el1{"123"}, el2{"1234123"};
    el2 = el1;
    ASSERT_TRUE(el1 == el2);
}

TEST(test_10_2, basic_test_set) {   
    Eleven el1{"12341234"}, el2{"1231AA"};
    el2 = el1;
    ASSERT_TRUE(el1 == el2);
}

TEST(test_10_3, basic_test_set) {   
    Eleven el1{"000"}, el2{"11111"};
    el2 = el1;
    ASSERT_TRUE(el1 == el2);
}

//random

TEST(test_11_1, basic_test_set) {   
    Eleven el1{"123AA236723AA"}, el2{"12311"}, el3{"12341234"}, el5("111111AA112322645789203633"), el6("111111AA112321405853312311");
    ASSERT_TRUE(el5 - el3 + el2 - el1 == el6);
}

TEST(test_11_2, basic_test_set) {   
    Eleven el1{"111101060099"}, el2{"12311"}, el3{"12341234"}, el5("111113403633"), el6("0");
    ASSERT_TRUE(el5 - (el2 + el3) - el1 == el6);
}

TEST(test_11_3, basic_test_set) {   
    Eleven el1{"111101060099"}, el2{"12311"}, el3{"12341234"}, el5("111113403633"), el6("246A6A8A");
    el2 += (el3 + el5);
    el2 -= (el1);
    ASSERT_TRUE(el2 == el6);
}

// operation with =

TEST(test_12_1, basic_test_set) {   
    Eleven el2{"12311"}, el3{"12341234"}, el1{"12353545"};
    ASSERT_TRUE((el2 += el3) == el1);
}

TEST(test_12_2, basic_test_set) {   
    Eleven el2{"AA7890123849070909823741723AA0020"}, el3{"12340918023887A3410A890223"}, el1{"AA7890136089988932600675833880243"};
    ASSERT_TRUE((el2 += el3) == el1);
}

TEST(test_12_3, basic_test_set) {   
    Eleven el2{"129898723412341A34123"}, el3{"980718237"}, el1{"12989872341321265135A"};
    ASSERT_TRUE((el2 += el3) == el1);
}

TEST(test_12_4, basic_test_set) {   
    Eleven el2{"12341235422141A1234123"}, el3{"12331235222141A1298123"}, el1{"100001AAAAAAAA47000"};
    ASSERT_TRUE((el2 -= el3) == el1);
}

TEST(test_12_5, basic_test_set) {   
    Eleven el2{"AAAAAA9999998888444"}, el3{"AAAAAA9999998888444"}, el1{"0"};
    ASSERT_TRUE((el2 -= el3) == el1);
}

TEST(test_12_6, basic_test_set) {   
    Eleven el2{"000000"}, el3{"0"}, el1{"0"};
    ASSERT_TRUE((el2 += el3) == el1);
}

TEST(test_12_7, basic_test_set) {   
    Eleven el2{"0"}, el3{"0"}, el1{"0"};
    ASSERT_TRUE((el2 -= el3) == el1);
}

TEST(test_12_8, basic_test_set) {   
    Eleven el2{"111"}, el3{"12312"};
    ASSERT_THROW(el2 -= el3, std::underflow_error);
}

int main(int argc, char **argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
