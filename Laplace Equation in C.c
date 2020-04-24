// Laplace Equation in C //
// By Anuj Barve //
// v 1.0 //

#include<stdio.h>
#include<math.h>
#define S 4
typedef float newvar[S+1][S+1];
void entrow(int i,newvar u)
{
    int j;
    printf("\n Enter the value of u[%d,j],j=1,%d\n",i,S);
    for(j=1;j<=S;j++)
    scanf("%f",&u[i][j]);
}
void entcol(int j, newvar u)
{
int i;
printf("Enter the value of u[i,%d],""i=2,%d\n",j,S-1);
for(i=2;i<=S-1;i++)
scanf("%f",&u[i][j]);
}
void oput(newvar u, int wd, int prsn)
{
    int i,j;
    for(i=i;i<=S;i++)
    {
        for(j=1;j<=S;j++)
        printf("%d,%d,%f",wd, prsn, u[i][j]);
        printf("\n");

    }
}
main()
{
    newvar u;
    float mer, ar, e, t;
   int i,j,itr, maxitr;
   for(i=1;i<=S;i++)
   for(j=1;j<=S;j++)
   u[i][j]=0;
   printf("\n  Enter the Boundary Condition\n");
   entrow(1,u); entrow(S,u);
   entcol(1,u); entcol(S,u);
   printf(" Enter the allowed error and maximum number of iteration : ");
   scanf("%f%d",&ar,&maxitr);
   for(itr=1;itr<=maxitr;itr++)
   {
       mer=0;
       for(i=2;i<S-1;i++)
       {
       for(j=2;j<=S-1;j++)
       {
           t=(u[i-1][j]+u[i+1][j]+u[i][j+1]+u[i][j-1])/4;
           e=fabs(u[i][j]-t);
           if(e>mer)
           mer=e;
           u[i][j]=t;
       }
       printf(" Iteration Number %d\n",itr);
       oput(u,9,2);
       if(mer<=ar)
       {
           printf(" After %d iteration \n The solution : \n",itr);
            oput(u,8,1);
           return 0;

       }
   }
   printf(" Sorry! The number of iteration is not sufficient");
   return 1;
}
}
