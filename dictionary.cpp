/*----------------------------------------------------------
 *				HTBLA-Leonding / Klasse: <your class>
 * ---------------------------------------------------------
 * Exercise Number: 0
 * Title:			dictionary.cpp
 * Author:			P. Bauer
 * Due Date:		November 25, 2012
 * ----------------------------------------------------------
 * Description:
 * Implementation of dictionary.h.
 * ----------------------------------------------------------
 */
#include "dictionary.h"
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

typedef struct NodeImplementation* Node;


struct DictionaryImplementation{
  int size;
  Node head;
  Node last;
};

struct NodeImplementation{
  const char* word;
  struct NodeImplementation* next;
  //bool start_iterating;
};


Dictionary new_dictionary()
{
  Dictionary new_dictionary=(Dictionary)malloc(sizeof(struct DictionaryImplementation));
  new_dictionary->size=0;
  new_dictionary->head=0;
  new_dictionary->last=0;
  return new_dictionary;
}

void delete_dictionary(Dictionary dictionary)
{
  Node current=dictionary->head;
  Node to_delete=current;
  while (current!=0) {
    Node to_delete=current;
    current=current->next;
    sfree(to_delete);
  }
  sfree(dictionary);
}

void add(Dictionary dict, const char* word)
{
  if (word!=0) {

    Node current=dict->head;
    while (current!=0) {
      if (current->word==word)return;
      current=current->next;
    }

    current=dict->head;
    Node new_Node=(Node)malloc(sizeof(NodeImplementation));
    new_Node->word=word;
    new_Node->next=0;

    if (dict->head==0) {
      dict->head=new_Node;
      dict->last=new_Node;
      dict->size++;
    }
    else{
      dict->last->next=new_Node;
      dict->last=new_Node;
      dict->size++;
    }

  }
}

int get_size(Dictionary dict)
{
  return dict->size;
}

bool is_in_dict(Dictionary dict, const char* word)
{
  int i=0;
  int count=strlen(word);
  bool no_dif=true;



  bool is_inside=false;
  Node current=dict->head;
  while (current!=0) {

    //for (int i = 0; i < count; i++) {
      //if (tolower(current->word[i])==tolower(word[i])) {
        //no_dif=true;
      //}
      //else{
        //no_dif=false;
      //}

    //}
    while (tolower(current->word[i])==tolower(word[i])&&i<count) {
      i++;
    }
    if (i==count) {
      return true;
    }


    if (current->word==word) {//no_dif=true){
      is_inside=true;
    }
    current=current->next;
  }
  return is_inside;
}

void start_iterating(Dictionary dict)
{
  Node current=dict->head;
  //if (dict->head!=0) {
    //current->start_iterating=true;
  //}
}

bool has_next(Dictionary dict)
{
  if (dict->head==0) {
    return false;
  }

  Node current=dict->head;


  if (current/*->next*/!=0) {
    //current=current->next;
    return true;
  }
  else{
    return false;
  }
}

const char* get_next_entry(Dictionary dict)
{
  Node current=dict->head;
  Node to_return=current;
  if (has_next(dict)==true) {
    current=current->next;
    return to_return/*->next*/->word;
  }
  else{
    return 0;
  }
}

void insert_sorted(Dictionary dict, const char* word)
{
  Node new_Node=(Node)malloc(sizeof(NodeImplementation));
  new_Node->word=word;
  new_Node->next=0;
  if (dict->head==0) {
    dict->head=new_Node;
    dict->last=new_Node;
    dict->size++;
  }
  //else{
    //dict->last->next=new_Node;
    //dict->last=new_Node;
    //dict->size++;
  //}
}
