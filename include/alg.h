// Copyright 2025 NNTU-CS
#ifndef ALG_H
#define ALG_H

#include "tree.h"
#include <vector>

void buildTree(std::shared_ptr<PMNode> node, std::vector<char> remaining);
void collectPerms(std::shared_ptr<PMNode> node, std::vector<char>& current, std::vector<std::vector<char>>& result);

std::vector<std::vector<char>> getAllPerms(PMTree& tree);
std::vector<char> getPerm1(PMTree& tree, int k);
std::vector<char> getPerm2(PMTree& tree, int k);

#endif  // ALG_H

