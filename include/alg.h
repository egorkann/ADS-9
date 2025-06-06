// Copyright 2025 NNTU-CS
#ifndef INCLUDE_ALG_H_
#define INCLUDE_ALG_H_

#include "tree.h"
#include <memory>
#include <vector>

void buildTree(std::shared_ptr<PMNode> node, const std::vector<char>& remaining);
void collectPerms(std::shared_ptr<PMNode> node, std::vector<char>& current,
                  std::vector<std::vector<char>>& result);

#endif  // INCLUDE_ALG_H_
