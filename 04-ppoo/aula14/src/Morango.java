public class Morango extends Sabor {
    public Morango(Sorvete s) {
        super(s);
    }

    @Override
    public int qtdBolas() {
        return 1 + getSorvete().qtdBolas();
    }

    @Override
    public double preco() {
        return 1.5 + getSorvete().preco();
    }
}
