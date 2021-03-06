/* ObjectReceiver.java
 *
 * Copyright (c) 2000 Sean Walton and Macmillan Publishers.  Use may be in
 * whole or in part in accordance to the General Public License (GPL).
 *
 * THIS SOFTWARE IS PROVIDED BY THE REGENTS AND CONTRIBUTORS ``AS IS'' AND
 * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
 * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
 * ARE DISCLAIMED.  IN NO EVENT SHALL THE REGENTS OR CONTRIBUTORS BE LIABLE
 * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL
 * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS
 * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)
 * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT
 * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY
 * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF
 * SUCH DAMAGE.
*/

/*****************************************************************************/
/*** ObjectReceiver.java                                                   ***/
/***                                                                       ***/
/*****************************************************************************/

import java.net.*;
import java.io.*;

public class ObjectReceiver
{
	public static void main(String[] args)
	{
		try
		{
			ServerSocket ss = new ServerSocket(9999);
			Socket s = ss.accept();
			ObjectInputStream ois = new ObjectInputStream(s.getInputStream());
			//---Get the string (should be okay)
			String newMsg = (String)ois.readObject();
			System.err.println(newMsg);
			//---Get the integer (should fail & throw an exception)
			Integer badVal = (Integer)ois.readObject();
			System.err.println(badVal.toString());
			s.close();
		}
		catch (Exception err)
		{
			System.err.println(err);
		}
	}
}