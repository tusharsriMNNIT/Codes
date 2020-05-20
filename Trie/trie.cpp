#include<bits/stdc++.h>
using namespace std;
#define ll long long int

//The structure for trie
struct trie
{
    char ch;
    trie *next[26];
    bool endOfWord;
};

//New Node Creation
trie *create(char c)
{
    trie *temp = (trie *)malloc(sizeof(struct trie));
    temp->ch = c;
    temp->endOfWord = false;
    for(int i=0;i<26;i++)
    {
        temp->next[i]=NULL;
    }
    return temp;
}

// Insert into trie
trie *insert(trie *node, string s, int pos)
{
    if(pos==s.size())
     return node;
    
    if(node->next[s[pos]-'a']==NULL)
      node->next[s[pos]-'a'] = create(s[pos]);
    
    if(pos==s.size()-1)
     node->endOfWord = true;

    node->next[s[pos]-'a'] = insert(node->next[s[pos]-'a'], s, pos+1);
    return node;
}


// Searching into trie
bool search(trie *node, string s, int pos)
{
    if(node==NULL)
     return false;
    
    if(pos==s.size()-1)
     return node->endOfWord;
    
    return search(node->next[s[pos]-'a'], s, pos+1);
}

// Delete from trie
trie * delete_trie(trie *root, string s, int pos)
{
    if(pos==s.size()-1)
    {
        root->endOfWord = false;
        int cnt = 0;
        for(int i=0;i<26;i++)
        {
            if(root->next[i] == NULL)
             cnt++;
        }
        if(cnt == 26)
        {
            free(root);
            root = NULL;
        }
        return root;
    }

    for(int i=0;i<26;i++)
    {
        if(root->next[i]!=NULL && root->next[i]->ch == s[pos])
        {
            root->next[i] = delete_trie(root->next[i], s, pos+1);

            int cnt = 0;
            for(int i=0;i<26;i++)
            {
                if(root->next[i] == NULL) 
                  cnt++;
            }
            if(cnt == 26)
            {
                free(root);
                root==NULL;
            }
            break;
        }
    }
    return root;
}


int main()
{
    string s;
    ll n,i;

    trie *root = (trie *)malloc(sizeof(struct trie));
    root->ch = '#';
    root->endOfWord = false;
    for(i=0;i<26;i++)
    {
        root->next[i]=NULL;
    }

    cout<<"Enter the number of words you wants to ENTER : ";
    cin>>n;
    for(i=0;i<n;i++)
    {
        cout<<"Enter the string --> ";
        cin>>s;
        root = insert(root,s,0);
    }    
    s = "if";
    root = delete_trie(root, s, 0);
    cout<<"Enter the words you wants to seach (Press exit to quit)\n";
    while(true)
    {
        cin>>s;
        if(s=="exit")
          break;
        bool ans = search(root, s, 0);
        cout<<ans<<endl;
    }

    return 0;
}