public class Chocolate extends Sabor {
    public Chocolate(Sorvete s) {
        super(s);
    }

    @Override
    public int qtdBolas() {
        return 1 + getSorvete().qtdBolas();
    }

    @Override
    public double preco() {
        return 2.5 + getSorvete().preco();
    }
}
