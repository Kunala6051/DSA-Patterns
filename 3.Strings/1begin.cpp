#include <iostream>
#include <cstring> // For strlen function
#include <string> // For string class
#include <algorithm> // For reverse function
using namespace std;

// Valid Palindrome check
// A phrase is a palindrome if, after converting all uppercase letters into lowercase letters and removing all non-alphanumeric characters
// It reads the same forward and backward. Alphanumeric characters include letters and numbers.

bool isAlphaNumeric(char c){
        if ((c>='0' && c<='9') || (tolower(c)>='a' && tolower(c)<='z')){
            return true;
        }
        return false;
}

bool isPalindrome(string s){
    int stt=0, endd=s.length()-1;
    while(stt<endd){
            if (!isAlphaNumeric(s[stt])){
                stt++;
                continue;
            }
            if (!isAlphaNumeric(s[endd])){
                endd--;
                continue;
            }
            if(tolower(s[stt])!=tolower(s[endd])){
                return false;
            }
            stt++;
            endd--;
            
        }  
        return true;
}

// Function to remove all occurrences of 'part' from 's'
// Given two strings s and part, perform the following operation on s until all occurrences of the substring part are removed:

// Find the leftmost occurrence of the substring part and remove it from s.
// Return s after removing all occurrences of part.

// A substring is a contiguous sequence of characters in a string.

string removeOccurrences(string s, string part) {
        while(s.length()>0 && s.find(part)<s.length()){
            s.erase(s.find(part),part.length());
        }
        return s;
}
// The find() function returns the index of the first occurrence of 'part' in 's', or string::npos if 'part' is not found.
// The erase() function removes the substring starting from the index returned by find() and of length equal to the length of 'part'.


int main(){
    cout << "Om Namaha Shivay \n";

    // Character array(C-style string)
    char str1[] = {'K', 'u', 'n', 'a', 'l', '\0'};
    cout << "Character array: " << str1 << endl; // Print character array

    // \0 is the null character that indicates the end of a string in C/C++.
    // It is used to terminate the string and is not printed when displaying the string.
    // Like all the characters have ASCII values, \0 has an ASCII value of 0.

    // String Literal (Constant string)
    cout << "String literal: " << "Kunal Ahuja" << endl; // Print string literal
    // String literal is a sequence of characters enclosed in double quotes.
    // It is stored in read-only memory and cannot be modified.
    char str[] = "Kunal Ahuja"; // String literal stored in a character array
    cout << "Character array from string literal: " << str << endl; // Print character array from string literal

    cout << str[0] << endl; // Access the first character of the string
    cout << str[1] << endl; // Access the second character of the string

    cout << "Length of string: " << sizeof(str) << endl; // Print the size of the character array (including null terminator)
    cout << "Length of string: " << strlen(str) << endl; // Print the length of the string (excluding null terminator)
    
    // Taking input from user

    // char str2[10]; // Declare a character array to store user input
    // cout << "Enter a string: ";
    // cin.getline(str2, 10,'@'); // Read a line of input from the user (up to 99 characters)

    // cin.getline() reads a line of text from the standard input (cin) and stores it in the character array str2.
    // It stops reading when it encounters a newline character or when it reaches the specified limit (100 characters in this case).
    // The third parameter '@' is used as a delimiter, meaning the input will stop when "@" is encountered.
    // If you want to read until a newline character, you can simply use cin.getline(str2, 100);

    // cout << "You entered: " << str2 << endl; // Print the user input

    // Suppose you need 10 characters in your string, u need to declare an array of size 11 to accommodate the null terminator.

    // calculating length of string using loop
    int length = 0;
    while (str[length] != '\0') { // Loop until the null terminator is encountered
        length++; // Increment the length for each character
    }
    cout << "Length of string using loop: " << length << endl; // Print the calculated length



    // String class (C++ string)
    string str3 = "Kunal Ahuja"; // Declare a string using the C++ string class

    // Strings made using the C++ string class are dynamic, more flexible and easier to work with than C-style strings.
    // They can be changed, grow and shrink in size, and they provide many useful member functions for string manipulation.

    str3 += " is a software engineer"; // Concatenate another string to str3
    cout << "Concatenated string: " << str3 << endl; // Print the concatenated string

    // However, strings made using character arrays are static, meaning they have a fixed size and cannot be changed after declaration.
    // (Size of arrays are fixed at compile time).


    // Concatenation using + operator
    string str4 = "Hello, ";
    string str5 = "World!";
    string str6 = str4 + str5; // Concatenate str4 and str5 using the + operator
    cout << "Concatenated string using + operator: " << str6 << endl; // Print the concatenated string

    // Comparing strings
    string str7 = "Kunal";
    string str8 = "Ahuja";

    cout << "Comparing strings: " << endl;
    cout << "str7 == str8: " << (str7 == str8) << endl; // Compare str7 and str8 for equality
    cout << "str7 != str8: " << (str7 != str8) << endl; // Compare str7 and str8 for inequality

    cout << "str7 < str8: " << (str7 < str8) << endl; // Compare str7 and str8 lexicographically (dictionary order)
    cout << "str7 > str8: " << (str7 > str8) << endl; // Compare str7 and str8 lexicographically

    // String length
    cout << "Length of str7: " << str7.length() << endl; // Get the length of str7 using the length() member function

    // Taking input using string class
    string dummy;
    getline(cin, dummy); // eats the broken input line

    string str9;
    cout << "Enter a string: ";

    getline(cin, str9); // Read a line of input from the user and store it in str9
    // getline() is a member function of the string class that reads a line of text from the standard input (cin) and stores it in the string object.

    for (char c : str9) { // Iterate through each character in str9
        cout << c << " "; // Print each character followed by a space
    }
    cout << endl; 

    // Reversing a string

    // string made using character array
    char str10[] = "Kunal Ahuja"; // Declare a character array

    int st=0;
    int end=strlen(str10) - 1; // Calculate the end index of the character array
    while (st < end) { // Loop until the start index is less than the end index
        swap(str10[st], str10[end]); // Swap the characters at the start and end indices
        st++; // Increment the start index
        end--; // Decrement the end index
    }
    cout << "Reversed character array: " << str10 << endl; // Print the reversed character array

    // string made using C++ string class
    string str11 = "Kunal Ahuja"; // Declare a string using the C++ string class
    reverse(str11.begin(), str11.end()); // Reverse the string using the reverse() function
    cout << "Reversed string: " << str11 << endl; // Print the reversed string


    // Palindrome check
    
    string str12 = "madam"; // Declare a string to check for palindrome
    string str13 = str12; // Create a copy of str12
    reverse(str13.begin(), str13.end()); // Reverse the copy of the string
    if (str12 == str13) { // Check if the original string is equal to the reversed string
        cout << str12 << " is a palindrome." << endl; // Print if it is a palindrome
    } else {
        cout << str12 << " is not a palindrome." << endl; // Print if it is not a palindrome
    }



    // Valid Palindrome check

    string s="A man, a plan, a canal: Panama";
    if (isPalindrome(s)) {
        cout << "\"" << s << "\" is a valid palindrome." << endl; // Print if it is a valid palindrome
    } else {
        cout << "\"" << s << "\" is not a valid palindrome." << endl; // Print if it is not a valid palindrome
    }


    // Remove all occurrences of a substring from a string
    string s1 = "daabcbaabcbc";
    string part = "abc";
    string result = removeOccurrences(s1, part); // Call the function to remove occurrences of 'part' from 's1'
    cout << "String after removing occurrences of \"" << part << "\": " << result << endl; // Print the result

    

    

    
    return 0;
}