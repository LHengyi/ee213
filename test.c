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
	deviceRes->name=name;
	deviceRes->numnodes=2;
	nodelist = (struct node_s**) malloc( 2 * sizeof(struct node_s*) );
	nodelist[0]->name=node1;
	nodelist[1]->name=node2;
	deviceRes->nodelist = nodelist;
	deviceRes->value=value;
	if (Reshead==NULL)
	{
		*Reshead=deviceRes;
	}
	else
	{
	    deviceRes->next=(*Reshead)->next;
		(*Reshead)->next=deviceRes;
	}

	Node_Entry *n1, *n2;
	n1=(struct node_s *) malloc(sizeof(struct node_s));
	n2=(struct node_s *) malloc(sizeof(struct node_s));
	n1->name=node1;
	n2->name=node2;
	n1->next=n2;

	if (Nodelist==NULL)
	{
		*Nodelist=n1;
	}
	else
	{
		(*Nodelist)->next=n1;
		*nodelist=n2;
	}
	printf("name: %s,",(*Reshead)->name);

	// Save the device, nodes, value info to the symbol tables.
	// Please write your own code here ...
}

int main()
{
    ParseRes('R1','N01','N02',1);
    return 0;
}
