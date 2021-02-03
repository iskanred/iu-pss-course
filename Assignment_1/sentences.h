#pragma once
#ifndef ASSIGNMENT_1_SENTENCES_H
#define ASSIGNMENT_1_SENTENCES_H

    #include <string>
    #include <vector>
    #include <cctype>
    #include <fstream>

    using namespace std;


    constexpr char DOT = '.';
    constexpr char SPACE = ' ';

    /**
     * new type 'sentence' is a vector of words, which are of string-type
     */
    typedef vector<string> sentence;


    #include "sentences_processing.h"
    #include "sentences_io.h"

#endif //ASSIGNMENT_1_SENTENCES_H