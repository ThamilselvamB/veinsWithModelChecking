public class JNITest1 {
     private static int magic_counter=777;

     public static void main(String args[]) {   // <=== We will call this 
         System.out.println("Hello, World in java from cpp or changed");
         System.out.println(magic_counter);
         contentChange();
     }
     
     public static void contentChange(){
     int changeCon = 1234 ;
     System.out.println(changeCon);
     }
}
