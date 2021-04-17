// Atividade número 1
#include <iostream>
#include<string>
#include<bits/stdc++.h>
using namespace std;

int main() {
  
  string text;
  string coded_text;
  string decoded_text;
  int c;
  int d;
  int n;
  int l;
  int r = 1;
  string z;
  string numbers = "0123456789";
  string converted_number = "ABCDEFGHIJ";
  string letter;
  string repeated_letter;
  string repeated_letter_number;
  string repeated_letter_string;
  string non_converted_number;
  int position;
  string method;
  int number;
  string last_number;
  string last_number_;
  string last_lertter;
  
  cout << "Digite 'C' para codificação 'D' para decodificação: " ;
  cin >> method;

  if(method != "C" && method != "D"){
    cout << "Comando inválido." << endl;
    main();
  }
  else if(method == "C"){
    cout << "Digite a mensagem para codificação: ";
    cin >> text;
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
    for(d = 0; d <= coded_text.length() ; d++){
      if(coded_text[d] == coded_text[d-1]){
        r++;
      }
      else if(r > 1){
        coded_text.insert(d - 1, to_string(r));
        coded_text.erase(d - r, r - 1);
        d = 0;
        r = 1;
      }
    }
    cout << "MENSAGEM CODIFICADA: " << coded_text << endl;
  }
  else if(method == "D"){
    cout << "Digite a mensagem para decodificação: ";
    cin >> coded_text;
    transform(coded_text.begin(), coded_text.end(), coded_text.begin(), ::toupper);
    if(coded_text.length() > 0 && coded_text.length() < 1000){
      for(c = 0; c <= coded_text.length() ; c++){
        n = 0;
        while(n < numbers.length()){
          if(coded_text[c] == numbers[n]){
            last_number = numbers[n];
            repeated_letter_string.clear();
            repeated_letter = coded_text[c + 1];
            repeated_letter_number = coded_text[c];
            position = stoi(repeated_letter_number);
            if(repeated_letter == "Z"){
              for(l = 1; l < (position / 2); l++){
                repeated_letter_string.append(1, coded_text[c + 1]);
              }
              decoded_text.append(repeated_letter_string);
            }
            else{
              for(l = 1; l < position; l++){
                repeated_letter_string.append(1, coded_text[c + 1]);
              }
              decoded_text.append(repeated_letter_string);
            }
            break;
          }
          else if(n == 9){
            letter = coded_text[c];
            last_number_ = coded_text[c - 1];
            if(letter == "Z" && last_number_ != last_number){
              non_converted_number = coded_text[c + 1];
              number = converted_number.find(non_converted_number);
              decoded_text.append(to_string(number));
              coded_text.erase(coded_text.begin() + c + 1);
            }
            else{
              decoded_text.append(1, coded_text[c]);
            }
          }
          n++;
        }
      }
    }
    cout << "MENSAGEM DECODIFICADA: " << decoded_text << endl;
  }
  main();
}