
#include "test.h"

int nRes;
int nCap;
int nInd;
int nVsrc;
int nIsrc;
int nVCCS;
Device_Entry *dhe[];
static Device_Entry *head;
static Device_Entry *p0;

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
		printf("head=p0");
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
		printf("head!=p0");
	}
	return NULL;
}
void ParseRes(char *name, char *node1, char *node2, double value)
{
	int numnodes=2;
	Node_Entry **nodelist;

	printf("[Resistor parsed ...]\n");
	printf("   name=%s, node+=%s, node-=%s, R=%e\n", name, node1, node2, value);
	nRes++;

	// Save the device, nodes, value info to the symbol tables.
	//import node
	Node_Entry *p1, *p2;
	nodelist = NULL;
	p1 = p2 = (Node_Entry *)malloc(sizeof(Node_Entry));
	nodelist = &p1;
	p1->name = node1;
	p1->index = 0;
	p1 = (Node_Entry *)malloc(sizeof(Node_Entry));
	p2->next = p1;
	p2 = p1;
	p1->name = node2;
	p1->index = 0;
	p2->next = NULL;
	//import device
	static Device_Entry *p0;
	p0 = (Device_Entry *)malloc(sizeof(Device_Entry));
	head = p0;
	p0->next = NULL;
//    Insert_Device_Entry(name, numnodes, nodelist, value);
	dhe[0] = head;
	printf("%s\n",(dhe[0])->name);
	//link the nodelist

}


int main()
{
    char name[]={"R1"};
    char node1[]={"N1"};
    char node2[]={"N2"};
    ParseRes(name,node1,node2, 1.00);

    return 0;
}
