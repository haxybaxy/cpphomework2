#include "main17.h"

#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <sstream>
#include <map>
#include <set>

using namespace homework;
int main() {
    std::vector<char> book = readBook("../pg2701.txt");

    std::map<std::string, int> wordFreq = computeWordFrequency(book);

    int uniqueWordsCount = countUniqueWords(book);
    std::cout << "Number of unique words: " << uniqueWordsCount << std::endl;

    std::multimap<int, std::string, std::greater<>> sortedFreq = sortFrequencies(wordFreq);

    outputFrequencies(sortedFreq, "../frequencies.txt");

    printHapaxLegomena(sortedFreq);

    return 0;
}
