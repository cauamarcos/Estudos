public class Creme extends Sabor {
    public Creme(Sorvete s) {
        super(s);
    }

    @Override
    public int qtdBolas() {
        return 1 + getSorvete().qtdBolas();
    }

    @Override
    public double preco() {
        return 3.5 + getSorvete().preco();
    }
}
