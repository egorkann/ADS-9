// Copyright 2025 NNTU-CS
#ifndef INCLUDE_TREE_H_
#define INCLUDE_TREE_H_

#include <memory>
#include <vector>

struct Node {
  char data;
  std::vector<std::shared_ptr<Node>> children;
  Node(char d) : data(d) {}
};

class PMTree {
 public:
  explicit PMTree(const std::vector<char>& elems);
  std::shared_ptr<Node> getRoot() const;
  std::vector<char> getElements() const;

 private:
  std::shared_ptr<Node> root_;
  std::vector<char> elements_;
};

#endif  // INCLUDE_TREE_H_


// === include/alg.h ===
#ifndef INCLUDE_ALG_H_
#define INCLUDE_ALG_H_

#include <vector>
#include "tree.h"

std::vector<std::vector<char>> getAllPerms(PMTree& tree);
std::vector<char> getPerm1(PMTree& tree, int k);
std::vector<char> getPerm2(PMTree& tree, int k);

#endif  // INCLUDE_ALG_H_
