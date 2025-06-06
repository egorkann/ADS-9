// Copyright 2022 NNTU-CS
#ifndef TREE_H_
#define TREE_H_

#include <vector>
#include <memory>

class PMNode {
 public:
  int value;
  std::vector<std::shared_ptr<PMNode>> children;

  explicit PMNode(int val);
};

class PMTree {
 public:
  std::shared_ptr<PMNode> root;

  explicit PMTree(int root_value);
  void addNode(const std::shared_ptr<PMNode>& parent, int child_value);
  void getAllPerms(const std::shared_ptr<PMNode>& node,
                   std::vector<std::vector<int>>& perms,
                   std::vector<int>& current);
};

#endif  // TREE_H_
