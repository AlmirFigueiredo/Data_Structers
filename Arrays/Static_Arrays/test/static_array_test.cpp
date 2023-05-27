#include <gtest/gtest.h>
#include "../src/static_array.cpp"

// Test case for basic initialization and access of StaticArray
TEST(StaticArrayTestSuite, TestBasicInitializationAndAccess) {
    StaticArray<int, 5> testArray;
    for (std::size_t i = 0; i < testArray.size(); ++i) {
        testArray[i] = i + 1;
        EXPECT_EQ(testArray[i], i + 1);
    }
}

// Test case for default initialization of StaticArray
TEST(StaticArrayTestSuite, TestDefaultInitialization) {
    StaticArray<int, 5> testArray;
    for (std::size_t i = 0; i < testArray.size(); ++i) {
        EXPECT_EQ(testArray[i], 0);
    }
}

// Test case for modifying elements of StaticArray
TEST(StaticArrayTestSuite, TestModifyingElements) {
    StaticArray<int, 3> testArray;
    testArray[0] = 10;
    testArray[1] = 20;
    testArray[2] = 30;

    EXPECT_EQ(testArray[0], 10);
    EXPECT_EQ(testArray[1], 20);
    EXPECT_EQ(testArray[2], 30);
}

// Test case for accessing elements beyond the StaticArray boundary
TEST(StaticArrayTestSuite, TestOutOfBoundsAccess) {
    StaticArray<int, 5> testArray;

    EXPECT_THROW(testArray[5], std::out_of_range);
}

// Test case for summing all elements of StaticArray
TEST(StaticArrayTestSuite, TestSumElements) {
    StaticArray<int, 4> testArray;
    testArray[0] = 5;
    testArray[1] = 10;
    testArray[2] = 15;
    testArray[3] = 20;

    int sum = testArray.sum();
    EXPECT_EQ(sum, 50);
}

// Test case for finding the maximum element in StaticArray
TEST(StaticArrayTestSuite, TestMaxElement) {
    StaticArray<int, 5> testArray;
    testArray[0] = 10;
    testArray[1] = 30;
    testArray[2] = 20;
    testArray[3] = 50;
    testArray[4] = 40;

    int max = testArray.max();
    EXPECT_EQ(max, 50);
}

// Test case for finding the minimum element in StaticArray
TEST(StaticArrayTestSuite, TestMinElement) {
    StaticArray<int, 5> testArray;
    testArray[0] = 10;
    testArray[1] = 30;
    testArray[2] = 20;
    testArray[3] = 50;
    testArray[4] = 40;

    int min = testArray.min();
    EXPECT_EQ(min, 10);
}

// Test case for sorting the elements in StaticArray
TEST(StaticArrayTestSuite, TestSortElements) {
    StaticArray<int, 6> testArray;
    testArray[0] = 10;
    testArray[1] = 30;
    testArray[2] = 20;
    testArray[3] = 50;
    testArray[4] = 40;
    testArray[5] = 15;

    testArray.sort();

    EXPECT_EQ(testArray[0], 10);
    EXPECT_EQ(testArray[1], 15);
    EXPECT_EQ(testArray[2], 20);
    EXPECT_EQ(testArray[3], 30);
    EXPECT_EQ(testArray[4], 40);
    EXPECT_EQ(testArray[5], 50);
}

// Test case for checking if StaticArray is empty
TEST(StaticArrayTestSuite, TestIsEmpty) {
    StaticArray<int, 0> emptyArray;
    StaticArray<int, 3> nonEmptyArray;

    EXPECT_TRUE(emptyArray.isEmpty());
    EXPECT_FALSE(nonEmptyArray.isEmpty());
}

// Test case for clearing the elements in StaticArray
TEST(StaticArrayTestSuite, TestClearElements) {
    StaticArray<int, 4> testArray;
    testArray[0] = 10;
    testArray[1] = 20;
    testArray[2] = 30;
    testArray[3] = 40;

    testArray.clear();

    for (std::size_t i = 0; i < testArray.size(); ++i) {
        EXPECT_EQ(testArray[i], 0);
    }
}

int main(int argc, char** argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
