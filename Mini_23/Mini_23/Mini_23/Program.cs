
  void test1() {
      var t1 = new TreeNode(1);
      var t2 = new TreeNode(2);
      var t3 = new TreeNode(3);
      var t4 = new TreeNode(4);
      var t5 = new TreeNode(5);
      t1.left = t2;
      t1.right = t3;
      t2.right = t4;
      t3.right = t5;

      Solution t = new Solution();
      t.RightSideView(t1);
  }

public class TreeNode {
      public int val;
      public TreeNode left;
      public TreeNode right;
      public TreeNode(int val=0, TreeNode left=null, TreeNode right=null) {
          this.val = val;
          this.left = left;
          this.right = right;
      }
  }
 
public class Solution {
    public IList<int> RightSideView(TreeNode root) {
        var answer = RightSideViewRecurse(root);
        return answer;
    }
    public IList<int>? RightSideViewRecurse(TreeNode? root) {
        if (root == null) return null;
        List<int> answer =  new List<int>(); 
        TreeNode nowTree = root;
        var left = RightSideViewRecurse(root.left);
        var right = RightSideViewRecurse(root.right);
        answer.Add(root.right.val);
        if (left == null) return answer;
        foreach (var i in left) {
            answer.Add(i);
        }
        if (right == null) return answer;
        foreach (var i in right) {
            answer.Add(i);
        }
        return answer;
    }
    
    
}
