#include <iostream>
#include <string>
#include <cctype>

using namespace std;

// Class to handle document editing operations
class DocEditor
{
public:
    // Function to process the input and edit the document according to the rules
    void processInput()
    {
        char ch;
        string ans = "";
        bool capitalizeNext = true;
        bool lastWasSpace = false;

        // Read characters until EOF
        while (cin.get(ch))
        {
            if (isalpha(ch))
            { //
                ans.push_back(ch);
                lastWasSpace = false;
            }
            else if (isSpace(ch))
            {
                if (!ans.empty())
                {
                    printWord(ans, capitalizeNext);
                    ans.clear();
                }
                if (!lastWasSpace)
                {
                    cout << ' ';
                    lastWasSpace = true;
                }
            }
            else if (isPunctuation(ch))
            {
                if (!ans.empty())
                {
                    printWord(ans, capitalizeNext);
                    ans.clear();
                }
                cout << ch;
                capitalizeNext = true;
                lastWasSpace = false;
            }
            else
            {
                if (!ans.empty())
                {
                    printWord(ans, capitalizeNext);
                    ans.clear();
                }
                cout << ch;
                lastWasSpace = false;
            }
        }

        if (!ans.empty())
        {
            printWord(ans, capitalizeNext);
        }

        // if (!ans.empty())
        // {
        //     printWord(ans, temp);
        // }
        // cout<<ans;
    }

private:
    // Function to check if the given word is an article
    bool isArticle(const string &word)
    {

        string lowerWord = word;
        for(char &c : lowerWord) {
            c = tolower(c);
        }


        return lowerWord == "the" || lowerWord == "a" || lowerWord == "an";
    }

    // Function to print the word, underlining articles with underscores
    void printWord(string &word, bool &capitalizeText)
    {
        if (word == "school")
        {
            word = "garden";
        }
        else if (word == "School")
        {
            word = "Garden";
        }
        else if (word == "SCHOOL")
        {
            word = "GARDEN";
        }


        if (capitalizeText && !word.empty())
        {
            word[0] = toupper(word[0]);
            capitalizeText = false;
        }

        if (isArticle(word))
        {
            cout << "_" << word << "_";
        }
        else
        {
            cout << word;
        }
    }

    // Function to check if a character is a space
    bool isSpace(char ch)
    {
        return isspace(static_cast<unsigned char>(ch));
    }

    // Function to check if a character is a punctuation mark
    bool isPunctuation(char ch)
    {
        return ch == '.' || ch == '?' || ch == '!';
    }

    // Function to handle word boundaries and manage input characters
    void handleWordBoundary(char ch, string &word)
    {
    }
};

int main()
{
    DocEditor editor;
    editor.processInput();
    return 0;
}
// the kids love to go to school every day.   there is a huge   neem tree just at the corner of the north    gate of the school.   it is a home to    many birds and    insects.

// _The_ kids love to go to garden every day. There is _a_ huge neem tree just at _the_ corner of _the_ north gate of _the_ garden. It is _a_ home to many birds and insects.

// The kids love to go to school every day. There is _a_ huge neem tree just at _the_ corner of _the_ north gate of _the_ school. It is _a_ home to many birds and insects.
