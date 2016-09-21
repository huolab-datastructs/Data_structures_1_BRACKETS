#include "../../C/UTILITY.H"
#include "../../C/UTILITY.CPP"

typedef char Stack_entry;
#include "../STACK/STACK.H"
#include "../STACK/STACK.CPP"
 
int main()
/* 
Post:
The program has notified the user of any bracket
mismatch in the standard input file.
Uses:
The class Stack.
*/
{
   Stack openings;
   char symbol;
   bool is_matched = true;
   cout << "Bracket checking program.\n"
        << "Enter a line of text to check." << endl;

   while (is_matched && (symbol = cin.get()) != '\n') {
      if (symbol == '{' || symbol == '(' || symbol == '[')
         openings.push(symbol);
      if (symbol == '}' || symbol == ')' || symbol == ']') {
         if (openings.empty()) {
            cout << "Unmatched closing bracket " << symbol
                 << " detected." << endl;
            is_matched = false;
         }

 
         else {
            char match;
            openings.top(match);
            openings.pop();
            is_matched = (symbol == '}' && match == '{')
                         || (symbol == ')' && match == '(')
                         || (symbol == ']' && match == '[');
            if (!is_matched)
               cout << "Bad match " << match << symbol << endl;
         }
      }
   }
   if (!openings.empty())
      cout << "Unmatched opening bracket(s) detected." << endl;
}
