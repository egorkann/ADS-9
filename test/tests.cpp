// Copyright 2025 NNTU-CS
#include <gtest/gtest.h>
#include <vector>
#include "alg.h"

TEST(ads9, test1) {
    PMTree tree({'a', 'b'});
    std::vector<char> result = getPerm1(tree, 1);
    ASSERT_EQ(result, std::vector<char>({'a', 'b'}));
}

TEST(ads9, test2) {
    PMTree tree({'a', 'b'});
    std::vector<char> result = getPerm2(tree, 2);
    ASSERT_EQ(result, std::vector<char>({'b', 'a'}));
}

TEST(ads9, test3) {
    PMTree tree({'a', 'b', 'c'});
    std::vector<char> result = getPerm1(tree, 6);
    ASSERT_EQ(result, std::vector<char>({'c', 'b', 'a'}));
}

TEST(ads9, test4) {
    PMTree tree({'a', 'b', 'c'});
    std::vector<char> result = getPerm2(tree, 4);
    ASSERT_EQ(result, std::vector<char>({'b', 'c', 'a'}));
}
