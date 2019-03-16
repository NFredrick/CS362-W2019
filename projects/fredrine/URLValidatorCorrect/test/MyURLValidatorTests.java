import org.junit.Test;

import junit.framework.TestCase;

public class MyURLValidatorTests extends TestCase {
	
	public UrlValidator setup() {
		return UrlValidator.getInstance();
	}
	
	@Test
	public void testIsValid1() {
		UrlValidator urlValidator = setup();
		String url = "http://www.google.com";
		assertTrue(urlValidator.isValid(url));
	}
	
	@Test
	public void testIsValid2() {
		UrlValidator urlValidator = setup();
		String url = "https://www.google.com";
		assertTrue(urlValidator.isValid(url));
	}
	
	@Test
	public void testIsValid3() {
		UrlValidator urlValidator = setup();
		String url = "http://www.wikipedia.org";
		assertTrue(urlValidator.isValid(url));
	}
	
	@Test
	public void testIsValid4() {
		UrlValidator urlValidator = setup();
		String url = "https://www.wikipedia.org";
		assertTrue(urlValidator.isValid(url));
	}
	
	@Test
	public void testIsValid5() {
		UrlValidator urlValidator = setup();
		String url = "http://www.google.com/search?q=test+search";
		assertTrue(urlValidator.isValid(url));
	}
	
	@Test
	public void testIsValid6() {
		UrlValidator urlValidator = setup();
		String url = "https://www.google.com/search?q=test+search";
		assertTrue(urlValidator.isValid(url));
	}
	
	@Test
	public void testIsValid7() {
		UrlValidator urlValidator = setup();
		String url = "ftp://access.engr.oregonstate.edu";
		assertTrue(urlValidator.isValid(url));
	}
	
	@Test
	public void testIsValid8() {
		UrlValidator urlValidator = setup();
		String url = "ftp://access.engr.oregonstate.edu";
		assertTrue(urlValidator.isValid(url));
	}
	
	@Test
	public void testIsValid9() {
		UrlValidator urlValidator = setup();
		String url = "html://www.google.com";
		assertTrue(urlValidator.isValid(url) == false);
	}
	
	@Test
	public void testIsValid10() {
		UrlValidator urlValidator = setup();
		String url = "http:/www.google.com";
		assertTrue(urlValidator.isValid(url) == false);
	}
	
	
	
	
	/*
	 * "https://github.com/NFredrick/FinalProject",
				"https://www.google.com/search?q=test+search",
				"http://www.seattle.gov",
				"ftp://access.engr.oregonstate.edu",
				"https://www.google.com/search?q=test+search&oq=test+search8&sourceid=chrome&ie=UTF-8"
	 * 
	 */
}
