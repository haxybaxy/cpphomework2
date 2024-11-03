#include "main19.h"

using namespace homework;
int main() {
    std::vector<char> book = readBook("../IntroducingLogic.txt");

    std::vector<std::string> words = extractWords(book);

    int uniqueWordsCount = countUniqueWords(words);
    std::cout << "Number of unique words: " << uniqueWordsCount << std::endl;

    std::vector<std::pair<std::string, int>> wordFrequencies = countWordFrequencies(words);

    sortFrequencies(wordFrequencies);

    outputFrequencies(wordFrequencies, "../frequencies.txt");

    printHapaxLegomena(wordFrequencies);

    return 0;
}
