

import junit.framework.TestCase;

//You can use this as a skeleton for your 3 different test approach
//It is an optional to use this file, you can generate your own test file(s) to test the target function!
// Again, it is up to you to use this file or not!



public class UrlValidatorTest extends TestCase {


   public UrlValidatorTest(String testName) {
      super(testName);
   }



   public void testManualTest()
   {
	   UrlValidator validator = new UrlValidator();
	   assertFalse(validator.isValid(""));
	   assertTrue(validator.isValid("https://www.google.com"));
	   assertFalse(validator.isValid("https://www.google.com../"));
	   assertFalse(validator.isValid("https://www.google.invalid"));
   }


   public void testYourFirstPartition()
   {
         //You can use this function to implement your First Partition testing
	   UrlValidator validator = new UrlValidator();
	   String result;
	   String pool = "abcdefghijklmnopqrstuvwxyz"
			   		 + "ABCDEFGHIJKLMNOPQRSTUVWXYZ"
			   		 + "0123456789"
			   		 + "./_~?#[]@,:;=+*()$&-"
			   		 + "` ";
	   int i=0;
	   while(i<1000) {
		   StringBuilder sb = new StringBuilder(10);
		   for(int j=0;j<10;j++) {
			   int index=(int)(pool.length() * Math.random());
			   sb.append(pool.charAt(index));
		   }
		   result = sb.toString();
		   assertFalse(validator.isValid(result));
	   }
   }

   public void testYourSecondPartition(){
	   UrlValidator validator = new UrlValidator();
	   String result;
	   String https;
	   String name1;
	   String name2;
	   String pool = "ABCEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789"
			   		+ "._~?#[]@,;=+*()$&-` ";
	   int i=0;
	   while(i<10000) {
		   StringBuilder http = new StringBuilder(4);
		   for(int j=0;j<4;j++) {
			   int index=(int)(pool.length() * Math.random());
			   http.append(pool.charAt(index));
		   }
		   https = http.toString();
		   StringBuilder name = new StringBuilder(10);
		   for(int j=0;j<10;j++) {
			   int index=(int)(pool.length() * Math.random());
			   name.append(pool.charAt(index));
		   }
		   name1 = name.toString();
		   StringBuilder names = new StringBuilder(5);
		   for(int j=0;j<5;j++) {
			   int index=(int)(pool.length() * Math.random());
			   names.append(pool.charAt(index));
		   }
		   name2 = names.toString();
		   result = https + "://" + name1 + "/" name2;
		   System.out.println("Testing " + result);
		   if(validator.isValid(result)==true) {
			   System.out.println("Test succeeded!");
		   }
		   else {
			   System.out.println("Test failed.");
		   }
	   }
   }
   //You need to create more test cases for your Partitions if you need to

   public void testIsValid()
   {
	   UrlValidator validator = new UrlValidator();
	   System.out.println("Testing that null returns false: ");
	   assertFalse(validator.isValid(""));
	   System.out.println("Test succeeded!");
	   System.out.println("Testing schemes that should return false: ");
	   assertFalse(validator.isValid("ftp://www.google.com"));
	   System.out.println("Test succeeded!");
	   System.out.println("Testing for file with trailing : should return false: ");
	   assertFalse(validator.isValid("file://host/path:"));
	   System.out.println("Test succeeded!");
	   System.out.println("Testing for invalid fragment url: ");
	   assertFalse(validator.isValid("https://www.google.com#"));
	   System.out.println("Test succeeded!");
	   System.out.println("Testing for invalid query url: ");
	   assertFalse(validator.isValid("https://www.google.com&"));
	   System.out.println("Test succeeded!");
	   System.out.println("Testing for invalid path url: ");
	   assertFalse(validator.isValid("https://www.google.com/../"));
	   System.out.println("Test succeeded!");
	   System.out.println("Testing using valid link that should return true: ");
	   assertTrue(validator.isValid("https://www.google.com"));
	   System.out.println("Test succeeded!");

   }
}
