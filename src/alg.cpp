// Copyright 2025 NNTU-CS
#include "alg.h"
#include <memory>
#include <vector>
#include <algorithm>

PMTree::PMTree(const std::vector<char>& elems) : elements_(elems) {
  root = std::make_shared<Node>('R');
}

std::vector<std::vector<char>> getAllPerms(PMTree& tree) {
  if (tree.getAllPerms().empty()) {
    buildTree(tree.root, tree.getElements());
    std::vector<char> current;
    collectPerms(tree.root, current, tree.getAllPerms());
  }
  return tree.getAllPerms();
}

std::vector<char> getPerm1(PMTree& tree, int index) {
  std::vector<char> elems = tree.getElements();
  if (index >= 0 && index < static_cast<int>(elems.size())) {
    return {elems[index]};
  }
  return {};
}

std::vector<char> getPerm2(PMTree& tree, int index) {
  std::vector<char> elems = tree.getElements();
  if (index >= 0 && index < static_cast<int>(elems.size())) {
    return {elems[index]};
  }
  return {};
}
