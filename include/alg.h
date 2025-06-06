
#ifndef INCLUDE_ALG_H_
#define INCLUDE_ALG_H_

#include <vector>
#include "tree.h"

std::vector<std::vector<char>> getAllPerms(PMTree& tree);
std::vector<char> getPerm2(PMTree& tree, int index);


struct Node;  

void buildTree(Node& root, const std::vector<char>& elements);
void collectPerms(Node& root, std::vector<char>& current,
                  std::vector<std::vector<char>>& allPerms);

#endif  // INCLUDE_ALG_H_
