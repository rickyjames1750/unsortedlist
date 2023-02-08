/*

Project: Unsorted List

Authors: 
Ricky Sparks      
Jeremia Subido  
Omar Arreola      

Course: CS 301-03 
Assignment Number: Assignment 3
Team: Group 2 

*/
// The following definitions go into file ItemType.cpp. 
#include <fstream>
#include <iostream>
#include "ItemType.h"

ItemType::ItemType()
{ 
  value = 0;
}

RelationType ItemType::ComparedTo(ItemType otherItem) const 
{
  if (value < otherItem.value)
    return LESS;
  else if (value > otherItem.value)
    return GREATER;
  else return EQUAL;
}

void ItemType::Initialize(int number) 
{
  value = number;
}

void ItemType::Print(std::ostream& out) const 
// pre:  out has been opened.
// post: value has been sent to the stream out.
{
  out << value;
}
