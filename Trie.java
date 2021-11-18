package concurrency.data_structure;

public class Trie {
    static final int ALPHABATE_SIZE=26;
    TrieNode root;
    static class TrieNode{
        boolean isEndWord;
        TrieNode[] children;

        TrieNode() {
            isEndWord = false;
            children = new TrieNode[ALPHABATE_SIZE];
        }
    }
    public Trie(){
        root=new TrieNode();
    }
    public void insert(String key){
        TrieNode pCrawl=root;
        for(int i=0;i<key.length();i++){
            int index=key.charAt(i)-'a';
            if(pCrawl.children[index]==null)
                pCrawl.children[index]=new TrieNode();
            pCrawl=pCrawl.children[index];
        }
        pCrawl.isEndWord=true;
    }
    public boolean search(String key){
        TrieNode pCrawl=root;
        for(int i=0;i<key.length();i++){
            int index=key.charAt(i)-'a';
            if(pCrawl.children[index]==null)
                return false;
            pCrawl=pCrawl.children[index];
        }
        return pCrawl.isEndWord;
    }
}
