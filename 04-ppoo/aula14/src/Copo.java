public class Copo extends Sorvete {
    public Copo(String nome) {
        setNome(nome);
    }

    @Override
    public int qtdBolas() {
        return 0;
    }

    @Override
    public double preco() {
        return 1.7;
    }
}
