import java.util.Scanner;

public class Ex01 {
    public static void main(String[] args) throws Exception { 
        Scanner sc = new Scanner (System.in);
        System.out.println("Entre com o codigo: ");
        int codigo = sc.nextInt();
        System.out.println("Entre com a quantidade: ");
        int qtd = sc.nextInt();
        sc.close();
        int preco;
        if(codigo < 11) {
            preco = 10;
        }
        else if(codigo < 21) {
            preco = 15;
        }
        else if(codigo < 31) {
            preco = 20;
        }
        else {
            preco = 30;
        }
        System.out.println("Preco unitario: " + preco + ",00");
        int total = preco*qtd;
        System.out.println("Valor bruto: " + total + ",00");
        float desconto;
        if(total < 250) {
            desconto = total * 0.05f;
        }
        else if(total <= 500) {
            desconto = total * 0.1f;
        }
        else {
            desconto = total * 0.15f;
        }
        System.out.println("Valor do desconto: " + desconto);
        float vfinal = total - desconto;
        System.out.println("Preco final: " + vfinal);
    }
}
