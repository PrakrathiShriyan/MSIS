void Bubble(int A[], int n) //n is size
{
    for(int i=0;i<n-1;i++)
    {   int flag=0;
        for(int j=0;j<n-1-i;j++)
        {
            if(A[j]>A[j+1])
            {
                int temp=A[j];
                A[j]=A[j+1];
                A[j+1]=temp;
                flag=1;
            }
        }
        if(flag==0)
        break;
    }
}