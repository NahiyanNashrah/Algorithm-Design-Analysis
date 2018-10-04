#include<bits/stdc++.h>
using namespace std;

struct MinHeapNode
{
    ///one of input character
    char data;

    ///frequency of the character
    unsigned freq;

    ///left & right child
    MinHeapNode *left, *right;

    MinHeapNode(char data, unsigned freq)
    {
        left = right = NULL;
        this ->data = data;
        this -> freq = freq;
    }
};

///for comparison of two heap nodes(needed in min heap)

struct compare
{
    bool operator()(MinHeapNode *l,MinHeapNode *r)
    {
        return (l -> freq > r -> freq);
    }
};


///print huffman codes from the root of the tree

void printCodes(struct MinHeapNode *root,string str)
{
    if(!root)
        return ;

    if(root -> data != '$')
        cout<< root->data<<": "<<str<<"\n";

    printCodes(root->left,str+"0");
    printCodes(root->right,str+"1");
}


///main function that builds a huffman tree

void HuffmanCodes(char data[],int freq[],int size)
{
    struct MinHeapNode *left, *right, *top;

    priority_queue<MinHeapNode* ,vector<MinHeapNode*>, compare> minHeap;

    for(int i = 0; i < size; i++)
        minHeap.push(new MinHeapNode(data[i],freq[i]));


    ///iterate while size of heap doesn't become 1
    while(minHeap.size() != 1)
    {
        left = minHeap.top();
        minHeap.pop();

        right = minHeap.top();
        minHeap.pop();

        top = new MinHeapNode('$',left->freq + right->freq);

        top->left = left;
        top->right = right;

        minHeap.push(top);
    }

    printCodes(minHeap.top(),"");
}


int main()
{
    char arr[] = {'f','c','a','d','e','b'};
    int freq[]={45,12,5,13,16,9};

    int size = sizeof(arr)/sizeof(arr[0]);

    HuffmanCodes(arr,freq,size);

    return 0;
}
