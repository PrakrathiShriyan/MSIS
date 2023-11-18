void Insertion(int A[], int n)
{
    for(int i=1;i<n;i++) // |4|5|10|1|6|2|
    {   int temp = A[i]; //declare ith position
        int j = i-1; //delcare j's position, j is given in terms of i so that it can vary every iteration
        while(j>=0 && A[j]>temp) //when value j is greater than 0 and A[j] is greater than value stored in temp
        {
        A[j+1]=A[j]; //A[j+1] will be always equal to A[i]
        j--;
        }
        A[j+1]=temp;
    }
}

 //          |4|7|4|10
//    <-sorted-><-unsorted->
//Initially 1st element will be in sorted part that is jth position
//2nd element will be the ith position, 
//element in ith position will be compared with the element in sorted part and placed accordingly
//    |4|5|10|1|6|2|
//     j i
//    |4|5|10|1|6|2|
//       j i
//    |4|5|10|1|6|2|
//         j  i
//    |4|5||10|6|2|
//    |4||5|10|6|2|          
//    |1|4|5|10|6|2|
//            j i
//    |1|4|5||10|2|
//    |1|4|5|6|10|2|
//              j i
//    |1|4|5|6||10|
//    |1|4|5||6|10|
//    |1|4||5|6|10|
//    |1||4|5|6|10|
//    |1|2|4|5|6|10|