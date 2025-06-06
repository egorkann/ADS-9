// Copyright 2025 NNTU-CS
#ifndef TREE_H
#define TREE_H

#include <vector>

class PMTree {
public:
    explicit PMTree(int root_value);
    PMTree(const std::vector<char>& elems);

    const std::vector<char>& getElements() const { return elements_; }
    const std::vector<std::vector<char>>& getAllPerms() const { return all_perms_; }
    std::vector<std::vector<char>>& getAllPerms() { return all_perms_; }

private:
    std::vector<char> elements_;
    std::vector<std::vector<char>> all_perms_;
};

#endif
