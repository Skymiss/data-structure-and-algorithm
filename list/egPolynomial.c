typedef struct Node *PtrToNode;

struct Node
{
    int Coefficient;
    int Exponent;
    PtrToNode Next;
}

typedef PtrToNode Polynomial;

void AddPolynomial(Polynomial P1, Polynomial P2, Polynomial Psum)
{
    PtrToNode temp;
    PtrToNode tail = Psum;
    P1 = P1->Next;
    P2 = P2->Next;
    while(P1 != NULL && P2 != NULL)
    {
        if(P1->Coefficient > P2->Coefficient)
        {
            temp = (PtrToNode)malloc(sizeof(Node));
            temp->Coefficient = P1->Coefficient;
            temp->Exponent = P1->Exponent;
            tail->Next = temp;
            tail = temp;
            P1 = P1->Next;
        }
        else if(P1->Coefficient < P2->Coefficient)
        {
            temp = (PtrToNode)malloc(sizeof(Node));
            temp->Coefficient = P2->Coefficient;
            temp->Exponent = P2->Exponent;
            tail->Next = temp;
            tail = temp;
            P2 = P2->Next;
        }
        else
        {
            temp = (PtrToNode)malloc(sizeof(Node));
            temp->Coefficient = P2->Coefficient;
            temp->Exponent = P2->Exponent + P1->Exponent;
            tail->Next = temp;
            tail = temp;
            P1 = P1->Next;
            P2 = P2->Next;
        }
    }

    if(P1 == NULL)
    {
        while(P2 != NULL)
        {
            temp = (PtrToNode)malloc(sizeof(Node));
            temp->Coefficient = P2->Coefficient;
            temp->Exponent = P2->Exponent;
            tail->Next = temp;
            tail = temp;
            P2 = P2->Next;
        }
    }
    if(P2 == NULL)
    {
        while(P1 != NULL)
        {
            temp = (PtrToNode)malloc(sizeof(Node));
            temp->Coefficient = P1->Coefficient;
            temp->Exponent = P1->Exponent;
            tail->Next = temp;
            tail = temp;
            P1 = P1->Next;
        }
    }
}