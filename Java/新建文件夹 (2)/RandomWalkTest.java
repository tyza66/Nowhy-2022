package bao;

public class RandomWalkTest {
	
	public static void main(String[] args) {
		int i1 = 0,j1 = 0,a1 = 0,b1 = 0,c1 = 0,d1 = 0;
        char[][] ditu = new char[10][10];
        char[] zimu = {'A','B','C','D','E','F','G','H','I','J','K','L','M','N','O','P','Q','R','S','T','U','V','W','X','Y','Z'};
        for(i1=0;i1<10;i1++){
            for(j1=0;j1<10;j1++){
                ditu[i1][j1] = '.';
            }
        }
        a1 = (int)(Math.random()*10);
        b1 = (int)(Math.random()*10);
        ditu[a1][b1] = zimu[c1++];
        while(c1 <= 25){
            d1 = (int)(Math.random()*4);
            switch (d1){
                case 0:
                    a1--;
                    if(a1>=0&&a1<=9&&ditu[a1][b1] == '.') {ditu[a1][b1] = zimu[c1++];}             
                    else a1++;
                    break;
                case 1:
                    a1++;
                    if(a1>=0&&a1<=9&&ditu[a1][b1] == '.') {ditu[a1][b1] = zimu[c1++];}     
                    else a1--;
                    break;
                case 2:
                    b1--;
                    if(b1>=0&&b1<=9&&ditu[a1][b1] == '.') {ditu[a1][b1] = zimu[c1++];}    
                    else b1++;
                    break;
                case 3:
                    b1++;
                    if(b1>=0&&b1<=9&&ditu[a1][b1] == '.') {ditu[a1][b1] = zimu[c1++];}
                    else b1--;
                    break;
            }
            if((a1==9||ditu[a1+1][b1] != '.')&&(a1==0||ditu[a1-1][b1] != '.')&&(b1==9||ditu[a1][b1+1] != '.')&&(b1==0||ditu[a1][b1-1] != '.'))
            {System.out.println("¶ÂËÀÁË£¡");break;}
        }
        for(char[] i:ditu){
            System.out.print("|");
            for(char j:i){
                System.out.print(j);
            }
            System.out.println("|");
        }
	
	}

}