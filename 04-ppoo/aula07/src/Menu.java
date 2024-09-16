import java.util.Scanner;

public class Menu {
    private Agenda agenda;
    private Scanner entrada;

    public Menu() {
        agenda = new Agenda ();
        entrada = new Scanner(System.in);
    }

    public void executar() {
        int op;
        do {
            exibirOpcoes();
            op = Integer.parseInt(entrada.nextLine());
            executarOpcao(op);
        } while(op != 5);
    }

    private void exibirOpcoes() {
        System.out.println();
        System.out.println("=======Menu de Opções=======");
        System.out.println("1 - Cadastrar uma pessoa fisica");
        System.out.println("2 - Cadastrar uma pessoa juridica");
        System.out.println("3 - Remover um contato");
        System.out.println("4 - Imprimir dados da agenda");
        System.out.println("5 - Sair");
        System.out.print("Escolha a sua opcao: ");
    }

    private void executarOpcao(int op) {
        switch (op){
            case 1:
                addPessoaFisica();
                break;
            case 2:
                addPessoaJuridica();
                break;
            case 3:
                removerContato();
                break;
            case 4:
                imprimirAgenda();
                break;
            case 5:
                break;
            default:
                System.out.println("Escolha uma opcao de 1 a 5! ");
        }
    }
    
    private void addPessoaFisica() {
        String nome, endereco, email, cpf, estado_civil;
        nome = lerNome();
        endereco = lerEndereco();
        email = lerEmail();
        System.out.print("Entre com o cpf: ");
        cpf = entrada.nextLine();
        System.out.print("Entre com o estado civil: ");
        estado_civil = entrada.nextLine();
        agenda.cadastrarPessoaFisica(nome, endereco, email, cpf, estado_civil);
    }

    private void addPessoaJuridica() {
        String nome, endereco, email, cnpj;
        nome = lerNome();
        endereco = lerEndereco();
        email = lerEmail();
        System.out.print("Entre com o cnpj: ");
        cnpj = entrada.nextLine();
        System.out.print("Entre com a inscricao estadual: ");
        int inscricao_estadual = Integer.parseInt(entrada.nextLine());
        agenda.cadastrarPessoaJuridica(nome, endereco, email, cnpj, inscricao_estadual);
    }

    private void removerContato() {
        System.out.print("Entre com o cpf ou cnpj: ");
        String id = entrada.nextLine();
        if (!agenda.removerContato(id))
            System.out.println("ERRO! Contato não encontrado");
        else
            System.out.println("Contato removido com sucesso!");
    }

    private void imprimirAgenda () {
        System.out.printf(agenda.toString());
    }

    private String lerNome(){
        System.out.print("Entre com o nome: ");
        return entrada.nextLine();
    }

    private String lerEndereco(){
        System.out.print("Entre com o endereco: ");
        return entrada.nextLine();
    }

    private String lerEmail(){
        System.out.print("Entre com o email: ");
        return entrada.nextLine();
    }
    
}

