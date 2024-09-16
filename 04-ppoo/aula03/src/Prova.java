import java.util.Scanner;

public class Prova {
    private Questao [] questoes;

    public Prova () {
        questoes = new Questao [5];
        for (int i = 0; i < 5; i++)
            questoes [i] = new Questao ();
    }
    public void aplicar () {
        for (int i = 0; i < 5; i++) {
            System.out.printf (questoes [i].getEnunciado ());
            Scanner sc = new Scanner (System.in);
            int resposta = sc.nextInt ();
            if (questoes [i].acertou (resposta))
                System.out.println ("Voce tentou 1 vez e acertou a questao.");
            else {
                System.out.println ("Voce ganhou mais uma chance! Digite outra resposta para a questao: ");
                resposta = sc.nextInt ();
                if (questoes [i].acertou(resposta))
                    System.out.println ("Voce tentou 2 vezes e acertou a questao.");
                else
                    System.out.println ("Você tentou 2 vezes e errou a questao.");
                sc.close ();
            }
        }
    }
}
