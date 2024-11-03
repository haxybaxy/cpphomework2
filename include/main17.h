#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <sstream>
#include <map>
#include <set>

namespace homework {

std::vector<char> readBook(std::string fileName) { //read book from file
    std::vector<char> book;
    std::ifstream file(fileName);
    if (!file.is_open()) {
        std::cerr << "Could not open the file " << fileName << std::endl;
        return book;
    }

    char c;
    while (file.get(c)) {
        if (std::isalpha(c)) {
            book.push_back(std::tolower(c));
        } else {
            book.push_back(' ');
        }
    }

    file.close();
    return book;
}

std::map<std::string, int> computeWordFrequency(const std::vector<char>& book) { //compute word frequency
    std::map<std::string, int> wordFreq;
    std::string data(book.begin(), book.end());
    std::stringstream ss(data);
    std::string word;
    while (ss >> word) {
        wordFreq[word]++;
    }
    return wordFreq;
}

int countUniqueWords(const std::vector<char>& book) { //count unique words
    std::set<std::string> uniqueWords;
    std::string data(book.begin(), book.end());
    std::stringstream ss(data);
    std::string word;
    while (ss >> word) {
        uniqueWords.insert(word);
    }
    return uniqueWords.size();
}

std::multimap<int, std::string, std::greater<>> sortFrequencies(const std::map<std::string, int>& frequencies) { //sort frequencies
    std::multimap<int, std::string, std::greater<>> sortedFreq;
    for (const auto& [word, freq] : frequencies) {
        sortedFreq.insert({freq, word});
    }
    return sortedFreq;
}

void outputFrequencies(const std::multimap<int, std::string, std::greater<>>& sortedFreq, const std::string& filename) { //output frequencies
    std::ofstream outFile(filename);
    if (!outFile) {
        std::cerr << "Could not open the file " << filename << std::endl;
        return;
    }

    int rank = 1;
    for (const auto& [freq, word] : sortedFreq) { // structured binding
        outFile << rank << " " << freq << " " << word << std::endl;
        rank++;
    }

    outFile.close();
}

void printHapaxLegomena(const std::multimap<int, std::string, std::greater<>>& sortedFreq) { //print hapax legomena
    int hapaxCount = 0;
    std::cout << "Hapax Legomena (words that occur only once):" << std::endl;

    for (auto it = sortedFreq.rbegin(); it != sortedFreq.rend(); ++it) {
        if (it->first == 1) {
            hapaxCount++;
            if (hapaxCount <= 10) { // Display first 10 hapax legomena
                std::cout << it->second << std::endl;
            }
        } else {
            break;
        }
    }

    std::cout << "Total number of hapax legomena: " << hapaxCount << std::endl;
}

} // namespace homework
