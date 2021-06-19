/*
Consider a file containing 500 integers as an input. From this file, fetch 50 integers at a time and copy them in an array 
and sort them in ascending order. Repeat the same process for next 50 integers and merge them with previously sorted 50 integers, 
and hence form the sorted sequence of 100 integers. Again fetch next 50 integers from file and store them in an array and sort 
them in ascending order and merge them with previously sorted 100 integers and hence form the sorted sequence of 150 integers. 
Continue this process until all integers fetched from the file are sorted and merged. Finally copy an array containing sorted 
500 integer numbers in file.
Expected Output:- The output file must contain all 500 integers in a sorted(ascending) order.
*/

#include<stdio.h>
#include<stdlib.h>
#define S 500

void WriteUnsortedFile(FILE *fptr);
void WriteSortedFile(FILE *fptr, int temp_array[]);

void ReadElements(FILE *fptr, int *i, int arr[]);
void insertionSort(int temp_array[], int k);
void main()
{
    FILE *fptr;
    int i, arr[S]={0};
    i=0;
    WriteUnsortedFile(fptr);
    ReadElements(fptr, &i, arr);
}

void WriteUnsortedFile(FILE *fptr)
{
    int i;
    fptr = fopen("E:\\Nirma\\DesignAndAnalysisOfAlgorithm\\20MCA037_DAA_Pract2\\unsortedElements.txt", "w");
    if (fptr == NULL)
    {
        printf("\nERROR IN FILE !!\n");
        exit(1);
    }
    
    for(i=0; i<S; i++)
    {
        fprintf(fptr,"%d\n", rand()%50000);
    }
    fclose(fptr);
}


void WriteSortedFile(FILE *fptr, int temp_array[])
{
    int i;
    fptr = fopen("E:\\Nirma\\DesignAndAnalysisOfAlgorithm\\20MCA037_DAA_Pract2\\SortedElements.txt", "w");
    if (fptr == NULL)
    {
        printf("\nERROR IN FILE !!\n");
        exit(1);
    }
    
    for(i=0; i<S; i++)
    {
        fprintf(fptr,"%d\n", temp_array[i]);
    }
    fclose(fptr);
}


void ReadElements(FILE *fptr ,int *i, int arr[])
{
    int pos,k,j,l,min,temp,m,cnt=0,key;
    int inc=*i;
    int temp_array[500]={0};
    fptr = fopen("E:\\Nirma\\DesignAndAnalysisOfAlgorithm\\20MCA037_DAA_Pract2\\unsortedElements.txt", "r");
    if (fptr == NULL)
    {
        printf("\nERROR IN FILE !!\n");
        exit(1);
    }
    
    for(pos=0; pos<S; pos++)
    {
        fscanf(fptr,"%d\n", &arr[pos]);
        cnt++;
        if(cnt == 50)
        {
            cnt=0;
            k=pos;
            for(j=k-49; j<=k; j++)
            {
                min=j;
                for(l=j+1; l<=k; l++)
                {
                    if(arr[min] > arr[l])
                    {
                        min=l;
                    }
                }
                temp=arr[j];
                arr[j]=arr[min];
                arr[min]=temp;
            }
            
           for(int a=k-49; a<=k; a++)
           {
               temp_array[a]=arr[a];
           }
           
           int y,x;
           insertionSort(temp_array,k);
           
           
        }
        
    }
        WriteSortedFile(fptr,temp_array);
        printf("\n\nYour task has been done.......");
         
    
    fclose(fptr);
}

//INSERTION SORT
void insertionSort(int temp_array[], int k)
{
    int x,key,y;
            for(x=1; x<=k; x++)
           {
               key=temp_array[x];
                y=x;
               while(y>0 && temp_array[y-1] >key)
               {
                   temp_array[y]=temp_array[y-1];
                   y--;
               }
               temp_array[y]=key;
           }
}

