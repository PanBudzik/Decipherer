#ifndef CAESARCIPHER_H
#define CAESARCIPHER_H
#include <algorithm>
#include <cctype>
#include <iostream>
#include <cstring>

using namespace std;

void DiagramFrequencyAnalisis(int diagram_frequency[], string text,
                              int diagram_count, string mostUsedDiagrams[], string diagraphs[]);
int DiagramShiftAnalisis(string diagraphs[], int diagram_frequency[], string text,
                              int diagram_count, string tryDigram);
void letterFrequencyAnalisis(int letter_frequency[], string text,
                             int letters_count, char letters[]);
int monogramShiftAnalisis(int letter_frequency[], string text,
                          int letters_count, int inputLetter);
int TrigramShiftAnalisis(string trigraphs[], int trigram_frequency[], string text,
                              int trigram_count, string tryTrigram);
void TrigramFrequencyAnalisis(int trigram_frequency[], string text,
                              int trigram_count, string mostUsedTrigrams[], string trigraphs[]);
string decodeText(string text, int shift);

#endif // CAESARCIPHER_H
