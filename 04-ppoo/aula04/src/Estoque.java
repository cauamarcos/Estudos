import java.util.ArrayList;
import java.util.Comparator;

public class Estoque {
    private String tipo;
    private ArrayList<Produto> listaProdutos;

    public Estoque(String tipo) {
        this.tipo = tipo;
        listaProdutos = new ArrayList<>();
    }
    private void ordenarLista() {
        Comparator <Produto> comparador = new Comparator <>() {
            public int compare(Produto p1, Produto p2) {
                int num = p1.getNome().compareTo(p2.getNome());
                if (num != 0)
                    return num;
                else
                    return p1.getMarca().compareTo(p2.getMarca());
            }
        };
        listaProdutos.sort(comparador);
    }
    public void adicionarProduto(Produto p) {
        listaProdutos.add(0, p);
        ordenarLista();
    }
    public void gerarRelatorio() {
        System.out.println("Tipo do estoque: " + tipo);
        System.out.printf("%-15s%-20s%-15s", "Nome", "Marca", "Quantidade");
        System.out.println();
        for (Produto p: listaProdutos) {
            System.out.printf("%-15s%-20s%-15d", p.getNome(), p.getMarca(), p.getQtd());
            System.out.println();
        }
    }
}
