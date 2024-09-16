/**
 * Essa classe é parte da aplicação "A Jornada de Guidolf".
 * 
 * Essa classe é usada apenas para que seja criada uma instância de Jogo,
 * e seja chamada o método "jogar", inciando o jogo.
 * 
 * @author Alex Cyrillo de Sousa Borges
 */

public class App {
    public static void main(String[] args) throws Exception {
        GUI jogo = new GUI();
        jogo.exibir();
    }
}
