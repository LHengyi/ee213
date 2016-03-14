#ifndef TEST_H_INCLUDED
#define TEST_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>

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

#endif // TEST_H_INCLUDED
