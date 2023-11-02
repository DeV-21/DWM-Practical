#include <iostream>
#include <cstdlib>
using namespace std;
int main()
{
    int numbers, k;
    cout << "How many numbers you want to enter: ";
    cin >> numbers;
    cout << "Enter value of k: ";
    cin >> k;
    int kvals[25], prevKvals[25], nums[100];
    int addition[25][100], groups[25][100];
    int ok = 1;
    int steps = 1;
    // Get input numbers
    for (int i = 0; i < numbers; i++)
    {
        cout << "Enter Number " << i + 1 << ": ";
        cin >> nums[i];
    }
    // Set initial values of C's
    for (int i = 0; i < k; i++)
    {
        kvals[i] = nums[i];
    }
    // Main loop
    while (ok == 1)
    {
        cout << endl << "Iteration Number: " << steps;
        // Make calculations
        for (int i = 0; i < k; i++)
        {
            for (int j = 0; j < numbers; j++)
            {
                addition[i][j] = abs(kvals[i] - nums[j]);
            }
        }
        // Make groups of numbers (C)
        for (int i = 0; i < numbers; i++)
        {
            int min = 100000;
            int groupnum = 0; // Initialize groupnum here
            for (int j = 0; j < k; j++)
            {
                if (addition[j][i] < min)
                {
                    min = addition[j][i];
                    groupnum = j;
                }
            }
            groups[groupnum][i] = nums[i];
        }
        // Show results of calculations
        cout << endl << "Calculations" << endl;
        for (int i = 0; i < numbers; i++)
            {
            for (int j = 0; j < k; j++)
            {
                cout << addition[j][i] << "\t";
            }
            cout << endl;
        }
        // Show groups and calculate new C's
        cout << endl << "Groups" << endl;
        for (int i = 0; i < k; i++)
        {
            int sum = 0;
            int count = 0;
            cout << "Group " << i + 1 << ": ";
            for (int j = 0; j < numbers; j++)
            {
                if (groups[i][j] != 0) // Change NULL to 0
                {
                cout << groups[i][j] << "\t";
                sum += groups[i][j];
                count++;
                }
            }
            prevKvals[i] = kvals[i];
            kvals[i] = sum / count;
            cout << "\t=\t" << kvals[i] << endl;
        }
        // Clear the array of groups
        for (int i = 0; i < 25; i++)
        {
            for (int j = 0; j < 100; j++)
            {
                groups[i][j] = 0; // Change NULL to 0
            }
        }
        // Check the termination condition
        ok = 0;
        for (int i = 0; i < k; i++)
        {
            if (prevKvals[i] != kvals[i])
            {
                ok = 1;
            }
        }
        steps++;
    } // end while loop
    return 0;
}



/*
Step 1 : g++ k_mean.cpp
Step 2 :./a.out
How many numbers you want to enter: 9
Enter value of k: 2
Enter Number 1: 2
Enter Number 2: 4
Enter Number 3: 10
Enter Number 4: 12
Enter Number 5: 3
Enter Number 6: 20 
Enter Number 7: 30
Enter Number 8: 11
Enter Number 9: 25
*/































/*
K-Means Clustering is an Unsupervised Learning algorithm, which groups the unlabeled dataset
into different clusters. Here K defines the number of pre-defined clusters that need to be created
in the process, as if K=2, there will be two clusters, and for K=3, there will be three clusters, and
so on.
The k-means clustering algorithm mainly performs two tasks:
o Determines the best value for K center points or centroids by an iterative process.

o Assigns each data point to its closest k-center. Those data points which are near to the particular k-
center, create a cluster.

Hence each cluster has datapoints with some commonalities, and it is away from other clusters.
The working of the K-Means algorithm is explained in the below steps:
Step-1: Select the number K to decide the number of clusters.
Step-2: Select random K points or centroids. (It can be other from the input dataset).
Step-3: Assign each data point to their closest centroid, which will form the predefined K clusters.
Step-4: Calculate the variance and place a new centroid of each cluster.
Step-5: Repeat the third steps, which means reassign each datapoint to the new closest centroid of
each cluster.
Step-6: If any reassignment occurs, then go to step-4 else go to FINISH.
Step-7: The model is ready.
*/
