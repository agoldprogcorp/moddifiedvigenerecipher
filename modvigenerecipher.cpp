#include "modvigenerecipher.h"

String vigenereCipher(String txt, String key, bool encode) {
    key.toLowerCase();
    txt.toLowerCase();
    String alphabetandnumbers = "abcdefghijklmnopqrstuvwxyz0123456789";
    String alphabet = "abcdefghijklmnopqrstuvwxyz";
    String numbers = "0123456789";
    String txtCode = "";
    int idx = 0;
    int keyidx = 0;
    for (int i = 0; i < txt.length(); i++) {
        int idx = alphabetandnumbers.indexOf(txt.substring(i, i+1));
        bool isDigitcheck = isDigit(char(txt.substring(i, i+1)));
        if (encode){
            if (!isDigitcheck){
                int idx = alphabet.indexOf(txt.substring(i, i+1));
                idx += alphabet.indexOf(key.substring(keyidx % key.length(), keyidx % key.length() + 1));
                txtCode += alphabet.substring(idx % alphabet.length(), idx % alphabet.length() + 1);
                keyidx++;
            } else {
                int idx = numbers.indexOf(txt.substring(i, i+1));
                idx += numbers.indexOf(key.substring(keyidx % key.length(), keyidx % key.length() + 1));
                txtCode += alphabet.substring(idx % numbers.length(), idx % alphabet.length() + 1);
                keyidx++;
            }
        } else {
            if (!isDigitcheck){
                int idx = alphabet.indexOf(txt.substring(i, i+1));
                idx -= alphabet.indexOf(key.substring(keyidx % key.length(), keyidx % key.length() + 1));
                if (idx < 0) { idx = alphabet.length() + idx; }
                txtCode += alphabet.substring(idx % alphabet.length(), idx % alphabet.length() + 1);
                keyidx++;
            } else {
                int idx = numbers.indexOf(txt.substring(i, i+1));
                idx -= numbers.indexOf(key.substring(keyidx % key.length(), keyidx % key.length() + 1));
                if (idx < 0) { idx numbers.length() + idx; }
                txtCode += alphabet.substring(idx % numbers.length(), idx % alphabet.length() + 1);
                keyidx++;
            }
        }
    }
    return txtCode;
}
