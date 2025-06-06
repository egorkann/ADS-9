// Copyright 2025 NNTU-CS
#include "alg.h"
#include "tree.h"
#include <iostream>
#include <vector>

int main() {
  std::vector<char> elements = {'a', 'b', 'c'};
  PMTree tree(elements);

  auto all_perms = getAllPerms(tree);
  std::cout << "All permutations:\n";
  for (const auto& perm : all_perms) {
    for (char c : perm) std::cout << c;
    std::cout << '\n';
  }

  int num1 = 2;
  auto perm1 = getPerm1(tree, num1);
  std::cout << "\nPermutation " << num1 << " using getPerm1: ";
  for (char c : perm1) std::cout << c;
  std::cout << '\n';

  int num2 = 4;
  auto perm2 = getPerm2(tree, num2);
  std::cout << "Permutation " << num2 << " using getPerm2: ";
  for (char c : perm2) std::cout << c;
  std::cout << '\n';

  return 0;
}
