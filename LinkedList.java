public class LinkedList {
  
  static ListNode head;
  
  public LinkedList(ListNode node){
    head = node;
  }
  
  void addNode(ListNode node){
    ListNode head = this.head;
    
    while(head.next != null){
      head = head.next;
    }
    head.next = node;
  }
  
  void addNode(int data_in){
    ListNode head = this.head;
    ListNode node = new ListNode(data_in);
    
    while(head.next != null){
      head = head.next; 
    }
    head.next = node;
  }
  
  ListNode removeNode(ListNode node){
   ListNode head = this.head;
   if(head == node){
     return head.next;
   }
   while(head.next != null){
     if(head.next == node){
       head.next = head.next.next;
       return head;

     }
    head = head.next; 
  }
   return null;
 }
  
 ListNode removeNode(int rmData){
   ListNode head = this.head;
   if(head.data == rmData){
     return head.next;
   }
   while(head.next != null){
     if(head.next.data == rmData){
       head.next = head.next.next;
       return head;
     }
    head = head.next; 
  }
   return null;
 }
 
 ListNode reverseList(){   
   if(this.head.next == null){
     return this.head;
   }else{
     ListNode current = this.head;
     ListNode next = null;
     ListNode prev = null;
     while(current != null){
       next = current.next;
       current.next = prev;
       prev = current;
       current = next;
     }
     return prev;
   }
   
 }
 
 void printList(){
  ListNode head = this.head;
  while(head != null){
    System.out.println(head.data + " ");
    head = head.next;
  }
 }
 
 Boolean detectLoop(){
  ListNode slow = this.head;
  ListNode fast = this.head;
  
  while(slow != null && fast != null){
    slow = slow.next;
    
    if(fast.next != null){
      fast = fast.next.next;
    }else{
      return false;
    }
    
    if(fast == slow){
      return true;
    }
    
  }
  return false;
 }
 
 public static void main(String args[]){
   ListNode head = new ListNode(5);
   LinkedList list = new LinkedList(head);
   
   list.addNode(4);
   ListNode newNode = new ListNode(10);
   list.addNode(newNode);
   list.printList();
   
   newNode = list.removeNode(newNode);
   list.printList();
   list.addNode(1);
   list.printList();
   //list.head.next.next.next = list.head.next.next;
   if(list.detectLoop()){
     System.out.println("Loop detected");
   }
   list.head = list.reverseList();
   list.printList();
 }
 
}
