#ifndef NODE_TYPE_H
#define	NODE_TYPE_H

typedef char ItemType;

struct NodeType {
	ItemType info;
	NodeType *next;
};

#endif
