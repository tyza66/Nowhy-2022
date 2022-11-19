package com.etc;

import java.util.concurrent.Executor;
import java.util.concurrent.Executors;

public class TestMain5 {
	public static void main(String[] args) {

		Executor exe = Executors.newSingleThreadExecutor();
		
		exe.execute(new Runnable() {       //ƒ‰√˚¿‡
			public void run() {
				// TODO Auto-generated method stub
				for (int i = 0; i < 50; i++)
					System.out.println(Thread.currentThread() + "===" + i);
			}
		});
		Executor service = Executors.newCachedThreadPool();
		service.execute(() -> {
			for (int i = 0; i < 50; i++) {
				System.out.println(Thread.currentThread() + "===" + i);
			}
		});

		service.execute(() -> {
			for (int i = 0; i < 50; i++) {
				System.out.println(Thread.currentThread() + "===" + i);
			}

		});
		
		
	}
}
