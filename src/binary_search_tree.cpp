#include "assignment/binary_search_tree.hpp"

namespace assignment {

  BinarySearchTree::~BinarySearchTree() {
    BinarySearchTree::Clear();
  }

  void BinarySearchTree::Insert(int key, int value) {
    if (root_ == nullptr) {
      root_ = new Node(key, value);
    } else {
      insert(key, value, root_);
    }
  }

  bool BinarySearchTree::Remove(int key) {
    return remove(key, root_);
  }

  void BinarySearchTree::Clear() {
    clear(root_);
    root_ = nullptr;
  }

  std::optional<int> BinarySearchTree::Find(int key) const {
    Node* node = find(key, root_);
    if (node != nullptr) {
      return node->value;
    } else {
      return std::nullopt;
    }
  }

  bool BinarySearchTree::Contains(int key) const {
    return find(key, root_) != nullptr;
  }

  bool BinarySearchTree::IsEmpty() const {
    return root_ == nullptr;
  }

  std::optional<int> BinarySearchTree::FindMin() const {
    if (root_ == nullptr) {
      return std::nullopt;
    } else {
      return find_min(root_)->key;
    }
  }

  std::optional<int> BinarySearchTree::FindMax() const {
    if (root_ == nullptr) {
      return std::nullopt;
    } else {
      return find_max(root_)->key;
    }
  }

  Node* BinarySearchTree::root() const {
    return root_;
  }

  // вспомогательные методы

  void BinarySearchTree::insert(int key, int value, Node*& node) {
    if (node == nullptr) {
      Node* newNode = new Node(key, value);
      node = newNode;
      node->right = node->left = nullptr;
    } else {
      if (node->key == key) {
        node->value = value;
      } else if (node->key < key) {
        insert(key, value, node->right);
      } else if (node->key > key) {
        insert(key, value, node->left);
      }
    }
  }

  bool BinarySearchTree::remove(int key, Node*& node) {
    return false;
  }

  void BinarySearchTree::clear(Node* node) {
    if (node == nullptr) {
      return;
    }
    clear(node->left);
    clear(node->right);
    delete node;
  }

  Node* BinarySearchTree::find(int key, Node* node) const {
    if (node == nullptr) {
      return nullptr;
    } else if (node->key > key) {
      return find(key, node->left);
    } else if (node->key < key) {
      return find(key, node->right);
    } else {
      return node;
    }
  }

  Node* BinarySearchTree::find_min(Node* node) const {
    if (node == nullptr) {
      return nullptr;
    } else if (node->left == nullptr) {
      return node;
    } else {
      return find_min(node->left);
    }
  }

  Node* BinarySearchTree::find_max(Node* node) const {
    if (node == nullptr) {
      return nullptr;
    } else if (node->right == nullptr) {
      return node;
    } else {
      return find_max(node->right);
    }
  }

}  // namespace assignment