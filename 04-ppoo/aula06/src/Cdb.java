public class Cdb extends Aplicacao {
    private double taxa_cdi;

    public Cdb (double taxa_cdi, double valorInicial) {
        super(valorInicial);
        this.taxa_cdi = taxa_cdi;
    }
    @Override
    public double calcularRetorno(int tempo) {
        double rendimento = (1.2 * taxa_cdi)/100;
        return getValorInicial()*Math.pow(1 + rendimento, tempo);
    }

}
