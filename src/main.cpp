// Copyright 2025 NNTU-CS
#include "alg.h"
#include "tree.h"

#include <iostream>
#include <memory>
#include <vector>

int main() {
  std::vector<char> input = {'a', 'b', 'c'};
  auto root = std::make_shared<PMNode>('\0');

  buildTree(root, input);

  std::vector<std::vector<char>> permutations;
  std::vector<char> current;

  for (const auto& child : root->children) {
    collectPerms(child, current, permutations);
  }

  for (const auto& perm : permutations) {
    for (char ch : perm) {
      std::cout << ch;
    }
    std::cout << '\n';
  }

  return 0;
}
