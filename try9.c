#include <iostream>
#include <vector>

using namespace std;

int n;
int arr[100][100];
int Q[100][100];
int infinite = INT8_MAX;
int start;

void display(){
  for(int i=0;i<n;i++) cout<<"  "<<i;
  cout<<"\n";
  for(int i=0;i<n*3+2;i++) cout<<"-";
  cout<<"\n";
  for(int i=0;i<n;i++){
    cout<<i<<"|";
    for(int j=0;j<n;j++){
      if (i==j) cout<<0<<"  ";
      else cout<<Q[i][j]<<"  ";
    }
    cout<<endl;
  }
  cout<<endl;
}

void path(int dest){
  
  if(arr[dest][start]!=0) return;
  vector<int> v(n-1,0);
  for(int i=0;i<n;i++){
    if(dest!=i && arr[dest][i]!=0) v.push_back(i);
  }
  int i;
  for(i=0;i<v.size();i++){
    if(Q[dest][v[i]]==Q[start][dest]-Q[start][v[i]]){ 
      break;
    }    
  }
  path(v[i]);
  cout<<v[i]<<"->";
  return;
}

void dijkstra(){
    
  for(int i=0;i<n;i++){
    for(int j=0;j<n;j++){
      if(arr[i][j]==0) Q[i][j]=infinite;
      else Q[i][j] = arr[i][j];
    }
  }  
  
  for(int k=0;k<n;k++){
    for(int i=0;i<n;i++){
      for(int j=0;j<n;j++){
        Q[i][j] = min(Q[i][j],Q[i][k]+Q[k][j]);
      }
    }
  }
  
  cout<<"minimam distance from one node to other :"<<endl;
  display(); 
  cout<<"Enter a start node :";
  cin>>start;
  
  for(int i=0;i<n;i++){
    if(start!=i && arr[start][i]!=0){
      cout<<"\ndistance from node "<<start<<"->"<<i<<" = "<<arr[start][i]<<endl;
      cout<<"path :"<<start<<"->"<<i<<endl;
    }
    if(start!=i && arr[start][i]==0){
      cout<<"\ndistance from node "<<start<<"->"<<i<<" = "<<Q[start][i]<<endl;
      cout<<"path :"<<start<<"->";
      path(i);
      cout<<i<<endl;
    }
  }
  
}

int main()
{
  
  cout<<"enter a no of nodes :";
  cin>>n;
  if(n==4){
  cout<<"|0|--3--|1|"<<endl;
  cout<<" |       |"<<endl;
  cout<<" 4       8"<<endl;
  cout<<" |       |"<<endl;
  cout<<"|2|--5--|3|"<<endl;
  }
  cout<<endl;
  if(n==5){
  cout<<"|0|--3--|2|"<<endl;
  cout<<" |       |"<<endl;
  cout<<" 5       2"<<endl;
  cout<<" |       |"<<endl;
  cout<<"|1|--2--|3|--3--|4|"<<endl;
  }
  cout<<endl;
  cout<<"enter a distance in the matrix from one node to other:\n";
  for(int i=0;i<n;i++) cout<<"  "<<i;
  cout<<"\n";
  for(int i=0;i<n*3+2;i++) cout<<"-";
  cout<<"\n";
  for(int i=0;i<n;i++){
    cout<<i<<"|";
    for(int j=0;j<n;j++){
      cin>>arr[i][j];
    }
  }
  cout<<endl;
  dijkstra();
  
  return 0;
}

