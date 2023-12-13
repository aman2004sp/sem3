#include<iostream>
#include<algorithm>
using namespace std;


//Round Robin


void findwat(int temp[],int temp1[],int pr,int quant,int wat[]){
    
    int rem_time[pr];
    
    for(int i=0;i<pr;i++){
        rem_time[i]=temp1[i];
    }
    int t=0;
    while(true){
        int p=1;
        
        for(int i=0;i<pr;i++){
            if(rem_time[i]>0){
            p=0;
            
            
                
            }
            
        }
    }
}
int main(){
    
    cout<<"Enter the number of process:";
    int pr,p=1;
    cin>>pr;
    
    int quant=2; // quantum of time 
    
    int arr[pr],temp[pr],temp1[pr],burst[pr],wat[pr],tat[pr];
    for(int i=0;i<pr;i++){
        cout<<"Enter the arrival time of "<<p++<<"process is:";
        cin>>arr[i];
        temp[i]=arr[i];
    }
    p=1;
    
    for(int i=0;i<pr;i++){
        cout<<"Enter the burst time of "<<p++<<"process is:";
        cin>>burst[i];
    }
    
   
    
    sort(temp,temp+pr);
    
    for(int i=0;i<pr;i++){
        int value=temp[i],steps=0;
        
        for(int j=0;j<pr;j++){
            if(value==arr[j]){
                break;
            }
            steps++;
        }
        
        temp1[i]=burst[steps];
    }
    
    findwat(temp,temp1,pr,quant,wat);
    return 0;
}
