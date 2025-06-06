// Copyright 2025 NNTU-CS
#include "alg.h"
#include <memory>
#include <vector>

void buildTree(std::shared_ptr<Node> node, std::vector<char> remaining) {
  if (remaining.empty()) return;
  for (size_t i = 0; i < remaining.size(); ++i) {
    auto child = std::make_shared<Node>(remaining[i]);
    node->children.push_back(child);
    auto next = remaining;
    next.erase(next.begin() + i);
    buildTree(child, next);
  }
}

void collectPerms(std::shared_ptr<Node> node,
                  std::vector<char>& current,
                  std::vector<std::vector<char>>& result) {
  current.push_back(node->data);
  if (node->children.empty()) {
    result.push_back(current);
  } else {
    for (auto& child : node->children) {
      collectPerms(child, current, result);
    }
  }
  current.pop_back();
}

std::vector<std::vector<char>> getAllPerms(PMTree& tree) {
  auto root = tree.getRoot();
  buildTree(root, tree.getElements());
  std::vector<std::vector<char>> result;
  std::vector<char> current;
  for (auto& child : root->children) {
    collectPerms(child, current, result);
  }
  return result;
}

std::vector<char> getPerm1(PMTree& tree, int k) {
  auto perms = getAllPerms(tree);
  if (k >= 1 && k <= static_cast<int>(perms.size())) {
    return perms[k - 1];
  }
  return {};
}

std::vector<char> getPerm2(PMTree& tree, int k) {
  std::vector<std::vector<char>> result;
  std::vector<char> current;
  auto root = tree.getRoot();
  buildTree(root, tree.getElements());
  for (auto& child : root->children) {
    collectPerms(child, current, result);
  }
  if (k >= 1 && k <= static_cast<int>(result.size())) {
    return result[k - 1];
  }
  return {};
}
