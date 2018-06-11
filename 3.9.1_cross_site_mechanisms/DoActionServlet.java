/**
CS638: Secure Programming Techniques
Exercise on XSS and CSRF

@author VISHNU SAI RAO SURESH LOKHANDE (lokhande@cs.wisc.edu)

Changes are highlighted in yellow

FILE - DoActionServlet.java
 */

import java.io.IOException;

import javax.servlet.http.HttpServlet;
import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;
import javax.servlet.http.HttpSession;

/**
 * Listen for get requests with sessions attached. Count the number of "clicks"
 * for each session.
 * 
 * @author eichenhofer
 */
public class DoActionServlet extends HttpServlet {

	/*
	 * (non-Javadoc)
	 * 
	 * @see
	 * javax.servlet.http.HttpServlet#doGet(javax.servlet.http.HttpServletRequest,
	 * javax.servlet.http.HttpServletResponse)
	 * 
	 * check for HTTP session and register a click if one exists; print to std out
	 */
	@Override
	protected void doGet(HttpServletRequest req, HttpServletResponse res) throws IOException {
		HttpSession session = req.getSession(false);

		if (session != null) {
		    String token_received = (String) req.getParameter("token");
		    String token_actual = (String) session.getAttribute("token");

		    System.out.println("token actual: "+ token_actual);
		    System.out.println("token received: " + token_received);

		    if (token_received != null && !token_received.equals("") && token_received.equals(token_actual)) {
			System.out.println("Token Match");
			Integer currCount = (Integer) session.getAttribute("clicks");
			session.setAttribute("clicks", currCount + 1);
			System.out.println(session.getAttribute("username") + " clicked!");
		    } else {
			System.out.println("invalid token");
			res.sendError(HttpServletResponse.SC_BAD_REQUEST, "Invalid token");
			return;
		    }
		} else {
		    System.out.println("no-session clicked");
		}
		res.sendRedirect("view");
	}
}
