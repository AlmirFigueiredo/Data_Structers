#include <gtest/gtest.h>
#include "../src/static_array.cpp"  // Include the source file to test
#include <iterator> 

TEST(StaticArrayTest, BasicInitializationAndAccess) {
    StaticArray<int, 5> arr;
    arr[0] = 1;
    arr[1] = 2;
    arr[2] = 3;
    arr[3] = 4;
    arr[4] = 5;

    for (int i = 0; i < arr.size(); ++i) {
        EXPECT_EQ(arr[i], (i + 1));
    }
}

TEST(StaticArrayTest, ModifyingElements) {
    StaticArray<int, 3> arr;
    arr[0] = 10;
    arr[1] = 20;
    arr[2] = 30;

    arr[1] = 25;
    EXPECT_EQ(arr[1], 25);

    arr[2] += 5;
    EXPECT_EQ(arr[2], 35);
}

TEST(StaticArrayTest, OutOfBoundsAccess) {
    StaticArray<int, 5> arr;

    EXPECT_THROW(arr[5] = 10, std::out_of_range);
}


TEST(StaticArrayTest, CustomObject) {
    struct Person {
        std::string name;
        int age;
    };

    StaticArray<Person, 2> arr;
    arr[0] = {"Alice", 25};
    arr[1] = {"Bob", 30};

    EXPECT_EQ(arr[0].name, "Alice");
    EXPECT_EQ(arr[0].age, 25);
    EXPECT_EQ(arr[1].name, "Bob");
    EXPECT_EQ(arr[1].age, 30);
}

int main(int argc, char** argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
