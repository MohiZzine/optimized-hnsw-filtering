#include <iostream>
#include <cassert>
#include "../src/core/roaring_filter.h"

#define TEST(name) void name()
#define EXPECT_TRUE(x) do { if (!(x)) { std::cout << "Test failed: " #x << std::endl; assert(x); } } while(0)
#define EXPECT_FALSE(x) EXPECT_TRUE(!(x))
#define EXPECT_EQ(a, b) do { if ((a) != (b)) { std::cout << "Test failed: " #a " == " #b << std::endl; assert((a) == (b)); } } while(0)

TEST(testSingleAttributeMatch) {
    filtering::RoaringFilter filter;
    
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
    filtering::RoaringFilter filter;
    
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
    filtering::RoaringFilter filter;
    
    filter.addAttribute(1, 100);
    filter.addAttribute(2, 100);
    
    filter.removeAttribute(1, 100);
    filter.setQueryAttributes({100});
    EXPECT_FALSE(filter(1));
    EXPECT_TRUE(filter(2));
    
    std::cout << "Attribute removal test passed\n";
}

TEST(testAttributeCount) {
    filtering::RoaringFilter filter;
    
    filter.addAttribute(1, 100);
    filter.addAttribute(1, 200);
    filter.addAttribute(1, 300);
    
    EXPECT_EQ(filter.getCardinality(1), 3);
    filter.removeAttribute(1, 200);
    EXPECT_EQ(filter.getCardinality(1), 2);
    
    std::cout << "Attribute count test passed\n";
}

// Add this line to specify the subsystem
#ifdef _WIN32
#include <windows.h>
int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow) {
#else
int main() {
#endif
    std::cout << "Running roaring filter tests...\n\n";
    
    testSingleAttributeMatch();
    testMultipleAttributesMatch();
    testAttributeRemoval();
    testAttributeCount();
    
    std::cout << "\nAll roaring filter tests passed!\n";
    return 0;
}