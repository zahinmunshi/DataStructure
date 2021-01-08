#include<stdio.h>
#include<conio.h>

struct Unused
{
  int info1;
  struct Unused *link1;
};
typedef struct Unused unused;

struct Used
{
  int info2;
  struct Used *link2;
};
typedef struct Used used;

void insert_into_unused(unused** first1)
{
    unused* newnode1;
    newnode1=(unused*)malloc(sizeof(unused));

    if(newnode1 == NULL)
    {
       printf("\nMemory allocation failed!!");
       return;
    }
      printf("\nEnter value:- ");
      scanf("%d",&newnode1->info1);
      newnode1->link1 = *first1;
      *first1= newnode1;
     // count++;
}

unused* insert_into_used(unused* first1, used** first2)
{
  unused* temp1;
  used* newnode2;
  newnode2=(used*)malloc(sizeof(used));
  if(newnode2 == NULL)
  {
    printf("\nMemory allocation failed!! \n");
     return first1;
  }

    if(first1 == NULL)
    {
      printf("\nStack underflow!!\n");
      return first1;
    }
	temp1=first1;
       first1=first1->link1;
     //  count1--;

       newnode2->info2 = temp1->info1;
       newnode2->link2 = *first2;
       *first2=newnode2;
     //  count2++;
	  printf("\nInsert into used and delete from unsed.");
	  printf("\nUsed Space = %d\n",temp1->info1);
	  free(temp1);
	  return first1;
}
void free_node(unused* first1)
{
       unused* temp1;
       if(first1 == NULL)
       {
	   printf("\nThere's no free node available!\n");
       }
       else
       {
	  temp1=first1;
	  while(temp1 != NULL)
	  {
	     printf("\n|%d|\n",temp1->info1);
	     temp1=temp1->link1;

	  }
	   printf("___");
       }

}

void used_node(used* first2)
{
       used* temp2;
       if(first2 == NULL)
       {
	   printf("\nThere's no used node!\n");
       }
       else
       {
	  temp2=first2;
	  while(temp2 != NULL)
	  {
	     printf("\n|%d|\n",temp2->info2);
	     temp2=temp2->link2;
	  }
	  printf("___");
       }

}




void main()
{
  unused *first1=NULL;
 // unused count1=0;

  used *first2=NULL;
 // used count2=0;

  int ch;
  clrscr();

   while(1)
   {
     printf("\n1. Allocate memory to program.");
     printf("\n2. Deallocate memory from program.");
     printf("\n3. Display lists of free nodes.");
     printf("\n4. Display lists of used nodes.");
     printf("\n5. EXIT.");
     printf("\nEnter your choice....");
     scanf("%d",&ch);

     switch(ch)
     {
	       case 1:insert_into_unused(&first1);
	       break;

	       case 2:first1=insert_into_used(first1, &first2);
	       break;

	       case 3:free_node(first1);
	       break;

	       case 4:used_node(first2);
	       break;

	       case 5: exit(0);

	       default: printf("\nInvalid choice!!");
	       break;
     }
   }

}