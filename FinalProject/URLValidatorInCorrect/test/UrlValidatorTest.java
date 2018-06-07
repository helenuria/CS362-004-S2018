

import junit.framework.TestCase;

//You can use this as a skeleton for your 3 different test approach
//It is an optional to use this file, you can generate your own test file(s) to test the target function!
// Again, it is up to you to use this file or not!

public class UrlValidatorTest extends TestCase {


   public void UrlValidatorTest(boolean retVal, boolean expectVal) {
      if (retVal == expectVal) {
		  System.out.print("Test Passed\n");
	  } else {
		  System.out.print("Test Failed\n");
	  }
   }
   
   public void testManualTest()
   {
	   //You can use this function to implement your manual testing	   
	   UrlValidator urlVal = new UrlValidator();

	   System.out.print("\nScheme is http, expect true:\n");
	   UrlValidatorTest(urlVal.isValid("http://facebook.com"), true);
	   
	   System.out.print("\nScheme is ftp, expect true:\n");
	   UrlValidatorTest(urlVal.isValid("ftp://facebook.com"), true);

	   System.out.print("\nScheme is incorrect, expect false:\n");
	   UrlValidatorTest(urlVal.isValid("http//facebook.com"), false);

	   System.out.print("\nNo scheme, expect true:\n");
	   UrlValidatorTest(urlVal.isValid("facebook.com"), true);

	   System.out.print("\nAuthority is valid, expect true:\n");
	   UrlValidatorTest(urlVal.isValid("www.foobar.com"), true);

	   System.out.print("\nAuthority is invalid, expect false:\n");
	   UrlValidatorTest(urlVal.isValid("www.foo.bar.com"), false);
	   
	   System.out.print("\nNo authority, expect false:\n");
	   UrlValidatorTest(urlVal.isValid("www..com"), false);

	   System.out.print("\nPort is valid, expect true:\n");
	   UrlValidatorTest(urlVal.isValid("www.foobar.com:80"), true);

	   System.out.print("\nPort is invalid, expect false:\n");
	   UrlValidatorTest(urlVal.isValid("www.foobar.com:-5"), false);
	   
	   System.out.print("\nNo Port, expect true:\n");
	   UrlValidatorTest(urlVal.isValid("www.foobar.com"), true);

	   System.out.print("\nPath is valid, expect true:\n");
	   UrlValidatorTest(urlVal.isValid("www.foobar.com/test"), true);

	   System.out.print("\nPath is invalid, expect false:\n");
	   UrlValidatorTest(urlVal.isValid("www.foobar.com/test//test"), false);

	   System.out.print("\nNo Path, expect true:\n");
	   UrlValidatorTest(urlVal.isValid("www.foobar.com"), true);

	   System.out.print("\nQuery is valid, expect true:\n");
	   UrlValidatorTest(urlVal.isValid("www.foobar.com?test=true"), true);

	   System.out.print("\nQuery is invalid, expect false:\n");
	   UrlValidatorTest(urlVal.isValid("www.foobar.com??query"), false);
	   
	   System.out.print("\nNo query, expect true:\n");
	   UrlValidatorTest(urlVal.isValid("www.foobar.com"), true);
	   
   }
   
   
   public void testYourFirstPartition()
   {
	 UrlValidator urlVal = new UrlValidator();

	 // input is invalid
	 
	 // invalid scheme
	 System.out.print("\nScheme is incorrect, expect false:\n");
	 UrlValidatorTest(urlVal.isValid("http//testcase.com"), false);

	 // invalid authourity
	 System.out.print("\nAuthority is incorrect, expect false:\n");
	 UrlValidatorTest(urlVal.isValid("www.test.case.com"), false);

	 // invalid port
	 System.out.print("\nPort is invalid, expect false:\n");
	 UrlValidatorTest(urlVal.isValid("www.testcase.com:-5"), false);

	 // invalid path
	 System.out.print("\nPath is invalid, expect false:\n");
	 UrlValidatorTest(urlVal.isValid("www.testcase.com/test//test"), false);

	 // invaid query
	 System.out.print("\nQuery is invalid, expect false:\n");
	 UrlValidatorTest(urlVal.isValid("www.testcase.com??query"), false);

   }
   
   public void testYourSecondPartition(){
	   // input is null
	   
	   // null scheme
	   System.out.print("\nNo scheme, expect true:\n");
	   UrlValidatorTest(urlVal.isValid("www.testcase.com"), true);

	   // null authourity
	   System.out.print("\nNo authority, expect false:\n");
	   UrlValidatorTest(urlVal.isValid("www..com"), false);

	   // null port
	   System.out.print("\nNo Port, expect true:\n");
	   UrlValidatorTest(urlVal.isValid("www.testcase.com"), true);

	   // null path
	   System.out.print("\nNo Path, expect true:\n");
	   UrlValidatorTest(urlVal.isValid("www.testcase.com"), true);
	   
	   // null query
	   System.out.print("\nNo query, expect true:\n");
	   UrlValidatorTest(urlVal.isValid("www.testcase.com"), true);

   }

   public void testYourThirdPartition(){
	   // input is valid
	   
	   // valid scheme
	   System.out.print("\nScheme is http, expect true:\n");
	   UrlValidatorTest(urlVal.isValid("http://www.testcase.com"), true);
	   
	   // valid authourity
	   System.out.print("\nAuthority is valid, expect true:\n");
	   UrlValidatorTest(urlVal.isValid("www.testcase.com"), true);

	   // valid port
	   System.out.print("\nPort is valid, expect true:\n");
	   UrlValidatorTest(urlVal.isValid("www.testcase.com:80"), true);

	   // valid path
	   System.out.print("\nPath is valid, expect true:\n");
	   UrlValidatorTest(urlVal.isValid("www.testcase.com/test"), true);

	   // valid query
	   System.out.print("\nQuery is valid, expect true:\n");
	   UrlValidatorTest(urlVal.isValid("www.testcase.com?test=true"), true);

   }
   
   public void testIsValid()
   {
	   //You can use this function for programming based testing

   }
   


}
