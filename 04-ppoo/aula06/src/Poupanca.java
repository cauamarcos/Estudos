public class Poupanca extends Aplicacao {
    private double selic;
    private double tr;

    public Poupanca(double selic, double tr, double valorInicial) {
        super(valorInicial);
        this.selic = selic;
        this.tr = tr;
    }
    @Override
    public double calcularRetorno(int tempo) {
        double rendimento = (0.7 * selic + tr)/100;
        return getValorInicial()*Math.pow(1 + rendimento, tempo);
    }
}