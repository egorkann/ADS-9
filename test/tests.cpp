// Copyright 2025 NNTU-CS
#include "alg.h"
#include "tree.h"

#include <cassert>
#include <iostream>
#include <memory>
#include <vector>

void testTwoPermutations() {
  std::vector<char> input = {'x', 'y'};
  auto root = std::make_shared<PMNode>('\0');

  buildTree(root, input);

  std::vector<std::vector<char>> result;
  std::vector<char> current;

  for (const auto& child : root->children) {
    collectPerms(child, current, result);
  }

  assert(result.size() == 2);
  std::cout << "Test passed.\n";
}

int main() {
  testTwoPermutations();
  return 0;
}
