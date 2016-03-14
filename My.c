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

#include "test.h"


// Global variables defined for the parser utility functions
int nRes;
int nCap;
int nInd;
int nVsrc;
int nIsrc;
int nVCCS;
Device_Entry *dhe[];


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

	printf("[Resistor parsed ...]\n");
	printf("   name=%s, node+=%s, node-=%s, R=%e\n", name, node1, node2, value);
	nRes++;

	// Save the device, nodes, value info to the symbol tables.
	//import node
	Node_Entry *p1, *p2;
	static Node_Entry *p[][];	//link the nodelist
	*nodelist = NULL;
	p1 = p2 = (Node_Entry *)malloc(sizeof(Node_Entry));
	*nodelist = p1;
	p1->name = node1;
	p1->index = 0;
	p1 = (Node_Entry *)malloc(sizeof(Node_Entry));
	p2->next = p1;
	*p[nRes][0] = p2;	//link the nodelist
	p2 = p1;
	p1->name = node2;
	p1->index = 0;
	p2->next = NULL;
	*p[nRes][1] = p2;	//link the nodelist
	//import device
	static Device_Entry *head, *p0;
	p0 = (Device_Entry *)malloc(sizeof(Device_Entry));
	head = p0;
	p0->next = NULL;
	Device_Entry* Insert_Device_Entry(name, numnodes, **nodelist, value);
	dhe[0] = head;
}








void ParseCap(char *name, char *node1, char *node2, double value)
{
	int numnodes;
	Node_Entry **nodelist;

	printf("[Capacitor parsed ...]\n");
	printf("   name=%s, node+=%s, node-=%s, C=%e\n", name, node1, node2, value);
	nCap++;

	// Save the device, nodes, value info to the symbol tables.
	Node_Entry *p1, *p2;
	Static Node_Entry *p[][2];	//link the nodelist
	*nodelist = NULL;
	p1 = p2 = (Node_Entry *)malloc(sizeof(Node_Entry));
	*nodelist = p1;
	p1->name = node1;
	p1->index = 0;
	p1 = (Node_Entry *)malloc(sizeof(Node_Entry));
	p2->next = p1;
	*p[nCap][0] = p2	//link the nodelist
	p2 = p1;
	p1->name = node2;
	p1->index = 0;
	p2->next = NULL;
	*p[nCap][1] = p2	//link the nodelist
	//import device
	static Device_Entry *head, *p0;
	p0 = (Device_Entry *)malloc(sizeof(Device_Entry));
	head = p0;
	p0->next = NULL;
	Device_Entry* Insert_Device_Entry(name, numnodes, **nodelist, value);
	dhe[1] = head;
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
	Node_Entry *p1, *p2;
	Static Node_Entry *p[][2];	//link the nodelist
	*nodelist = NULL;
	p1 = p2 = (Node_Entry *)malloc(sizeof(Node_Entry));
	*nodelist = p1;
	p1->name = node1;
	p1->index = 0;
	p1 = (Node_Entry *)malloc(sizeof(Node_Entry));
	p2->next = p1;
	*p[nInd][0] = p2	//link the nodelist
	p2 = p1;
	p1->name = node2;
	p1->index = 0;
	p2->next = NULL;
	//import device
	*p[nInd][1] = p2	//link the nodelist
	static Device_Entry *head, *p0;
	p0 = (Device_Entry *)malloc(sizeof(Device_Entry));
	head = p0;
	p0->next = NULL;
	Device_Entry* Insert_Device_Entry(name, numnodes, **nodelist, value);
	dhe[2] = head;
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
	Node_Entry *p1, *p2;
	Static Node_Entry *p[][2];	//link the nodelist
	*nodelist = NULL;
	p1 = p2 = (Node_Entry *)malloc(sizeof(Node_Entry));
	*nodelist = p1;
	p1->name = node1;
	p1->index = 0;
	p1 = (Node_Entry *)malloc(sizeof(Node_Entry));
	p2->next = p1;
	*p[nVsrc][0] = p2	//link the nodelist
	p2 = p1;
	p1->name = node2;
	p1->index = 0;
	p2->next = NULL;
	*p[nVsrc][1] = p2	//link the nodelist
	//import device
	static Device_Entry *head, *p0;
	p0 = (Device_Entry *)malloc(sizeof(Device_Entry));
	head = p0;
	p0->next = NULL;
	Device_Entry* Insert_Device_Entry(name, numnodes, **nodelist, value);
	dhe[3] = head;
}

void ParseIsrc(char *name, char *node1, char *node2, double value)
{
	int numnodes;
	Node_Entry **nodelist;

	printf("[Current source parsed ...]\n");
	printf("   name=%s, node+=%s, node-=%s, I=%e\n", name, node1, node2, value);
	nIsrc++;

	// Save the device, nodes, value info to the symbol tables.
	Node_Entry *p1, *p2;
	Static Node_Entry *p[][2];	//link the nodelist
	*nodelist = NULL;
	p1 = p2 = (Node_Entry *)malloc(sizeof(Node_Entry));
	*nodelist = p1;
	p1->name = node1;
	p1->index = 0;
	p1 = (Node_Entry *)malloc(sizeof(Node_Entry));
	p2->next = p1;
	*p[nIsrc][0] = p2	//link the nodelist
	p2 = p1;
	p1->name = node2;
	p1->index = 0;
	p2->next = NULL;
	*p[nIsrc][1] = p2	//link the nodelist
	//import device
	static Device_Entry *head, *p0;
	p0 = (Device_Entry *)malloc(sizeof(Device_Entry));
	head = p0;
	p0->next = NULL;
	Device_Entry* Insert_Device_Entry(name, numnodes, **nodelist, value);
	dhe[4] = head;
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
	Node_Entry *p1, *p2;
	*nodelist = NULL;
	Static Node_Entry *p[][4];	//link the nodelist
	p1 = p2 = (Node_Entry *)malloc(sizeof(Node_Entry));
	*nodelist = p1;
	p1->name = node1;
	p1->index = 0;
	p1 = (Node_Entry *)malloc(sizeof(Node_Entry));
	p2->next = p1;
	*p[nVCCs][0] = p2	//link the nodelist
	p2 = p1;
	p1->name = node2;
	p1->index = 0;
	p1 = (Node_Entry *)malloc(sizeof(Node_Entry));
	p2->next = p1;
	*p[nVCCs][1] = p2	//link the nodelist
	p2 = p1;
	p1->name = node3;
	p1->index = 0;
	p1 = (Node_Entry *)malloc(sizeof(Node_Entry));
	p2->next = p1;
	*p[nVCCs][2] = p2	//link the nodelist
	p2 = p1;
	p1->name = node4;
	p1->index = 0;
	p2->next = NULL;
	*p[nVCCs][3] = p2	//link the nodelist
	//import device
	static Device_Entry *head, *p0;
	p0 = (Device_Entry *)malloc(sizeof(Device_Entry));
	head = p0;
	p0->next = NULL;
	Device_Entry* Insert_Device_Entry(name, numnodes, **nodelist, value);
	dhe[5] = head;
}


void Summarize()
{
	printf("[Finished parsing netlist!]\n");
	printf("   #res=%d, #cap=%d, #ind=%d, #vccs=%d, #vsrc=%d, #isrc=%d\n", \
		nRes, nCap, nInd, nVCCS, nVsrc, nIsrc);
}
