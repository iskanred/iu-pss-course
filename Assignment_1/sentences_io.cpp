#include "sentences_io.h"

/**
 * inputs text
 * @param in is input stream of data
 * @param text is reference to string which will contain whole text
 */
void InputText(istream& in, string& text) {
    getline(in, text);
}

/**
 * inputs word which program should convert to upper-case
 * @param in is input stream of data
 * @param words is reference to vector of words which will contain words to convert in upper-case
 */
void InputWords(istream& in, vector<string>& words) {
    size_t numOfWords;
    in >> numOfWords;
    words = vector<string>(numOfWords);

    for (auto & word : words)
        in >> word;
}

/**
 * Print sentences
 * @param out is output stream of data
 * @param sents is const reference to vector of sentences of new-defined type {@see sentence}
 */
void OutputSentences(ostream& out, const vector<sentence>& sents) {
    for (const auto& sent : sents) {
        for (const auto& word : sent) {
            out << word << SPACE;
        }
        out << endl;
    }
}