// Copyright 2025 NNTU-CS
#include <gtest/gtest.h>
#include "alg.h"  

TEST(ads9, test1) {
  PMTree tree({'a', 'b', 'c'});
  std::vector<char> result = getPerm1(tree, 1);
  EXPECT_EQ(result.size(), 1);
}

TEST(ads9, test2) {
  PMTree tree({'a', 'b', 'c'});
  std::vector<char> result = getPerm2(tree, 2);
  EXPECT_EQ(result.size(), 1);
}

TEST(ads9, test3) {
  PMTree tree({'a', 'b', 'c'});
  std::vector<char> result = getPerm1(tree, 6);
  EXPECT_TRUE(result.empty());
}

TEST(ads9, test4) {
  PMTree tree({'a', 'b', 'c'});
  std::vector<char> result = getPerm2(tree, 8);
  EXPECT_TRUE(result.empty());
}
