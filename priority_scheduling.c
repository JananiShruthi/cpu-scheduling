#include<stdio.h>

void waiting_time(int burst_time[], int arr_time[], int priority[], int process[], int n);

void selection_sort(int burst_time[], int arr_time[], int priority[], int process[], int n, int k)
{
    int i = k;
    int pos, temp, j;
    for(i=0;i<n;i++) // sort the burst time, priority, procees id using selection sort
  {
        pos=i;
        for(j=i+1;j<n;j++)
        {
            if(priority[j]<priority[pos])
                pos=j;
        }

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
}

void waiting_time(int burst_time[], int arr_time[], int priority[], int process[], int n)
{
  int wt[n], i, j, k, temp, pos;
  int total_wt = 0;
  /*for(i=0;i<n;i++) // sort the burst time, priority, procees id using selection sort
  {
        pos=i;
        for(j=i+1;j<n;j++)
        {
            if(priority[j]<priority[pos])
                pos=j;
        }

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
 }*/
  printf("sequence in which the process is scheduled:\n");
  printf("process\tpriority\n");
  for(i = 0; i < n; i++)
  {
    printf("p%d\t%d\n", process[i], priority[i]);
  }
  wt[0] = 0;
  for(i = 1; i < n; i++)
  {

     wt[i] = burst_time[i - 1] + wt[i - 1];
  }
  for(i = 1; i < n; i++)
  {
    wt[i] = wt[i] - arr_time[i];
  }
  for(i = 0; i < n; i++)
     total_wt += wt[i];
  float avg_wt = total_wt/n;
  printf("\nAverage waiting time is: %.2f", avg_wt);
}

int main()
{
  int n, i, j, k, temp, pos, cnt = 0;
  printf("enter the number of process: ");
  scanf("%d", &n);
  int process[n];
  for(i = 0; i < n; i++)
  {
    process[i] =  i + 1;
  }
  int burst_time[n], arr_time[n], priority[n];
  printf("enter the burst time for each process\n");
  for(i = 0; i < n; i++)
  {
    printf("p%d: ", i + 1);
    scanf("%d", &burst_time[i]);
  }

  printf("enter the arrival time for each process\n");
  for(i = 0; i < n; i++)
  {
    printf("p%d: ", i + 1);
    scanf("%d", &arr_time[i]);
    if(arr_time == 0)
       cnt++;
  }

  printf("enter the priority for all the process:");
  for(i = 0; i < n; i++)
  {
    printf("p%d: ", i + 1);
    scanf("%d", &priority[i]);
  }

  if(cnt == n)
  {
    i = 0;
    selection_sort(burst_time, arr_time, priority, process, n, i);
  }
  else
  {
    i = 1;
    selection_sort(burst_time, arr_time, priority, process, n, i);
  }
  waiting_time(burst_time, arr_time, priority, process, n);
}


