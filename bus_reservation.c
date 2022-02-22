// bus reservation system.

# include <stdio.h>
# include <string.h>
# include <stdlib.h>
struct node{
    int seat;
    struct node * next;
};
struct node * front=NULL, * rear=NULL;
int c=0,d=0,a[30],front1=-1,rear1=-1,e;
char name[0][400],name2[0][400];
void fill(){
    for (int i=0;i<30;i++){
        struct node * ptr = (struct node *) malloc (sizeof(struct node));
        ptr->seat=i+1;
        if (rear==NULL){
            ptr->next=NULL;
            front=rear=ptr;
        }
        else{
            rear->next=ptr;
            ptr->next=NULL;
            rear=ptr;
        }
    }
}
int view1(){
    struct node * p=front;
    while (p!=NULL){
        printf("%i ",p->seat);
        p=p->next;
    }
}
void del(int e){
    struct node * p=front;
    struct node * q=front->next;
    while(p->seat!=e){
        p=p->next;
        q=q->next;
    }
    p->seat=0;
}
void book(){
    if (rear1==29)
        printf("\nThe bus is full...");
    else{
        front1=0;
        rear1++;
        printf("\nEnter the first name : ");
        scanf("%s",name[rear1]);
        printf("\nEnter the sur name : ");
        scanf("%s",name2[rear1]);
        printf("\nEnter the seat number : ");
        scanf("%i",&e);
        struct node * ptr1=front;
        while (ptr1!=NULL){
            if (ptr1->seat==e){
                printf("\nThe seat is available.");
                a[rear1]=e;
                c++;
                d++;
                del(e);
            }
            ptr1=ptr1->next;
        }
    }
}
void cancel(){
    int x;
    printf("\nEnter the seat number : ");
    scanf("%i",&x);
    struct node * ptr=front;
    for (int i = 0; i<x-1; i++)
    {
        ptr=ptr->next;
    }
    ptr->seat=x;
    for (int j = 0; j< c; j++)
    {
        if(a[j]==x)
            a[j]=0;
    }
    c--;
    printf("\nOne of the ticket is cancelled.");
}
int view2(){
    float const price = 2500.26;
    printf("\t\t\tSUBMARINE TRAVELS\t\t\t\n");
    printf("\t===================================================\n\n");
    printf("\tPassenger name\t\t\t\tSeat number\n\n");
    for (int i = front1; i <= rear1; i++)
        printf("\t%s %s\t\t\t\t%i\n",name[i],name2[i],a[i]);
    printf("\tCost for per head travel :--- %f\n",price);
    printf("\tTotal cost of your travel = %f\n",price*c);
}
int main(){
    int ch;
    fill();
    printf("\t\t\t BUS RESERVATION...\t\t\t\n");
    printf("\t\tFron-> DURGAPUR To-> Kolkata (non-stop)\n");
    printf("\t1. View Available seats.\t\n");
    printf("\t2. Book a ticket.\t\n");
    printf("\t3. View ticket.\t\n");
    printf("\t4. cancel ticket.\t\n");
    printf("\t5. Exit.\t\n");
    while (1){
        printf("\nEnter your choice : ");
        scanf("%i",&ch);
        if (ch==1)
            view1();
        else if (ch==2)
            book();
        else if (ch==3)
            view2();
        else if (ch==4)
            cancel();
        else if (ch==5)
            break;
        else
            printf("\nInvalid choice...");
    }
    return 0;
}
