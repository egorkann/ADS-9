// Copyright 2025 NNTU-CS
#include "tree.h"
#include <algorithm>
#include <chrono>
#include <iostream>
#include <random>

PMTree::PMTree(const std::vector<char>& elems) : elements(elems) {
    std::sort(elements.begin(), elements.end());
    root = std::make_shared<PMNode>('\0');
}

void buildTree(std::shared_ptr<PMNode> node, std::vector<char> remaining) {
    if (remaining.empty()) return;

    for (size_t i = 0; i < remaining.size(); ++i) {
        char val = remaining[i];
        auto child = std::make_shared<PMNode>(val);
        node->children.push_back(child);

        std::vector<char> next = remaining;
        next.erase(next.begin() + i);
        buildTree(child, next);
    }
}

void collectPerms(std::shared_ptr<PMNode> node, std::vector<char>& current, std::vector<std::vector<char>>& result) {
    if (node->value != '\0')
        current.push_back(node->value);

    if (node->children.empty()) {
        result.push_back(current);
    } else {
        for (auto& child : node->children) {
            collectPerms(child, current, result);
        }
    }

    if (node->value != '\0')
        current.pop_back();
}

std::vector<std::vector<char>> getAllPerms(PMTree& tree) {
    if (tree.allPerms.empty()) {
        buildTree(tree.root, tree.elements);
        std::vector<char> current;
        collectPerms(tree.root, current, tree.allPerms);
    }
    return tree.allPerms;
}

std::vector<char> getPerm1(PMTree& tree, int num) {
    auto perms = getAllPerms(tree);
    if (num <= 0 || num > perms.size()) return {};
    return perms[num - 1];
}

void getPerm2Helper(std::shared_ptr<PMNode> node, int& k, std::vector<char>& result, std::vector<char> remaining) {
    if (remaining.empty()) return;
    int fact = 1;
    for (int i = 1; i < remaining.size(); ++i) fact *= i;

    int idx = (k - 1) / fact;
    k = k - idx * fact;
    result.push_back(remaining[idx]);
    remaining.erase(remaining.begin() + idx);
    getPerm2Helper(node, k, result, remaining);
}

std::vector<char> getPerm2(PMTree& tree, int num) {
    if (num <= 0) return {};
    std::vector<char> result;
    std::vector<char> elems = tree.elements;
    getPerm2Helper(tree.root, num, result, elems);
    return result;
}

