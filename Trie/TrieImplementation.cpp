#include<bits/stdc++.h>
using namespace std;

struct Node
{
    Node* links[26];
    bool flag = false;

    bool containsKey(char ch){
        return links[ch - 'a'] != NULL;
    }

    void put(char ch, Node* node){
        links[ch - 'a'] = node;
    }

    Node* get(char ch){
        return links[ch - 'a'];
    }

    void setEnd(){
        flag = true;
    }

    bool isEnd(){
        return flag;
    }
};

class Trie
{
private:
    Node* root;
public:
    //Initialize your data structure
    Trie(){
        root = new Node();
    };

    //Inserting a word into the trie
    void insert(string word){
        Node* node = root;

        for (int i = 0; i < word.size(); i++)
        {
            if (!node->containsKey(word[i]))
            {
                node->put(word[i], new Node());
            }
            //moves to the reference Trie
            node = node->get(word[i]);
        }
        node->setEnd();
    }

    //Searching a word in the Trie i.e. whether it exists or not... TC - O(length)
    bool search(string word){
        Node* node = root;

        for(int i = 0; i < word.size(); i++){
            if (!node->containsKey(word[i]))
            {
                return false;
            }
            node = node->get(word[i]);
        }
        return node->isEnd();
    }

    //To check if a given prefix exists in the Trie or not... TC - O(length)
    bool startsWith(string prefix){
        Node* node = root;

        for (int i = 0; i < prefix.size(); i++)
        {
            if(!node->containsKey(prefix[i]))
            {
                return false;
            }
            node = node->get(prefix[i]);
        }
        return true;
    }
};

int main()
{
    Trie trie;
    trie.insert("help");
    trie.insert("hellen");
    trie.insert("rat");
    trie.insert("ram");

    cout << "Word - 'hellen' exists in the given Trie or not?: " << trie.search("hellen") << endl;
    cout << "Word - 'hello' exists in the given Trie or not?: " << trie.search("hello") << endl;
    cout << "Word - 'man' exists in the given Trie or not?: " << trie.search("man") << endl;
    cout << "Prefix - 'ran' exists in the given Trie or not?: " << trie.startsWith("ran") << endl;
    cout << "Prefix - 'ra' exists in the given Trie or not?: " << trie.startsWith("ra") << endl;
    cout << "Prefix - 'rat' exists in the given Trie or not?: " << trie.startsWith("rat") << endl;

    return 0;
}