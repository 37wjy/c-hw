#include <iostream>

using namespace std;

class LinkedList2
{
private:
    class Node
    { // LinkedList2::Node
    public:
        int val;
        Node *next;
        Node(int x, Node *nd = NULL) : val(x), next(nd){};
    };
    Node *head=nullptr;
    Node *tail=nullptr;
public:
    LinkedList2(){};
    ~LinkedList2(){
        Node* p;
        while (head!=nullptr)
        {
            p=head;
            head=head->next;
            delete p;
        }
    };
    LinkedList2(const LinkedList2 &orig)
    {
        //cout<<"cpy\n";
        while (head != nullptr)
        {
            Node *p = head;
            head = head->next;
            delete p;
        }
        Node *p = orig.head;
        head = new Node(orig.head->val);
        tail = head;
        while ((p = p->next) != nullptr)
        {
            Node *n = new Node(p->val);
            tail->next = n;
            tail = n;
        }
    };

    // move constructor
    LinkedList2(LinkedList2 &&orig){
        // steal orig data while it's dying (nice)
        //cout<<"move"<<endl;
        this->head=orig.head;
        this->tail=orig.tail;
        orig.head=nullptr;
        orig.tail=nullptr;
    };
    void addStart(int v)
    {
        if (head == nullptr)
        {
            head = new Node(v);
        }
        else
        {
            Node *s = new Node(v, head);
            head = s;
        }
    };
    void addEnd(int v)
    {
        if (head == nullptr)
        {
            head = new Node(v);
            tail = head;
        }
        else
        {
            if (tail == nullptr)
            {
                Node *p = head;
                while ((p->next) != nullptr)
                {
                    p = p->next;
                }
                tail = p;
            }

            Node *s = new Node(v);
            tail->next = s;
            tail = s;
        }
    };
    void removeStart()
    {
        if (!(head == nullptr))
        {
            Node *s = head->next;
            delete head;
            head = s;
            if (s == nullptr)
                tail = nullptr;
        }
    };
    void removeEnd()
    {
        if (tail == head)
        {
            try
            {
                delete head;
                tail = nullptr;
            }
            catch (const std::exception &e)
            {
                std::cerr << e.what() << '\n';
            }
        }
        else if (!(head == nullptr))
        {
            Node *p = head;
            while ((p->next->next) != nullptr)
            {
                p = p->next;
            }
            tail = p;
            delete tail->next;
            tail->next = nullptr;
        }
    };
    LinkedList2 &operator=(const LinkedList2 &orig)
    {
        if(&orig==this)return *this;
        
        LinkedList2 s(orig);
        while (head != nullptr)
        {
            Node *p = head;
            head = head->next;
            delete p;
        }
        head=s.head;
        tail=s.tail;
        s.head=nullptr;
        s.tail=nullptr;
        return *this;
    }

    friend ostream& operator << (ostream& a,LinkedList2& r){
        //a<<"head --> ";
        Node *p=r.head;
        while (p!=nullptr)
        {
            a<<p->val<<" ";
            p=p->next;
            //if(p!=nullptr)a<<"----> ";
        }
        //a<<"nullptr ";
        return a;
        
    }
};
/**
  head --> nullptr

  head --> [ val=3 next= nullptr  ]

  head -->  [val=1 next= ---->  [ val=3 next= nullptr  ]



 */
int main()
{
    LinkedList2 a;
    a.addStart(3); // 3 is the first element in the list
    a.addStart(1); // 1 3
    a.addStart(4); // 4 1 3
    for (int i = 1; i <= 5; i++)
        a.addEnd(i);
    a.removeStart();
    a.removeEnd();
    cout << a << '\n'; // print out the list, separated by spaces or commas

    LinkedList2 b = a;
    cout << b << '\n';

    LinkedList2 c;
    c.addStart(5);
    c = b; // wipe out c, copy in b
    cout << c << '\n';
}
