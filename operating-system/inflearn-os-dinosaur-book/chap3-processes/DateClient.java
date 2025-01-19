import java.io.*;
import java.net.*;

public class DateClient {
    public static void main(String[] args) throws Exception{
        // make connection to server socket
        Socket client = new Socket("127.0.0.1", 6013);


        InputStream in = client.getInputStream();
        BufferedReader br = new BufferedReader(new InputStreamReader(in));

        // read date from the socket
        String line = null;
        while((line = br.readLine()) != null) {
            System.out.println("line = " + line);
        }

        // close the socket connetions
        client.close();
    }
}
