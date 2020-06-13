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
    print_forward(&front,length);
    
    
    
    //Exit
    return 0;
    
    
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
        
        //add front
        if(pos==1){    
            newNode->next = curr;
            curr->prev = newNode;
            *front = newNode;
            length++;
        }
        //add end
        else if(pos==length){
            
        }
        else if(pos>length){
            cout<<"position not in range \n";
        }
        else{
            //add at position
            for(int i=1;i<pos-1;i++){
                curr = curr->next;
            }
            temp = curr->next;
            curr->next = newNode;
            newNode->next = temp;
            temp->prev = newNode;
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

