#include "basic.h"
#include "caesarCipher.h"
#include <iostream>
// https://slidetodoc.com/terminology-monoalphabetic-ciphers-shift-affine-permutation-cipher-vigenere/

using namespace std;
int main() {

  const int mostUsedLettersIndex[26] = {4, 19, 0, 14, 9,  13, 18, 8,  17,
                                        3, 11, 2, 20, 12, 22, 6,  24, 25};
  string mostUsedDiagrams[26] = {"th", "he", "in", "re", "an", "ed", "on",
                                 "es", "st", "en", "at", "to", "nt", "nd",
                                 "ou", "ea", "ng", "as", "is", "et", "ar",
                                 "te", "se", "hi", "of", "ha"};
  string mostUsedTrigrams[26] = {"the", "ing", "and", "her", "ere",
                                 "ent", "tha", "nth", "was", "eth",
                                 "for", "dth", "cs"};
  int letter_frequency[26];
  int diagram_frequency[676];
  int trigram_frequency[17576];

  char letters[26];
  readTabelFromText(letters, "Letters.txt");

  string diagraphs[676];
  readTabelFromText(diagraphs, "Digraphs.txt");

  string trigraphs[17576];
  readTabelFromText(trigraphs, "Trigraphs.txt");

  int letters_count = sizeof(letters);
  int diagram_count = sizeof(diagraphs) / sizeof(diagraphs[0]);
  int trigram_count = sizeof(trigraphs) / sizeof(trigraphs[0]);

  string path = whichPath();
  string text = read(path);
  int tryLetter = 0;
  bool decodingSuccessful = false;
  string answer;
  int shift = 0;
  int count_attempts = 0;
  int analisys_level = 1;
  bool DiagramFrequencyAnalisis_done = false;
  bool TrigramFrequencyAnalisis_done = false;
  bool letterFrequencyAnalisis_done = false;
  bool stop = true;

  do {
    switch (analisys_level) {
    case 1:
      if (!DiagramFrequencyAnalisis_done)
        DiagramFrequencyAnalisis(diagram_frequency, text, diagram_count,
                                 mostUsedDiagrams, diagraphs);
      shift = DiagramShiftAnalisis(diagraphs, diagram_frequency, text,
                                   diagram_count, mostUsedDiagrams[tryLetter]);
      stop = false;
      count_attempts++;
      stop = false;
      if (count_attempts > 26) {
        analisys_level++;
        count_attempts = 0;
      }
      break;
    case 2:
      if (!TrigramFrequencyAnalisis_done)
        TrigramFrequencyAnalisis(trigram_frequency, text, trigram_count,
                                 mostUsedTrigrams, trigraphs);
      shift = TrigramShiftAnalisis(trigraphs, trigram_frequency, text,
                                   trigram_count, mostUsedTrigrams[tryLetter]);
      stop = false;
      count_attempts++;
      if (count_attempts > 26) {
        analisys_level++;
        count_attempts = 0;
      }
      break;
    case 3:
      if (!letterFrequencyAnalisis_done)
        letterFrequencyAnalisis(letter_frequency, text, letters_count, letters);
      shift = monogramShiftAnalisis(letter_frequency, text, letters_count,
                                    mostUsedLettersIndex[tryLetter]);
      stop = false;
      count_attempts++;
      if (count_attempts > 26) {
        analisys_level++;
        count_attempts = 0;
      }
      break;
    }

    if (shift != 0) {
      string result = decodeText(text, shift);

      do {
        cout << "\n\nIs result readable? (y/n)";
        cin >> answer;
        if (answer == "Y" || answer == "y") {
          cout << "\nI'm happy that I saved your day!";
          do {
            stop = true;
            cout << "\n\n\nWould you like to save? (y/n)";
            cin >> answer;
            if (answer == "Y" || answer == "y") {
              save(result, "CipheredMessage.txt", shift);
              return 0;
            } else if (answer == "N" || answer == "n") {
              return 0;
            } else {
              cout << "\n Wrong input!";
            }
          } while (answer == "Y" || answer == "y" || answer == "N" ||
                   answer == "n");
        } else if (answer == "N" || answer == "n") {
          cout << "\nLets try another one then!\n\n";
          cout<<"\n\nProcessing...";
          tryLetter++;
        } else {
          cout << "\n Wrong input!";
        }
      } while (
          !(answer == "Y" || answer == "y" || answer == "N" || answer == "n"));
    }

  } while (1);
}