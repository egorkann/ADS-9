// Copyright 2025 NNTU-CS
#ifndef INCLUDE_TREE_H_
#define INCLUDE_TREE_H_

#include <vector>
#include <memory>

struct Node {
  char val;
  std::vector<std::shared_ptr<Node>> children;
  explicit Node(char v) : val(v) {}
};

class PMTree {
 public:
  explicit PMTree(const std::vector<char>& elements);
  std::vector<char> getElements() const;
  std::vector<std::vector<char>>& getAllPerms();

  std::shared_ptr<Node> root;

 private:
  std::vector<char> elements_;
  std::vector<std::vector<char>> allPerms_;
};

#endif  // INCLUDE_TREE_H_
