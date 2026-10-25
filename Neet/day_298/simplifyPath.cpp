class Solution 
{
    public:
    string simplifyPath(string path) 
    {
        if (path.length() == 0) return "";
 
        stack<string> deck;
        string curr = "";

        for (char ch : path+"/") {
            if (ch == '/') {
                if (curr == "..") {
                    if (!deck.empty()) {
                        deck.pop();
                    }
                } else if (curr != "." && curr != "") {
                    deck.push(curr);
                }
                curr = ""; // reset
            } else {
                curr += ch;
            }
        }

        string res = "";
        while (!deck.empty()) {
            res = '/' + deck.top() + res;
            deck.pop();
        }
        return res.empty() ? "/" : res;
    }
};