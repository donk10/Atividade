// Atividade número 1
#include <iostream>
#include<bits/stdc++.h>
using namespace std;

int main() {
  
  string text = "1234567890";
  string coded_text;
  string decoded_text;
  int c;
  int n;
  string z;
  string numbers = "0123456789";
  string converted_number = "ABCDEFGHIJ";
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
          if(letter != z){
            coded_text.append(1, text[c]);
          }
        }
        n++;
      }
    }   
  }

cout << coded_text;
}