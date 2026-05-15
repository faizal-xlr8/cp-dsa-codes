   int left = findLevel (root -> left, target, level + 1);
     if (left == - 1)
     return findLevel(root -> right, target, level + 1);
     return left;