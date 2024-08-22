#include <iostream>
#include <string>
#include <chrono>
#include "all_algorithms.h"
using namespace algorithms;

void measureTime(int (*searchFunc)(const std::string &, const std::string &), const std::string &text, const std::string &pattern, const std::string &algoName) {
    auto start = std::chrono::high_resolution_clock::now();
    searchFunc(text, pattern);
    auto end = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> duration = end - start;
    std::cout << algoName << " took " << duration.count() << " nanoseconds\n";
}

int main() {
    std::string text = "Mom bought me a new computer";
    std::string pattern_small = "new";
    std::string pattern_large = "Mom bought me a new computer.";

    // Small pattern tests

    // Performance tests for small patterns
    std::string text_small = std::string(1000, 'b');
    std::string pattern_small_performance = "The air-conditioner pumped out stale, barely cold air.";

    std::cout << "\nPerformance tests for small patterns:\n";
    measureTime(bruteForceSearch, text_small, pattern_small_performance, "Brute-force");
    measureTime(sundaySearch, text_small, pattern_small_performance, "Sunday");
    measureTime(kmpSearch, text_small, pattern_small_performance, "KMP");
    measureTime(fsmSearch, text_small, pattern_small_performance, "FSM");
    measureTime(rabinKarpSearch, text_small, pattern_small_performance, "Rabin-Karp");
    measureTime(gusfieldZSearch, text_small, pattern_small_performance, "Gusfield Z");

    // Performance tests for long patterns
    std::string text_long = std::string(100000, 'a');
    std::string pattern_long = "The air-conditioner pumped out stale, barely cold air. It was still a sticky twenty-eight degrees outside, the humidity high. She dug her fingers and hands into the fat at his hips, gulping for air as she tried to push him off. She put her right knee between his legs, forcing him out of her. She dug the fingers and hands into the fat, pushed and pushed until finally, she got a whole arm clear, then a leg and rolled out from under him. She got to her feet covered in his awful sweat, pubic hair from his body attached to her skin. She ran to the shower, turned it on, got underneath the cold water until it turned hot, stayed there until every inch of her body was clean from him.";
    std::string pattern_kmp = "The air-conditioner pumped out stale, barely cold air. It was still a sticky twenty-eight degrees outside, the humidity high. She dug her fingers and hands into the fat at his hips, gulping for air as she tried to push him off. She put her right knee between his legs, forcing him out of her. She dug the fingers and hands into the fat, pushed and pushed until finally, she got a whole arm clear, then a leg and rolled out from under him. She got to her feet covered in his awful sweat, pubic hair from his body attached to her skin. She ran to the shower, turned it on, got underneath the cold water until it turned hot, stayed there until every inch of her body was clean from him.";
    std::string pattern_rabin_karp = "The air-conditioner pumped out stale, barely cold air. It was still a sticky twenty-eight degrees outside, the humidity high. She dug her fingers and hands into the fat at his hips, gulping for air as she tried to push him off. She put her right knee between his legs, forcing him out of her. She dug the fingers and hands into the fat, pushed and pushed until finally, she got a whole arm clear, then a leg and rolled out from under him. She got to her feet covered in his awful sweat, pubic hair from his body attached to her skin. She ran to the shower, turned it on, got underneath the cold water until it turned hot, stayed there until every inch of her body was clean from him.";
    std::cout << "\nPerformance tests for long patterns:\n";

    // Compare Sunday and Gusfield Z
    auto start1 = std::chrono::high_resolution_clock::now();
    sundaySearch(text_long, pattern_long);
    auto end1 = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> time_sunday = end1 - start1;

    auto start2 = std::chrono::high_resolution_clock::now();
    gusfieldZSearch(text_long, pattern_long);
    auto end2 = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> time_gusfield_z = end2 - start2;

    std::cout << "Sunday: " << time_sunday.count() << " seconds\n";
    std::cout << "Gusfield Z: " << time_gusfield_z.count() << " seconds\n";

    if (time_sunday.count() * 2 < time_gusfield_z.count()) {
        std::cout << "Sunday is at least twice as fast as Gusfield Z.\n";
    }

    // Compare KMP and Rabin-Karp
    auto start3 = std::chrono::high_resolution_clock::now();
    kmpSearch(text_long, pattern_long);
    auto end3 = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> time_kmp = end3 - start3;

    auto start4 = std::chrono::high_resolution_clock::now();
    rabinKarpSearch(text_long, pattern_long);
    auto end4 = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> time_rabin_karp = end4 - start4;

    std::cout << "KMP: " << time_kmp.count() << " seconds\n";
    std::cout << "Rabin-Karp: " << time_rabin_karp.count() << " seconds\n";

    if (time_kmp.count() * 2 < time_rabin_karp.count()) {
        std::cout << "KMP is at least twice as fast as Rabin-Karp.\n";
    }

    // Compare Rabin-Karp and Sunday
    auto start5 = std::chrono::high_resolution_clock::now();
    rabinKarpSearch(text_long, pattern_long);
    auto end5 = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> time_rabin_karp2 = end5 - start5;

    auto start6 = std::chrono::high_resolution_clock::now();
    sundaySearch(text_long, pattern_long);
    auto end6 = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> time_sunday2 = end6 - start6;

    std::cout << "Rabin-Karp: " << time_rabin_karp2.count() << " seconds\n";
    std::cout << "Sunday: " << time_sunday2.count() << " seconds\n";

    if (time_rabin_karp2.count() * 2 < time_sunday2.count()) {
        std::cout << "Rabin-Karp is at least twice as fast as Sunday.\n";
    }

    return 0;
}
