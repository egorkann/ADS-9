// Copyright 2025 NNTU-CS
#ifndef INCLUDE_TREE_H_
#define INCLUDE_TREE_H_

#include <vector>
#include <memory>

struct Node {
  char value;
  std::vector<std::shared_ptr<Node>> children;
  explicit Node(char v) : value(v) {}
};

class PMTree {
 public:
  explicit PMTree(int root_value);
  explicit PMTree(const std::vector<char>& elems);

  const std::vector<char>& getElements() const { return elements_; }
  const std::vector<std::vector<char>>& getAllPerms() const { return all_perms_; }
  std::vector<std::vector<char>>& getAllPerms() { return all_perms_; }

  std::shared_ptr<Node> root;

 private:
  std::vector<char> elements_;
  std::vector<std::vector<char>> all_perms_;
};

#endif  // INCLUDE_TREE_H_
