import org.junit.Test;

import junit.framework.TestCase;

public class MyURLValidatorTests extends TestCase {

	@Test
	public void testIsValid() {
		UrlValidator urlValidator = UrlValidator.getInstance();
		
		String urls[] = {"http://google.com",
				"https://github.com/NFredrick/FinalProject",
				"https://www.google.com/search?q=test+search",
				"http://www.seattle.gov",
				"ftp://access.engr.oregonstate.edu",
				"https://www.google.com/search?q=test+search&oq=test+search8&sourceid=chrome&ie=UTF-8"
		};
		for (String url: urls)
			assertTrue(urlValidator.isValid(url));
	}
	
	
}
