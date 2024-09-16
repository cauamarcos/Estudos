import java.util.Scanner;

public class Menu {
    private Investidor investidor;
    private Scanner sc;

    public Menu() {
        sc = new Scanner(System.in);
    }

    public void executar() {
        String resp = "Sim";
        double valorInicial, rendimento = 0;
        int tempo, op;
        do {
            System.out.println("Entre com o valor inicial do investimento: ");
            valorInicial = sc.nextDouble();
            System.out.println("Entre com o tempo(meses) da aplicaçao: ");
            tempo = sc.nextInt();
            exibirOpcoes();
            op = sc.nextInt();
            if(op == 1) {
                investidor = new Conservador();
                rendimento = investidor.rendimento(valorInicial, tempo);
            }
            else if(op == 2) {
                investidor = new Moderado();
                rendimento = investidor.rendimento(valorInicial, tempo);
            }
            else if(op == 3) {
                investidor = new Arrojado();
                rendimento = investidor.rendimento(valorInicial, tempo);
            }
            System.out.println("Valor final esperado: " + rendimento);
            System.out.println("Deseja realizar nova simulação?(Sim/Nao): ");
            resp = sc.next();
        } while (resp.equals("Sim"));
    }

    private void exibirOpcoes() {
        System.out.println("Escolha o tipo do investidor:");
        System.out.println("1 - Conservador");
        System.out.println("2 - Moderado");
        System.out.println("3 - Arrojado");
        System.out.println("Digite sua opcao: ");
    }
}
