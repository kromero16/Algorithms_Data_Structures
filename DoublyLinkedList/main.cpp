/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: kromero
 * Purpose: Algorithmic operations with Doubly Linked List without Classes
 * Created on June 11, 2020, 10:47 AM
 */

//System Libraries
#include <cstdlib>
#include <iostream>
using namespace std;

//User Libraries
struct Node{
    int data;
    Node *next;
    Node *prev;
};

//Function Prototypes
void push_front(Node **,int,int&);
void print_forward(Node **,int&);
void insertAt(Node**,int,int&,int);
void deleteFront(Node **,int &);

/*
 * 
 */
int main(int argc, char** argv) {
    //Declare variables
    Node *front = NULL;
    Node *end = NULL;
    int length = 0;
    
    push_front(&front,1,length);
    push_front(&front,2,length);
    push_front(&front,3,length);
    insertAt(&front,34,length,1);
    insertAt(&front,23,length,1);
    insertAt(&front,266,length,2);
    insertAt(&front,267,length,3);
    insertAt(&front,2444,length,4);
    insertAt(&front,10100,length,8);
    print_forward(&front,length);
    cout<<"Deleting head \n";
    deleteFront(&front,length);
    deleteFront(&front,length);
    print_forward(&front,length);
    
    
    
    //Exit
    return 0;
    
    
}
//delete front node
void deleteFront(Node **front,int &length){
    //delete
    Node *curr = *front;
    
    *front = curr->next;
    curr->prev = NULL;
    curr->next = NULL;
   
    delete curr;
    
    //
    length--;
}

//insert at given position
    void insertAt(Node **front,int data, int &length,int pos){
        //create node
        Node *newNode = new Node();
        newNode->data = data;
        newNode->next = NULL;
        newNode->prev = NULL;
        
        //
        Node *curr = *front;
        Node *temp = NULL;
        
        //add head
        if(pos==1){
            newNode->next = curr;
            curr->prev = newNode;
            *front = newNode;
            
            //increment length
            length++;
            
        }
        //add at end
        else if(pos==length){
            //traverse list to end
            while(curr->next!=NULL){
                curr = curr->next;
            }
            //add at end
            curr->next = newNode;
            newNode->prev = curr;
            
            //increment length
            length++;
        }
        else if(pos<0||pos>length){
            cout<<"position not in range \n";
        }
        //add middle
        else{
            //traverse to position-1
            for(int i=1;i<pos-1;i++){
                curr = curr->next;
            }
            //add middle
            temp = curr->next;
            curr->next = newNode;
            newNode->prev = curr;
            newNode->next = temp;
            temp->prev = newNode;
            
            //increment length
            length++;
            
        }
     
        
        
    }

//print
void print_forward(Node **front,int &length){
    Node *temp = *front;
    while(temp!=NULL){
        cout<<temp->data<<" -> ";
        temp = temp->next;
    }cout<<"NULL \n";
     cout<<"Length: "<<length<<"\n";
}

//push front
void push_front(Node **front,int data,int &length){
    //create node 
    Node *newNode = new Node();
    newNode->data = data;
    newNode->next = NULL;
    newNode->prev = NULL;
    
    Node *curr = *front;
    if(*front!=NULL){
        newNode->next = curr;
        curr->prev = newNode;
        *front = newNode;
        length++;
    }
    else{
        *front = newNode;
        length++;
    }
    
    
}

