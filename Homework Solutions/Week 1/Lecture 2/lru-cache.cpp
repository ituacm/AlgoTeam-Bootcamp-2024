// Author: Fatih Baskın
// Question Link: https://leetcode.com/problems/lru-cache/

class LinkedListNode
{
public:
    // Node holds the key-value and pointers to the next and previous nodes.
    int value;
    int key;
    LinkedListNode *next;
    LinkedListNode *prev;

    // Constructor
    LinkedListNode(int key, int value)
    {
        // Set the key and value of the node.
        this->key = key;
        this->value = value;
        // Set the next and prev pointers to NULL.
        this->next = NULL;
        this->prev = NULL;
    }

    // Add a node after this node
    void addNext(LinkedListNode *node)
    {
        // Skip if the node is NULL.
        if (node == NULL)
            return;

        // You should preserve the current next node.
        LinkedListNode *temp = this->next;

        // Connect the current node to the new node.
        this->next = node;
        // Connect the new node in between current node and previous next node.
        node->prev = this;
        node->next = temp;
        // Check if the previous next node is NULL, connect previous next node to the new node.
        if (temp != NULL)
            temp->prev = node;
    }

    // Add a node before this node
    void addPrev(LinkedListNode *node)
    {
        // Skip if the node is NULL.
        if (node == NULL)
            return;

        // You should preserve the current previous node.
        LinkedListNode *temp = this->prev;

        // Connect the current node to the new node.
        this->prev = node;
        // Connect the new node in between current node and previous previous node.
        node->next = this;
        node->prev = temp;
        // Check if the previous previous node is NULL, connect previous previous node to the new node.
        if (temp != NULL)
            temp->next = node;
    }

    // Remove this node from the list
    void remove()
    {
        // Connect the previous and next nodes to each other.
        if (this->prev != NULL)
            this->prev->next = this->next;
        if (this->next != NULL)
            this->next->prev = this->prev;
        this->next = NULL;
        this->prev = NULL;
    }

    // Destructor
    ~LinkedListNode()
    {
        // For debugging purposes, print a message when the node is deleted.
        // cout << "Node with key " << this->key << " and value " << this->value << " is deleted." << endl;
    }
};

class LinkedList
{
public:
    // Constructor with no arguments
    LinkedList()
    {
        this->head = NULL;
        this->tail = NULL;
    }
    // Add a node to the tail of the list
    void enqueue(LinkedListNode *node)
    {
        // If the tail is NULL, the list is empty.
        if (this->tail == NULL)
        {
            // Set the head and tail to the new node.
            this->head = node;
            this->tail = node;
        }
        else
        {
            // Add the new node to the tail.
            this->tail->addNext(node);
            // Update the tail.
            this->tail = node;
        }
    }

    // Remove the last node from the list
    LinkedListNode *dequeue()
    {
        // If the head is NULL, the list is empty.
        if (this->head == NULL)
            return NULL;

        // Get the head node.
        LinkedListNode *node = this->head;
        // Remove the head node from the list.
        this->head = this->head->next;
        // If the head is NULL, the list is empty.
        if (this->head == NULL)
            this->tail = NULL;
        else
            // If the head is not NULL, set the previous pointer of the new head to NULL.
            this->head->prev = NULL;
        // Return the removed node.
        return node;
    }

    // Remove a node from the list
    void remove(LinkedListNode *node)
    {
        // If the node is NULL, return.
        if (node == NULL)
            return;

        // If the node is the head, remove the head.
        if (node == this->head)
        {
            this->dequeue();
            return;
        }

        // If the node is the tail, remove the tail.
        if (node == this->tail)
        {
            // If the tail is the head, set the head and tail to NULL.
            if (this->tail == this->head)
            {
                this->head = NULL;
                this->tail = NULL;
                return;
            }
            // Otherwise, update the tail.
            this->tail = this->tail->prev;
            this->tail->next = NULL;
            return;
        }

        // Remove the node from the list.
        node->remove();
    }

    // Destructor
    ~LinkedList()
    {
        // Remove all nodes from the list.
        while (this->head != NULL)
        {
            LinkedListNode *node = this->head;
            this->head = this->head->next;
            delete node;
        }
    }

private:
    LinkedListNode *head;
    LinkedListNode *tail;
};

class LRUCache
{
public:
    LRUCache(int capacity)
    {
        this->cap = capacity;
        this->size = 0;
    }

    int get(int key)
    {
        // If the key is not in the cache, return -1.
        if (this->cache.find(key) == this->cache.end())
            return -1;

        // Get the node from the cache.
        LinkedListNode *node = this->cache[key];
        // Remove the node from the queue.
        this->queue.remove(node);
        // Add the node to the tail of the queue.
        this->queue.enqueue(node);
        // Return the value of the node.
        return node->value;
    }

    void put(int key, int value)
    {
        // If the key is already in the cache, update the value.
        if (this->cache.find(key) != this->cache.end())
        {
            // Get the node from the cache.
            LinkedListNode *node = this->cache[key];
            // Update the value of the node.
            node->value = value;
            // Remove the node from the queue.
            this->queue.remove(node);
            // Add the node to the tail of the queue.
            this->queue.enqueue(node);
            return;
        }

        // If the cache is full, remove the least recently used node.
        if (this->size == this->cap)
        {
            // Remove the least recently used node from the queue.
            LinkedListNode *node = this->queue.dequeue();
            // Remove the node from the cache.
            this->cache.erase(node->key);
            // Delete the node.
            delete node;
            // Decrease the size of the cache.
            this->size--;
        }

        // Create a new node.
        LinkedListNode *node = new LinkedListNode(key, value);
        // Add the node to the tail of the queue.
        this->queue.enqueue(node);
        // Add the node to the cache.
        this->cache[key] = node;
        // Increase the size of the cache.
        this->size++;
    }

private:
    int cap;
    int size;
    unordered_map<int, LinkedListNode *> cache;
    // The linked list is used to keep the order of the keys, this will be used like a queue.
    LinkedList queue;
};
