#include <iostream>
#include <windows.h>
using namespace std;

struct activityInfo{
    int activityNo;
    int start;
    int end;
};

void getInformation(activityInfo activity[],int size);
void sortInfo(activityInfo activity[],int size);
void printInfo(activityInfo activity[],int size);
void activity_selection(activityInfo activity[],int size);

int main()
{
    int size;
    cout<<"Enter the number of activities:";
    cin>>size;
    activityInfo activity[size];
    getInformation(activity,size);
    system("CLS");
    cout<<"Initial Activity List"<<endl;
    cout<<endl;
    printInfo(activity,size);
    cout<<"\nAfter Sorting by Finishing Time"<<endl;
    cout<<endl;
    sortInfo(activity,size);
    printInfo(activity,size);
    cout<<"\nSelected Activities"<<endl;
    cout<<endl;
    cout<<"Activity No "<<"Starting Time "<<"Finishing Time"<<endl;
    activity_selection(activity,size);

    return 0;
}

void getInformation(activityInfo activity[],int size){
    cout<<"Enter the Starting and Finishing Time"<<endl;
    for(int i=0; i<size; i++){
        cout<<"Enter the activity no:";
        cin>>activity[i].activityNo;
        cout<<"Enter the starting time for activity "<<i+1<<":";
        cin>>activity[i].start;
        cout<<"Enter the ending time for activity "<<i+1<<":";
        cin>>activity[i].end;
    }
}

void sortInfo(activityInfo activity[],int size){
activityInfo index;
int j;
for(int i=1; i<size; i++){
    index=activity[i];
    j=i-1;
    while(j>=0 && activity[j].end>index.end){
        activity[j+1]=activity[j];
        j--;
    }
    activity[j+1]=index;
}
}

void printInfo(activityInfo activity[],int size){
    cout<<"Activity No "<<"Starting Time "<<"Finishing Time"<<endl;
    for(int i=0; i<size; i++){
        cout<<activity[i].activityNo<<"\t\t"<<activity[i].start<<"\t\t"<<activity[i].end<<endl;
    }
}

void activity_selection(activityInfo activity[],int size){
    int i=0;
    int activityCount=1;
    activityInfo temp[size];
    int k=0;
    cout<<activity[0].activityNo<<"\t\t"<<activity[0].start<<"\t\t"<<activity[0].end<<endl;
    temp[k].activityNo=activity[0].activityNo;
    for(int j=i+1; j<size; j++){
        if(activity[j].start>=activity[i].end){
            activityCount++;
            cout<<activity[j].activityNo<<"\t\t"<<activity[j].start<<"\t\t"<<activity[j].end<<endl;
            i=j;
            temp[++k].activityNo=activity[j].activityNo;
        }
    }
    cout<<"\nSelected Activities:";
    for(int i=0; i<=k; i++){
    cout<<temp[i].activityNo<<" ";
    }
    cout<<"\nN.B:These Activities will not clash with each other."<<endl;
    cout<<"\nMaximum Number of Activities can be performed:"<<activityCount;
    cout<<endl;
}
