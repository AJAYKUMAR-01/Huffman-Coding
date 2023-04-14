#include<iostream>
#include<queue>
#include<string>
#include<bits/stdc++.h>
using namespace std;
struct Node
{
    char Data;
    int Frequency;
    const Node *child0, *child1;
    Node(char d, int f = -1)
    {
        Data = d;
        Frequency = f;
        child0 = NULL;
        child1 = NULL;
    }
    Node(const Node *c0, const Node *c1)
    {
        Data = 0;
        Frequency = c0->Frequency + c1->Frequency;
        child0 = c0;
        child1 = c1;
    }
    bool operator<( const Node &a ) const { 
      return  Frequency > a.Frequency;
      }
void Traverse(string Code = "")
{
    if(child0 != NULL)
    {
        child0->Traverse(Code + '0');
        child1->Traverse(Code + '1');
    }
    else
    {
        cout << "Charecter : " << Data << "Frequency: " << Frequency << "Code" << Code << endl;
    }
}
};

void HuffmanCoding(string Message)
{
    priority_queue<Node> Pq;
    vector<int> Freq(256 + 1, 0);
    for(int i = 0; i < Message.size(); i++)
    {
        Freq[(int)Message[i]]++;
    }
    for(int i = 0; i <= 256; i++)
    {
        if(Freq[i])
        {
            Pq.push(Node(i, Freq[i]));
        }
    }
    while(Pq.size() > 1){
      node *c0 = new Node(Pq.top());
      Pq.pop();
      node *c1 = new Node(Pq.top());
      Pq.pop();
      Pq.push(Node(c0, c1));
    }
    cout << "Huffman Code: " << endl;
    Pq.top().Traverse();
}

int main()
{
    string Message;
    cout << "Enter the Message: " << endl;
    cin >> Message;
    HuffmanCoding(Message);
}