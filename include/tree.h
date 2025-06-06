// Copyright 2025 NNTU-CS
#ifndef INCLUDE_TREE_H_
#define INCLUDE_TREE_H_

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

  void buildTree(const std::vector<char>& elems);
  void collectPerms(std::shared_ptr<PMNode> node,
                    std::vector<char>& current,
                    std::vector<std::vector<char>>& perms);

  std::vector<std::vector<char>> getAllPerms();
  std::vector<char> getPerm1(int k);
  std::vector<char> getPerm2(int k);

 private:
  std::vector<char> elements_;
  std::vector<std::vector<char>> all_perms_;
};

#endif  // INCLUDE_TREE_H_
