#include<stdio.h>
#include<stdlib.h>

struct node
{
  int x;
  struct node *link;
} *front = NULL,*rear=NULL, *temp, *nn;

void insert ()
{
  nn = (struct node *) malloc (sizeof (struct node));
  printf ("enter data:");
  scanf ("%d", &nn->x);
  if (front == NULL)
    {
      front = nn;
      rear = nn;
      rear->link = NULL;
    }
  else
    {
      rear->link = nn;
      rear=nn;
      rear->link = NULL;
    }
}

void Delete ()
{
  int ele;
  if (front == NULL && rear==NULL)
    {
      printf ("queue is empty\n");
    }
  else
    {
      ele = front->x;
      temp=front;
      front=front->link;
      temp->link=NULL;
      free(temp);
      printf("%d is deleted\n",ele);
    }
}

void display (struct node *front)
{
  if (front == NULL )
    printf ("queue is empty\n");
  else
    {
      printf ("Content of queue is\n");
      temp = front;
      while (temp != NULL)
{
 printf ("%3d", temp->x);
 temp = temp->link;
}
      printf ("\n");
    }
}

int main ()
{
  int choice, f;
  char ch;
  do
    {
      printf (" 1:insert 2:delete 3:display\n");
      scanf ("%d", &choice);
      switch (choice)
{
case 1:
 insert ();
 break;
case 2:
 Delete ();
 break;
case 3:
 display (front);
 break;
default:
 printf ("Wrong choice\n");
}
      printf ("Continue on main(Y/N):");
      scanf (" %c", &ch);
    }
  while (ch == 'y');
  return 0;
}
