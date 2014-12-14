#include<iostream>
using namespace std;
struct osoba{
       int ai,bi,ci,di;
	   int dan,mjesec,godina;
       char ime[30];
       char spol;
};
struct queue{
       osoba osobe[10000];
       int front,rear;
};
int Addone(int i){
       return ((i+1)%10000);
}
bool IsEmptyQ(queue *red){
     if(Addone(red->rear)==red->front)
              return true;
     return false;    
}
void EnQueueQ(osoba x, queue *red){
     if(Addone(Addone(red->rear))==red->front)
               cout<<"Cekaona poste je puna!"<<endl;
     else{
          red->rear=Addone(red->rear);
          red->osobe[red->rear]=x;     
     }     
}
void DeQueueQ(queue *red){
     if(IsEmptyQ(red))
              cout<<"Red je prazan!"<<endl;
     else
         red->front=Addone(red->front);
}
queue *InitQ(queue *red){
     red->front=0;
     red->rear=9999;    
     return red;
}
osoba FrontQ(queue *red){
      if(IsEmptyQ(red))
              cout<<"Red je prazan!"<<endl;
      else
          return (red->osobe[red->front]);
}
