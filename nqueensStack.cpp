#include<iostream>
using namespace std;

struct Coor{
    int r;
    int c;
};

struct Node{
    Coor data;
    Node* next;
};

struct Stack{
    Node* top;
    int size=0;
};

bool empty(Stack stack)
{
    return !(stack.top);
}

Node* init(Coor clone)
{
    Node*temp = new Node;
    temp->data.r=clone.r;
    temp->data.c=clone.c;
    temp->next=NULL;
    return temp;
}

void push(Stack& stack, Coor data)
{
    Node*newNode = init(data);
    newNode->next=stack.top;
    stack.top = newNode;
    stack.size++;
}

Coor peek(Stack stack)
{
    if(!stack.top) exit(-1);
    else return stack.top->data;
}

Coor pop(Stack& stack)
{
    if(empty(stack)) exit(-1);
    else {
        Node* temp = stack.top;
        Coor popres = temp->data;
        stack.top = stack.top->next;
        temp->next=NULL;
        delete temp;
        stack.size--;
        return popres;
    }
}

void print(Stack stack)
{
    cout<<"Positions of queens:"<<endl;
    for(Node*node=stack.top;node;node=node->next)
        cout<<"("<<node->data.r<<","<<node->data.c<<")"<<"\t";
    cout<<endl;
}

bool isSafe(Stack stack, int row, int col,int size)
{
    for(Node*temp=stack.top;temp;temp=temp->next)
    {
        if(temp->data.c==col) return false;
        if(temp->data.c+temp->data.r==row+col) return false;
        if(temp->data.c-temp->data.r==col-row) return false;
    }
    return true;
}

bool Backtrack(Stack&stack, int&row, int&col, int size)
{
    if(empty(stack)) return false;
    if(col==size)
    {
        row--;
        col=pop(stack).c+1;
    }
    else{
        col=pop(stack).c+1;
    }
    return true;
}

bool Queens(Stack stack,int size,int row,int *count)
{
    int col=0;
    Coor queen;
    while(true)
    {
        int flag=0;
        for(;col<size;++col)
            if(isSafe(stack,row,col,size))
                {
                    queen.r=row;
                    queen.c=col;
                    push(stack,queen);
                    row++;
                    col=0;
                    flag=1;
                    break;
                }
        if(flag==0){
            {
                if(!Backtrack(stack,row,col,size)) return false;
            }
        }
        if(row==size) {
            print(stack);
            (*count)++;
            row--;
            Backtrack(stack,row,col,size);
            }

    }
}

int main()
{
    Stack stack; stack.top=NULL;
    int count=0;
    int row=0;
    int size;
    do{cout<<"Enter number of queens (size of chessboard):"<<endl;
    cin>>size;
    } while(size<1);
    if(Queens(stack,size,row,&count)) cout<<"No solutions."<<endl;
    else cout<<"Number of solutions: "<<count;
    return 0;
}