/**
	Symbol_Table.c
	For the undergraduate EDA course offered at 
	Dept of Micro/Nano-electronics

	(c) Guoyong Shi, 
	All rights reserved, 2006-2015
	Shanghai Jiao Tong University

	If you modify the code, please keep the above copyright info.
*/

#ifdef MATLAB
#include "mex.h"
#endif

#include <stdio.h> 
#include <stdlib.h> 
#include <string.h>
#include "Symbol_Table.h"

// Electric type of a node variable
#define SP_NOTYPE 	0
#define SP_VOLTAGE 	1
#define SP_CURRENT 	2

#define LINE_INFO   "\n[" << __FILE__ << " : line " << __LINE__ << " : " << __FUNCTION__ << "()] - "
#define PRINT_LINE_INFO 	printf("\n[%s : line %d : %s()]\n", __FILE__, __LINE__, __FUNCTION__);


Node_Entry **NodeTable;
int NodeTableSize;

Device_Entry **DeviceTable;
int DeviceTableSize;


void Init_Symbol_Tables()
{
	
}


void Destroy_Symbol_Table()
{
	Delete_Node_Table();
	Delete_Device_Table();
}


void Delete_Node_Table()
{
}

void Delete_Device_Table()
{
}

void Delete_Node_Entry(const char *name)
{
}

void Delete_Device_Entry(const char *name)
{
	// NOT IMPLEMENTED!
}

Node_Entry* Lookup_Node_Entry(const char *name)
{
	return  NULL;
}


Device_Entry* Lookup_Device_Entry(const char *name)
{
	return NULL;
}


Node_Entry* Insert_Node_Entry(const char *name)
{
	return NULL;
}


Device_Entry* Insert_Device_Entry(const char *name,  const int numnodes, 
				Node_Entry **nodelist, const double value)
{
	Device_Entry *p1;
	if(head == p0)
	{
		p1 = head; 
		p1->name = name;
		p1->numnodes = numnodes;
		p1->nodelist = nodelist;
		p1->value = value;
	}
	else
	{
		p1 = (Device_Entry *)malloc(sizeof(Device_Entry));
		p1 = head; 
		p1->name = name;
		p1->numnodes = numnodes;
		p1->nodelist = nodelist;
		p1->value = value;
		p0->next = p1;
		p0 = p1;
		p1->next = NULL;
	}
	return NULL;
}


void Print_Node_Table()
{
}


void Print_Device_Table()
{
	Device_Entry *p0;
	for(int i = 0; i < 6; i++)
	{
		p0= dhe[i];
		do
		{
			printf("%s, %d,%d, %d, %g\n", p0->name, p0->numnodes, *(p0->nodelist)->index, *(p0->nodelist)->next->index, p0->value);
			p0 = p0->next;
		}while(p0 != NULL);
	}
}


int NameHash(const char *name,  int tsize)
{
	const char *s; 
	register int i = 0; 

	// In case no name
	if (!name)	return (0);
	
	for (s = name; *s; s++) {
		i += (unsigned) *s; 
	}
	
	return (i % tsize);
}


