// Copyright 2025 NNTU-CS
#include "alg.h"
#include "alg.h"

void buildTree(std::shared_ptr<PMNode> node, const std::vector<char>& remaining) {
  if (remaining.empty()) return;

  for (size_t i = 0; i < remaining.size(); ++i) {
    char ch = remaining[i];
    std::shared_ptr<PMNode> child = std::make_shared<PMNode>(ch);
    node->children.push_back(child);

    std::vector<char> next_remaining = remaining;
    next_remaining.erase(next_remaining.begin() + i);

    buildTree(child, next_remaining);
  }
}

void collectPerms(std::shared_ptr<PMNode> node, std::vector<char>& current,
                  std::vector<std::vector<char>>& result) {
  current.push_back(node->val);

  if (node->children.empty()) {
    result.push_back(current);
  } else {
    for (const auto& child : node->children) {
      collectPerms(child, current, result);
    }
  }

  current.pop_back();
}
