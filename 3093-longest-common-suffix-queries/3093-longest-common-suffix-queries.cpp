class Solution {
public:
    struct Node{
        int child[26];
        int bestIndex;
        int bestLength;

        Node(){
            memset(child,-1,sizeof(child));
            bestIndex=-1;
            bestLength=INT_MAX;
        }
    };

    vector<Node> trie;

    void update(int node,int idx,int len){
        if(len<trie[node].bestLength){
            trie[node].bestLength=len;
            trie[node].bestIndex=idx;
        }
        else if(len==trie[node].bestLength&&idx<trie[node].bestIndex){
            trie[node].bestIndex=idx;
        }
    }

    vector<int> stringIndices(vector<string>& wordsContainer,vector<string>& wordsQuery){
        trie.push_back(Node());

        for(int i=0;i<wordsContainer.size();i++){
            string& s=wordsContainer[i];
            int curr=0;

            update(curr,i,s.length());

            for(int j=s.length()-1;j>=0;j--){
                int c=s[j]-'a';

                if(trie[curr].child[c]==-1){
                    trie[curr].child[c]=trie.size();
                    trie.push_back(Node());
                }

                curr=trie[curr].child[c];

                update(curr,i,s.length());
            }
        }

        vector<int> ans;

        for(string& q:wordsQuery){
            int curr=0;
            int res=trie[0].bestIndex;

            for(int j=q.length()-1;j>=0;j--){
                int c=q[j]-'a';

                if(trie[curr].child[c]==-1){
                    break;
                }

                curr=trie[curr].child[c];

                res=trie[curr].bestIndex;
            }

            ans.push_back(res);
        }

        return ans;
    }
};