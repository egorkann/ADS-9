// Copyright 2025 NNTU-CS
#include "tree.h"

PMTree::PMTree(const std::vector<char>& elems) : elements_(elems) {
  root_ = std::make_shared<Node>('\0');
}

std::shared_ptr<Node> PMTree::getRoot() const {
  return root_;
}

std::vector<char> PMTree::getElements() const {
  return elements_;
}
