#include<bits/stdc++.h>
using namespace std;
#define ll long long int
bool ans;
struct trie
{
    char ch;
    bool endOfWord;
    trie *next[10];
};

// Creating NewNode
trie *create(char c)
{
    trie *temp = (trie *)malloc(sizeof(struct trie));
    temp->ch = c;
    temp->endOfWord = false;
    for(int i=0;i<10;i++)
      temp->next[i] = NULL;
    
    return temp;
}

// Inserting NewNode
trie *insert(trie *root, string s, int pos)
{
    if(pos==s.size())
     return root;
    
    if(root->next[s[pos]-'0']==NULL)
    {
        root->next[s[pos]-'0'] = create(s[pos]);
    }

    if(pos==s.size()-1)
     root->endOfWord = true;

    root->next[s[pos]-'0'] = insert(root->next[s[pos]-'0'], s, pos+1);
    return root;
}

bool search(trie *root, string s, int pos)
{
    if(root==NULL)
     return false;
    
    if(pos==s.size())
    {
        return root->endOfWord;
    }
    return search(root->next[s[pos]-'0'], s, pos+1);
}


int main()
{
    ll t;
    cin>>t;
    while(t--)
    {
        ll n,i;

        trie *root = (trie *)malloc(sizeof(struct trie));
        root->ch = '#';
        root->endOfWord = false;
        for(i=0;i<10;i++)
         root->next[i] = NULL;

        cin>>n;
        string s[n];

        for(i=0;i<n;i++)
        {
            cin>>s[i];
            root = insert(root, s[i], 0);
        }
        int f=0;
        for(i=0;i<n;i++)
        {
            ans = search(root, s[i], 0);
            cout<<ans<<endl;
        }
    }
    return 0;
}