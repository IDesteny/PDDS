#pragma once
#include <string>

struct Node
{
	Node *next;
	int data;
};

// F1
Node *create_empty();

// F2
bool isEmpty(Node *set);

// F3
bool own(Node *set, int val);

// F4
Node *add(Node *set, int val);

// F5
Node *create(int counter, int min, int max);

// F6
int size(Node *set);

// F7
std::string print(Node *set, char sp);

// F8
Node *delete_set(Node *set);

// F9
bool subset(Node *set1, Node *set2);

// F10
bool quality(Node *set1, Node *set2);

// F11
Node *union_set(Node *set1, Node *set2);

// F12
Node *intersection_set(Node *set1, Node *set2);

// F13
Node *difference_set(Node *set1, Node *set2);

// F14
Node *symmetric_difference_set(Node *set1, Node *set2);