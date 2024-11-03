#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <sstream>
#include <algorithm>

namespace homework {

std::vector<char> readBook(const std::string& fileName) { //read book from file
    std::vector<char> book;
    std::ifstream file(fileName);
    if (!file.is_open()) {
        std::cerr << "Could not open the file " << fileName << std::endl;
        return book;
    }

    char c;
    while (file.get(c)) {
        if (std::isalpha(static_cast<unsigned char>(c))) {
            book.push_back(static_cast<char>(std::tolower(static_cast<unsigned char>(c))));
        } else {
            book.push_back(' ');
        }
    }

    file.close();
    return book;
}

std::vector<std::string> extractWords(const std::vector<char>& book) { //extract words
    std::string data(book.begin(), book.end());
    std::stringstream ss(data);
    std::string word;
    std::vector<std::string> words;

    while (ss >> word) {
        words.push_back(word);
    }

    return words;
}

std::vector<std::pair<std::string, int>> countWordFrequencies(std::vector<std::string>& words) { //count word frequencies
    std::vector<std::pair<std::string, int>> wordFrequencies;

    // Sort the words
    std::sort(words.begin(), words.end());

    // Iterate and count frequencies
    for (auto it = words.begin(); it != words.end();) { // iterator
        auto word = *it;
        // Find the range of equal words
        auto range = std::equal_range(it, words.end(), word);
        int count = std::distance(range.first, range.second);
        wordFrequencies.emplace_back(word, count);
        // Move iterator to the next new word
        it = range.second;
    }

    return wordFrequencies;
}

int countUniqueWords(std::vector<std::string>& words) { //count unique words
    auto uniqueEnd = std::unique(words.begin(), words.end());
    int uniqueCount = std::distance(words.begin(), uniqueEnd);
    return uniqueCount;
}

void sortFrequencies(std::vector<std::pair<std::string, int>>& wordFrequencies) { //sort frequencies
    std::sort(wordFrequencies.begin(), wordFrequencies.end(),
              [](const auto& a, const auto& b) {
                  return a.second > b.second;
              });
}

void outputFrequencies(const std::vector<std::pair<std::string, int>>& wordFrequencies, const std::string& filename) { //output frequencies
    std::ofstream outFile(filename);
    if (!outFile) {
        std::cerr << "Could not open the file " << filename << std::endl;
        return;
    }

    int rank = 1;
    for (const auto& [word, freq] : wordFrequencies) { // structured binding
        outFile << rank << " " << freq << " " << word << std::endl;
        rank++;
    }

    outFile.close();
}

void printHapaxLegomena(const std::vector<std::pair<std::string, int>>& wordFrequencies) { //print hapax legomena
    int hapaxCount = 0;
    std::cout << "Hapax Legomena (words that occur only once):" << std::endl;


    for (auto it = wordFrequencies.rbegin(); it != wordFrequencies.rend(); ++it) {
        if (it->second == 1) {
            hapaxCount++;
            if (hapaxCount <= 10) {
                std::cout << it->first << std::endl;
            }
        } else {
            break;
        }
    }

    std::cout << "Total number of hapax legomena: " << hapaxCount << std::endl;
}

} // namespace homework
