#include <stdio.h>
#include <stdlib.h>
#include <time.h>
int stack[100],choice,n,top,x,i;
void random(int l, int h, int n);
void push(int x);
void read(int a[], int n);
void dis(int a[],int n);
void pop(int );
void display();
void read1(int b[],int n);
int main()
{
    FILE*f=fopen("log push.txt","w");
    int top=-1;
    int l, h, n;
    char t;
    printf("enter range L-H and size\n");
    scanf("%d%d%d", &l, &h, &n);
    random(l, h, n);
    int a[n];
    int b[n];
    read(a, n);
    dis(a,n);
    i=0;
     while(i<n)
         {
             push(a[i]);
             fprintf(f,"%d\n",a[i]);
             i++;
         }
         fprintf(f,"Push operations %d\n",i);
         printf("\n");
         fclose(f);
         read1(b,n);

         FILE*i=fopen("log pop.txt","w");
         int j=n-1;
         while(j>=0)
         {
                fprintf(i,"%d\n",b[j]);
             pop(b[j]);

             j--;

         }

         fprintf(i,"Pop operations %d\n",n);
         remove(f);
         FILE *fp=fopen("stack.txt","w");

//dis(b,n);



}
void read1(int a[],int n)
{
    FILE*fp=fopen("log push.txt","r");
    int i, r;


    for (i = 0; i < n; i++)
    {
        fscanf(fp, "%d", &r);
        a[i] = r;
    }

    fclose(fp);
dis(a,i);

}
void display()
{
    if(top>0)
    {
        printf("\n The elements in STACK \n");
        for(i=top; i>=0; i--)
            printf("\n%d",stack[i]);
        printf("\n Press Next Choice");
    }
    else
    {
        printf("\n The STACK is empty");
    }
}
void random(int l, int h, int n)
{
    int i, r;
    FILE *fp;
    fp = fopen("stack.txt", "w");
    for (i = 0; i < n; i++)
    {
        r = random()) % (h - l) + l;
        fprintf(fp, "%d\t", r);
    }
    fclose(fp);
}
void push(int x)
{
    FILE*fp=xfopen("log push.txt","r+");
    /*if(top>=n-1)
    {
        printf("\n\tSTACK is over flow");

    }
    else*/


        top++;
        stack[top]=x;
       // fprintf(fp,"%d\n",stack[top]);


}
void read(int a[], int n)
{
    int i, r;
    FILE *fp;
    fp = fopen("stack.txt", "r");
    for (i = 0; i < n; i++)
    {
        fscanf(fp, "%d", &r);
        a[i] = r;
    }

    fclose(fp);
}
void dis(int a[],int n)
{
    int i;
    for(i=0;i<n;i++)
    {
        printf("%d  ",a[i]);
    }
}
void pop(int i)
{
    FILE*fp=fopen("log pop.txt","w");
    if(top<=-1)
    {
        printf("\n\t Stack is under flow");
    }
    else
    {
        //printf("\n\t The popped elements is %d",stack[top]);
        fprintf(fp,"%d\n",stack[top]);
        top--;
    }
}
