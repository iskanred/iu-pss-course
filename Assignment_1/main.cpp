#include "sentences.h"

/**
 * main function
 * @return 0 if program terminated successfully
 */
int main() {
    ifstream fin("../in-out/in.txt"); // file input stream
    ofstream fout("../in-out/out.txt"); // file output stream

    string text;
    vector<string> words; // words to convert them to upper-case

    InputText(fin, text);
    InputWords(fin, words);

    auto sents = GetSentences(text); // type: vector<sentence>

    for (const auto& word : words) {
        auto upperWordSents = GetUpperWordSentences(sents, word);
        fout << upperWordSents.size() << endl;
        OutputSentences(fout, upperWordSents);
    }

    fin.close();
    fout.close();

    return 0;
}