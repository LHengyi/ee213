#ifndef TEST_H_INCLUDED
#define TEST_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>

// Global variables defined for the parser utility functions
struct node_s
{
	char *name;	// node name to be allocated
	int index;	// node index for accessing matrix row/column
	void *node; 	// points to a Node instance in the future
	struct node_s *next;
};
typedef struct node_s Node_Entry;

struct device_s {
	char *name;
	int numnodes;	// length of the node list
	Node_Entry **nodelist;
	double value;
	void *device;	// points to a device instance in the future
	struct device_s *next;
};
typedef struct device_s Device_Entry;
extern int nRes;
extern int nCap;
extern int nInd;
extern int nVsrc;
extern int nIsrc;
extern int nVCCS;
Node_Entry **NodeTable;
Device_Entry **DeviceTable, **Reshead, **Restail, **Caphead, **CapIChead, **Indhead, **IndIChead, **Vsrchead, **Isrchead, **VCCS;




extern void Init_parse_util();
extern void ParseRes(char *str, char *node1, char *node2, double value);
//extern void ParseCap(char *str, char *node1, char *node2, double value);
//extern void ParseCapIC(char *str, char *node1, char *node2, double value, double init);
//extern void ParseInd(char *str, char *node1, char *node2, double value);
//extern void ParseIndIC(char *str, char *node1, char *node2, double value, double init);
//extern void ParseVsrc(char *str, char *node1, char *node2, double value);
//extern void ParseIsrc(char *str, char *node1, char *node2, double value);
//extern void ParseVCCS(char *str, char *node1, char *node2, char *node3, char *node4, double value);
//extern void Summarize();

#endif // TEST_H_INCLUDED
