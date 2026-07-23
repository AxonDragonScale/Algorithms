// https://leetcode.com/problems/flatten-binary-tree-to-linked-list?envType=study-plan-v2&envId=top-interview-150

// Given the root of a binary tree, flatten the tree into a "linked list":
//     The "linked list" should use the same TreeNode class where the right child pointer points to the next node in the list and the left child pointer is always null.
//     The "linked list" should be in the same order as a pre-order traversal of the binary tree.

// Approach 1: Use recursive flatten1. It returns the end of the flattened list.
// For a node, flatten the left and right. Move right to the end of left. Remove left and move it to right.
fun flatten(root: TreeNode?): Unit {
    flatten1(root)
}

fun flatten1(root: TreeNode?): TreeNode? {
    if (root == null) return null
    if (root.left == null && root.right == null) return root

    if (root.left == null) return flatten1(root.right)

    if (root.right == null) {
        val flattenedLeftEnd = flatten1(root.left)
        root.right = root.left
        root.left = null
        return flattenedLeftEnd
    }

    val flattenedLeftEnd = flatten1(root.left)
    val flattenedRightEnd = flatten1(root.right)

    val tempRight = root.right
    root.right = root.left
    root.left = null
    flattenedLeftEnd?.right = tempRight
    return flattenedRightEnd
}


// Approach 2
var prev: TreeNode? = null  // global var

fun flatten(root: TreeNode?): Unit {
    if (root == null) return

    flatten(root.right)
    flatten(root.left)

    root.right = prev
    root.left = null

    prev = root
}


// Approach 3
fun flatten(root: TreeNode?): Unit {
    var cur = root
    var leftEnd = root
    while (cur != null) {
        if (cur.left != null) {
            leftEnd = cur.left
            while (leftEnd?.right != null)  // If left node exists, then after flattening, its end would be its right most node.
                leftEnd = leftEnd.right

            leftEnd?.right = cur.right
            cur.right = cur.left
            cur.left = null
        }
        cur = cur.right
    }
}
