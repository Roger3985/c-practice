#include <stdio.h>
#include <stdlib.h>
#define maxVolume 16	//定義佇列的最大容量

int Queue[maxVolume];	//佇列的陣列宣告 
int First = -1;		//佇列的前端(第一筆)
int Last = -1;		//佇列的尾端(最後一筆)		
int Size = 0;		//佇列目前的大小

void Enqueue(int a);	//從佇列尾端存入資料，在main函數之後定義
int Dequeue();		//從佇列前端移除資料，在main函數之後定義
int getFirst();		//回傳佇列前端(第一筆)的資料，在main函數之後定義
int getLast();		//回傳佇列尾端(最後一筆)的資料，在main函數之後定義
int getSize();		//回傳佇列目前的大小，在main函數之後定義
int isEmpty();		//檢查佇列是否為空，在main函數之後定義

int main() {

	for(int i =0; i<10;i++){
		Enqueue(rand()%36);
	}  
	
	if(isEmpty()){
		printf("佇列第一筆資料為:NULL\n");
		printf("佇列最後一筆資料為:NULL\n");
	}else{
		printf("佇列第一筆資料為:%d\n",getFirst());
		printf("佇列最後一筆資料為:%d\n",getLast());
	}
	printf("佇列的總數為:%d\n\n",getSize());
  
	while(!isEmpty()){
		printf("佇列移除的資料為:%d\n",Dequeue());	
	}
	Dequeue();
	return 0;
}

void Enqueue(int a){
	if(Last >= maxVolume){
		printf("佇列滿囉");
	}else{
		Queue[++Last] = a;
		Size+=1;
		if(First == -1){First = 0;}
	}
}

int Dequeue(){   
	if(isEmpty()){
		printf("佇列為空\n");
	}else{ 
		int data;
		data = Queue[First];
		for(int i=First; i<=Last;i++){
			Queue[i] = Queue[i+1];
		}
		Last -=1;
		Size -= 1;
		return data;
	}
}

int getFirst(){
	if(!isEmpty()){return Queue[First];}
}

int getLast(){
	if(!isEmpty()){return Queue[Last];}
}

int getSize(){
	return Size;
}

int isEmpty(){
	if(Size<=0){
		First = -1;
		Last = -1;
		return 1;
	}else{
		return 0;
	}
}