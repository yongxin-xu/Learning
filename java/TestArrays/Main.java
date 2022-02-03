package TestArrays;

public class Main {
  public static void main(String[] args) {
    // Declare arrays
    String[] cars = {"Volvo", "BMW", "Ford", "Mazda"};
    int[] myNum = {10, 20, 30, 40};

    // Access an element
    System.out.println(cars[0]);

    // Change an element
    cars[2] = "Audi"; 
    
    // Get the size of the array
    System.out.println("Size of the cars array is " + cars.length);

    // Loop through an array
    for (int i = 0; i < cars.length; i++) {
      System.out.println("Array element No. " + i + " is " + cars[i]);
    }
    // A second way to loop through
    for (int num : myNum) {
      System.out.println(num);
    }

    // Multi-dimension arrays
    int[][] myNumbers = { {1, 2, 3, 4}, {5, 6, 7} };
    int x = myNumbers[1][2];
    System.out.println(x); // Outputs 7

    for (int i = 0; i < myNumbers.length; ++i) {
      for(int j = 0; j < myNumbers[i].length; ++j) {
        System.out.println(myNumbers[i][j]);
      }
    }
  }
}
