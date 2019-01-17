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
  Node current_element; // added field
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
  new_dictionary->current_element = 0; // init new field
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
    while (tolower(current->word[i])==tolower(word[i])&&i<count)
    {
      i++;
    }
    if (i==count){//+1) {       //wenn ich count+1 rechne unt unten bei void insert_sorted  if (is_in_dict(dict,word)==true) return; auskommentiere geht der letzte Test
      return true;          //aber der Test case_insensitivity nicht???
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
  dict->current_element = dict->head;
  // removed rest of function
}

bool has_next(Dictionary dict)
{
  return (dict->current_element != 0);
  // removed rest of function
}

const char* get_next_entry(Dictionary dict)
{
  const char* word_to_return = 0; // added word to return
  if (has_next(dict)==true) {
    word_to_return = dict->current_element->word; // store current word
    dict->current_element = dict->current_element->next; // move to next entry
  }
  return word_to_return;
}

void insert_sorted(Dictionary dict, const char* word)
{
  Node current = dict->head; //current added
  Node new_Node=(Node)malloc(sizeof(NodeImplementation));
  new_Node->word=word;
  new_Node->next=0;

  //if (is_in_dict(dict,word)==true) return;

  if (current==0) {
    dict->head=new_Node;
    dict->last=new_Node;
    dict->size++;
    return;                                       //return added
  }

  if (strcmp(current->word,word) > 0) //if added
  {
    new_Node->next = current;
    dict->head = new_Node;
    dict->size++;
  }

   else{                                                                      //else changed + while added
     while (current->next != 0 && strcmp(current->next->word, word) < 0 )
     {
       current = current->next;
     }
     new_Node->next = current->next;
     current->next =new_Node;
     dict->size++;
  }
}
