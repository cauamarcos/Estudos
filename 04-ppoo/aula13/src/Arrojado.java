import java.util.Random;

public class Arrojado implements Investidor {

    @Override
    public double rendimento(double valorInicial, int tempo) {
        Random r = new Random();
        double rand = r.nextInt(100)+0;
        double rentabilidade;

        if (rand < 65)
            rentabilidade = 1.003;
        else if (rand < 90)
            rentabilidade = 1.02;
        else
            rentabilidade = 1.05;
            
        for(int i = 0; i < tempo; i++)
            valorInicial *= rentabilidade;
            
        return valorInicial;
    }
    
}
