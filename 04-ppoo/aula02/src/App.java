import java.util.Scanner;

public class App {
    public static void main(String [] args) throws Exception {
        String nome;
        int n;
        Scanner sc = new Scanner(System.in);
        System.out.println("Digite o nome do paciente:");
        nome = sc.nextLine();
        System.out.println("Entre com a quantidade de amostras coletadas: ");
        n = sc.nextInt();
        Paciente paciente = new Paciente(nome, 0);
        double resultado;
        for(int i = 1; i <= n; i++) {
            System.out.println("Insira o resultado do teste " + i + ": ");
            resultado = sc.nextDouble();
            paciente.inserir_resultado(resultado);
        }
        sc.close();
        System.out.println("############### RELATORIO FINAL ###############");
        System.out.printf("Resultado medio = %.2f%n", paciente.media_resultados());
        System.out.println("Diagnostico: " + paciente.diagnostico());
    }
}
