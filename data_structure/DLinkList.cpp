
/*
 * 双链表的链式存储
 *
 * */

#define NULL 0

typedef struct DLNode {
    int data;
    DLNode *prior, *next;
} DLNode, *DLinkList;

void DLinkListInit(DLinkList &L) {
    L->data = 0;
    L->prior = NULL;
    L->next = NULL;
}

DLNode *getLNode(DLinkList L, int i) {
    if (i < 0) {
        return NULL;
    }
    int now = 0;
    DLNode *result = L;
    while (i != now) {
        result = result->next;
        now++;
    }
    return result;
}

// ⛤⛤⛤⛤⛤
DLinkList insert(DLinkList &L, int i, int e) {
    DLNode *node = new DLNode;
    node->data = e;
    DLNode *frontNode = getLNode(L, i);
    node->next = frontNode->next;
    frontNode->next->prior = node;
    node->prior = frontNode;
    frontNode->next = node;
    return L;
}

// ⛤⛤⛤⛤⛤
DLinkList delete_(DLinkList &L, int i) {
    DLNode *curNode = getLNode(L, i);
    DLNode *frontNode = curNode->prior;
    frontNode->next = curNode->next;
    curNode->next->prior = frontNode;
    delete (curNode);
    return L;
}