#include <iostream>
#include <cassert>
#include "../src/core/bitset_filter.h"

#define TEST(name) void name()
#define EXPECT_TRUE(x) do { if (!(x)) { std::cout << "Test failed: " #x << std::endl; assert(x); } } while(0)
#define EXPECT_FALSE(x) EXPECT_TRUE(!(x))
#define EXPECT_EQ(a, b) do { if ((a) != (b)) { std::cout << "Test failed: " #a " == " #b << std::endl; assert((a) == (b)); } } while(0)

TEST(testSingleAttributeMatch) {
    filtering::BitsetFilter filter;
    
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
    filtering::BitsetFilter filter;
    
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
    filtering::BitsetFilter filter;
    
    filter.addAttribute(1, 100);
    filter.addAttribute(2, 100);
    
    filter.removeAttribute(1, 100);
    filter.setQueryAttributes({100});
    EXPECT_FALSE(filter(1));
    EXPECT_TRUE(filter(2));
    
    std::cout << "Attribute removal test passed\n";
}

TEST(testAttributeCount) {
    filtering::BitsetFilter filter;
    
    filter.addAttribute(1, 100);
    filter.addAttribute(1, 200);
    filter.addAttribute(1, 300);
    
    EXPECT_EQ(filter.getNumAttributes(1), 3);
    filter.removeAttribute(1, 200);
    EXPECT_EQ(filter.getNumAttributes(1), 2);
    
    std::cout << "Attribute count test passed\n";
}

TEST(testInvalidAttribute) {
    filtering::BitsetFilter filter;
    
    bool caught_exception = false;
    try {
        filter.addAttribute(1, filtering::MAX_ATTRIBUTES + 1);
    } catch (const std::out_of_range&) {
        caught_exception = true;
    }
    EXPECT_TRUE(caught_exception);
    
    std::cout << "Invalid attribute test passed\n";
}

int main() {
    std::cout << "Running bitset filter tests...\n\n";
    
    testSingleAttributeMatch();
    testMultipleAttributesMatch();
    testAttributeRemoval();
    testAttributeCount();
    testInvalidAttribute();
    
    std::cout << "\nAll bitset filter tests passed!\n";
    return 0;
}