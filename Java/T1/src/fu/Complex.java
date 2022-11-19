package fu;

 public class Complex {
	private double realPart; //复数实部，包级别
    private double imaginaryPart;//复数虚部，包级别
	

	public Complex(double realPart, double imaginaryPart) {//有参构造	
		this.realPart = realPart;
		this.imaginaryPart = imaginaryPart;
	}

	public Complex(double realPart) {//一个参
		this(realPart,0.0);
	}
	
	public Complex() {//无参构造：实部、虚部都为0，调用有参构造实现	
		this(0.0,0.0);
	}
	
	public void setRealPart(double d) {
		realPart = d;
	}

	public double getRealPart() {
		return realPart;
	}

	public void setImaginaryPart(double d) {
		 imaginaryPart = d;
	}

	public double getImaginaryPart() {
		return imaginaryPart;
	}

	public Complex complexAdd(Complex cn) { //成员方法7：两个完整的复数加法
		Complex guo = new Complex();
		guo.realPart = this.realPart + cn.realPart;
		guo.imaginaryPart = this.imaginaryPart + cn.imaginaryPart;
		return guo;
	}

	public Complex complexAdd(double c) {//成员方法8：一个完整复数+一个实数
		Complex guo = new Complex();
		guo.realPart = this.realPart + c;
		guo.imaginaryPart = this.imaginaryPart;
		return guo;
	}

	public Complex complexMinus(Complex cn) {//成员方法9：两个完整的复数减法
		Complex guo = new Complex();
		guo.realPart = this.realPart - cn.realPart;
		guo.imaginaryPart = this.imaginaryPart - cn.imaginaryPart;
		return guo;
	}

	public Complex complexMinus(double c) {//成员方法10：一个完整复数-一个实数
		Complex guo = new Complex();
		guo.realPart = this.realPart - c;
		guo.imaginaryPart = this.imaginaryPart;
		return guo;
	}

	public Complex complexMulti(Complex cn) {//成员方法11：两个完整的复数乘法
		Complex guo = new Complex();
		guo.realPart = this.realPart*cn.realPart  - this.imaginaryPart*cn.imaginaryPart;
		guo.imaginaryPart = this.realPart*cn.imaginaryPart + this.imaginaryPart*cn.realPart;
		return guo;
	}

	public Complex complexMulti(double c) {//成员方法12：一个完整复数*一个实数
		Complex guo = new Complex();
		guo.realPart = this.realPart*c;
		guo.imaginaryPart = this.imaginaryPart*c;
		return guo;
	}

	
	public double abs() {
		return Math.sqrt(realPart*realPart + imaginaryPart*imaginaryPart);
	}
	public String toString() {//成员方法13：把复数对象以复数a+bi形式表示：写成一个字符串
		if(imaginaryPart>=0)
			return ""+realPart+"+"+imaginaryPart+"i";
		else
			return ""+realPart+""+imaginaryPart+"i";
	}
 }
