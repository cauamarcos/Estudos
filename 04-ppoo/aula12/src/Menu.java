import java.util.Scanner;

public class Menu {
    private Scanner entrada;
    private HistogramaVotos hv;
    
    public void executar() {
        entrada = new Scanner(System.in);
        int opcao;
        do{
            exibirMenu();
            opcao = entrada.nextInt();
            entrada.nextLine();
            processarOpcao(opcao);
        }while(opcao != 6);
    }
    
    private void exibirMenu(){
        System.out.println("=======MENU=======");
        System.out.println("1 - Carregar dados de arquivo texto");
        System.out.println("2 - Carregar dados de arquivo binario");
        System.out.println("3 - Gerar relatorio na tela");
        System.out.println("4 - Salvar relatorio em arquivo de texto");
        System.out.println("5 - Salvar relatorio em arquivo binario");
        System.out.println("6 - Sair\n");
        System.out.print("Digite sua opcao: ");
    }
    private void processarOpcao(int opcao){
        switch(opcao){
        case 1:
            carregarArquivoTexto();
            break;
        case 2:
            carregarArquivoBinario();
            break;
        case 3:
            gerarRelatorioTela();
            break;
        case 4:
            gerarArquivoTexto();
            break;
        case 5:
            gerarArquivoBinario();
            break;
        case 6://sair
            break;
        default: 
            System.out.println("Opção inválida!");
        }
    }
    private void carregarArquivoTexto(){
        hv = null;//Eliminando carregamento de arquivo anterior
        hv = ManipuladoraArquivos.lerArquivoTexto(lerNomeArquivo("texto"));
    }
    private void gerarArquivoTexto() {
        if(hv != null){
            ManipuladoraArquivos.gerarArquivoTexto(hv.getHistograma(), lerNomeArquivo("texto"));
        }else{
            System.out.println("Carregar dados de arquivo primeiro");
        }
    }    
    private void carregarArquivoBinario(){
        hv = null;//Eliminando carregamento de arquivo anterior
        hv = ManipuladoraArquivos.lerArquivoBinario(lerNomeArquivo("binario"));
    }
    private void gerarArquivoBinario(){
        if(hv != null){
            ManipuladoraArquivos.gerarArquivoBinario(hv,lerNomeArquivo("binario"));
        }else{
            System.out.println("Carregar dados de arquivo primeiro");
        }    
    }
    private void gerarRelatorioTela(){
        if(hv != null){
            hv.gerarRelatorioTela();
        }else{
            System.out.println("Carregar dados de arquivo primeiro");
        }   
    }
    private String lerNomeArquivo(String tipo){
        System.out.print("Nome do arquivo " + tipo + ": ");
        return entrada.nextLine();
    }
}
