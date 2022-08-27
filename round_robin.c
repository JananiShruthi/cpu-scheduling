//Round robin scheduling
#include<stdio.h>

/*void selection_sort(int burst_time[], int arr_time[], int process[], int n, int tq)
{
    int i;
    int pos, temp, j;
    for(i=0;i<n;i++) // sort the burst time, priority, procees id using selection sort
    {
        pos=i;

        temp=priority[i];
        priority[i]=priority[pos];
        priority[pos]=temp;

        temp=arr_time[i];
        arr_time[i]=arr_time[pos];
        arr_time[pos]=temp;

        temp=burst_time[i];
        burst_time[i]=burst_time[pos];
        burst_time[pos]=temp;

        temp=process[i];
        process[i]=process[pos];
        process[pos]=temp;
    }
}*/

int main()
{
    int i, j, k, n, tq, sum = 0;
    float avg_wt, avg_tat;
    printf("Enter the numer of process: ");
    scanf("%d", &n);
    int x = n;
    int process[n], bt[n], wt[n], arr_time[n], temp[n];
    for(i = 0; i < n; i++)
    {
        process[i] = i + 1;
    }
    printf("Enter the bursttime for each process: ");
    for(i = 0; i < n; i++)
    {
        printf("\np%d: ", i + 1);
        scanf("%d", &bt[i]);
    }
    
    printf("Enter the arrival time for each process: ");
    for(i = 0; i < n; i++)
    {
        printf("\np%d: ", i + 1);
        scanf("%d", &arr_time[i]);
        
    }
    
    printf("Enter the time quantum for the round robin: ");
    scanf("%d", &tq);
    
    //selection_sort(bt, arr_time, process, n, tq);
    for(i = 0; i < n; i++)
    {
        temp[i] = bt[i]; //storing the burst time in another array temp
    }
    
    int counter = 0, wait_time = 0, tat = 0;
    for(i = 0, sum = 0; x!= 0;)
    {
        if(temp[i] > 0 && temp[i] <= tq)
        {
            sum += temp[i];
            temp[i] = 0;
            counter = 1;//variable to indicate that the process is completed
        }
        else if(temp[i] > 0)
        {
            temp[i] -= tq;
            sum += tq;
        }
        if(counter == 1 && temp[i] == 0) //process finished executing
        {
            x--;
            wait_time = wait_time + sum - arr_time[i] - bt[i];
            tat = tat + sum - arr_time[i];
            counter = 0;
        }
        if(i == n - 1)
        {
            i = 0;
        }
        else if(arr_time[i + 1] <= sum)
        {
            i++;
        }
        else
        {
            i = 0;
        }
      }
      
      avg_wt = wait_time / n;
      avg_tat = tat / n;
      printf("AVERAGE WAITING TIME: %.2f", avg_wt);
      printf("AVERAGE TURN AROUND TIME: %.2f", avg_tat);
}
