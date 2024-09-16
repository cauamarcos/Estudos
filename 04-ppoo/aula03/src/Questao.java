import java.util.Random;

public class Questao {
    private static int idQuestao = 0;

    private String enunciado;
    private int gabarito;

    public Questao () {
        idQuestao++;
        Random random = new Random ();
        int num1 = random.nextInt(10);
        int num2 = random.nextInt(10);
        gabarito = num1 * num2;
        enunciado = "Questão " + Questao.idQuestao + "%n%nQuanto e " + num1 + " * " + num2 + "? ";
    }
    public String getEnunciado () {return enunciado; }
    public boolean acertou (int resposta) {
        if (resposta == gabarito)
            return true;
        else
            return false;
    }
}
