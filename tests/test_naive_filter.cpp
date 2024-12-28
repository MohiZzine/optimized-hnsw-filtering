#include <iostream>
#include <cassert>
#include "../src/core/naive_filter.h"

#define TEST(name) void name()
#define EXPECT_TRUE(x) do { if (!(x)) { std::cout << "Test failed: " #x << std::endl; assert(x); } } while(0)
#define EXPECT_FALSE(x) EXPECT_TRUE(!(x))

TEST(testSingleAttributeMatch) {
    filtering::NaiveFilter filter;
    
    // Set up test data
    filter.addAttribute(1, 100);  // Point 1 has attribute 100
    filter.addAttribute(1, 200);  // and attribute 200
    filter.addAttribute(2, 100);  // Point 2 has attribute 100
    filter.addAttribute(3, 300);  // Point 3 has attribute 300

    filter.setQueryAttributes({100});
    EXPECT_TRUE(filter(1));
    EXPECT_TRUE(filter(2));
    EXPECT_FALSE(filter(3));
    
    std::cout << "Single attribute match test passed\n";
}

TEST(testMultipleAttributesMatch) {
    filtering::NaiveFilter filter;
    
    // Set up test data
    filter.addAttribute(1, 100);
    filter.addAttribute(1, 200);
    filter.addAttribute(2, 100);
    filter.addAttribute(3, 300);

    filter.setQueryAttributes({100, 200});
    EXPECT_TRUE(filter(1));   // Has both attributes
    EXPECT_FALSE(filter(2));  // Only has attribute 100
    EXPECT_FALSE(filter(3));  // Has neither attribute
    
    std::cout << "Multiple attributes match test passed\n";
}

TEST(testAttributeRemoval) {
    filtering::NaiveFilter filter;
    
    filter.addAttribute(1, 100);
    filter.addAttribute(2, 100);
    
    filter.removeAttribute(1, 100);
    filter.setQueryAttributes({100});
    EXPECT_FALSE(filter(1));
    EXPECT_TRUE(filter(2));
    
    std::cout << "Attribute removal test passed\n";
}

int main() {
    std::cout << "Running tests...\n\n";
    
    testSingleAttributeMatch();
    testMultipleAttributesMatch();
    testAttributeRemoval();
    
    std::cout << "\nAll tests passed!\n";
    return 0;
}