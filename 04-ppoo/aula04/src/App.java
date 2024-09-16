public class App {
    public static void main(String[] args) throws Exception {
        Produto p1 = new Produto ("Arroz", "Tio Joao", 125);
        Produto p2 = new Produto ("Arroz", "Prato Fino", 250);
        Produto p3 = new Produto ("Sabonete", "Dove", 50);
        Produto p4 = new Produto ("Sabonete", "Palmolive", 40);
        Produto p5 = new Produto ("Sabonete", "Nivea", 25);
        Estoque estoque = new Estoque("fluxo");
        estoque.adicionarProduto(p1);
        estoque.adicionarProduto(p2);
        estoque.adicionarProduto(p3);
        estoque.adicionarProduto(p4);
        estoque.adicionarProduto(p5);
        estoque.gerarRelatorio();
    }
}
