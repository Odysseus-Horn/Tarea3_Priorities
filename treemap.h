#ifndef TREEMAP_h
#define TREEMAP_h

typedef struct TreeMap TreeMap;

typedef struct TreeNode TreeNode;

typedef struct Pair {
     void * key;
     void * value;
} Pair;

struct TreeNode {
    Pair* pair;
    TreeNode * left;
    TreeNode * right;
    TreeNode * parent;
};

TreeMap * createTreeMap(int (*lower_than_int) (void* key1, void* key2));

void insertTreeMap(TreeMap * tree, void* key, void * value);

void eraseTreeMap(TreeMap * tree);

void * firstTreeMap(TreeMap * tree);

void * nextTreeMap(TreeMap * tree);



#endif /* TREEMAP_h */
