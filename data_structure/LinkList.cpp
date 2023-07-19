/*
 * 线性表的链式存储
 *
 * */


#define NULL 0

typedef struct LNode {
    int data;
    struct LNode *next;
} LNode, *LinkList;

void LinkListInit(LinkList &L) {
    L = new LNode;
    L->next = NULL;
}

LinkList headInsert(LinkList &L, int e) {
    LNode *node = new LNode;
    node->data = e;
    if (L->next != NULL) {
        node->next = L->next;
    }
    L->next = node;
    return L;
}

LinkList tailInsert(LinkList &L, int e) {
    LNode *node = new LNode;
    node->data = e;
    LNode *rearNode = L;
    if (rearNode->next != NULL) {
        rearNode = rearNode->next;
    }
    rearNode->next = node;
    return L;
}

LNode *getLNode(LinkList L, int i) {
    if (i < 0) {
        return NULL;
    }
    int now = 0;
    LNode *result = L;
    while (i != now) {
        result = result->next;
        now++;
    }
    return result;
}

LNode *locate(LinkList L, int value) {
    LNode *result = L;
    while (L != NULL && result->data != value) {
        result = result->next;
    }
    return result;
}

// ⛤⛤⛤
LinkList insert(LinkList &L, int i, int value) {
    LNode *node = new LNode;
    node->data = value;
    LNode *frontNode = getLNode(L, i);
    node->next = frontNode->next;
    frontNode->next = node;
    return L;
}

// ⛤⛤⛤
LinkList delete_(LinkList &L, int i) {
    LNode *frontNode = getLNode(L, i - 1);
    LNode *curNode = frontNode->next;
    frontNode->next = curNode->next;
    delete (curNode);
}