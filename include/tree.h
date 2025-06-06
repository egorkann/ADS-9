// Copyright 2025 NNTU-CS
#ifndef TREE_H
#define TREE_H

#include <vector>
#include <memory>

struct PMNode {
    char val;
    std::vector<std::shared_ptr<PMNode>> children;

    explicit PMNode(char v) : val(v) {}
};

class PMTree {
 private:
    std::shared_ptr<PMNode> root;
    std::vector<char> elements;
    std::vector<std::vector<char>> allPerms;

 public:
    PMTree(const std::vector<char>& elems);

    std::shared_ptr<PMNode> getRoot();
    std::vector<char> getElements() const;
    std::vector<std::vector<char>> getAllPerms() const;
};

#endif  // TREE_H
