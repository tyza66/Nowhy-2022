package tPC;

import java.io.IOException;
import java.io.InputStream;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.net.Socket;
import java.util.concurrent.Executor;
import java.util.concurrent.Executors;

import javafx.fxml.FXML;
import javafx.scene.control.Alert;
import javafx.scene.control.Button;
import javafx.scene.control.TextArea;
import javafx.scene.control.TextField;

public class Controller {

//	先定义一些必须的控制器(组件)
		@FXML
	    TextField txt_nickname;   
	    @FXML
	    TextField txt_ip;
	    @FXML
	    TextField txt_port;
	    @FXML
	    Button btn_conn;
	    @FXML
	    TextArea txt_message;
	    @FXML
	    TextArea txt_context;
	    @FXML
	    Button btn_send;

	public void contect() {
/*		
 *      一、 自定义port值,但不能取值为1~1023，因为小于1024的端口号通常被通用的知名端口占用了，已经有了通用定义，我们再调用可能会引起冲突
 *		
 *		二、 关于IP与port的区别：
 *			使用IP地址找到一台主机，使用port找到服务
 *		
 *		三、例如：
 *			你的电脑上有两个聊天软件：QQ和微信，如果你用QQ发了一个消息，那么你期望的是 对方在她自己的QQ上收到这条消息，而不是微信，整个过程这条消息的经历可以简化为两步
 *		    				  1、通过IP找到这台主机
 *							  2、通过port找到QQ，从而不让他发到微信上去
*/
		 int port = 8888;
		 
//		    用个try  当用户输入的port值不合法时 告诉他 他错了  此时的Exception是  NumberFormatException
	        try {
/*        	
 * 			一、port的值从txt_port框中获取，所以是id为txt_port的文本框执行getText()操作，得到的这个东东 就是所谓的 数值字符串
 * 			二、Integer 类在对象中包装了一个基本类型int的值。Integer类型的对象包含一个 int 类型的字段
 *      	三、Integer类中的parseInt()方法  返回与调用该方法的 数值字符串 相应的整型(int)值
*/
	            port = Integer.parseInt(txt_port.getText());
	            
	        } catch (Exception e) {
/*        	
 *          调用异常对象的printStackTrace()方法，他从控制台输出异常栈跟踪。从栈跟踪中可以了解到 发生的异常类型 和 发生异常源代码的行号
 *     	    即 打印出所有与之相关的异常出处，换句话说就是不仅打印出异常名字还是显示出位置。便于程序的调试。
*/	
	        	e.printStackTrace();
/*	        	
 * 			设置提示对话框，当你输入port不合法时弹出
 * 			只包含一段信息提示，一个确认按钮，用来单纯做信息提示，所以后面是INFORMATION
 * 			也可以做一个警示框（一个黄色的感叹号），其余不变，后面换成WARNING
 * 			红色错误标志，后面换成ERROR
 * 			包含提示和确认、取消按钮的的提示对话框，是最经常使用的格式，后面换成CONFIRMATION
 * */
	            Alert alter = new Alert(Alert.AlertType.INFORMATION, "port输入错误");
//	            调用 静态 show() 方法以显示 Alert 控件
	            alter.show();
	            return;
	        }	
	        
	        
	        try {
//			创建一个客户端对象Socket,构造方法绑定服务器的ip地址和端口号  ip+port构成套接字，防止通信时造成混乱
	           Socket socket = new Socket(txt_ip.getText(), port);
/*	           一、定义线程池执行对象server(服务器)
           	   二、优点：创建一个可缓存线程池，如果线程池长度超过处理需要，可灵活回收空闲线程，若无可回收，则新建线程。
           	   三、特性：线程池为无限大，当执行第二个任务时第一个任务已经完成，会复用执行第一个任务的线程，而不用每次新建线程。
           	   四、基本格式：Executors.newCachedThreadPool(Runnable任务)
           	   五、Lambda表达式：允许把函数作为一个方法的参数（函数作为参数传递进方法中）
           	      这里的 r 表示  由新线程实例执行的可运行对象 就是Runnable任务的实例，也是个线程 {}里表示的是任务(线程)详情
           	   六、总结：
           	      线程池，就是在调用线程的时候初使化一定数量的线程，有线程过来的时候，先检测初使化的线程还有空的没有，
           	      没有就再看当前运行中的线程数是不是已经达到了最大数，如果没有，就新分配一个线程去处理，就像餐馆中吃饭一样，
           	      从里面叫一个服务员出来；但如果已经达到了最大数，就相当于服务员已经用完了，那没得办法，另外的线程就只有等了，
           	      直到有新的“服务员”为止。线程池的优点就是可以管理线程，有一个高度中枢，这样程序才不会乱，
           	      保证系统不会因为大量的并发而因为资源不足挂掉。 
 */
	            Executor server = Executors.newCachedThreadPool(r -> {
//	            	一般情况下，一律使用 Executors.defaultThreadFactory() 创建线程，将任务r传入
	                Thread t = Executors.defaultThreadFactory().newThread(r);
	                
/*					java中线程setDaemon（true）就是将当前进程变成后台进程。
					如果对某个线程对象在启动(调用start方法)之前调用了setDaemon(true)方法,这个线程就变成了后台线程.
					对java程序来说,只要还有一个前台线程在运行,这个进程就不会结束,如果一个进程中只有后台线程运行,这个进程会结束.
					保证客户端正常运行
*/	                
	                t.setDaemon(true);
	                return  t;
	            });
	            
	            // 开启客户端 输入流监控  ChatClient类,模拟客户端控制,代码:
	            server.execute(new ClientInputStreamThread());
	            
	            // 发送昵称给服务端
	            server.execute(() -> {
	                try {
/*
客户端上的使用（client）

1.getInputStream方法可以得到一个输入流，客户端的Socket对象上的getInputStream方法得到输入流其实就是从服务器端发回的数据。

2.getOutputStream方法得到的是一个输出流，客户端的Socket对象上的getOutputStream方法得到的输出流其实就是发送给服务器端的数据。

服务器端上的使用（server）

1.getInputStream方法得到的是一个输入流，服务端的Socket对象上的getInputStream方法得到的输入流其实就是从客户端发送给服务器端的数据流。

2.getOutputStream方法得到的是一个输出流，服务端的Socket对象上的getOutputStream方法得到的输出流其实就是发送给客户端的数据。

PrintWriter(OutputStream out)  根据现有的 OutputStream 创建不带自动行刷新的新 PrintWriter。

这里是客户端使用，这个socket是  客户端对象  所以socket.getOutputStream()的意思就是  发送给服务器数据
*/
	                    PrintWriter pw = new PrintWriter(socket.getOutputStream());
/*
 * 						write()与println()的区别：
 * 							print是将各种数据类型都转换成字符串的形式输出
 * 							write()只能输出与字符相关的数据
 * 							简而言之：当输出内容有汉字的时候就用write()
 * */
/*
 * 						字符流常用类：reader (输出流)  writer(输入流) ————>一般用来处理文本文件
 * 						作用是：客户端发送昵称信息
 * */	        
	                    pw.write (txt_nickname.getText());
	                    
/*	                    调用flush（）方法 强制把数据输出，清空缓存区（刷新该流缓存）
 *	                    缓存区定义：缓冲区可以简单地理解为一段内存区域。可以简单地把缓冲区理解为一段特殊的内存。
 * 						某些情况下，如果一个程序频繁地操作一个资源（如文件或数据库），则性能会很低，此时为了提升性能，
 * 						就可以将一部分数据暂时读入到内存的一块区域之中，以后直接从此区域中读取数据即可，因为读取内存速度会比较快，这样可以提升程序的性能。
*/                      pw.flush();
	                } catch (IOException e) {
	                    e.printStackTrace();
	                }
	            });
	        } catch (IOException e) {
	            Alert alter = new Alert(Alert.AlertType.INFORMATION, "ip输入错误或服务端无效");
	            e.printStackTrace();
	        }
	        
	    }
//	服务端Socket对象
	 private Socket socket;
	    /**
	     *  发送消息
	     */
	    public void send() {
	        PrintWriter osw = null;
	        try {
	            osw = new PrintWriter(socket.getOutputStream());
	            osw.write(txt_message.getText());
	            osw.flush();
	        } catch (IOException e) {
	            e.printStackTrace();
	        }


	    }

	    /**
	     *  客户端 输入流 监控线程
	     */
	    public class ClientInputStreamThread implements Runnable{



	        @Override
	        public void run() {
	            {
	                InputStream is = null;
/*	 
 *                1. socket.getInetAddress()返回InetAddress对象包含远程计算机的IP地址。
 *                	 InetAddress.getHostAddress()返回String对象与该地址的文本表示。（就是让你得到一个用字符串表示的IP地址）
 *                2. 采用连式编程法
*/	                  
	                String ip = socket.getInetAddress().getHostAddress();
	                try {
	                    is = socket.getInputStream();
	                    InputStreamReader reader = new InputStreamReader(is);
	                    char[] buffer = new char[1024];
	                    int len = -1;

	                    while (true) {

	                        if (-1 != (len = reader.read(buffer))) {
	                            String tmp = new String(buffer, 0 , len);
	                            txt_context.setText(txt_context.getText() + "\r\n" + tmp);
	                            txt_message.setText("");
	                        }
	                    }

	                } catch (IOException e) {
	                    e.printStackTrace();

	                } finally {
	                    try {
	                        is.close();
	                    } catch (IOException e) {
	                        e.printStackTrace();
	                    }
	                }
	            }
	        }
	    }


	}
