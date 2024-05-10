//
// Created by Maja on 5/9/2024.
//

#ifndef WORDLE_REPRESENTATIONSCHEME_H
#define WORDLE_REPRESENTATIONSCHEME_H


#include <cstdio>
#include <fstream>
#include <vector>
#include <set>
#include <unordered_set>
#include <chrono>
#include <string>

#include "WordDrawingLogic.h"
#include "../Data/LettersPositionData.h"
/**
 * @file RepresentationScheme.h
 * @brief Header file containing the RepresentationScheme class.
 */

/**
 * @class RepresentationScheme
 * @brief Abstract base class providing an interface for different dictionary representation schemes.
 */
class RepresentationScheme {
protected:
    std::string drawedWord; /**< The word drawn for the game. */
    std::vector<LettersPositionData> lettersPosition; /**< The positions of letters in the user word. */
public:
    /**
     * @brief Reads words from a file, filters, sorts, saves to chosen container and selects a random word.
     * @param fileName The name of the file containing the words.
     * @return A string representing the drawn word.
     */
    virtual std::string chosenRepresentation(std::string fileName) = 0;
    /**
     * @brief Checks the user's word against the drawn word.
     * @param userWordArray The array representing the user word.
     * @return A vector of LettersPositionData containing the position data of the letters.
     */
    virtual std::vector<LettersPositionData> checkingWord(std::vector<std::string> userWordArray) = 0;
    /**
     * @brief Measures the time taken by a specific representation scheme to perform operations.
     */
    virtual void measureTime() = 0;
    /**
     * @brief Virtual destructor.
     */
    virtual ~RepresentationScheme() = default;
};

/**
 * @class VectorLinearSearch
 * @brief Derived class implementing a linear search scheme for words representation using a vector.
 */
class VectorLinearSearch : public RepresentationScheme {
private:
    std::vector<std::string> dictionary; /**< The dictionary of words stored as a vector. */
public:
    /**
     * @brief Reads words from a file, filters, sorts, saves to vector and selects a random word.
     * @param fileName The name of the file containing the words.
     * @return A string representing the drawn word.
     */
    std::string chosenRepresentation(std::string fileName) override;
    /**
     * @brief Checks the user's word against the drawn word.
     * @param userWordArray The array representing the user word.
     * @return A vector of LettersPositionData containing the position data of the letters.
     */
    std::vector<LettersPositionData> checkingWord(std::vector<std::string> userWordArray) override;
    /**
     * @brief Measures the time taken by a specific representation scheme to perform operations.
     */
    void measureTime() override;
};

/**
 * @class VectorBinarySearch
 * @brief Derived class implementing a binary search scheme for words representation using a vector.
 */
class VectorBinarySearch : public RepresentationScheme {
private:
    std::vector<std::string> dictionary; /**< The dictionary of words stored as a vector. */
public:
    /**
     * @brief Reads words from a file, filters, sorts, saves to vector and selects a random word.
     * @param fileName The name of the file containing the words.
     * @return A string representing the drawn word.
     */
    std::string chosenRepresentation(std::string fileName) override;
    /**
     * @brief Checks the user's word against the drawn word.
     * @param userWordArray The array representing the user word.
     * @return A vector of LettersPositionData containing the position data of the letters.
     */
    std::vector<LettersPositionData> checkingWord(std::vector<std::string> userWordArray) override;
    /**
     * @brief Measures the time taken by a specific representation scheme to perform operations.
     */
    void measureTime() override;
};

/**
 * @class SetSearch
 * @brief Derived class representing the dictionary using std::set.
 */
class SetSearch : public RepresentationScheme {
private:
    std::set<std::string> dictionary; /**< The dictionary of words stored as a std::set. */
public:
    /**
     * @brief Reads words from a file, filters, sorts, saves to set and selects a random word.
     * @param fileName The name of the file containing the words.
     * @return A string representing the drawn word.
     */
    std::string chosenRepresentation(std::string fileName) override;
    /**
     * @brief Checks the user's word against the drawn word.
     * @param userWordArray The array representing the user word.
     * @return A vector of LettersPositionData containing the position data of the letters.
     */
    std::vector<LettersPositionData> checkingWord(std::vector<std::string> userWordArray) override;
    /**
     * @brief Measures the time taken by a specific representation scheme to perform operations.
     */
    void measureTime() override;
};

/**
 * @class UnorderedSetSearch
 * @brief Derived class representing the dictionary using std::unordered_set.
 */
class UnorderedSetSearch : public RepresentationScheme {
private:
    std::unordered_set<std::string> dictionary; /**< The dictionary of words stored as a std::unordered_set. */
public:
    /**
     * @brief Reads words from a file, filters, sorts, saves to unordered set and selects a random word.
     * @param fileName The name of the file containing the words.
     * @return A string representing the drawn word.
     */
    std::string chosenRepresentation(std::string fileName) override;
    /**
     * @brief Checks the user's word against the drawn word.
     * @param userWordArray The array representing the user word.
     * @return A vector of LettersPositionData containing the position data of the letters.
     */
    std::vector<LettersPositionData> checkingWord(std::vector<std::string> userWordArray) override;
    /**
     * @brief Measures the time taken by a specific representation scheme to perform operations.
     */
    void measureTime() override;
};


#endif //WORDLE_REPRESENTATIONSCHEME_H
