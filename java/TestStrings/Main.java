package TestStrings;

public class Main {
   public static void main(String[] args) {
     String greeting = "Hello";
     System.out.println(greeting);
     System.out.println("The length of the greeting is " + greeting.length());

     String txt = "Hello World";
     System.out.println(txt.toLowerCase());
     System.out.println(txt.toUpperCase());

     String txt2 = "Please locate where 'locate' occurs!";
     System.out.println(txt2.indexOf("locate")); // Outputs 7

     String firstName = "John";
     String lastName = "Doe";
     System.out.println(firstName.concat(lastName)); // No space between two strings
     System.out.println(firstName + " " + lastName);
   }
}
