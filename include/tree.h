// Copyright 2025 NNTU-CS
#ifndef INCLUDE_TREE_H_
#define INCLUDE_TREE_H_

#include <memory>
#include <vector>

struct PMNode {
  char val;
  std::vector<std::shared_ptr<PMNode>> children;

  explicit PMNode(char value) : val(value) {}
};

#endif  // INCLUDE_TREE_H_
