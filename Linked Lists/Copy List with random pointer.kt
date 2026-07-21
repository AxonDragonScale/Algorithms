// https://leetcode.com/problems/copy-list-with-random-pointer?envType=study-plan-v2&envId=top-interview-150
// A linked list of length n is given such that each node contains an additional random pointer, which could point to any node in the list, or null.
// Construct a deep copy of the list. The deep copy should consist of exactly n brand new nodes, where each new node has its value set to the value of its corresponding original node.
// Both the next and random pointer of the new nodes should point to new nodes in the copied list such that the pointers in the original list and copied list represent the same list state.
// None of the pointers in the new list should point to nodes in the original list.

// For example, if there are two nodes X and Y in the original list, where X.random --> Y, then for the corresponding two nodes x and y in the copied list, x.random --> y.
// Return the head of the copied linked list.

fun copyRandomList(head: Node?): Node? {
    if (head == null) return null

    var cur: Node? = head
    var next: Node? = null

    // Insert copies after the original
    // A -> B -> C becomes A -> a -> B -> b -> C -> c
    while (cur != null) {
        next = cur?.next
        cur?.next = Node(cur.`val`)
        cur?.next?.next = next

        cur = next
    }

    // Set up random pointer of the copies
    // a.random = A.random.next
    cur = head
    while (cur != null) {
        cur?.next?.random = cur?.random?.next

        cur = cur?.next?.nex
    }

    // Break list: A -> a -> B -> b -> C -> c becomes A -> B -> C and a -> b -> c
    cur = head
    next = null
    val copyHead = cur?.next
    var copy: Node? = null
    while (cur != null) {
        next = cur?.next?.next
        copy = cur?.next

        cur?.next = next
        copy?.next = next?.next

        cur = next
    }


    return copyHead
}
