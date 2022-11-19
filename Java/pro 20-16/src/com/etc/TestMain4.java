package com.etc;

import java.util.concurrent.Executor;

public class TestMain4 {

	public static void main(String[] args) {
		System.out.println(Thread.currentThread());
		
		//创建任务对象
		Task1 tak1=new Task1();
		
		//创建线程对象
		
		//方式1
		Thread t1 =new Thread(tak1,"第一个线程");
		t1.start();
		
		//方式2
	    Thread t2 =new Task2();//多态
	    t2.start();
	    
	    
	    
	    
	   

	}
}
class Task1 implements Runnable{

	@Override
	public void run() {
		// TODO Auto-generated method stub
		for(int i=0;i<50;i++)
System.out.println(Thread.currentThread()+"==="+i);
	
	}  //Task1 实现 Runnable接口，并且覆盖run()方法
	
class Task2 extends Thread{
	//Task2继承Thread类 并重写run()方法    
	public void run() {
		// TODO Auto-generated method stub
		for(int i=0;i<50;i++)
System.out.println(Thread.currentThread()+"==="+i);
	
	}
	
}



