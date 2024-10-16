#include <gtest/gtest.h>
#include "LinkedList.cpp"

// Case 1: Instantiate an Empty List
TEST(LinkedListTest, InstantiateEmptyList)
{
    LinkedList<int> llist;

    ASSERT_EQ(llist.head(), nullptr);
    ASSERT_EQ(llist.tail(), nullptr);
    ASSERT_EQ(llist.size(), 0);
}

// Case 2: Instantiate from a Vector
TEST(LinkedListTest, InstantiateFromVector)
{
    LinkedList<int> llist(std::vector<int>{17, 19, 23});

    ASSERT_EQ(llist.size(), 3);

    LinkedListNode<int> *node = llist.head();
    ASSERT_EQ(node->value, 17);
    ASSERT_EQ(node->next()->value, 19);
    ASSERT_EQ(node->next()->next()->value, 23);
    ASSERT_EQ(node->next()->next()->next(), nullptr);
}

// Case 3: Append to an Empty List
TEST(LinkedListTest, AppendToEmptyList)
{
    LinkedList<int> llist;
    LinkedListNode<int> *node = llist.append(17);

    ASSERT_EQ(node, llist.head());
    ASSERT_EQ(node, llist.tail());
    ASSERT_EQ(node->value, 17);
    ASSERT_EQ(node->next(), nullptr);
    ASSERT_EQ(llist.size(), 1);
}

// Case 4: Append to a Non-Empty List
TEST(LinkedListTest, AppendToNonEmptyList)
{
    LinkedList<int> llist;
    LinkedListNode<int> *first = llist.append(17);
    LinkedListNode<int> *second = llist.append(19);

    ASSERT_EQ(first, llist.head());
    ASSERT_EQ(first->value, 17);
    ASSERT_EQ(first->next(), second);

    ASSERT_EQ(second, llist.tail());
    ASSERT_EQ(second->value, 19);
    ASSERT_EQ(second->next(), nullptr);

    ASSERT_EQ(llist.size(), 2);
}

// Case 5: Insert at head
// Append initial nodes, Insert a new value at the head, Assuming there's an insertAtHead method, assert after insertion
TEST(LinkedListTest, InsertAtHead)
{
    LinkedList<int> llist;

    LinkedListNode<int> *first = llist.append(17);
    LinkedListNode<int> *second = llist.append(19);

    ASSERT_EQ(first, llist.head());
    ASSERT_EQ(second, llist.tail());

    llist.insertAtHead(15);

    ASSERT_EQ(llist.head()->value, 15);
    ASSERT_EQ(llist.head()->next(), first);
    ASSERT_EQ(llist.size(), 3);
}

// Case 6: Insert at tail
// This test case verifies that inserting a new value at the tail of a non-empty list
TEST(LinkedListTest, InsertAtTail)
{
    LinkedList<int> llist;

    // Append initial nodes to the list
    llist.append(10);
    llist.append(20);

    // Now the list contains: 10 -> 20
    ASSERT_EQ(llist.size(), 2);
    ASSERT_EQ(llist.head()->value, 10);
    ASSERT_EQ(llist.tail()->value, 20);

    // Insert a new value at the tail
    LinkedListNode<int> *newTailNode = llist.append(30);

    // Verify that the new tail is correctly updated
    ASSERT_EQ(newTailNode, llist.tail());
    ASSERT_EQ(newTailNode->value, 30);
    ASSERT_EQ(llist.size(), 3);

    // Verify the order of the list
    ASSERT_EQ(llist.head()->next()->next(), newTailNode);
    ASSERT_EQ(llist.head()->next()->value, 20);
    ASSERT_EQ(llist.head()->next()->next()->next(), nullptr);
}

// Case 7: Remove from Head
TEST(LinkedListTest, RemoveFromHead)
{
    LinkedList<int> llist;
    llist.append(10);
    llist.append(20);
    llist.append(30);

    ASSERT_EQ(llist.size(), 3);

    LinkedListNode<int> *removedNode = llist.removeFromHead();

    ASSERT_EQ(removedNode->value, 10);
    ASSERT_EQ(llist.size(), 2);
    ASSERT_EQ(llist.head()->value, 20);
    ASSERT_EQ(llist.tail()->value, 30);
    ASSERT_EQ(removedNode->next(), nullptr);

    delete removedNode;
}

// Case 8: Remove from Tail

// Case 9: Remove a Specific Value

// Case 10: Clear the List

// Case 11: Traversal of the List

// Case 12: Handle Removal from an Empty List

// Case 13: Check Size After Multiple Operations

// Case 14: Check Head and Tail After Multiple Operations

// Case 15: Check for Duplicates Handling

// Case 16: Reinserting After Removal