#include "Strand.h"
// constructor without params
Strand::Strand()
{
    m_name="";
    m_head=nullptr;
    m_tail=nullptr;
    m_size = 0;
}
// Constructor with name for strand
Strand::Strand(string str)
{
    m_name = str;
    m_head=nullptr;
    m_tail=nullptr;
    m_size = 0;
}
// Destructor
Strand::~Strand()
{
Node *temp1=m_head;
Node *temp2;
// For every node call delete
while(temp1!=nullptr)
{
    temp2 = temp1;
    temp1 = temp1->m_next;
    delete temp2;
}
}
// Traverse list and insert at end
void Strand::InsertEnd(char data)
{
    Node *temp = new Node();
    temp->m_data = data;
    temp->m_next = nullptr;
    Node *traverse = m_head;
    // if list is empty insert in head
    if(m_head==nullptr)
    {m_head = temp;
    m_tail = temp;
    }
    else {
        // traverse till end if not empty
    while(traverse->m_next!=nullptr)
    {
        traverse = traverse->m_next;
    }

    traverse->m_next=temp;
    m_tail = temp;
    }
    m_size++;
}
// getter for name
string Strand::GetName()
{
    return m_name;
}
// Getter for size
int Strand::GetSize()
{
    return m_size;
}
// Reverse a strand
void Strand::ReverseSequence()
{
    Node *current,*prev = nullptr,*next = nullptr;
    current = m_head;
    m_tail = m_head;
    // to reverse we neer current, previous, next pointers
    while(current != nullptr){
        next = current->m_next;
        current->m_next = prev;
        prev = current;
        current = next;
    }
    m_head = prev;
}
// Get a character ar location nodeNum
char Strand::GetData(int nodeNum)
{
int count=0;
Node *traverse=m_head;
// Traverse starting from head
while(count<nodeNum)
{
    traverse = traverse->m_next;
    count++;
}
return traverse->m_data;
}
// friend function is outside the class
ostream  &operator<< (ostream &output, Strand &myStrand)
{
    int count = myStrand.m_size;
    Node *traverse=myStrand.m_head;
    // starting from head node traverse list
    while(count)
    {
        // send to output stream char data
        output<< traverse->m_data;
        if(count-1 > 0)
         output << "->";
    traverse = traverse->m_next;
    count--;
    }
    // Display end
    output<< "->END"<<endl;
    return output;
}