#include "sentences_processing.h"


/**
 * Takes the word, and make all it's letters to upper-case
 * @param word is reference to word to convert it to upper-case
 *
 * If some letters are already in upper-case, then they will not be changed
 * {@see toupper(char)} from {@see cctype} standard directive
 */
void UpCase(string& word) {
    for (char& c : word)
        c = (char) toupper(c);
}

/**
 * Takes string containing text and split it into sentences
 * @param text is const reference to string which contains whole text
 * @return vector of new-defined type {@see sentence}
 */
vector<sentence> GetSentences(const string& text) {
    vector<sentence> sents; // to return
    sentence snt; // current sentence in text
    string word; // current word in text

    for (const char c : text) {
        if (c == SPACE && word.empty()) // if it is a space at the beginning of sentence
            continue;

        if (c == SPACE) { // identifies that word is finished
            snt.push_back(word);
            word.clear();
            continue;
        }

        word += c; // append a character from text to a word

        if (c == DOT) { // identifies that sentence is finished
            snt.push_back(word);
            word.clear();

            sents.push_back(snt);
            snt.clear();
            continue;
        }
    }

    return sents;
}

/**
 * Takes vector of sentences and convert passed word to upper-case
 * @param sents is vector of sentences of new-defined type {@see sentence}
 * @param word is word which should be in upper-case after this function execution
 * @return vector of sentences in which passed word occur with this word in upper-case
 */
vector<sentence> GetUpperWordSentences(vector<sentence> sents, const string& word) {
    vector<sentence> upperWordSents; // to return

    for (auto & sent : sents) {
        bool containsWord = false; // flag identifies if sentence contains passed word

        // iterates over a sentence by words
        for (auto & wordOfSent : sent) {

            size_t posWordStarts = 0;
            size_t posWordEnds = wordOfSent.size() - 1;

            // word can stat with marks (" { [ etc), then not consider them for matching
            while (!isalpha(wordOfSent[posWordStarts]))
                ++posWordStarts;

            // word can end with marks (" , ; etc), then not consider them for matching
            while (!isalpha(wordOfSent[posWordEnds]))
                --posWordEnds;

            // already word without any punctual marks
            string cleanWordOfSent = wordOfSent.substr(posWordStarts, posWordEnds - posWordStarts + 1);

            if (cleanWordOfSent == word) {
                UpCase(wordOfSent);
                containsWord = true;
            }
        }

        if (containsWord)
            upperWordSents.push_back(sent);
    }

    return upperWordSents;
}