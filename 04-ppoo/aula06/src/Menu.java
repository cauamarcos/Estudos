import java.util.Scanner;

public class Menu {
    private Aplicacao ap;
    private Scanner entrada;

    public Menu(){
        entrada = new Scanner(System.in);
    }

    public void executar(){
        int op;
        do {
            exibirOpcoes();
            op = Integer.parseInt(entrada.nextLine());
            executarOpcao(op);
        } while(op != 4);
    }

    private void exibirOpcoes() {
        System.out.println("###### SIMULAÇÃO ######");
        System.out.println("1 - Investimento em poupança");
        System.out.println("2 - Investimento em CDB");
        System.out.println("3 - Investimento em ação");
        System.out.println("4 - Sair");
        System.out.print("Escolha a sua opcao: ");
    }

    private void executarOpcao(int op) {
        switch (op){
            case 1:
                simularInvestimentoPoupanca();
                break;
            case 2:
                simularInvestimentoCdb();
                break;
            case 3:
                simularInvestimentoAcao();
                break;
            case 4:
                break;
            default:
                System.out.println("Escolha uma opcao entre 1 e 4!");
        }
    }
    
    private void simularInvestimentoPoupanca() {
        double selic, tr;
        System.out.print("Entre com o valor da taxa Selic em %: ");
        selic = Double.parseDouble(entrada.nextLine());
        System.out.print("Entre com o valor da taxa referencial (TR) em %: ");
        tr = Double.parseDouble(entrada.nextLine());
        ap = new Poupanca(selic,tr,lerValorInicial());
        System.out.printf("Valor final para investimento em poupanca: R$ %.2f%n",ap.calcularRetorno(lerTempo()));
    }

    private void simularInvestimentoCdb() {
        double cdi;
        System.out.print("Entre com o valor da taxa CDI em %: ");
        cdi = Double.parseDouble(entrada.nextLine());
        ap = new Cdb(cdi,lerValorInicial());
        System.out.printf("Valor final para investimento em CDB: R$ %.2f%n",ap.calcularRetorno(lerTempo()));
    }

    private void simularInvestimentoAcao() {
        double precoInicial, precoFinal;
        System.out.print("Entre com o preço inicial da ação: ");
        precoInicial = Double.parseDouble(entrada.nextLine());
        System.out.print("Entrar com o preço final da ação: ");
        precoFinal = Double.parseDouble(entrada.nextLine());
        ap = new Acao(precoInicial,precoFinal,lerValorInicial());
        System.out.printf("Valor final para investimento em ação: R$ %.2f%n",ap.calcularRetorno(lerTempo()));
    }

    private double lerValorInicial(){
        System.out.print("Entre com o valor a ser investido: ");
        return Double.parseDouble(entrada.nextLine());
    }

    private int lerTempo(){
        System.out.print("Entre com a duração da aplicação em meses: ");
        return Integer.parseInt(entrada.nextLine());
    }
    
}
