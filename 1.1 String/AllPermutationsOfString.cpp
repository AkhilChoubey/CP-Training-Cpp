
void permute(string &s, int i = 0) {
    if(i == s.size()-1) {
        cout<<s<<" "; // you can push it in result vector if asked
    }

    for(int j = i; j < s.size(); j++) {
        swap(s[i], s[j]);
        permute(s, i+1);
        swap(s[i], s[j]);
    }
}