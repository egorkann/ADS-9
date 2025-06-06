// Copyright 2025 NNTU-CS
#include "tree.h"
#include <chrono>
#include <iostream>
#include <random>
#include <vector>

using std::cout;
using std::endl;
using std::vector;
using std::string;
using std::chrono::high_resolution_clock;
using std::chrono::duration;

int main() {
    vector<char> input = {'1', '2', '3'};
    PMTree tree(input);

    cout << "All permutations:" << endl;
    auto all_perms = getAllPerms(tree);
    for (const auto& perm : all_perms) {
        for (char c : perm) {
            cout << c;
        }
        cout << endl;
    }

    int num1 = 1;
    auto perm1 = getPerm1(tree, num1);
    cout << "Permutation " << num1 << " using getPerm1: ";
    for (char c : perm1) {
        cout << c;
    }
    cout << endl;

    int num2 = 2;
    auto perm2 = getPerm2(tree, num2);
    cout << "Permutation " << num2 << " using getPerm2: ";
    for (char c : perm2) {
        cout << c;
    }
    cout << endl;

    // Performance experiment
    cout << "\nPerformance comparison:" << endl;
    vector<int> sizes = {3, 4, 5, 6};
    std::mt19937 rng(std::random_device{}());

    for (int n : sizes) {
        vector<char> chars;
        for (int i = 0; i < n; ++i) {
            chars.push_back('a' + i);
        }
        PMTree perf_tree(chars);
        int total_perms = 1;
        for (int i = 2; i <= n; ++i) {
            total_perms *= i;
        }
        std::uniform_int_distribution<int> dist(1, total_perms);
        int target = dist(rng);

        auto start1 = high_resolution_clock::now();
        getAllPerms(perf_tree);
        auto end1 = high_resolution_clock::now();

        auto start2 = high_resolution_clock::now();
        getPerm1(perf_tree, target);
        auto end2 = high_resolution_clock::now();

        auto start3 = high_resolution_clock::now();
        getPerm2(perf_tree, target);
        auto end3 = high_resolution_clock::now();

        auto dur1 = duration<double, std::milli>(end1 - start1).count();
        auto dur2 = duration<double, std::milli>(end2 - start2).count();
        auto dur3 = duration<double, std::milli>(end3 - start3).count();

        cout << "Size: " << n << ", getAllPerms: " << dur1 << " ms, ";
        cout << "getPerm1: " << dur2 << " ms, ";
        cout << "getPerm2: " << dur3 << " ms" << endl;
    }

    return 0;
}

