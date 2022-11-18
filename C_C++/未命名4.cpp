#include <stdio.h>

void change(int *p1, int *p2);
int sort(int *pArr, int n);

int main( )
{
    int arr[20], *pa, i, n;

    scanf("%d", &n);
    for (i=0, pa=arr;  i<n;  i++)
    {
        scanf("%d", pa++); 
    }

    
    sort(pa=arr,n);  //

    printf("output : \n");
    for (i=0; i<n; i++)
    {
        printf("%d   ", *(pa + i));
    }
    printf("\n");

    return 0;   
}

void change(int *p1, int *p2)
{
    int tmp;

    tmp = *p1;
    *p1 = *p2;
    *p2 = tmp;
}

int sort(int *pArr, int n)  //

{
    int i, *pa;

    for (i=n-1; i>0; i--)
    {
        for (pa=pArr; pa<pArr+i; pa++)
        {
            if (*pa > *(pa+1))
            {
                change(pa,pa+1);   //

            }
        }
    }

    
     return 0;   //


}
