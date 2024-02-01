#include <cstring>
#include <iostream>
#include <queue>
using namespace std;
//function to find first non-repeating character in a stream
string firstNonRepeatingChar(string input_stream)
{
    // Create a count array of size 26 to store the frequency of each character.
    int count[26] = { 0 };
    // Create a queue to store the characters in the input stream.
    queue<char> q;
    // Initialize an empty string as the answer.
    string answer = "";
    for (char c :
         input_stream) {
     // For each character in the input stream, add it to the queue and increment its frequency in the count array.
        count++;
        // Increment the frequency of the character in the count array
        q.push(c);
        // Add the character to the queue
        while (!q.empty()
               && count[q.front() - 'a']
                      > 1) { 
        // While the queue is not empty, check if the frequency of the front character in the queue is 1.
            q.pop();
            // If the frequency is greater than 1, remove the front character from the queue.
        }
 
        if (q.empty()) { 
            // If there are no characters left in the queue,append '#' to the answer.
            answer += '#';
        }
        else {
             // If the frequency is 1, append the character to the answer.
            answer += q.front();
        }
    }
    return answer; 
    // Return the answer.
}
int main()
{
    string input_stream = "geeksforgeeksandgeeksquizfor";
    string answer = firstNonRepeatingChar(input_stream);
    cout << answer << endl;
    return 0;
}
