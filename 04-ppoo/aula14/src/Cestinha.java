public class Cestinha extends Sorvete {
    public Cestinha(String nome) {
        setNome(nome);
    }

    @Override
    public int qtdBolas() {
        return 0;
    }

    @Override
    public double preco() {
        return 3.2;
    }
}
