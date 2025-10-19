import java.util.Scanner;  // Import Scanner class for user input

public class SelectionSort_ascending
{
    public static void main(String args[])
    {
        Scanner sc = new Scanner(System.in); // Create Scanner object
        int i = 0, j = 0, temp = 0;          // Declare loop variables and a temp variable for swapping
        int a[] = new int[5];                // Declare an integer array of size 5

        System.out.println("Enter 5 numbers");
        // Input: Accept 5 numbers from the user
        for(i = 0; i < 5; i++)
        {
            a[i] = sc.nextInt();
        }

        // Display array before sorting
        System.out.println("Array before sorting:");
        for(i = 0; i < 5; i++)
        {
            System.out.print(a[i] + ",");
        }

        // -------------------------------
        // Selection Sort Technique Begins
        // -------------------------------

        int s = 0, pos = 0;  // Variables to store smallest value and its position

        // Outer loop: iterate through each element except the last
        for(i = 0; i < 4; i++)
        {
            s = a[i];   // Assume the first element of the unsorted part is the smallest
            pos = i;    // Store its index

            // Inner loop: find the smallest element in the unsorted part
            for(j = i + 1; j < 5; j++)
            {
                if(a[j] < s) // If a smaller element is found
                {
                    s = a[j];   // Update smallest value
                    pos = j;    // Update its position
                }
            }

            // Swap the smallest element found with the first element of the unsorted part
            temp = a[pos];
            a[pos] = a[i];
            a[i] = temp;
        }

        // -------------------------------
        // Display array after sorting
        // -------------------------------
        System.out.println("\nArray after sorting:");
        for(i = 0; i < 5; i++)
        {
            System.out.print(a[i] + ",");
        }

        sc.close(); // Close the Scanner to prevent resource leak
    }
}
