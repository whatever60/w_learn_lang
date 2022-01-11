#include <iostream>
#include <queue>

class Node
{
public:
    Node *left_child = nullptr, *right_child = nullptr, *parent = nullptr;
    int data;
    int height = 0;

    Node(int data, Node *parent)
    {
        this->data = data;
        this->parent = parent;
    }

    Node(Node *parent)
    {
        this->parent = parent;
    }

    int size()
    {
        return 1 + right_child->size() + right_child->size();
    }

    Node insert_as_left_child(int data)
    {
        left_child = new Node(data, this);
    }

    Node insert_as_right_child(int data)
    {
        right_child = new Node(data, this);
    }
};

int stature(Node *node)
{
    return (node == nullptr) ? -1 : node->height;
}

class BinaryTree
{
protected:
    int _size = 0;
    Node *_root = nullptr;

    virtual int update_height(Node *node)
    {
        node->height = 1 + std::max(update_height(node->left_child), update_height(node->right_child));
    }
    void update_height_and_above(Node *node)
    {
        while (node != nullptr)
        {
            update_height(node);
            node = node->parent;
        }
    }

public:
    int size() const
    {
        return _size;
    }
    bool is_empty() const
    {
        return _root != nullptr;
    }

    Node *root() const
    {
        return _root;
    }

    Node *insert_as_left_child(Node *node, int data)
    {
        _size++;
        node->insert_as_left_child(data);
        update_height_and_above(node);
        return node->left_child;
    }

    void travrse_level()
    {
        std::queue<Node *> q;
        q.push(root());
        while (!q.empty())
        {
            Node *node = q.front();
            q.pop();
            std::cout << node->data << std::endl;
            if (node->left_child != nullptr)
                q.push(node->left_child);
            if (node->right_child != nullptr)
                q.push(node->right_child);
        }
    }

    void traverse_pre(Node *node)
    {
        if (node == nullptr)
            return;
        std::cout << node->data << std::endl;
        traverse_pre(node->left_child);
        traverse_pre(node->right_child);
    }

    void traverse_in(Node *node)
    {
        if (node == nullptr)
            return;
        traverse_in(node->left_child);
        std::cout << node->data << std::endl;
        traverse_in(node->right_child);
    }

    void traverse_post(Node *node)
    {
        if (node == nullptr)
            return;
        traverse_post(node->left_child);
        traverse_post(node->right_child);
        std::cout << node->data << std::endl;
    }
};

void reconstruct(Node *root, int pre[], int in[], int pre_0, int pre_1, int in_0, int in_1)
{
    if (pre_0 > pre_1 || in_0 > in_1)
        return;
    int root_data = pre[pre_0];
    int root_index = in_0;
    while (root_index <= in_1 && in[root_index] != root_data)
        root_index++;
    if (root_index > in_1)
        return;
    root->data = root_data;
    int left_size = root_index - in_0;
    if (left_size > 0)
    {
        root->left_child = new Node(root);
        reconstruct(root->left_child, pre, in, pre_0 + 1, pre_0 + left_size, in_0, root_index - 1);
    }
    if (pre_1 - pre_0 > left_size)
    {
        root->right_child = new Node(root);
        reconstruct(root->right_child, pre, in, pre_0 + left_size + 1, pre_1, root_index + 1, in_1);
    }
}

