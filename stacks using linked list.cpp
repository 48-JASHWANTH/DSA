#include<stdio.h>
#include<stdlib.h>

struct node
{
  int x;
  struct node *link;
} *top = NULL, *temp, *nn;

void insert ()
{
  nn = (struct node *) malloc (sizeof (struct node));
  printf ("enter data:");
  scanf ("%d", &nn->x);
  if (top == NULL)
    {
      top = nn;
      nn->link=NULL;
    }
  else
    {
      nn->link=top;
      top=nn;
    }
}

void Delete ()
{
  int ele;
  if (top == NULL)
    {
      printf ("stack is empty\n");
    }
  else
    {
      ele = top->x;
      temp=top;
      top=top->link;
      temp->link=NULL;
      free(temp);
      printf("%d is deleted\n",ele);
    }
}

void display (void)
{
  if (top==NULL)
    printf ("stack is empty\n");
  else{
  	temp=top;
  	while(temp!=NULL){
  		printf("%3d",temp->x);
  		temp=temp->link;
	  }
	  printf("\n");
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
 display ();
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
