//
// Created by Maja on 5/9/2024.
//

#include "RepresentationScheme.h"
std::string VectorLinearSearch::chosenRepresentation(std::string fileName){

    std::ifstream fullDictionary(fileName);
    std::string word;
    while(fullDictionary >> word){
        this->dictionary.push_back(word);
    }
    int letterAmount = 5;
    this->dictionary.erase(std::remove_if(this->dictionary.begin(), this->dictionary.end(),
                                          [letterAmount](const std::string& str) {
                                              if (str.length() != letterAmount) {
                                                  return true;
                                              }
                                              if (str.find('\'') != std::string::npos || str.find('-') != std::string::npos) {
                                                  return true;
                                              }
                                              return false;
                                          }),
                           this->dictionary.end());
    std::sort(this->dictionary.begin(), this->dictionary.end());

    this->drawedWord = this->dictionary[WordDrawingLogic::rand_int(0, int(this->dictionary.size()-1))];
    return drawedWord;

}

void VectorLinearSearch::measureTime() {
    std::vector<std::string> wordsToSearch;
    for(int i = 0; i < 500; i++){
        int randomIndex = WordDrawingLogic::rand_int(0, int(this->dictionary.size()-1));
        wordsToSearch.push_back(this->dictionary[randomIndex]);
    }

    auto start = std::chrono::high_resolution_clock::now();

    for(const auto& word : wordsToSearch){
        for (const auto& element : this->dictionary) {
            if(element == word){
                std::cout<<word<<std::endl;
                break;
            }
        }
    }
    auto end = std::chrono::high_resolution_clock::now();

    auto duration = std::chrono::duration_cast<std::chrono::microseconds>(end - start);
    std::cout<<"Duration for linear search: " << duration.count() << " us" << std::endl;
}

std::vector<LettersPositionData> VectorLinearSearch::checkingWord(std::vector<std::string> userWordArray) {
    lettersPosition = {};
    std::string userWord;
    for (const std::string& element:userWordArray) {
        userWord +=  element;
    }
    bool foundWord = false;
    for (const auto &element: this->dictionary) {
        if (userWord == element) {
            foundWord = true;
        }
    }
    if (foundWord) {
        for (int i = 0; i < this->drawedWord.size(); i++) {
            LettersPositionData letter = notExisting;
            if(this->drawedWord.find(userWord[i])!= std::string::npos){
                letter = wrongPlace;
                if (this->drawedWord[i] == userWord[i]){
                    letter = inPlace;
                }
            }
            lettersPosition.push_back(letter);
        }
    }
    return lettersPosition;

}


std::string VectorBinarySearch::chosenRepresentation(std::string fileName){

    std::ifstream fullDictionary(fileName);
    std::string word;
    while(fullDictionary >> word){
        this->dictionary.push_back(word);
    }

    int letterAmount = 5;

    this->dictionary.erase(std::remove_if(this->dictionary.begin(), this->dictionary.end(),
                                          [letterAmount](const std::string& str) {
                                              if (str.length() != letterAmount) {
                                                  return true;
                                              }
                                              if (str.find('\'') != std::string::npos || str.find('-') != std::string::npos) {
                                                  return true;
                                              }
                                              return false;
                                          }),
                           this->dictionary.end());
    std::sort(this->dictionary.begin(), this->dictionary.end());

    this->drawedWord = this->dictionary[WordDrawingLogic::rand_int(0, int(this->dictionary.size()-1))];
    std::cout<<drawedWord<<std::endl;
    return drawedWord;
}

void VectorBinarySearch::measureTime() {
    std::vector<std::string> wordsToSearch;
    for(int i = 0; i < 5; i++){
        int randomIndex = WordDrawingLogic::rand_int(0, int(this->dictionary.size()-1));
        wordsToSearch.push_back(this->dictionary[randomIndex]);
    }

    auto start = std::chrono::high_resolution_clock::now();

    for(const auto& word : wordsToSearch){
        auto it = std::lower_bound(this->dictionary.begin(), this->dictionary.end(), word);
        if(it != this->dictionary.end() && *it == word) {
            std::cout<<word<<std::endl;
        }
    }

    auto end = std::chrono::high_resolution_clock::now();

    auto duration = std::chrono::duration_cast<std::chrono::microseconds>(end - start);
    std::cout<<"Duration for binary search: " << duration.count() << " us" << std::endl;
}

std::vector<LettersPositionData> VectorBinarySearch::checkingWord(std::vector<std::string> userWordArray){
    lettersPosition = {};
    std::string userWord;
    for (const std::string& element:userWordArray) {
        userWord +=  element;
    }
    bool foundWord = false;
    for (const auto &element: this->dictionary) {
        if (userWord == element) {
            foundWord = true;
        }
    }
    if (foundWord) {
        for (int i = 0; i < this->drawedWord.size(); i++) {
            LettersPositionData letter = notExisting;
            if(this->drawedWord.find(userWord[i])!= std::string::npos){
                letter = wrongPlace;
                if (this->drawedWord[i] == userWord[i]){
                    letter = inPlace;
                }
            }
            lettersPosition.push_back(letter);
        }
    }
    return lettersPosition;
}


