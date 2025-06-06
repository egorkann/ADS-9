// Copyright 2025 NNTU-CS
#include "alg.h"
#include "tree.h"
#include <gtest/gtest.h>
#include <vector>

TEST(ads9, test1) {
  PMTree tree({'a', 'b', 'c'});
  std::vector<char> result = getPerm1(tree, 1);
  EXPECT_EQ(result, std::vector<char>({'a', 'b', 'c'}));
}

TEST(ads9, test2) {
  PMTree tree({'a', 'b', 'c'});
  std::vector<char> result = getPerm2(tree, 2);
  EXPECT_EQ(result, std::vector<char>({'a', 'c', 'b'}));
}

TEST(ads9, test3) {
  PMTree tree({'x', 'y', 'z'});
  std::vector<char> result = getPerm1(tree, 6);
  EXPECT_EQ(result, std::vector<char>({'z', 'y', 'x'}));
}

TEST(ads9, test4) {
  PMTree tree({'1', '2', '3'});
  std::vector<char> result = getPerm2(tree, 5);
  EXPECT_EQ(result, std::vector<char>({'3', '1', '2'}));
}

