/************************************************************
  	parse_func.c
  	containing parsing functions for SPICE netlist parser example.

Author(s):
   	Shi, Guoyong  2015
 
	Course material for "Introduction to EDA", 2015
   	Dept of Micro/Nano-electronics
   	Shanghai Jiao Tong University (SJTU)
************************************************************/

#ifdef MATLAB
#include "mex.h"
#endif

#include "parse_func.h"
#include "Symbol_Table.h"

// Global variables defined for the parser utility functions
int nRes;
int nCap;
int nInd;
int nVsrc;
int nIsrc;
int nVCCS;
Device_Entry **DeviceTable;
Device_Entry **Reshead;
Device_Entry **Caphead;
Device_Entry **CapIChead;
Device_Entry **Indhead;
Device_Entry **IndIChead;
Device_Entry **Vsrchead;
Device_Entry **Isrchead;
Device_Entry **VCCS;


void Init_parse_util()
{
	nRes = 0;
	nCap = 0;
	nInd = 0;
	nVsrc = 0;
	nIsrc = 0;
	nVCCS = 0;
}

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
		*Reshead->next=deviceRes;
	}

	Node_Entry *n1, *n2;
	n1=(struct node_s *) malloc(sizeof(struct node_s));
	n2=(struct node_s *) malloc(sizeof(struct node_s));
	n1->name=node1;
	n2->name=node2;
	n1->next=n2;

	if (nodelist==NULL)
	{
		*nodelist=n1;
	}
	else
	{
		nodelist->next=n1;
		*nodelist=n2;
	}

	// Save the device, nodes, value info to the symbol tables.
	// Please write your own code here ...
}

void ParseCap(char *name, char *node1, char *node2, double value)
{
	int numnodes;
	Node_Entry **nodelist;
	
	printf("[Capacitor parsed ...]\n");
	printf("   name=%s, node+=%s, node-=%s, C=%e\n", name, node1, node2, value);
	nCap++;

	// Save the device, nodes, value info to the symbol tables.
	// Please write your own code here ...
}

void ParseCapIC(char *name, char *node1, char *node2, double value, double init)
{
	printf("[Capacitor parsed ...]\n");
	printf("   name=%s, node+=%s, node-=%s, C=%e, init=%e\n", name, node1, node2, value, init);
	nCap++;

	// Save the device, nodes, value info to the symbol tables.
	// Please write your own code here ...
}

void ParseInd(char *name, char *node1, char *node2, double value)
{
	int numnodes;
	Node_Entry **nodelist;
	
	printf("[Inductor parsed ...]\n");
	printf("   name=%s, node+=%s, node-=%s, L=%e\n", name, node1, node2, value);
	nInd++;

	// Save the device, nodes, value info to the symbol tables.
	// Please write your own code here ...
}

void ParseIndIC(char *name, char *node1, char *node2, double value, double init)
{
	printf("[Inductor parsed ...]\n");
	printf("   name=%s, node+=%s, node-=%s, L=%e, init=%e\n", name, node1, node2, value, init);
	nInd++;

	// Save the device, nodes, value info to the symbol tables.
	// Please write your own code here ...
}

void ParseVsrc(char *name, char *node1, char *node2, double value)
{
	int numnodes;
	Node_Entry **nodelist;
	
	printf("[Voltage Source parsed ...]\n");
	printf("   name=%s, node+=%s, node-=%s, V=%e\n", name, node1, node2, value);
	nVsrc++;

	// Save the device, nodes, value info to the symbol tables.
	// Please write your own code here ...
}

void ParseIsrc(char *name, char *node1, char *node2, double value)
{
	int numnodes;
	Node_Entry **nodelist;
	
	printf("[Current source parsed ...]\n");
	printf("   name=%s, node+=%s, node-=%s, I=%e\n", name, node1, node2, value);
	nIsrc++;

	// Save the device, nodes, value info to the symbol tables.
	// Please write your own code here ...
}

void ParseVCCS(char *name, char *node1, char *node2, char *node3, char *node4, double value)
{
	int numnodes;
	Node_Entry **nodelist;
	
	printf("[VCCS parsed ...]\n");
	printf("   name=%s, N+=%s, Ne-=%s,  Nc+=%s, Nc-=%s, G=%e\n", 
			name, node1, node2, node3, node4, value);
	nVCCS++;

	// Save the device, nodes, value info to the symbol tables.
	// Please write your own code here ...
}


void Summarize()
{
	printf("[Finished parsing netlist!]\n");
	printf("   #res=%d, #cap=%d, #ind=%d, #vccs=%d, #vsrc=%d, #isrc=%d\n", \
		nRes, nCap, nInd, nVCCS, nVsrc, nIsrc);
}
