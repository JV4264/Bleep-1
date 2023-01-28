#include "tools.hpp"

void bleep(int n, string *datap);

int main(int argc, char *argv[]) {
  banner();
  string words[100];
  string *ptr = words;
  string temp;
  string filename;
  string checkName;
  int x;
  ifstream Wordfile(argv[1]);
  ofstream Bleep("bleep.txt");

  if (!Wordfile)
    fatal("unable to open file");
  //---------------------------------------------------
  for (x = 0; x < 101; x++) {
    if (Wordfile.eof()) break;
    Wordfile >> temp;
    words[x] = temp;
  }
  bleep(x, ptr);
  Wordfile.close();
  bye();
}
//----------------------------------------------------
void bleep(int n, string *datap) {
  if (n > 0) {
    int newnum = n - 1;
    string *newdatap = datap + 1;
    bleep(newnum, newdatap);
    string word = *datap;
    if (word.length() == 4) {
      cout << "****" << " ";
    } 
    else {
      cout << word << " ";
    }
  }
}
//----------------------------------------------------

/*---------------------------------------------------------
    P9: bleep 1
    Justin Vasquez and Anthony Yannella
    CS 2212
    Mon May  9 2022 00:10:33
----------------------------------------------------------*/
//./main word.txt
