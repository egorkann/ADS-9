// Copyright 2025 NNTU-CS
#include "alg.h"

PMTree::PMTree(const std::vector<char>& elements) : elements_(elements) {
  root = std::make_shared<Node>('R');
}

std::vector<char> PMTree::getElements() const {
  return elements_;
}

std::vector<std::vector<char>>& PMTree::getAllPerms() {
  return allPerms_;
}

void buildTree(std::shared_ptr<Node> root, const std::vector<char>& elements) {
  if (elements.empty()) {
    return;
  }
  for (char c : elements) {
    root->children.push_back(std::make_shared<Node>(c));
  }
}

void collectPerms(std::shared_ptr<Node> node, std::vector<char>& current,
                  std::vector<std::vector<char>>& allPerms) {
  if (node->children.empty()) {
    allPerms.push_back(current);
    return;
  }
  for (auto& child : node->children) {
    current.push_back(child->val);
    collectPerms(child, current, allPerms);
    current.pop_back();
  }
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
