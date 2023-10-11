// Greedy Algorithm		JOB SEQUENCING PROBLEM

/* every job has a deadline and associated profit if the job is finished before the deadline. 
It is also given that every job takes a single unit of time, so the minimum possible deadline for any job is 1. 
Maximize the total profit if only one job can be scheduled at a time.

JobID   Deadline  Profit

  a            2          100
  b            1          19
  c            2          27
 d            1          25
 e            3          15
 
 Ans a,c,e
 5 activity => max time 5
 but multiple activity with same deadline;
 also higher deadline activity can be performed much before deadline.
 
 Method: we are first going to arrange all these job activities in decreasing order of their profit.
 Now we will take each activity from start( highest profit) and fit them in slot( another array) starting
 from position of their deadline. if that position is already filled we will go to deadline-1 till we find a empty position.
 Here we are greedy with profit. 
 
 It wont happen that low profit add upto become larger than larger profit because each take equal time (1)
 Our priorty is to fit those first.
 Then smaller profit.
 */ 
 
#include <iostream>
using namespace std;
class job
{
    public:
	int len;
	int* deadline;
	int* profit;
	char* id;
};
int min(int& a,int&b)
{
    if(a< b)
    return a;
    return b;
}

int partition(int* ar,char* c,int* priorty, int low,int high)
{
	 int j = low;//pointer for larger element
    	for(int i= low; i<high;i++)
    	{
        	if(priorty[i]>priorty[high])  //we search for smaller element then swap with already found larger element // last element is the pivot
        	{    
           		swap(*(priorty+i),*(priorty+j));// swap every time you find new smaller element
           		swap(*(ar+i),*(ar+j));
           		swap(*(c+i),*(c+j));
           		j++;    //also increase j when swap is done
        	}
    }
    swap(*(priorty+j),*(priorty+high));
    swap(*(ar+j),*(ar+high));//for last swap
    swap(*(c+j),*(c+high));
    return j;
}

void quicksort_priorty(int* ar,char* c,int* priorty, int low, int high)
{
    if(low < high)
    {
        int par = partition(ar,c,priorty,low,high);
        quicksort_priorty(ar,c,priorty,low,par-1);
        quicksort_priorty(ar,c,priorty,par+1,high);
    }
}



void job_sequencing_problem(job j)
{
	quicksort_priorty(j.deadline,j.id,j.profit,0,j.len-1);
	
	int result[j.len];
	bool slot[j.len];
	for(int i = 0; i < j.len;i++)
	slot[i] = false;
	
	for(int i = 0; i< j.len; i++)
	{
		for(int k = min(j.len,j.deadline[i]) - 1; k>=0; k--)
		if(slot[k] == false)
		{
			slot[k] = true;
			result[k] = i;
			break;
		}
	}
	for(int i = 0; i< j.len; i++)
	{
		if(slot[i])
		cout << j.id[result[i]] << " ";
	}
}
	
