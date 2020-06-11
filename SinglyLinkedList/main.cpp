/* 
 * File:   main.cpp
 * Author: kromero
 * Created on May 30, 2020, 12:33 AM
 * Purpose: Singly Linked List with algorithmic operations
 *                without using classes
 */

//System Libraries
#include <cstdlib>
#include <iostream>
#include <ctime>
using namespace std;

//User Libraries
struct Node{
    int data;
    Node *next;
};

//Function Prototypes
void print(Node *,int);
void push_back(Node **,int,int&);
void push_front(Node **,int,int&);
void insert_at(Node **,int,int,int&);
void delete_node(Node **,int,int&);
int search_data(Node **,int,int); 
void reverse_list(Node **);

//Begin Execution
int main(int argc, char** argv) {
    
    //create list
    Node *front = NULL;
    
    //declare variables
    int length = 0;
    int num = 1;
    
    //push data
    push_front(&front,6,length);
    push_back(&front,7,length);
    push_back(&front,8,length);
    push_front(&front,3,length);
    push_front(&front,1,length);
    push_back(&front,9,length);
    insert_at(&front,4,3,length);
    insert_at(&front,5,4,length);
    insert_at(&front,2,2,length);
  
    //print
    print(front,length);
    /*
    //search list for data
    cout<<"found "<<num<<" at "
            "position "<<search_data(&front,num,length)<<"\n";
    
    //delete node if data found
    delete_node(&front,num,length);
    delete_node(&front,2,length);
    delete_node(&front,3,length);
    push_front(&front,13,length);
    
    cout<<"Deleting 1, 2, and 3. Pushing 13 to front \n";
    */
    
    reverse_list(&front);
    cout<<"\nList after reversing: \n";
    print(front,length);
    
    //Exit
    return 0;
}
//reverse list
void reverse_list(Node **front){
    Node *curr = *front;
    Node *next = NULL;
    Node *prev = NULL;
    
    while(curr!=NULL){
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }
    *front = prev;
}

//delete node if found
void delete_node(Node **front,int data,int &length){
    //declare variables
    Node *prev = *front;
    Node *target = *front;
  
    
    //check if data is found in list & get position
    int n = search_data(front,data,length);
    
    //traverse to node previous to target
    if(n!=-1){
        if(n==1){
            Node *temp = *front;
            //delete front
            *front = temp->next;
            delete temp;
            length--;
            
        }else{
            //else delete at given position
            //traverse to previous node
            for(int i=1;i<n-1;i++){
                prev = prev->next;
        }
        
            //traverse to target node
            for(int i=1;i<n;i++){
                 target = target->next;
        }
        
            //point next of prev node to next of target node
            prev->next = target->next;
            target->next = NULL;
            target = NULL;
            delete target;
        
            //decrement length
            length--;
        
        }
                
    }else{
        cout<<"Data in Node not found \n";
    }
}

//search for data in node and return position found at
int search_data(Node **front,int data,int length){
    //declare variables
    bool found = false;
    int position;
    
    Node *end = *front;
    
    //search for data in list
    for(int i=1;i<length+1;i++){
        if(end->data == data){
            return i;
            found = true;
        }
        end = end->next;
    }
    if(found==false)
        return -1;
    
}

//push at given pos
void insert_at(Node **front,int data,int position,int &length){
    //create node
    Node *newNode = new Node();
    newNode->data = data;
    newNode->next = NULL;
    
    //if position is 1 add to end
    if(position<=0||position>length){
        cout<<"Position out of range \n";
        return;
    }
    else if(position==1){
        newNode->next = *front;
        *front = newNode;
        length++;
    }else{
        //set temp
        Node *temp = *front;
        //traverse to position
        for(int i=1;i<position-1;i++){
            temp = temp->next;
        }
        //add at position
        newNode->next = temp->next;
        temp->next = newNode;
        length++;
    }
    
}


//push front
void push_front(Node **front,int data,int &length){
    //create node
    Node *temp = new Node();
    temp->data = data;
    temp->next = NULL;
    
    //push to front
    if(*front!=NULL){
        temp->next = *front;
        *front = temp;
         length++;
    }
    else{
        *front = temp;
         length++;
    }
}

//push back
void push_back(Node **front,int data,int &length){
    //create node
    Node *temp = new Node();
    temp->data = data;
    temp->next = NULL;
    
    //if not empty add at end
    if(*front!=NULL){
        Node *end = *front;
        while(end->next!=NULL){
            end = end->next;
        }
        end->next = temp;
         length++;
    }else{
        //if empty add at front
        *front = temp;
         length++;
    }
   
}

//print
void print(Node *front,int length){
    Node *temp = front;
    while(temp!=NULL){
        cout<<temp->data<<" -> ";
        temp = temp->next;
    }cout<<"NULL \n";
    cout<<"List Length: "<<length<<"\n";
}


    
