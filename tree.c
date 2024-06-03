#include <stdio.h>
#include <stdlib.h>
#define Node_Num 7		//定義二元數節點的總數

void CreateBinaryTree(int*, int);	//建立二元樹
void Preorder(int);		//前序追蹤
void Inorder(int);		//中序追蹤	
void Postorder(int);		//後序追蹤

int data[Node_Num];		//暫存資料的陣列宣告
int BinaryTree[Node_Num];	//二元數的陣列宣告

int main() {
  
	for(int i = 0; i < Node_Num; i++){
		data[i] = 1 + (rand()%16);
	}
    
	CreateBinaryTree(data, Node_Num);	

	printf("二元樹前序追蹤的結果：\n");
 	Preorder(1);
	printf("\n\n");

	printf("二元樹中序追蹤的結果：\n");
    	Inorder(1);
	printf("\n\n");

	printf("二元樹後序追蹤的結果：\n");
	Postorder(1);
	printf("\n\n");

	return 0;
}

void CreateBinaryTree(int data[], int n) {   
	int node=1;
	for (int i=0; i<n; i++) {
		BinaryTree[node]=data[i];

		if ( i==0 )
			printf( "存入二元樹陣列的內容：\n%d ", BinaryTree[node] );
		else if ( i > 0 && i < n-1 )
			printf( "%d ", BinaryTree[node] );
		else
			printf( "%d \n\n", BinaryTree[node] );

		node=node + 1;
	}
}

void Preorder(int node) {  
	if (BinaryTree[node] != NULL) {
		if (BinaryTree[node] != NULL) {
			printf("%d ",BinaryTree[node]);	//列印樹根
		}
		Preorder(2*node);	//遞迴左子樹
		Preorder(2*node+1);	//遞迴右子樹
	}
}

void Inorder(int node) { 
	if (BinaryTree[node] != NULL) {
		Inorder(2*node);	//遞迴左子樹
		if (BinaryTree[node] != NULL) {  
			printf("%d ", BinaryTree[node]);	//列印樹根
		}
		Inorder(2*node+1);	//遞迴右子樹             
	}
}

void Postorder(int node) { 
	if (BinaryTree[node] != NULL) {
		Postorder(2*node);		//遞迴左子樹
		Postorder(2*node+1);		//遞迴右子樹
		if (BinaryTree[node] != NULL) {  
			printf("%d ",BinaryTree[node]);	//列印樹根
		}
	}
}