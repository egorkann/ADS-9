// Copyright 2025 NNTU-CS
#ifndef INCLUDE_ALG_H_
#define INCLUDE_ALG_H_

#include <vector>
#include <memory>
#include "tree.h"

std::vector<std::vector<char>> getAllPerms(PMTree& tree);
std::vector<char> getPerm1(PMTree& tree, int index);
std::vector<char> getPerm2(PMTree& tree, int index);

void buildTree(std::shared_ptr<Node> root, const std::vector<char>& elements);
void collectPerms(std::shared_ptr<Node> root, std::vector<char>& current,
                  std::vector<std::vector<char>>& allPerms);

#endif  // INCLUDE_ALG_H_
