package com.sdm.server;

import java.io.BufferedWriter;
import java.io.IOException;
import java.io.OutputStream;
import java.io.OutputStreamWriter;
import java.net.ServerSocket;
import java.net.Socket;
import java.util.ArrayList;
import java.util.HashMap;
import java.util.List;
import java.util.Map;

public class Server {
    public static Map<String, Socket> map = new HashMap<>();
    public static List<Socket> list = new ArrayList<>();

    public static void main(String[] args) {
        Socket socket=new Socket();
        try {
            ServerSocket serverSocket=new ServerSocket(8888);
            socket=serverSocket.accept();

            String massage=socket.getInetAddress().getHostAddress();
            map.put(massage,socket);
            list.add(socket);
            OutputStream os=socket.getOutputStream();
            BufferedWriter be=new BufferedWriter(new OutputStreamWriter(os));
            //缓冲输出流
            be.write(massage);//写入缓冲区
            be.flush();//刷新
            be.close();//关闭,注意顺序
            os.close();
            socket.close();
            serverSocket.close();        } catch (IOException e) {
            e.printStackTrace();
        }
    }
}