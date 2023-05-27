#include <gtest/gtest.h>
#include "../src/static_array.cpp"  // Include the source file to test
#include <iterator>

// Test case for basic initialization and access of StaticArray
TEST(StaticArrayTestSuite, TestBasicInitializationAndAccess) {
    StaticArray<int, 5> testArray;
    for(int i = 0; i < testArray.size(); ++i) {
        testArray[i] = i + 1;
        EXPECT_EQ(testArray[i], i + 1);
    }
}

// Test case for default initialization of StaticArray
TEST(StaticArrayTestSuite, TestDefaultInitialization) {
    StaticArray<int, 5> testArray;
    for(int i = 0; i < testArray.size(); ++i) {
        EXPECT_EQ(testArray[i], 0);
    }
}

// Test case for modifying elements of StaticArray
TEST(StaticArrayTestSuite, TestModifyingElements) {
    StaticArray<int, 3> testArray = {10, 20, 30};

    testArray[1] = 25;
    EXPECT_EQ(testArray[1], 25);

    testArray[2] += 5;
    EXPECT_EQ(testArray[2], 35);
}

// Test case for copy constructor and assignment operator
TEST(StaticArrayTestSuite, TestCopyConstructorAndAssignment) {
    StaticArray<int, 3> originalArray = {10, 20, 30};
    StaticArray<int, 3> copiedArray(originalArray);  // Copy construction
    StaticArray<int, 3> assignedArray;
    assignedArray = originalArray;  // Copy assignment

    for(int i = 0; i < originalArray.size(); ++i) {
        EXPECT_EQ(copiedArray[i], originalArray[i]);
        EXPECT_EQ(assignedArray[i], originalArray[i]);
    }
}

// Test case for access beyond the StaticArray boundary
TEST(StaticArrayTestSuite, TestOutOfBoundsAccess) {
    StaticArray<int, 5> testArray;

    EXPECT_THROW(testArray[5] = 10, std::out_of_range);
}

// Test case for iterator functionality of StaticArray
TEST(StaticArrayTestSuite, TestIteratorFunctionality) {
    StaticArray<int, 5> testArray = {1, 2, 3, 4, 5};
    int value = 1;

    for(auto it = testArray.begin(); it != testArray.end(); ++it) {
        EXPECT_EQ(*it, value);
        ++value;
    }
}

// Test case for StaticArray containing custom objects
TEST(StaticArrayTestSuite, TestCustomObject) {
    struct Person {
        std::string name;
        int age;
    };

    StaticArray<Person, 2> testArray = {{"Alice", 25}, {"Bob", 30}};

    EXPECT_EQ(testArray[0].name, "Alice");
    EXPECT_EQ(testArray[0].age, 25);
    EXPECT_EQ(testArray[1].name, "Bob");
    EXPECT_EQ(testArray[1].age, 30);
}

int main(int argc, char** argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
