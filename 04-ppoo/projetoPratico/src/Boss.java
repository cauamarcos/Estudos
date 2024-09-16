import java.util.Random;

/**
 * Essa classe é parte da aplicação "A Jornada de Guidolf".
 * 
 * Essa classe é responsável por inicilizar o objeto do tipo Boss e
 * manusear seus atributos, permitindo a chamada de getters e setters
 * por outras classes que devem modificar o valor de seus atributos, bem
 * como definir a quantidade de dano que o Boss causará ao atacar o jogador.
 * 
 * @author Lucas de Castro Nizio
 */
public class Boss {
    private int vida;
    private int ataque;

    /**
     * Construtor padrão que inicializa a vida e o ataque padrão do Boss.
     */
    public Boss() {
        this.vida = 50;
        this.ataque = 2;
    }

    /**
     * Método que calcula a quantidade de dano que o Boss causará ao atacar 
     * o jogador, considerando uma chance de usar a habilidade especial.
     * 
     * @return A quantidade de dano causada pelo ataque do Boss
     */
    public int atacar() {
        Random random = new Random();
        int chanceHabilidade = random.nextInt(100) + 1;

        if (chanceHabilidade <= 35) {
            // Habilidade especial - Chance de 35%
            int danoAdicional = random.nextInt(4);
            return danoAdicional + ataque;
        } else {
            // Ataque padrão - Chance de 65%
            return ataque;
        }
    }

    /**
     * Obtém a quantidade de vida atual do Boss.
     * 
     * @return A quantidade de vida do Boss.
     */
    public int getVida() {
        return vida;
    }

    /**
     * Obtém a quantidade de ataque do Boss.
     * 
     * @return A quantidade de ataque do Boss.
     */
    public int getAtaque() {
        return ataque;
    }

    /**
     * Define a quantidade de vida do Boss.
     * 
     * @param novaVida A nova quantidade de vida do Boss.
     */
    public void setVida(int novaVida) {
        this.vida = novaVida;
    }

    /**
     * Define a quantidade de ataque do Boss.
     * 
     * @param novoAtaque A nova quantidade de ataque do Boss.
     */
    public void setAtaque(int novoAtaque) {
        this.ataque = novoAtaque;
    }
}