std::string SetSearch::chosenRepresentation(std::string fileName){
    std::ifstream fullDictionary(fileName);
    std::string word;
    while(fullDictionary >> word){
        this->dictionary.insert(word);
    }
    int letterAmount = 5;

    std::erase_if(this->dictionary, [letterAmount](const std::string& str) {
        return str.length() != letterAmount || str.find('\'') != std::string::npos || str.find('-') != std::string::npos;
    });

    auto it = std::next(this->dictionary.begin(), WordDrawingLogic::rand_int(0, int(this->dictionary.size()) - 1));
    this->drawedWord = *it;
    return *it;
}

void SetSearch::measureTime() {
    std::vector<std::string> wordsToSearch;
    for(int i = 0; i < 5; i++) {
        auto it = std::next(this->dictionary.begin(), WordDrawingLogic::rand_int(0, int(this->dictionary.size()-1)));
        wordsToSearch.push_back(*it);
    }
    auto start = std::chrono::high_resolution_clock::now();

    for(const auto& targetWord : wordsToSearch) {
        auto it = this->dictionary.find(targetWord);
        if(it != this->dictionary.end()) {
            std::cout<<targetWord<<std::endl;
        }
    }
    auto end = std::chrono::high_resolution_clock::now();
    auto duration = std::chrono::duration_cast<std::chrono::microseconds>(end - start);
    std::cout<<"Duration for set search: " << duration.count() << " us" << std::endl;
}

std::vector<LettersPositionData> SetSearch::checkingWord(std::vector<std::string> userWordArray){
    lettersPosition = {};
    std::string userWord;
    for (const auto& element : userWordArray) {
        userWord += element;
    }
    bool foundWord = this->dictionary.find(userWord) != this->dictionary.end();

    if (foundWord) {
        for (unsigned int i = 0; i < this->drawedWord.size(); i++) {
            LettersPositionData letter = notExisting;
            if(this->drawedWord.find(userWord[i])!= std::string::npos){
                letter = wrongPlace;
                if (this->drawedWord[i] == userWord[i]){
                    letter = inPlace;
                }
            }
            lettersPosition.push_back(letter);
        }
    }
    return lettersPosition;
}


std::string UnorderedSetSearch::chosenRepresentation(std::string fileName){

    std::ifstream fullDictionary(fileName);
    std::string word;
    while(fullDictionary >> word){
        this->dictionary.insert(word);
    }
    int letterAmount = 5;

    std::erase_if(this->dictionary, [letterAmount](const std::string& str) {
        return str.length() != letterAmount || str.find('\'') != std::string::npos || str.find('-') != std::string::npos;
    });

    auto it = std::next(this->dictionary.begin(), WordDrawingLogic::rand_int(0, int(this->dictionary.size()) - 1));
    this->drawedWord = *it;
    return *it;


}
void UnorderedSetSearch::measureTime() {
    std::vector<std::string> wordsToSearch;
    for(int i = 0; i < 5; i++) {
        auto it = std::next(this->dictionary.begin(), WordDrawingLogic::rand_int(0, int(this->dictionary.size()-1)));
        wordsToSearch.push_back(*it);
    }
    auto start = std::chrono::high_resolution_clock::now();

    for(const auto& targetWord : wordsToSearch) {
        auto it = this->dictionary.find(targetWord);
        if(it != this->dictionary.end()) {
            std::cout << targetWord << std::endl;
        }
    }
    auto end = std::chrono::high_resolution_clock::now();
    auto duration = std::chrono::duration_cast<std::chrono::microseconds>(end - start);
    std::cout << "Duration for unordered set search: " << duration.count() << " us" << std::endl;
}

std::vector<LettersPositionData> UnorderedSetSearch::checkingWord(std::vector<std::string> userWordArray){
    lettersPosition = {};
    std::string userWord;
    for (const auto& element : userWordArray) {
        userWord += element;
    }
    bool foundWord = this->dictionary.find(userWord) != this->dictionary.end();

    if (foundWord) {
        for (unsigned int i = 0; i < this->drawedWord.size(); i++) {
            LettersPositionData letter = notExisting;
            if(this->drawedWord.find(userWord[i])!= std::string::npos){
                letter = wrongPlace;
                if (this->drawedWord[i] == userWord[i]){
                    letter = inPlace;
                }
            }
            lettersPosition.push_back(letter);
        }
    }
    return lettersPosition;
}

