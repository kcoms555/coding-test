def invertTree(self, root: TreeNode) -> TreeNode:
	queue = collections.deque([root])
	while queue:
		node = queue.popleft()
		if not node:
			continue
		node.left, node.right = node.right, node.left
		queue.append(node.left)
		queue.append(node.right)
	return root
