import java.util.Scanner;
class calculator {

    public static void main(String[] args)
    {
        String ch;
        int a,b,result=0;
        System.out.println("\n Enter the operator : ");
        Scanner sc = new Scanner(System.in);
        ch=sc.next();
        System.out.println("\n Enter the operands 1 : ");
        a=sc.nextInt();
        System.out.println("\n Enter the operand 2 : ");
        b=sc.nextInt();
        switch(ch)
        {
            case "+":
            result=a+b;
            break;
            case "-":
            result = a-b;
            break;
            case "*":
            result=a*b;
            break;
            case "/":
            result=a/b;
            break;
            default :
            System.out.println("\n Wrong imput : ");

        }
        System.out.println("\n Result = " + result );
        sc.close();
    }
    
}