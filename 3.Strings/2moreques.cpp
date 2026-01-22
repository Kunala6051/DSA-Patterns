#include <iostream>
#include <cstring> 
#include <string> 
#include <vector>
#include <algorithm> 
using namespace std;

// Function to check if two frequency arrays are equal
bool areEqual(int a[], int b[], int n) { // Time complexity O(1) we can assume n is constant (26 for lowercase letters)
    for (int i = 0; i < n; i++) {
        if (a[i] != b[i]) return false;
    }
    return true;
}

// Permutations of a string

// Given two strings s1 and s2, return true if s2 contains a permutation of s1, or false otherwise.
// In other words, return true if one of s1's permutations is the substring of s2.


// condition is given that both strings s1 and s2 consist of lowercase English letters only
// if strings would have been of any characters then we would have to use unordered_map or map to store the frequency of characters
// and then compare the frequency maps

bool checkInclusion(string s1, string s2) {
    int k=s1.length();
    int l=s2.length();

    bool x=false;
        
    int arrPattern[26]={0};
        

    for(char c: s1){
        arrPattern[int(c)-97]+=1;
    }



    for(int i=0; i<l-k+1; i++){

        string s3 = s2.substr(i,k);

        int arrText[26]={0};

        for(char c: s3){
            arrText[int(c)-97]+=1;
        }

        if (areEqual(arrText,arrPattern,26)){
            x=true;
            break;
        }

    }

    return x;

}

// Given an input string s, reverse the order of the words.
// A word is defined as a sequence of non-space characters. 
// The words in s will be separated by at least one space.
// Return a string of the words in reverse order concatenated by a single space.
// Note that s may contain leading or trailing spaces or multiple spaces between two words.
// The returned string should only have a single space separating the words. Do not include any extra spaces.

string reverseWords(string s) {

    reverse(s.begin(),s.end());
        
    string ans;

    for (int i=0; i<s.length(); i++){
        string word;

        while (s[i]!=' ' && i<s.length()){ // Collect characters until a space is found
            word+=s[i];
            i++;  
        }

        reverse(word.begin(),word.end());
        if (word.length()>0){ // Only add non-empty words to the result
            ans+= " " + word; // Add a space before the word
        }
    }

    return ans.substr(1);   // Remove the leading space from the result
        
}

// Time Complexity is O(n) for both functions where n is the length of the string s2 in checkInclusion and the length of the string s in reverseWords.
// Space Complexity is O(1) for both functions since we are using fixed size arrays of size 26 to store the frequency of characters in checkInclusion and a string to store the result in reverseWords.


string stringCompression(string s){
    int count=1;
    string ans="";

    for (int i=0; i<s.length()-1; i++){
        if(s[i]==s[i+1]){
            count+=1;
        } else if(s[i]!=s[i+1]) {
            ans+=s[i];
            if (count>1){
                ans+=to_string(count);
            }
             count=1;
        }
    }
    ans+=s[s.length()-1];
    if (count>1){
        ans+=to_string(count);
    }

    return ans;
}

// Leetcode 443: STRING COMPRESSION
// Given an array of characters chars, compress it using the following algorithm:

// Begin with an empty string s. For each group of consecutive repeating characters in chars:

// If the group's length is 1, append the character to s.
// Otherwise, append the character followed by the group's length.
// The compressed string s should not be returned separately, but instead, be stored in the input character array chars. Note that group lengths that are 10 or longer will be split into multiple characters in chars.

// After you are done modifying the input array, return the new length of the array.

// You must write an algorithm that uses only constant extra space.

int compress(vector<char>& chars) {

    int n=chars.size();
    int idx=0; // Index to place the next character in the compressed array

    for(int i=0; i<n;i++){
        int count=0;
        char ch=chars[i]; // Store the current character

        while(i<n && chars[i]==ch){
            count++;
            i++; 
        }

        if (count==1){
            chars[idx++]=ch;
        } else{
            chars[idx++]=ch;
            string s=to_string(count); // Convert count to string
            // Append each character of the count string to the chars array
            // We can use a for loop to iterate through the string and add each character to the chars array
            for(char digit: s){
                chars[idx++]=digit;
            }
            
        }
        i--;  // Decrement i to account for the outer loop increment as we already moved i to the next character (line 143)
    }

    chars.resize(idx);
    return idx; // Return the new length of the compressed array

}

 

int main(){

    string s1 = "ab";
    string s2 = "eidbaooo";
    if (checkInclusion(s1, s2)) {
        cout << "s2 contains a permutation of s1." << endl; // Print if s2 contains a permutation of s1
    } else {
        cout << "s2 does not contain a permutation of s1." << endl; // Print if s2 does not contain a permutation of s1
    }

    string s = "  hello world  ";
    string reversed = reverseWords(s);
    cout << "Reversed words: '" << reversed << "'" << endl; // Print the reversed words in the string

    cout << stringCompression("aaaaabKKKccccttab");

    vector<char> chars = {'a', 'a', 'b', 'b', 'c', 'c', 'c', 'd', 'd', 'd'};
    int newLength = compress(chars);
    cout << "Compressed length: " << newLength << endl; // Print the new length of the compressed array
    cout << "Compressed characters: ";
    for (char c : chars) {
        cout << c << " "; // Print the compressed characters
    }


    return 0; 


}