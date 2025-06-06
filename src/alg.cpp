// Copyright 2025 NNTU-CS
#include "alg.h"
#include <memory>
#include <vector>

void buildTree(std::shared_ptr<PMNode> node, std::vector<char> remaining) {
    if (remaining.empty()) return;
    for (size_t i = 0; i < remaining.size(); ++i) {
        char c = remaining[i];
        auto child = std::make_shared<PMNode>(c);
        node->children.push_back(child);

        std::vector<char> next = remaining;
        next.erase(next.begin() + i);
        buildTree(child, next);
    }
}

void collectPerms(std::shared_ptr<PMNode> node, std::vector<char>& current, std::vector<std::vector<char>>& result) {
    if (node->val != '\0') current.push_back(node->val);

    if (node->children.empty()) {
        result.push_back(current);
    } else {
        for (const auto& child : node->children) {
            collectPerms(child, current, result);
        }
    }

    if (!current.empty()) current.pop_back();
}

std::vector<std::vector<char>> getAllPerms(PMTree& tree) {
    buildTree(tree.getRoot(), tree.getElements());
    std::vector<char> current;
    std::vector<std::vector<char>> result;
    collectPerms(tree.getRoot(), current, result);
    return result;
}

std::vector<char> getPerm1(PMTree& tree, int k) {
    auto perms = getAllPerms(tree);
    if (k >= 1 && k <= static_cast<int>(perms.size())) {
        return perms[k - 1];
    }
    return {};
}

std::vector<char> getPerm2(PMTree& tree, int k) {
    std::vector<std::vector<char>> result;
    std::vector<char> current;
    buildTree(tree.getRoot(), tree.getElements());
    collectPerms(tree.getRoot(), current, result);

    if (k >= 1 && k <= static_cast<int>(result.size())) {
        return result[k - 1];
    }
    return {};
}
