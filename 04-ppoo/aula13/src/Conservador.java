public class Conservador implements Investidor {

    @Override
    public double rendimento(double valorInicial, int tempo) {
        for(int i = 0; i < tempo; i++)
            valorInicial *= 1.008;
        return valorInicial;
    }
}
