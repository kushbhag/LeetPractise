#include<string>
using namespace std;

/*
Your friend is typing his name into a keyboard.  Sometimes, when typing a character c, the key might get long pressed, and the character will be typed 1 or more times.

You examine the typed characters of the keyboard.  Return True if it is possible that it was your friends name, with some characters (possibly none) being long pressed.
*/

class Solution {
public:
    bool isLongPressedName(string name, string typed) {
        int nameCounter = 0;
        char currChar;
        char prevChar;
        for (int i = 0; i < typed.size(); i ++){
            if (name[nameCounter] == typed[i]){
                prevChar = name[nameCounter];
                nameCounter++;
                currChar = name[nameCounter];
            } else if (currChar != typed[i] && prevChar != typed[i]) return false;
            if (nameCounter == name.size()) return true;
        }
        return false;
    }
};