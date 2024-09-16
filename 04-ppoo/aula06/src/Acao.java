public class Acao extends Aplicacao {
    private double precoInicial;
    private double precoFinal;

    public Acao (double precoInicial, double precoFinal, double valorInicial) {
        super(valorInicial);
        this.precoInicial = precoInicial;
        this.precoFinal = precoFinal;
    }

    @Override
    public double calcularRetorno(int tempo) {
        double rendimento = ((precoFinal/precoInicial)*100 - 100)/100;
        return getValorInicial()*Math.pow(1 + rendimento, tempo);
    }
}
