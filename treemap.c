#include "treemap.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct TreeMap {
    TreeNode * root;
    TreeNode * current;
    int (*lower_than) (void* key1, void* key2);
};

int is_equal(TreeMap *tree, void *key1, void *key2) {
  if (tree->lower_than(key1, key2) == 0 && tree->lower_than(key2, key1) == 0)
    return 1;
  else
    return 0;
}

TreeNode *minimum(TreeNode *x) {

  if (x->left == NULL) {
    return x;
  }
  return minimum(x->left);
}

TreeNode *createTreeNode(void *key, void *value) {
  TreeNode *new = (TreeNode *)malloc(sizeof(TreeNode));
  if (new == NULL)
    return NULL;
  new->pair = (Pair *)malloc(sizeof(Pair));
  new->pair->key = key;
  new->pair->value = value;
  new->parent = new->left = new->right = NULL;
  return new;
}

TreeMap *createTreeMap(int (*lower_than)(void *key1, void *key2)) {

  TreeMap *newTree = (TreeMap *)malloc(sizeof(TreeMap));
  newTree->root = NULL;
  newTree->current = NULL;

  newTree->lower_than = lower_than;

  return newTree;
}

void insertTreeMap(TreeMap *tree, void *key, void *value) {
  if (tree == NULL)
    return;

  // Crear un nuevo nodo con la clave y el valor proporcionados
  TreeNode *newNode = createTreeNode(key, value);
  if (newNode == NULL)
    return;

  if (tree->root == NULL) {
    // Si el árbol está vacío, el nuevo nodo se convierte en la raíz
    tree->root = newNode;
    tree->current = newNode;
  } else {
    TreeNode *currentNode = tree->root;
    TreeNode *parent = NULL;

    // Recorrer el árbol para encontrar la ubicación adecuada para insertar el nuevo nodo
    while (currentNode != NULL) {
      parent = currentNode;

      // Si la clave ya existe, el nuevo nodo se convierte en el hijo izquierdo del nodo repetido
      if (is_equal(tree, key, currentNode->pair->key)) {
        newNode->parent = parent;
        parent->left = newNode;
        return;
      } else if (tree->lower_than(key, currentNode->pair->key)) {
        // Si la clave es menor que la clave actual, moverse hacia la izquierda
        currentNode = currentNode->left;
      } else {
        // Si la clave es mayor que la clave actual, moverse hacia la derecha
        currentNode = currentNode->right;
      }
    }

    // Asignar el padre al nuevo nodo y colocarlo como hijo izquierdo o derecho del padre según corresponda
    newNode->parent = parent;
    if (tree->lower_than(key, parent->pair->key))
      parent->left = newNode;
    else
      parent->right = newNode;
  }
}

void RemoveNode(TreeMap *tree, TreeNode *node) {
  if (tree == NULL || node == NULL)
    return;

  // Caso 1: El nodo no tiene hijos
  if (node->left == NULL && node->right == NULL) {
    if (node->parent == NULL) {
      // El nodo es la raíz del árbol
      tree->root = NULL;
    } else {
      // El nodo es un hijo izquierdo o derecho de su padre
      TreeNode *parent = node->parent;
      if (parent->left == node)
        parent->left = NULL;
      else
        parent->right = NULL;
    }
    free(node->pair);
    free(node);
  }
  // Caso 2: El nodo tiene un hijo izquierdo pero no un hijo derecho
  else if (node->left != NULL && node->right == NULL) {
    TreeNode *child = node->left;
    TreeNode *parent = node->parent;
    child->parent = parent;

    if (parent == NULL) {
      // El nodo es la raíz del árbol
      tree->root = child;
    } else {
      // El nodo es un hijo izquierdo o derecho de su padre
      if (parent->left == node)
        parent->left = child;
      else
        parent->right = child;
    }
    free(node->pair);
    free(node);
  }
  // Caso 3: El nodo tiene un hijo derecho pero no un hijo izquierdo
  else if (node->left == NULL && node->right != NULL) {
    TreeNode *child = node->right;
    TreeNode *parent = node->parent;
    child->parent = parent;

    if (parent == NULL) {
      // El nodo es la raíz del árbol
      tree->root = child;
    } else {
      // El nodo es un hijo izquierdo o derecho de su padre
      if (parent->left == node)
        parent->left = child;
      else
        parent->right = child;
    }
    free(node->pair);
    free(node);
  }
  // Caso 4: El nodo tiene tanto un hijo izquierdo como un hijo derecho
  else {
    TreeNode *successor = minimum(node->right);
    node->pair->key = successor->pair->key;
    node->pair->value = successor->pair->value;
    RemoveNode(tree, successor);
  }
}

void eraseTreeMap(TreeMap *tree) {
  if (tree == NULL || tree->root == NULL)
    return;

  TreeNode *node = tree->current;
  if (node == NULL)
    return;

  RemoveNode(tree, node);
}

void* firstTreeMap(TreeMap *tree) {
  if (tree == NULL || tree->root == NULL)
    return NULL;

  // Encontrar el nodo más pequeño (el nodo izquierdo más profundo)
  TreeNode *currentNode = minimum(tree->root);

  tree->current = currentNode;  // Establecer el nodo actual en el nodo más pequeño
  return currentNode->pair->value;
}

void* nextTreeMap(TreeMap *tree) {
  if (tree == NULL || tree->current == NULL)
    return NULL;

  TreeNode *currentNode = tree->current;

  // Si el nodo tiene un hijo derecho, el siguiente valor es el nodo más pequeño en el subárbol derecho
  if (currentNode->right != NULL) {
    currentNode = minimum(currentNode->right);
    tree->current = currentNode;  // Actualizar el nodo actual
    return currentNode->pair->value;
  }

  // Si el nodo no tiene un hijo derecho, se busca el primer ancestro mayor
  TreeNode *parent = currentNode->parent;
  while (parent != NULL && currentNode == parent->right) {
    currentNode = parent;
    parent = parent->parent;
  }

  tree->current = parent;  // Actualizar el nodo actual
  if (parent != NULL)
    return parent->pair->value;
  else
    return NULL;

  
}
