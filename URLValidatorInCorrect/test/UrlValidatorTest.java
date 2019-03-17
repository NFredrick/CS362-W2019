import junit.framework.TestCase;

import java.util.Random;

public class UrlValidatorTest extends TestCase {

    public UrlValidatorTest(String testName) {
        super(testName);
    }

    public void testIsValid() {
        UrlValidator urlVal = new UrlValidator(null, null, UrlValidator.ALLOW_ALL_SCHEMES);

        Random rand = new Random();

        for (int i = 0; i < 10; i++) {
            int max, min, pos;

            System.out.println("\n-------TESTING RANDOM EXTENSION-------");
            StringBuffer extBuffer = new StringBuffer("http://www.google");

            max = testUrlExt.length - 1;
            min = 0;

            pos = min + rand.nextInt((max - min) + 1);
            extBuffer.append("." + testUrlExt[pos].item);

            if (testUrlExt[pos].valid) {
                if (urlVal.isValid(extBuffer.toString())) {
                    System.out.println("Success: This is a valid URL: " + extBuffer + "");
                }
            } else {
                if (!urlVal.isValid(extBuffer.toString())) {
                    System.out.println("Failure: This is not a valid URL: " + extBuffer + "");
                }
            }

            System.out.println("\n-------TESTING RANDOM IP ADDRESS-------");
            StringBuffer ipBuffer = new StringBuffer("https://");
            int a, b, c, d;

            max = 300;
            min = 0;

            a = min + rand.nextInt((max - min) + 1);
            b = min + rand.nextInt((max - min) + 1);
            c = min + rand.nextInt((max - min) + 1);
            d = min + rand.nextInt((max - min) + 1);
            ipBuffer.append(a + "." + b + "." + c + "." + d);

            if ((a > 255) || (b > 255) || (c > 255) || (d > 255)) {
                System.out.println("Failure: This is not a valid URL: " + ipBuffer + "");
            } else {
                System.out.println("Success: This is a valid URL: " + ipBuffer + "");
            }

            System.out.println("\n-------TESTING RANDOM SCHEME-------");
            StringBuffer schemeBuffer = new StringBuffer("www.google.com");

            max = testUrlScheme.length - 1;
            min = 0;

            pos = min + rand.nextInt((max - min) + 1);
            schemeBuffer.insert(0, testUrlScheme[pos].item);

            if (testUrlScheme[pos].valid) {
                if (urlVal.isValid(schemeBuffer.toString()))
                    System.out.println("Success: This is a valid URL: " + schemeBuffer + "");
            } else {
                if (urlVal.isValid(schemeBuffer.toString()))
                    System.out.println("Failure: This should not be a valid URL: " + schemeBuffer + "");
                else {
                    System.out.println("Failure: This is not a valid URL: " + schemeBuffer + "");
                }
            }

            System.out.println("\n-------TESTING RANDOM PORT-------");
            StringBuffer portBuffer = new StringBuffer("http://www.google.com:");

            int portNumber;
            max = 99999;
            min = -100;

            portNumber = min + rand.nextInt((max - min) + 1);
            portBuffer.append(portNumber);

            if (portNumber >= 0 && portNumber <= 65535) {
                if (urlVal.isValid(portBuffer.toString())) {
                    System.out.println("Success: This is a valid URL: " + portBuffer + "");
                }
            } else {
                System.out.println("Failure: This is not a valid URL " + portBuffer + "");
            }

            System.out.println("\n-------TESTING RANDOM QUERY-------");
            StringBuffer queryBuffer = new StringBuffer("http://www.google.com/");

            max = testUrlQuery.length - 1;
            min = 0;

            pos = min + rand.nextInt((max - min) + 1);
            queryBuffer.append(testUrlQuery[pos].item);

            if (testUrlQuery[pos].valid) {
                if (urlVal.isValid((queryBuffer.toString()))) {
                    System.out.println("Success: This is a valid URL: " + queryBuffer + "");
                } else {
                    System.out.println("Failure: This should be a valid URL: " + queryBuffer + "");
                }
            } else {
                if (!urlVal.isValid((queryBuffer.toString()))) {
                    System.out.println("Failure: This is not a valid URL: " + queryBuffer + "");
                }
            }
        }

    }

    ResultPair[] testUrlScheme = {
            new ResultPair("http://", true),
            new ResultPair("ftp://", true),
            new ResultPair("https://", true),
            new ResultPair("http:/", false),
            new ResultPair("ftp:/", false),
            new ResultPair("https:/", false),
            new ResultPair("htt://", false),
    };

    ResultPair[] testUrlExt = {
            new ResultPair("aero", true),
            new ResultPair("asia", true),
            new ResultPair("biz", true),
            new ResultPair("cat", true),
            new ResultPair("fauj", false),
            new ResultPair("sar", false),
            new ResultPair("klsdf", false),
            new ResultPair("oij", false),
            new ResultPair("ac", true),
            new ResultPair("ad", true),
            new ResultPair("ae", true),
            new ResultPair("af", true),
            new ResultPair("zk", false),
            new ResultPair("zl", false),
            new ResultPair("zo", false),
            new ResultPair("zq", false)
    };

    ResultPair[] testUrlQuery = {
            new ResultPair("?action=view", true),
            new ResultPair("?action=edit&mode=up", true),
            new ResultPair("*action=view", true)
    };
}