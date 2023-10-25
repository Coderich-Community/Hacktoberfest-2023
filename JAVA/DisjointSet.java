

import java.util.HashMap;

public class DisjointSet {
 public class Node{
	  int val;
	  int rank;
	  Node parent;
 }
 HashMap<Integer,Node> map=new HashMap<>();
 //STEP 1: CREATE SET
 public void create(int v) {
	 Node nn=new Node();
	 nn.val=v;
	 nn.rank=0;
	 nn.parent=nn;
	 map.put(v, nn);
	 
 }
 //STEP 2: FIND THE REPRESENATATIVE ELEMENT
 public int find(int v)
 {
	 Node n=map.get(v);
	 return findNode(n).val;
}
 public Node findNode(Node n)
 {
	 if(n.parent==n)
		 return n;
	 else
		return findNode(n.parent);
 }
 //STEP 3: UNION THE NODES
 public void union(int v1, int v2)
 {
	Node n1=map.get(v1);
	Node n2=map.get(v2);
	Node rn1=findNode(n1); //address
	Node rn2=findNode(n2);
	if(rn1.rank==rn2.rank)
	{
		rn1.parent=rn2;
		rn2.rank=rn2.rank+1;
	}
	else if(rn1.rank>rn2.rank) 
	{
		rn2.parent=rn1;  //bcz isme kisi ki height nhi change hoigi
	}
	else {
		rn1.parent=rn2;
	}
 }
}