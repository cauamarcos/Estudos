import java.util.Random;

public class Moderado implements Investidor {
    @Override
    public double rendimento(double valorInicial, int tempo) {
        Random r = new Random();
        double rand = r.nextInt(10)+0;
        double rentabilidade;

        if (rand < 8)
            rentabilidade = 1.006;
        else
            rentabilidade = 1.02;

        for(int i = 0; i < tempo; i++) {
            System.out.println(valorInicial);
            valorInicial *= rentabilidade;
        }
        
        return valorInicial;
    }
}
