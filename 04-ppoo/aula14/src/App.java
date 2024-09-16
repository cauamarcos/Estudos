public class App {
    public static void main(String[] args) throws Exception {
        Sorvete sorvete = new Cestinha("napolitano");
        sorvete = new Chocolate(sorvete);
        sorvete = new Chocolate(sorvete);
        sorvete = new Creme(sorvete);
        sorvete = new Morango(sorvete);
        sorvete = new Morango(sorvete);
        System.out.println("Nome: " + sorvete.getNome());
        System.out.println("Quantidade de bolas: " + sorvete.qtdBolas());
        System.out.println("Preco: " + sorvete.preco());
    }
}
