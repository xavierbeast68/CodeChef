/* package codechef; // don't place package name! */

import java.util.*;
import java.lang.*;
import java.io.*;

/* Name of the class has to be "Main" only if the class is public. */
class N_triplets 
{
    public static void main(String[] args) throws java.lang.Exception 
    {
        Scanner sc = new Scanner(System.in);

        // your code goes here->
        int t = sc.nextInt();
        while (t-- > 0) 
        {
            int n = sc.nextInt();

            int flag = 1;
            for (int i = 2; i < Math.sqrt(n); i++) 
            {
                if (n % i == 0) 
                {
                    System.out.println("1 " + i + " " + n/i);
                    flag = 0;
                    break;
                }
            }

            if(flag == 1)
            {
                System.out.println(-1);
            }
        }
    }
}