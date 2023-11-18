void Selection(int A[], int n) // <-sorted->|7|4|10|   , i and min will be A[0]th position
{                              //           <-unsorted->
    for(int i=0; i<n-1; i++)       //here the the array will be divided into sorted and unsorted
    {   int min = i;              //initially there will be no element in sorted part
        for(int j=i+1; j<n; j++) //1st element of sorted part will be considered i and min,
        {                       //ie i=min
            if(A[j]<A[min])    //j will initialize with 2nd element
            {                 //compare value at j and min
                min = j;     //if value at j is less thabn value at min
            }               //make min equal to j, since j is minimum
                           //Next check if min is eqaul to i
        }                 //if not swap value in min to value in i
        if(min!=i)     
            {
                int temp = A[i];
                A[i] = A[min];
                A[min] = temp;
            }
    }
}