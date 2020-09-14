#include <iostream>
using namespace std;
struct node
{
    long long int data;
    struct node *next;
};
typedef struct node *nodeptr;
struct queues
{
    nodeptr front;
    nodeptr rear;
};

nodeptr getNode(long long int item)
{
    nodeptr p = (nodeptr)malloc(sizeof(struct node));
    p->data = item;
    p->next = NULL;
    return p;
}
void enqueue(long long int item, queues *q1)
{
    nodeptr p = getNode(item);
    if (p == NULL)
    {
        cout << "OVERFLOW" << endl;
    }
    else if (q1->rear == NULL)
    {
        q1->rear = p;
        q1->front = p;
    }
    else
    {
        q1->rear->next = p;
        q1->rear = p;
    }
    q1->rear->next = q1->front;
}
void dequeue(queues *q1)
{
    if (q1->front == NULL)
    {
        cout << "UNDERFLOW" << endl;
    }
    if (q1->front == q1->rear) //DELETION WHEN ONLY ONE NODE IS LEFT
    {
        free(q1->front);
        q1->front = NULL;
        q1->rear = NULL;
    }
    nodeptr temp = q1->front;
    q1->rear->next = q1->front->next;
    q1->front = q1->front->next;
    free(temp);
}
void display(queues *q1)
{
    if (q1->front == NULL)
        cout << "NO ELEMENTS PRESENT" << endl;
    else
    {
        nodeptr temp = q1->front;
        while ((temp->next) != q1->front)
        {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << temp->data << endl;
    }
}
int main()
{
    long long int choice, item;
    queues q1;
    q1.front = NULL;
    q1.rear = NULL;
    for (long long int i = 1; i; i++)
    {
        cout << "1.ENQUEUE\n2.DEQUEUE\n3.DISPLAY\n4.EXIT" << endl;
        cin >> choice;
        switch (choice)
        {
        case 1:
            cout << "ENTER ELEMENT TO BE ADDED" << endl;
            cin >> item;
            enqueue(item, &q1);
            break;
        case 2:
            dequeue(&q1);
            break;
        case 3:
            display(&q1);
            break;
        case 4:
            return 0;
        }
    }
    return 0;
}
