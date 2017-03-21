#include <iostream>
#include <cstdlib>

using namespace std;

class TNode{
		private:
				int data;
				TNode* left;
				TNode* right;
		public:
				TNode(int x = 0){
					data = x;
					left = NULL;
					right = NULL;
				}
				int getData(){return data;}
				void setData(int x){data = x;}
				TNode* getLeft(){return left;}
				void setLeft(TNode* x){left = x;}
				TNode* getRight(){return right;}
				void setRight(TNode* x){right = x;}
};

class STree{
		private:
				TNode *root;
				int size, length;
				int *list;
		public:
				STree(int x = 0){
					size = x;
					root = NULL;
					list = new int[4];
					length = 4;
					for(int i = 0;i < 4; i++){
						list[i] = 0;
					}
				}
				~STree(){delete [] list;}
				TNode* getRoot(){return root;}
				void setRoot(TNode* x){root = x;}
				int getSize(){return size;}
				void setSize(int x){size = x;}
				void print();
				void addElement(int x);
				TNode* search(int x);
};

int main(){
	STree obj;
	obj.addElement(10);
	obj.addElement(100);	
	obj.addElement(5);
	obj.addElement(50);
	obj.addElement(200);
	obj.addElement(30);
	obj.print();
	cout<<obj.search(5)->getData()<<endl;				
	return 0;
}

void STree::print(){
	for(int i = 0;i < size;i++){
		cout<<list[i]<<"	";
	}
	cout<<endl;
}

void STree::addElement(int x){
	TNode *temp = root, *temp2 = NULL, *newTemp = new TNode;
	newTemp->setData(x);
	while(temp != NULL){
		if(temp->getData() < x){
			temp2 = temp;
			temp = temp->getRight();
			
		}else{
			temp2 = temp;
			temp = temp->getLeft();
		}
	}
	if(temp2 == NULL){
		root = newTemp;
	}else if(temp2->getData() < x){
		temp2->setRight(newTemp);
	}else if(temp2->getData() > x){
		temp2->setLeft(newTemp);
	}
	list[size] = x;
	size++;
	if(size == length){
		int *newList = new int[size +4];
		for(int i = 0; i < size; i++){
			newList[i] = list[i];
		}
		for(int i = 0; i < 4; i++){
			newList[size + i] = 0;
		}
		delete [] list;
		list = newList;
	}
}


TNode* STree::search(int x){
	TNode* temp = root;
	while(temp != NULL){
		if(temp->getData() == x){
			break;
		}else{
			if(temp->getData() < x){
				temp = temp->getRight();
			}else{
				temp = temp->getLeft();
			}
		}
	}
	return temp;
}
