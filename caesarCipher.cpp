#include "caesarCipher.h"



void letterFrequencyAnalisis(int letter_frequency[], string text,
                             int letters_count, char letters[]) {

  transform(text.begin(), text.end(), text.begin(),
            [](unsigned char c) { return tolower(c); });

  for (int i = 0; i < letters_count; i++) {
    letter_frequency[i] = 0;
  }

  int length_text = text.length();
  for (int i = 0; i < length_text; i++) {
    for (int j = 0; j < letters_count; j++) {
      if (text[i] == letters[j]) {
        letter_frequency[j]++;
      }
    }
  }

  /*cout << "\n Letter frequency analisis of text: \n";
  for (int i = 0; i < letters_count; i++) {
    cout << letters[i] << "=" << letter_frequency[i] << "\n";
  }*/
}

int monogramShiftAnalisis(int letter_frequency[], string text,
                          int letters_count, int tryLetter) {

  int max_index = 0;
  for (int i = 0; i < letters_count; i++) {
    if (letter_frequency[i] > letter_frequency[max_index]) {
      max_index = i;
    }
  }
  int shift = 0;
  shift = max_index - tryLetter;

  cout << "\n\nShift: " << shift;
  return shift;
}


void DiagramFrequencyAnalisis(int diagram_frequency[], string text,
                              int diagram_count, string mostUsedDiagrams[], string diagraphs[]) {

  transform(text.begin(), text.end(), text.begin(),
            [](unsigned char c) { return tolower(c); });

  
  for (int i = 0; i < diagram_count; i++) {
    diagram_frequency[i] = 0;
  }

  string diagraph = "";
  int length_text = text.length();
  for (int i = 0; i < length_text - 2; i++) {
    if (i != 0) {
      if (isalpha(text[i]) && isalpha(text[i+1])) {
        diagraph.push_back(text[i]);
        diagraph.push_back(text[i + 1]);
        diagraph.push_back('-');
      }
    }
  }

  string s1 = "";
  string s2 = "";
  bool res = false;
  
  int length_diagraphs = diagraph.length();
  for (int i = 0; i < length_diagraphs; i=i+3) {
    for (int j = 0; j < diagram_count; j++) {
      s1 = s1.append(1,diagraph[i]).append(1,diagraph[i+1]);
      s2 = diagraphs[j];
      res = s1.compare(s2);
      if (!res) {
        diagram_frequency[j]++;
      }
      s1=s2="";
      res = false;
    }
    }

    /*cout << "\n Diagram frequency analisis of text: \n";
    for (int i = 0; i < diagram_count; i++) {
      cout << diagraphs[i] << "=" << diagram_frequency[i] << ", ";
    }*/
}

int DiagramShiftAnalisis(string diagraphs[], int diagram_frequency[], string text,
                              int diagram_count, string tryDigram) {
  int max_index = 0;
  for (int i = 0; i < diagram_count; i++) {
    if (diagram_frequency[i] > diagram_frequency[max_index]) {
      max_index = i;
    }
  }
  
  int shift = 0;
  char max_digram_index_letter1 = diagraphs[max_index][0];
  char max_digram_index_letter2 = diagraphs[max_index][1];
  char max_digram_index_gap = max_digram_index_letter1-max_digram_index_letter2;

  char try_digram_letter1 = tryDigram[0];
  char try_digram_letter2 = tryDigram[1];
  char try_digram_gap = try_digram_letter1-try_digram_letter2;

  if(max_digram_index_gap==try_digram_gap){
    shift = abs(max_digram_index_letter1 - try_digram_letter1);    
    }
  if(shift!=0)
  {
  cout << "\n\nShift: " << shift;
  }
  return shift;
}

void TrigramFrequencyAnalisis(int trigram_frequency[], string text,
                              int trigram_count, string mostUsedTrigrams[], string trigraphs[]) {

  transform(text.begin(), text.end(), text.begin(),
            [](unsigned char c) { return tolower(c); });

  
  for (int i = 0; i < trigram_count; i++) {
    trigram_frequency[i] = 0;
  }

  string trigraphs_from_text = "";
  int length_text = text.length();
  for (int i = 0; i < length_text - 3; i++) {
    if (i != 0) {
      if (isalpha(text[i]) && isalpha(text[i+1]) && isalpha(text[i+2])) {
        trigraphs_from_text.push_back(text[i]);
        trigraphs_from_text.push_back(text[i + 1]);
        trigraphs_from_text.push_back(text[i + 2]);
        trigraphs_from_text.push_back('-');
      }
    }
  }

  string s1 = "";
  string s2 = "";
  bool res = false;
  
  int length_trigraphs = trigraphs_from_text.length();
  for (int i = 0; i < length_trigraphs; i=i+4) {
    for (int j = 0; j < trigram_count; j++) {
      s1 = s1.append(1,trigraphs_from_text[i]).append(1,trigraphs_from_text[i+1]).append(1,trigraphs_from_text[i+2]);
      s2 = trigraphs[j];
      res = s1.compare(s2);
      if (!res) {
        trigram_frequency[j]++;
      }
      s1=s2="";
      res = false;
    }
    }

    /*cout << "\n Trigram frequency analisis of text: \n";
    for (int i = 0; i < trigram_count; i++) {
      cout << trigraphs[i] << "=" << trigram_frequency[i] << ", ";
    }*/
}

int TrigramShiftAnalisis(string trigraphs[], int trigram_frequency[], string text,
                              int trigram_count, string tryTrigram) {

  int max_index = 0;
  for (int i = 0; i < trigram_count; i++) {
    if (trigram_frequency[i] > trigram_frequency[max_index]) {
      max_index = i;
    }
  }
  
  int shift = 0;
  char max_trigram_index_letter1 = trigraphs[max_index][0];
  char max_trigram_index_letter2 = trigraphs[max_index][1];
  char max_trigram_index_letter3 = trigraphs[max_index][2];
  char max_trigram_index_gap = max_trigram_index_letter1-max_trigram_index_letter2;

  char try_trigram_letter1 = tryTrigram[0];
  char try_trigram_letter2 = tryTrigram[1];
  char try_trigram_letter3 = tryTrigram[2];
  char try_trigram_gap = try_trigram_letter1-try_trigram_letter2;

  if(max_trigram_index_gap==try_trigram_gap){
    shift = abs(max_trigram_index_letter1 - try_trigram_letter1);    
    } 

  if(shift!=0)
  {
  cout << "\n\nShift: " << shift;
  }
  return shift;
}




string decodeText(string text, int shift) {
  char letter;
  int i;

  for (i = 0; text[i] != '\0'; ++i) {
    letter = text[i];
    if (letter >= 'a' && letter <= 'z') {
      letter = letter - shift;
      if (letter < 'a') {
        letter = letter + 'z' - 'a' + 1;
      }
      text[i] = letter;
    } else if (letter >= 'A' && letter <= 'Z') {
      letter = letter - shift;
      if (letter > 'a') {
        letter = letter + 'Z' - 'A' + 1;
      }
      text[i] = letter;
    }
  }
  cout << "\n\nDecrypted text: " << text;
  return text;
}