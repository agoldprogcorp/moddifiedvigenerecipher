#include "modvigenerecipher.h"

String vigenereCipher(String txt, String key, bool encode) {
    String alphabet = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    String numbers = "0123456789";
    String txtCode = "";
    int keyidx = 0;
    for (int i = 0; i < txt.length(); i++) {
        char ch = txt[i];
        int idx;
        int shift;
        if (alphabet.indexOf(ch) != -1) {
            idx = alphabet.indexOf(ch);
            shift = alphabet.indexOf(key[keyidx % key.length()]);
            if (encode) {
                idx = (idx + shift) % alphabet.length();
            } else {
                idx = (idx - shift + alphabet.length()) % alphabet.length();
            }
            txtCode += alphabet[idx];
            keyidx++;
        } 
        else if (numbers.indexOf(ch) != -1) {
            idx = numbers.indexOf(ch);
            shift = alphabet.indexOf(key[keyidx % key.length()]);  
            if (encode) {
                idx = (idx + shift) % numbers.length();
            } else {
                idx = (idx - (shift % numbers.length()) + numbers.length()) % numbers.length();
            }
            txtCode += numbers[idx];
            keyidx++;
        } else {
            txtCode += ch;
        }
    }
    return txtCode;
}
