/**
 * Test
 */

import java.util.ArrayList;
import java.util.LinkedList;
import java.util.Queue;

/**
 * InnerTest
 */
class Node {
    int data;
    Node left;
    Node right;
    Node(){}
    Node(int data){
        this.data = data;
    }
}


public class Test {

    public Node trrBuild(int[] arr){ // take array or arraylist
        int n = arr.length;
        if(n == 0 || arr[0] == -1){
            return null;
        }

        Node root = new Node(arr[0]);
        Queue<Node> queue = new LinkedList<>();
        queue.offer(root);

        int idx = 1;
        while(!queue.isEmpty()){
            Node temp = queue.poll();
            if(idx<n && arr[idx]!=-1){
                temp.left = new Node(arr[idx]);
                queue.offer(temp.left);
            }
            idx++;

            if(idx<n && arr[idx] != -1){
                temp.right = new Node(arr[idx]);
                queue.offer(temp.right);
            }

            idx++;

        }

        return root;
    }

    

    public static void main(String[] args) {
        
    }
}