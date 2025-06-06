// Copyright 2022 NNTU-CS
#include "tree.h"
#include <iostream>
#include <chrono>
#include <random>
#include <fstream>
#include <matplot/matplot.h>

using namespace std;
using namespace std::chrono;
using namespace matplot;

int main() {
    vector<int> sizes = {3, 4, 5, 6, 7, 8};
    vector<double> t_all, t_1, t_2;

    random_device rd;
    mt19937 gen(rd());

    for (int n : sizes) {
        vector<char> chars;
        for (int i = 0; i < n; ++i) chars.push_back('a' + i);

        PMTree tree(chars);

        // Measure getAllPerms
        auto start = high_resolution_clock::now();
        auto perms = getAllPerms(tree);
        auto end = high_resolution_clock::now();
        t_all.push_back(duration<double>(end - start).count());

        uniform_int_distribution<> dis(1, perms.size());
        int num = dis(gen);

        // Measure getPerm1
        start = high_resolution_clock::now();
        auto p1 = getPerm1(tree, num);
        end = high_resolution_clock::now();
        t_1.push_back(duration<double>(end - start).count());

        // Measure getPerm2
        start = high_resolution_clock::now();
        auto p2 = getPerm2(tree, num);
        end = high_resolution_clock::now();
        t_2.push_back(duration<double>(end - start).count());
    }

    loglog(sizes, t_all, "-o")->label("getAllPerms");
    loglog(sizes, t_1, "-o")->label("getPerm1");
    loglog(sizes, t_2, "-o")->label("getPerm2");
    legend();
    xlabel("Alphabet size n");
    ylabel("Time (s)");
    save("result/plot.png");
    show();

    return 0;
}

