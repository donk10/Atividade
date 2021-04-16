// Atividade número 1
#include <iostream>
#include<string>
#include<bits/stdc++.h>
using namespace std;

int main() {
  
  string text = "12zy";
  string coded_text;
  string decoded_text;
  int c;
  int d;
  int n;
  int r = 1;
  string z;
  string numbers = "0123456789";
  string converted_number = "ABCDEFGHIJ";
  string repeated_letters;
  string letter;

  transform(text.begin(), text.end(), text.begin(), ::toupper);
  
  if(text.length() > 0 && text.length() < 1000){
    for(c = 0; c < text.length(); c++){
        z = "Z";
        n = 0;
      while(n < numbers.length()){
        if(text[c] == numbers[n]){
          coded_text.append(z.append(1, converted_number[n]));
          break;
        }
        else if(n == 9){
          letter = text[c];
          if(letter == "Z"){
            coded_text.append("ZZ");
          }
          else{
            coded_text.append(1, text[c]);
          }
        }
        n++;
      }
    }   
  }

  for(d = 1; d < coded_text.length(); d++){
    if(coded_text[d] == coded_text[d - 1]){
      r++;
    }
    else if(r > 1){
      cout << d << endl << r << endl;
      coded_text.erase(d, r);
      r = 1;
    }
    
  }


cout << coded_text << endl;
}

//int find_repeated_letters(){

//}