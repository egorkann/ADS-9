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
  assert((result[0] == std::vector<char>{'x', 'y'} ||
          result[0] == std::vector<char>{'y', 'x'}));
  assert((result[1] == std::vector<char>{'x', 'y'} ||
          result[1] == std::vector<char>{'y', 'x'}));

  std::cout << "Test passed: two permutations.\n";
}

int main() {
  testTwoPermutations();
  return 0;
}
