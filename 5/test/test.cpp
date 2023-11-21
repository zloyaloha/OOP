#include <gtest/gtest.h>
#include <vector>
#include "list.h"

TEST(NodeConstructor, TEST_01) {
    ASSERT_NO_THROW(Node<int> l);
}

TEST(NodeConstructor, TEST_02) {
    ASSERT_NO_THROW(Node<int> l(3));
}

TEST(NodeConstructor, TEST_03) {
    ASSERT_NO_THROW(Node<double> l(3.0));
}

TEST(NodeConstructor, TEST_04) {
    ASSERT_NO_THROW(Node<char *> l("abcd"));
}

TEST(NodeConstructor, TEST_05) {
    Node<int> l(1);
    ASSERT_NO_THROW(Node<int> l1(l));
}

TEST(NodeConstructor, TEST_06) {
    Node<double> l(9.0);
    ASSERT_NO_THROW(Node<double> l1(l));
}

TEST(EqualNode, TEST_01) {
    Node<double> l(9.0), l1(9.0);
    ASSERT_TRUE(l1 == l);
}

TEST(EqualNode, TEST_02) {
    Node<int> l(3), l1(4);
    ASSERT_FALSE(l1 == l);
}

TEST(AllocatorTest, TEST_01) {
    PoolAllocator<int> allocator;
    ASSERT_NO_THROW(allocator.allocate(1));
}

TEST(AllocatorTest, TEST_02) {
    PoolAllocator<int> allocator;
    int *tmp = allocator.allocate(1);
    ASSERT_NO_THROW(allocator.deallocate(tmp, 1));
}

TEST(AllocatorTest, TEST_03) {
    PoolAllocator<int> allocator;
    ASSERT_ANY_THROW(allocator.allocate(5));
}

TEST(AllocatorTest, TEST_04) {
    PoolAllocator<int> allocator;
    int *tmp = allocator.allocate(1);
    ASSERT_ANY_THROW(allocator.deallocate(tmp, 135));
}

TEST(AllocatorTest, TEST_05) {
    PoolAllocator<int> allocator;
    for (size_t i = 0; i < 1024; i++) {
        allocator.allocate(1);
    }
    ASSERT_ANY_THROW(allocator.allocate(1));
}

TEST(AllocatorTest, TEST_06) {
    PoolAllocator<int> allocator;
    int *tmp1 = allocator.allocate(1) + sizeof(int) * 2048;
    ASSERT_ANY_THROW(allocator.deallocate(tmp1, 1));
}

TEST(AllocatorTest, TEST_07) {
    PoolAllocator<int> allocator;
    int *tmp;
    for (size_t i = 0; i < 100; i++) {
        tmp = allocator.allocate(1);
    }
    ASSERT_NO_THROW(allocator.destroy(tmp));
}

TEST(ListConstructorTest, TEST_01) {
    ASSERT_NO_THROW(List<int> l({1,1,2,3,4,234,23,4123}));
}

TEST(ListConstructorTest, TEST_02) {
    List<int> l{1,1,2,3,4,234,23,4123};
    std::vector<int> v{1,1,2,3,4,234,23,4123};
    bool flag = true;
    for (size_t i = 0; i < l.size(); ++i) {
        if (v[i] != l[i]) {
            flag = false;
        }
    }
    ASSERT_TRUE(flag);
}

TEST(ListConstructorTest, TEST_03) {
    ASSERT_NO_THROW(List<int> l);
}

TEST(ListConstructorTest, TEST_04) {
    List<int> l1{123,43,2,1,23,4,1,234};
    ASSERT_NO_THROW(List<int> l(l1));
}

TEST(ListConstructorTest, TEST_05) {
    List<int> l1{123,43,2,1,23,4,1,234};
    List<int> l(l1);
    ASSERT_TRUE(l == l1);
}

TEST(ListConstructorTest, TEST_06) {
    List<int> l{1,1,2,3,4,234,23,4123};
    List<int> l1(std::move(l));
    std::vector<int> v{1,1,2,3,4,234,23,4123};
    bool flag = true;
    for (size_t i = 0; i < l1.size(); ++i) {
        if (v[i] != l1[i]) {
            flag = false;
        }
    }
    ASSERT_TRUE(flag);
}

TEST(ListSize, TEST_01) {
    List<int> l{1,1,2,3,4,234,23,4123};
    ASSERT_TRUE(l.size() == 8);
}

TEST(ListSize, TEST_02) {
    List<int> l;
    ASSERT_TRUE(l.size() == 0);
}

TEST(ListPushBack, TEST_01) {
    List<int> l;
    l.push_back(1);
    l.push_back(3);
    l.push_back(2);
    l.push_back(0);
    l.push_back(-9); 
    List<int> l1{1,3,2,0,-9};
    ASSERT_TRUE(l == l1 && l.size() == 5);
}

TEST(ListPushBack, TEST_02) {
    List<int> l{11,22,33,44};
    l.push_back(1);
    l.push_back(3);
    l.push_back(2);
    l.push_back(0);
    l.push_back(-9); 
    List<int> l1{11,22,33,44,1,3,2,0,-9};
    ASSERT_TRUE(l == l1 && l.size() == 9);
}

TEST(ListEmplace, TEST_01) {
    List<int> l{11,22,33,44};
    l.emplace(1);
    l.emplace(3);
    l.emplace(2);
    l.emplace(0);
    l.emplace(-9); 
    List<int> l1{-9,0,2,3,1,11,22,33,44};
    ASSERT_TRUE(l == l1 && l.size() == 9);
}

TEST(ListEmplace, TEST_02) {
    List<int> l;
    l.emplace(1);
    l.emplace(3);
    l.emplace(2);
    l.emplace(0);
    l.emplace(-9);
    List<int> l1{-9,0,2,3,1};
    ASSERT_TRUE(l == l1 && l.size() == 5);
}

TEST(ListRemove, TEST_01) {
    List<int> l;
    l.emplace(1);
    l.emplace(3);
    l.emplace(2);
    l.emplace(0);
    l.emplace(-9); 
    l.remove();
    l.remove();
    List<int> l1{2,3,1};
    ASSERT_TRUE(l1 == l);
}

TEST(ListRemove, TEST_02) {
    List<int> l{1,2,3};
    l.emplace(1);
    l.emplace(3);
    l.emplace(2);
    l.emplace(0);
    l.emplace(-9); 
    l.remove();
    l.remove();
    l.remove();
    l.remove();
    l.remove();
    List<int> l1{1,2,3};
    ASSERT_TRUE(l1 == l);
}

int main(int argc, char **argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}