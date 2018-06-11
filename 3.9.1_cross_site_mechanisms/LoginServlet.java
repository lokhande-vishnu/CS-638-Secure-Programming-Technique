/**
CS638: Secure Programming Techniques
Exercise on XSS and CSRF

@author VISHNU SAI RAO SURESH LOKHANDE (lokhande@cs.wisc.edu)

Changes are highlighted in yellow

FILE - LoginServlet.java
 */

import java.io.IOException;

import javax.servlet.http.HttpServlet;
import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;

import java.util.regex.Pattern;
import java.security.SecureRandom;
import org.apache.commons.codec.binary.Hex;

/**
 * Java servlet for creating a session and attaching two attributes: a username
 * and a counter. Does not consider existing sessions.
 * 
 * @author Joseph Eichenhofer
 */
public class LoginServlet extends HttpServlet {

	/*
	 * (non-Javadoc)
	 * 
	 * @see
	 * javax.servlet.http.HttpServlet#doGet(javax.servlet.http.HttpServletRequest,
	 * javax.servlet.http.HttpServletResponse)
	 * 
	 * Create a session for the specified username (no checks of
	 * password/authentication). Does not consider existing sessions with same
	 * username. Initialize clicks to zero.
	 */
	@Override
	protected void doGet(HttpServletRequest req, HttpServletResponse res) throws IOException {

	    // >> Create a session token
	    SecureRandom random = new SecureRandom();
	    byte bytes[] = new byte[32];
	    random.nextBytes(bytes);
	    String token = new String(Hex.encodeHex(bytes));
	    
	    // check for username parameter
	    String username = req.getParameter("username");
	    
	    if (username != null && !username.equals("")) {
		
		// >> WHITELISTING HERE
		if (! Pattern.matches("[\\p{L}\\p{Digit}_-]+", username)) {
		    res.sendError(HttpServletResponse.SC_BAD_REQUEST, "Invalid username characters");
		    return;
		}
		// request contained a username, set session attribute for username and
		//>> initialize click count to zero
		req.getSession(true).setAttribute("token", token);
		req.getSession(true).setAttribute("username", username);
		req.getSession().setAttribute("clicks", new Integer(0));
	    }
	    
	    // redirect to main page
	    res.sendRedirect("view");
	}
}
