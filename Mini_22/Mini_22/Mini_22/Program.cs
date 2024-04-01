void test1() {
    var t1 = new TreeNode(1);
    var t2 = new TreeNode(3);
    var t3 = new TreeNode(11);
    var t4 = new TreeNode(5);
    var t5 = new TreeNode(15);
    var t6 = new TreeNode(13);
    t1.left = t2;
    t1.right = t3;
    t2.left = t4;
    t3.left = t5;
    t3.right = t6;
    t3.right = t6;

    //var r = Codec.serialize(t1);
    //var r2 = Codec.deserialize(r);
}


public class TreeNode {
      public int val;
      public TreeNode left;
      public TreeNode right;
      public TreeNode(int x) { val = x; }
  }

  public class Codec {

      // Encodes a tree to a single string.
      public string serialize(TreeNode root) {
          string test = serializeRecurse(root) ?? throw new Exception("Error");
          return test;
      }
      
      private static string? serializeRecurse(TreeNode? root) {
          if (root != null) {
              var left = serializeRecurse(root.left);
              var right = serializeRecurse(root.right);
              var answer = ("(" + root.val);
              answer += left ?? "(X)";
              answer += right ?? "(X)";
              answer += ")";
              return answer;
          }
          else {
              return null;
          }
      }
      
      public TreeNode deserialize(string data) {
          return deserializeRecurse(data);
      }
      
      private static TreeNode? deserializeRecurse(string data) {
          if (data == "(X)") {
              return null;
          }
          else {
              int indexBrects = 1;
              string value = "";
              string left = "";
              string right = "";
              bool readLeft = true;
              for (int i = 1; i < data.Length; i++) {
                  if (left != "" && indexBrects == 1) {
                      readLeft = false;
                  }

                  if (data[i] == '(') indexBrects++;
                  if (indexBrects == 1 && data[i] != ')') {
                      value += data[i];
                  }

                  if (indexBrects >= 2 && readLeft == true) {
                      left += data[i];
                  }

                  if (indexBrects >= 2 && readLeft == false) {
                      right += data[i];
                  }

                  if (data[i] == ')') indexBrects--;
              }

              TreeNode root = new TreeNode(Convert.ToInt32(value));
              root.left = deserializeRecurse(left);
              root.right = deserializeRecurse(right);
              return root;
          }
      }
  }

public class Solution {
    public IList<int> RightSideView(TreeNode root) {
        List<int> answer =  new List<int>(); 
        TreeNode nowTree = root;
        while(nowTree!= null){
            answer.Add(nowTree.val);
            answer = answer.right;
        }

        return answer;
    }
}


