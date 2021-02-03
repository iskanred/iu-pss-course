#pragma once
#ifndef ASSIGNMENT_1_SENTENCES_PROCESSING_H
#define ASSIGNMENT_1_SENTENCES_PROCESSING_H

    #include "sentences.h"


    /**
     * Takes string containing text and split it into sentences
     * @param text is const reference to string which contains whole text
     * @return vector of new-defined type {@see sentence}
     */
    vector<sentence> GetSentences(const string& text);

    /**
     * Takes vector of sentences and convert passed word to upper-case
     * @param sents is vector of sentences of new-defined type {@see sentence}
     * @param word is word which should be in upper-case after this function execution
     * @return vector of sentences in which passed word occur with this word in upper-case
     */
    vector<sentence> GetUpperWordSentences(vector<sentence> sents, const string& word);

#endif //ASSIGNMENT_1_SENTENCES_PROCESSING_H
