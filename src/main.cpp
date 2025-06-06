// Copyright 2025 NNTU-CS
#include <iostream>
#include <string>
#include "alg.h"

int main() {
  PMTree tree({'a', 'b', 'c'});

  auto all_perms = getAllPerms(tree);

  for (const auto& perm : all_perms) {
    for (char c : perm) {
      std::cout << c;
    }
    std::cout << '\n';
  }

  int num1 = 1;
  auto perm1 = getPerm1(tree, num1);

  int num2 = 2;
  auto perm2 = getPerm2(tree, num2);

  return 0;
}
