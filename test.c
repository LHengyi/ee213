#include "test.h"
#include <stdio.h>
//#include "Symbol_Table.h"

// Global variables defined for the parser utility functions
int nRes;
int nCap;
int nInd;
int nVsrc;
int nIsrc;
int nVCCS;
Node_Entry **Nodelist;
//Device_Entry **DeviceTable;
//Device_Entry **Caphead;
//Device_Entry **Reshead;
//Device_Entry **CapIChead;
//Device_Entry **Indhead;
//Device_Entry **IndIChead;
//Device_Entry **Vsrchead;
//Device_Entry **Isrchead;
//Device_Entry **VCCS;


//void Init_parse_util()
//{
//	nRes = 0;
//	nCap = 0;
//	nInd = 0;
//	nVsrc = 0;
//	nIsrc = 0;
//	nVCCS = 0;
//}

void ParseRes(char *name, char *node1, char *node2, double value)
{
	int numnodes;
	Node_Entry **nodelist;
	Device_Entry *deviceRes;

	printf("[Resistor parsed ...]\n");
	printf("   name=%s, node+=%s, node-=%s, R=%e\n", name, node1, node2, value);
	nRes++;

	deviceRes = (struct device_s *) malloc(sizeof(struct device_s));
	// if (deviceRes==NULL)
	// {
	// 	printf("malloc failed");
	// 	exit(0);
	// }
	deviceRes->name=name;
	deviceRes->numnodes=2;
	// nodelist = (struct node_s**) malloc( 2 * sizeof(struct node_s*) );
	Node_Entry *N1=(struct node_s*) malloc(sizeof(struct node_s*) );
	Node_Entry *N2=(struct node_s*) malloc(sizeof(struct node_s*) );
	// if (nodelist==NULL)
	// {
	// 	printf("malloc failed");
	// 	exit(0);
	// }
	N1->name=node1;
	N2->name=node2;
	N1->next=N2;
	nodelist=&N1;
    deviceRes->nodelist = nodelist;
	deviceRes->value=value;
	deviceRes->next=NULL;

	if (Reshead==NULL)
	{
		Reshead=&deviceRes;
		// Restail=&deviceRes;
		printf(" Head NULL\n");
	}
	else if (Restail==NULL)
	{
		Restail=&deviceRes;
		(*Reshead)->next=*Restail;
		printf("Tail NULL\n");
	}
	else
	{
	    deviceRes->next=(*Restail)->next;
	    (*Restail)->next=deviceRes;
	    Restail=&deviceRes;
	}

	Node_Entry *n1, *n2;
	n1=(struct node_s *) malloc(sizeof(struct node_s));
	n2=(struct node_s *) malloc(sizeof(struct node_s));
	n1->name=node1;
	n2->name=node2;
	n1->next=n2;

	if (Nodelist==NULL)
	{
		Nodelist=&n1;
	}
	else
	{
		(*Nodelist)->next=n1;
		nodelist=&n2;
	}
	printf("%s\n", (*Reshead)->name);

	// Save the device, nodes, value info to the symbol tables.
	// Please write your own code here ...
}

int main()
{
    ParseRes("R1","N01","N02",1.00);
    ParseRes("R2","N01","N02",1.00);
    ParseRes("R3","N01","N02",1.00);
    printf("name: %s %s",(*Reshead)->name,(*Reshead)->next->name);

    return 0;
}
