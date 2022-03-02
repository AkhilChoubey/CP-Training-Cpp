
// Substring -- A Substring takes out characters from a string placed between 
//              two specified indices in a continuous order

vector<string> AllSubstrings(string &s) {
    int n = s.size();

    vector<string> result;

    for(int len = 1; len < n; len++) {
        for(int i = 0; i + len <= n; i++) {
            string curr = s.substr(i, len);  // s.substr(i, len) will create substring from 1 to len
            result.push_back(curr);
        }
    }

    return result;
}