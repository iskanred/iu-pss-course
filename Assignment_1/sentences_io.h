#pragma once
#ifndef ASSIGNMENT_1_SENTENCES_IO_H
#define ASSIGNMENT_1_SENTENCES_IO_H

    #include "sentences.h"

    /**
     * inputs text
     * @param in is input stream of data
     * @param text is reference to string which will contain whole text
     */
    void InputText(istream& in, string& text);

    /**
     * inputs word which program should convert to upper-case
     * @param in is input stream of data
     * @param words is reference to vector of words which will contain words to convert in upper-case
     */
    void InputWords(istream& in, vector<string>& words);

    /**
     * Print sentences
     * @param out is output stream of data
     * @param sents is const reference to vector of sentences of new-defined type {@see sentence}
     */
    void OutputSentences(ostream& out, const vector<sentence>& sents);

#endif //ASSIGNMENT_1_SENTENCES_IO_H
