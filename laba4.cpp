#include <iostream>
#include <stdio.h>
#include <cctype>
using namespace std;

int _strspn (const char* string, const char* strCharSet);
char* replace_spaces(char* str, int length);
bool areNumbers(char* word);
bool hasZeros(char* word);

int main () {

// задача А
char str1[] = "abcd";
char str2[] = "dafjkabkab";
cout << _strspn(str1, str2) << endl;

char str3[] = "abcd";
char str4[] = "abcd";
cout << _strspn(str3, str4) << endl;

char str5[] = "abcd";
char str6[] = "cbd";
cout << _strspn(str5, str6) << endl;

// задача B

int const MAX_SIZE = 300;
char str [MAX_SIZE];
cout << "Input a string of words devided by spaces (words may include numbers); input no more than 300 characters" << endl;
gets_s(str, MAX_SIZE);
int length = strlen(str);
replace_spaces(str, length);
int max_zeros = 0;
char* last_word = new char [300];
char* sectolast_word = new char [300];
bool morethan1 = 0;
for(int i = 0; i < length; i++) {
    while (str[i] == '\0') {
        i++;
    }
    char* word = new char[300];
    strcpy(word, &str[i]);
    i += strlen(word);
    int zeros = 0;
    if (areNumbers(word)&&hasZeros(word)) {
        for(int k = 0; k < strlen(word); k++) {
            if (word[k] == '0') {
                zeros+=1;
            }
        if (zeros > max_zeros) {
            max_zeros = zeros;
            strcpy(last_word, word);
    
        } 
        if (zeros == max_zeros) {
            bool morethan1 = true;
            strcpy(sectolast_word, last_word);
            strcpy(last_word, word);
        } 
        }
        }
        delete[]word;
}
if (max_zeros == 0){
    cout << "No such word" << endl;
} else if (morethan1) {
    cout << sectolast_word;
} else {
    cout << last_word;
}
}

// не получается сделать так, чтобы, если у меня несколько слов с наибольшим количеством нулей, выводилось предпоследнее((( 


int _strspn (const char* string, const char* strCharSet) {
int sum = 0;
int last_sum;
for(int i = 0; string[i] != '\0'; i++) {
    for (int k = 0; strCharSet[k] != '\0'; k++) {
        last_sum = sum;
        if (string[i] == strCharSet[k]) {
            sum+=1;
            break;
        }
        }
    if (sum == last_sum) {
        return sum;
    }
}
return sum;
}

char* replace_spaces(char* str, int length) {
    for (int i = 0; i < length; i++) {
        if (str[i] == ' ') {
            str[i] = '\0';  
        }
    }
return str;
}


bool areNumbers(char* word) {
    int counter = 0;
    for (int k = 0; k < strlen(word); k++) {
        if (int(word[k] <= 57)&&(int(word[k]>=48))) {
            counter+=1;
        }
    }
    if (counter == strlen(word)) {
        return true;
    }
    else {
        return false;
    }
}

bool hasZeros(char* word) {
    for (int k = 0; k < strlen(word); k++) {
        if (word[k] == '0') {
            return true;
        }
    }
}


