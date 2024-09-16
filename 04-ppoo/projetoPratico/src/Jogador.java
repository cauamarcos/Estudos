import java.util.Random;

/**
 * Essa classe é parte da aplicação "A Jornada de Guidolf".
 * 
 * Essa classe é responsável por inicilizar o objeto do tipo Jogador e
 * manusear seus atributos, permitindo a chamada de getters e setters
 * por outras classes que devem modificar o valor de seus atributos.
 * 
 * @author Lucas de Castro Nizio
 */

public class Jogador {
    private int vida;
    private int ataque;
    private int pocoesDeCura;
    private int armadurasReforcadas;
    private int espadasLendarias;

    /**
     * Construtor para inicializar os atributos do jogador.
     *
     */

    public Jogador() {
        vida = 10; // Valor inicial de vida
        ataque = 5; // Valor inicial de ataque
        pocoesDeCura = 1; // Quantidade inicial de poções de cura
        armadurasReforcadas = 0; // Quantidade inicial de armaduras reforçadas
        espadasLendarias = 0; // Quantidade inicial de espadas lendárias
    }

    /**
     * Obtém a vida atual do jogador.
     *
     * @return A quantidade de vida do jogador.
     */
    public int getVida() {
        return vida;
    }

    /**
     * Define a quantidade de vida do jogador.
     *
     * @param novaVida A nova quantidade de vida do jogador.
     */
    public void setVida(int novaVida) {
        vida = novaVida;
    }

    /**
     * Obtém o ataque atual do jogador.
     *
     * @return A quantidade de ataque do jogador.
     */
    public int getAtaque() {
        return ataque;
    }


    /**
     * Define a quantidade de ataque do jogador.
     *
     * @param novaVida A nova quantidade de ataque do jogador.
     */
    public void setAtaque(int novoAtaque) {
        ataque = novoAtaque;
    }

    /**
     * Obtém a quantidade de poções de cura disponíveis para o jogador.
     *
     * @return A quantidade de poções do jogador.
     */
    public int getPocoesDeCura() {
        return pocoesDeCura;
    }

    /**
     * Adiciona uma poção de cura disponível para o jogador.
     * 
     */
    public void adicionarPocaoDeCura() {
        pocoesDeCura++;
    }

    /**
     * Utiliza uma poção de cura, que adiciona vida ao jogaodor.
     *
     */
    public void usarPocaoDeCura() {
        if (pocoesDeCura > 0) {
            vida += 3; // Aumenta a vida em 3 pontos ao usar uma poção de cura
            pocoesDeCura--;
        }
    }

    /**
     * Obtém a quantidade de armaduras reforçadas encontradas pelo jogador.
     *
     * @return A quantidade de armaduras reforçadas encontradas.
     */
    public int getArmadurasReforcadas() {
        return armadurasReforcadas;
    }

    /**
     * Método que incrementa a vida e o número de armaduras
     * reforçadas do jogador caso ele tenha sorte ao "jogar o dado".
     */
    public void adicionarArmaduraReforcada() {
        Random random = new Random();
        int vidaExtra = random.nextInt(6);
        if (vidaExtra == 0){
            vidaExtra = 1;
        }
        vida += vidaExtra;
        armadurasReforcadas++;
    }

    /**
     * Obtém a quantidade de espadas lendárias encontradas pelo jogador.
     *
     * @return A quantidade de espadas lendárias encontradas.
     */
    public int getEspadasLendarias() {
        return espadasLendarias;
    }

    /**
     * Método que incrementa o ataque e o número de espadas lendárias
     * do jogador caso ele tenha sorte ao "jogar o dado".
     */
    public void adicionarEspadaLendaria() {
        Random random = new Random();
        int ataqueExtra = random.nextInt(6);
        if (ataqueExtra == 0){
            ataqueExtra = 1;
        }
        ataque += ataqueExtra;
        espadasLendarias++;
    }
}
