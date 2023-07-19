vector<int> KMP(string s){
    int n = s.length();
    vector<int> kmp(n+1);
    int i=0, j=-1; kmp[0]=-1;
    while(i<n){
        while(j!=-1 && s[i]!=s[j]){
            j = kmp[j];
        }
        j++; i++;
        kmp[i]=j;
    }
    return kmp;
}
