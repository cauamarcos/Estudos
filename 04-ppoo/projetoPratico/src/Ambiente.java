import java.util.HashMap;

/**
 * Esta classe é parte da aplicação "A Jornada de Guidolf".
 *
 * Um "Ambiente" representa uma localização no cenário do jogo. Ele é conectado
 * aos
 * outros ambientes através de saídas. As saídas são nomeadas como norte, sul,
 * leste
 * e oeste. Para cada direção, o ambiente guarda uma referência para o ambiente
 * vizinho,
 * ou null se não há saída naquela direção.
 * 
 * @author Alex Cyrillo de Sousa Borges & Lucas de Castro Nizio
 */

public class Ambiente {
    // descrição do ambiente
    private String descricao;
    // ambientes vizinhos de acordo com a direção
    private HashMap<String, Ambiente> saidas;
    private boolean primeiraChegada;

    /**
     * Cria um ambiente com a "descricao" passada. Inicialmente, ele não tem saidas.
     * "descricao" eh algo como "uma cozinha" ou "um jardim aberto".
     * 
     * @param descricao A descrição do ambiente.
     */
    public Ambiente(String descricao) {
        this.descricao = descricao;
        saidas = new HashMap<>();
        primeiraChegada = true;
    }

    /**
     * Define uma saída do ambiente.
     * 
     * @param direcao A direção daquela saída.
     * @param saida   O ambiente para o qual a direção leva.
     */
    public void ajustarSaida(String direcao, Ambiente saida) {
        saidas.put(direcao, saida);
    }

    /**
     * @return A descrição do ambiente.
     */
    public String getDescricao() {
        return descricao;
    }

    /**
     * Retorna uma saída do ambiente, dada uma direção (null se não existir)
     * 
     * @param direcao Direção à qual a saída se refere
     * @return Ambiente de saída naquela direção
     */
    public Ambiente getSaida(String direcao) {
        return saidas.get(direcao);
    }

    /**
     * Texto montado com todas as saídas disponíveis
     * 
     * @return Texto com as saídas
     */
    public String direcoesDeSaida() {
        String texto = "";
        for (String direcao : saidas.keySet()) {
            texto += direcao + " ";
        }
        return texto;
    }

    /**
     * Define o estado do atributo "primeiraChegada", incialmente definido como true.
     *
     * @param primeiraChegada valor booleano indicando se é a primeira chegada ao ambiente.
     */
    public void setPrimeiraChegada(boolean primeiraChegada) {
        this.primeiraChegada = primeiraChegada;
    }

    /**
     * Verifica se é a primeira chegada do jogador a este ambiente.
     *
     * @return Valor booleano indicando se é a primeira chegada ao ambiente.
     */
    public boolean isPrimeiraChegada() {
        return primeiraChegada;
    }

}
