import java.io.*;
import java.net.*;
import java.util.Date;

public class DateServer {
    public static void main(String[] args) throws Exception {
        ServerSocket serverSocket = new ServerSocket(6013);

        while(true) {
            System.out.println("Listening..");
            Socket client = serverSocket.accept();
            PrintWriter pout = new PrintWriter(client.getOutputStream(), true);
            System.out.println("New client is connected...");

            // wirte the Date to the socket
            pout.println((new Date()).toString());

            // close the socket and resume listening for connections
            client.close();
        }
    }
}
