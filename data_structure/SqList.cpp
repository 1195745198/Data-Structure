/*
 * 线性表的顺序表示
 *
 * */


#define MaxSize 10

struct SqList {
    int data[MaxSize] = {0};
    int length = 0;
};

struct SeqList {
    int *data;
    int maxsize, length;
};

void SeqListInit(SeqList SeqList) {
    SeqList.data = new int[MaxSize];
    SeqList.maxsize = MaxSize;
}

bool SqListInsert(SqList &L, int i, int e) {
    if (i < 0 || i > L.length - 1 || L.length + 1 > MaxSize) {
        return false;
    }
    for (int j = L.length; j > i; j--) {
        L.data[j] = L.data[j - 1];
    }
    L.data[i] = e;
    L.length++;
    return true;
}

bool SqListDelete(SqList &L, int i, int &e) {
    if (i < 0 || i >= L.length - 1) {
        return false;
    }
    e = L.data[i];
    for (int j = i + 1; j < L.length; j++) {
        L.data[j - 1] = L.data[j];
    }
    L.length--;
    return true;
}

int Locate(SqList L, int e) {
    for (int i = 0; i < L.length; i++) {
        if (L.data[i] == e)
            return i;
    }
    return -1;
}