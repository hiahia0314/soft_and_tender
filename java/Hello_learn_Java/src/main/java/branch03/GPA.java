package branch03;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class GPA {

	public static void main (String[] args) {
		Clac();
	}

	public static void Clac(){
		int cps = 0; //class performance scores
		int mtr = 0; //mid-term results
		int fg = 0;  //final grade
		double gpa = 0.0;

		//1 input
		cps = inputInt("please enter your class performance scores:");
		mtr = inputInt("please enter your mid-term results:");
		fg = inputInt("please enter your final grades:");

		//2 process
		gpa=calculateGPA(cps,mtr,fg);

		//3 output
		output(gpa);

	}
	public static int inputInt(String prompt) {
		String temp = "";
		try {
			System.out.println(prompt);
			BufferedReader br1 = new BufferedReader(new InputStreamReader(System.in));
			temp = br1.readLine();

		} 
		catch(IOException e) {
			e.printStackTrace();
		}

		return Integer.parseInt(temp);
	}

	public static double calculateGPA(int n1, int n2, int n3){
		double sum = 0;
		if( (n1<0 || n1>100) || (n2<0 || n2>100) || (n3<0 || n3>100)) {
			System.out.println("Invalid Grades. Please try again.");
		}
		else {
			sum = 0.1*n1 + 0.4*n2 + 0.5*n3;
		}
		return sum;
	}
	public static void output(double sum){
		if(sum>=97) {
			System.out.println("Congrats! Your branch03.GPA is A+!" + "(" + sum + ")");
		}
		else if(sum>=93) {
			System.out.println("Congrats! Your branch03.GPA is A!" + "(" + sum + ")");
		}
		else if(sum>=90) {
			System.out.println("Your branch03.GPA is A-!." + "(" + sum + ")");
		}
		else if(sum>=87) {
			System.out.println("Your branch03.GPA is B+." + "(" + sum + ")");
		}
		else if(sum>=83) {
			System.out.println("Your branch03.GPA is B." + "(" + sum + ")");
		}
		else{
			System.out.println("U fail.");
		}
	}

}



