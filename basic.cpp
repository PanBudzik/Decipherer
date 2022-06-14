#include "basic.h"
string text;
string line;

string whichPath(void) {
  string path;
  ifstream p;
  do{
    cout << "Choose path: ";
    cin >> path;
    p.open(path);
  } while(p.fail());
  p.close();
  return path;
}

string read(string path) {

  ifstream reading(path.c_str());

  if (reading.is_open()) {
    cout<<"\n\nProcessing...";
    while (reading >> line)
    {
      text += line + (" ");
    }
  } else
    cout << "I can't open file";
  reading.close();
  return text;
}

void save(string text, string path, int shift){
  path=path.insert((path.length()-4),"Deciphered");
  ofstream save (path);
  if (save.is_open())
  {
    save << "Shift: "+to_string(shift)+"\n\n";
    save << "Deciphered text: "+text;
    save.close();
    cout<< "\nFile saved!";
  }
  else cout << "Unable to open file";
}


void readTabelFromText(string table[], string path){
  ifstream reading(path.c_str());

  int i=0;
  if (reading.is_open()) {
    while (reading >> line)
    {
      table[i] = line;
      i++;
    }
  } else
    cout << "I can't open file";
  reading.close();
}

void readTabelFromText(char table[], string path){
  ifstream reading(path.c_str());

  int i=0;
  if (reading.is_open()) {
    while (reading >> line)
    {
      table[i] = (char)line[0];
      i++;
    }
  } else
    cout << "I can't open file";
  reading.close();
}

