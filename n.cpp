
#include<iostream>

using namespace std;

int main()
{
    int bt[5],p[5],wt[5],tat[5],pt[5],i,j,n,t=0,s,ds,avg_wt, avg_tat;
    cout<<"Enter Total Number of Process:";
    cin>>n;

    cout<<"\nEnter Burst Time and Priority\n";
    for(i=0;i<n;i++)
    {
    	//get burst time and priority
    	
        cout<<"\nP["<<i+1<<"]\n";
        cout<<"Burst Time:";
        cin>>bt[i];
        cout<<"Priority:";
        cin>>pt[i];
        p[i]=i+1;           
    }

    for(i=0;i<n;i++)
    {
        s=i;
        for(j=i+1;j<n;j++)
        {
            if(pt[j]<pt[s])
                s=j;
        }

        ds=pt[i];
        pt[i]=pt[s];
        pt[s]=ds;

        ds=bt[i];
        bt[i]=bt[s];
        bt[s]=ds;

        ds=p[i];
        p[i]=p[s];
        p[s]=ds;
    }

    wt[0]=0;            

    for(i=1;i<n;i++)
    {
        wt[i]=0;
        for(j=0;j<i;j++)
            wt[i]+=bt[j];

        t+=wt[i];
    }

    avg_wt=t/n;      
    t=0;

   
    for(i=0;i<n;i++)
    {
        tat[i]=bt[i]+wt[i];     
        t+=tat[i];
   
   }

    avg_tat=t/n;     
    cout<<"\n\nAverage Waiting Time="<< avg_wt;
    cout<<"\nAverage Turnaround Time="<<avg_tat;

    return 0;
}

