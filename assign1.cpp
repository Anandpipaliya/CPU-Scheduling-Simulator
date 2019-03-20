//Name-Anand Pipaliya
//ID-201601457

#include <iostream>
#include <fstream>
#include <string>
#include<bits/stdc++.h>
using namespace std;

bool cmp( vector<int >x, vector<int > y){
	if(x[1]==y[1])return x[0]<y[0];
	return x[1]<y[1];
}
bool cmp2( vector<int >x,vector<int > y){
	if(x[1]==y[1])return x[2]<y[2];
	return x[1]<y[1];
}

int main (int argc, char *argv[]) {
	string line;
	if(argc<4)
	{
		cout<<"Arguments are not enough"<<endl;
		cout<<"Plaese give argument like: %schd File_name Algorithm(FCFS/SJF/RR) Argument(if RR)"<<endl;
		return -1;	
	}
	
	string file=argv[2];
	string stype=argv[3];
	int slice=0;
	/*cout<<"Input Examples:"<<endl<<"Input.txt SJF"<<endl<<"Input.txt FCFS"<<endl<<"Input.txt RR 2"<<endl<<"Enter Input: ";
	getline(cin,line);
        istringstream is( line );
        is >> file;
	is >> stype;
	is >> slice;*/

	ifstream myfile (file);
	if(myfile.fail())
	{
		cout<<"File does not exist code here"<<endl;
		return -1;
	}
	else
		cout<<"Date from "<<file<<": Pid Arrival_time Burst_time"<<endl;
	
	vector<vector<int> > p;
	vector<int> x;	
	if (myfile.is_open())
	{
		while ( getline (myfile,line) )
		{
			istringstream is( line );
    			int z;
    			while( is >> z ) {
         		x.push_back(z);	
   			}
		    	p.push_back (x);
			cout<<"\t\t";
			for(int i=0;i<x.size();i++)
				cout<<x[i]<<" \t";
			cout<<endl;
			x.clear();		
		}
		myfile.close();
	}	
	else cout << "Unable to open file"; 

	int n=p.size();
	long int clock=p[0][1];
	long int free_time=0;
	double waiting_time=0;
	cout << fixed << setprecision(2)<<endl; 


	for(int i=0;i<clock;i++)
		cout<<"<system time "<<i<<">there is no process running....."<<endl;
	
	if(stype=="FCFS"){
        sort(p.begin(),p.end(),cmp);
	cout<<"Schdeuling algorithm: FCFS"<<endl;
	cout<<"Total "<<n<<" tasks are read from \""<<file<<"\". press 'enter' to start..."<<endl;
	cout<<"=================================================================="<<endl;
	getchar();
	for(int i=0;i<n;i++)
	{
		waiting_time+=clock-p[i][1];
		for(int j=0;j<p[i][2];j++)
		{
			cout<<"<system time "<< clock<<"> process "<< p[i][0]<<" is running"<<endl;
			clock+=1;	
		}
		cout<<"<system time "<< clock<<"> process "<< p[i][0]<<" is finished......."<<endl;
		for(;i+1<n && p[i+1][1]>clock;clock++,free_time++)
		{	
			cout<<"<system time "<<clock<<">there is no process running....."<<endl;
		}
	}
	cout<<"<system time "<<clock<<"> All processes finish ...................."<<endl;
	cout<<"============================================================"<<endl; 
	cout<<"Average waiting time : "<<waiting_time/n<<endl;
	cout<<"Average response time : "<<waiting_time/n<<endl;//for FIFO waiting time is equl to responce time
	cout<<"Average turnaround time: "<<(waiting_time+clock-free_time)/n<<endl;
	//cout<<free_time<<endl;
	}

	else if(stype=="SJF"){
	sort(p.begin(),p.end(),cmp2);
	vector<vector<int> > dp(n,vector<int>(4));
	for(int i=0;i<n;i++)
		{dp[i][0]=p[i][0];dp[i][1]=p[i][1];dp[i][2]=p[i][2];dp[i][3]=dp[i][1];}
	waiting_time=0;
	free_time=0;
	clock=dp[0][1];

	cout<<"Schdeuling algorithm: SJF"<<endl;
        cout<<"Total "<<n<<" tasks are read from \""<<file<<"\". press 'enter' to start..."<<endl;
        cout<<"=================================================================="<<endl;
        getchar();	
	for(int i=0;i<n;i++)
	{
		sort(dp.begin()+i,dp.end(),cmp2);
		waiting_time+=clock-dp[i][3];
		for(int j=0;j<dp[i][2];j++)
                {
                	cout<<"<system time "<< clock<<"> process "<< dp[i][0]<<" is running"<<endl;
                        clock+=1;
                }
		for(int j=i+1;j<n;j++)
		{
			if(dp[j][1]<=clock)
				dp[j][1]=clock;
			else
				break;
		}
		cout<<"<system time "<< clock<<"> process "<< dp[i][0]<<" is finished......."<<endl;
		for(;i+1<n && dp[i+1][1]>clock;clock++,free_time++)
                {
                        cout<<"<system time "<<clock<<">there is no process running....."<<endl;
                }	
	}
	cout<<"<system time "<<clock<<"> All processes finish ...................."<<endl;
        cout<<"============================================================"<<endl;
        cout<<"Average waiting time : "<<waiting_time/n<<endl;
        cout<<"Average response time : "<<waiting_time/n<<endl;//for SJF waiting time is equl to responce time
        cout<<"Average turnaround time: "<<(waiting_time+clock-free_time)/n<<endl;
	}

	else if(stype=="RR"){
	if(!argv[4] || stoi(argv[4])==0)
	{	cout<<"Enter valid size of time slice as an argument"<<endl;
		return -1;
	}
	slice=atoi(argv[4]);
	sort(p.begin(),p.end(),cmp);
        vector<vector<int> > dp=p;
	waiting_time=0;
	free_time=0;
	double responce_time=0;
        clock=dp[0][1];
	vector<vector<int> > rq;
	rq.push_back(dp[0]);
	dp[0][0]=-1;
        int process=1;
	double turnaround_time=0;
	map<int,int> visit;
	cout<<"Schdeuling algorithm: SJF"<<endl;
        cout<<"Total "<<n<<" tasks are read from \""<<file<<"\". press 'enter' to start..."<<endl;
        cout<<"=================================================================="<<endl;
        getchar();
        int flag;
	while(1){
                flag=0;
                if(!rq.empty()){
		for(int i=0;i<min(slice,rq[0][2]);i++)
		{
			if(visit[rq[0][0]]==0)
			{
				responce_time+=clock-rq[0][1];
				visit[rq[0][0]]=1;
			}
                        cout<<"<system time "<< clock<<"> process "<< rq[0][0]<<" is running"<<endl;
                        clock+=1;
		}
                flag=1;
                }
                if(flag==0)
		{ 
                    	cout<<"<system time "<<clock<<">there is no process running....."<<endl;
                	clock++;
			free_time++;
		}
		for(int i=0;i<n;i++)
		{
			if(dp[i][1]<=clock && dp[i][0]!=-1)
			{	
				rq.push_back(dp[i]);
				dp[i][0]=-1;
			}
		}
                if(flag==1){
		rq[0][2]-=min(slice,rq[0][2]);
		if(rq[0][2]==0)
		{
	                cout<<"<system time "<< clock<<"> process "<< rq[0][0]<<" is finished......."<<endl;
			turnaround_time+=clock-rq[0][1];
			rq.erase(rq.begin());
                        process++;
		}
		else
		{
			rq.push_back(rq[0]);
			rq.erase(rq.begin());
		}
                }
		if(process==n+1)break;
	}
	cout<<"<system time "<<clock<<"> All processes finish ...................."<<endl;
        cout<<"============================================================"<<endl;
	cout<<"Average waiting time : "<<(turnaround_time-clock+free_time)/n<<endl;
        cout<<"Average response time : "<<responce_time/n<<endl;
        cout<<"Average turnaround time: "<<turnaround_time/n<<endl;
	}

	else 
	cout<<"There is no schdeuling algorithm name:"<<stype<<endl;
	
	return 0;
}
