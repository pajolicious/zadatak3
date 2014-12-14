#include<iostream>
using namespace std;
struct osoba{
       char ime[30];
	   int ai,bi,ci,di;
	   int dan,mjesec,godina;
       char spol;
};
struct que{
  	   osoba osobe;
 	   que *next;     
};
struct queue{
       que *front, *rear;
};
queue *InitQ(queue *red){
     que *lista = new que;
     lista->next=NULL;
     red->front=lista;
     red->rear=lista; 
	 return red;   
}
bool IsEmptyQ(queue *red){
     if(red->front==red->rear)
           return true;
     return false;     
}
void EnQueueQ(osoba x, queue  *red){
     que *x= new que;
     x->next=NULL;
     x->osobe=x;
     red->rear->next=x;
     red->rear=x;     
};
void DeQueueQ(queue *red){
     que *tekuci=red->front;
     if(IsEmptyQ(red))
           cout<<"Red je prazan!"<<endl;
     else{
           red->front=red->front->next;
           delete tekuci;     
     }    
}
osoba FrontQ(queue *red){
      if(!IsEmptyQ(red))
           return red->front->next->osobe;     
}
