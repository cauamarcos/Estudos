import java.util.ArrayList;

/**
 * Esta classe é parte da aplicacao "A Jornada de Guidolf".
 * 
 * Essa clase lê o arquivo que contém todas as entradas que serão usadas durante
 * a execução
 * da aplicação para que possam ser executados de forma ordenada.
 *
 * O analisador tem um conjunto de palavras de comando conhecidas. Ele compara a
 * entrada do
 * usuário com os comandos conhecidos, e se a entrada não é um dos comandos
 * conhecidos, ele
 * retorna um objeto comando que é marcado como um comando desconhecido.
 * 
 * @author Cauã Marcos de Oliveira Silva & Lucas de Castro Nizio
 */

public class Analisador {
    // guarda todas as palavras de comando validas
    private PalavrasComando palavrasDeComando;
    // origem da entrada de comandos

    /**
     * Cria um analisador para ler do terminal.
     */
    public Analisador() {
        palavrasDeComando = new PalavrasComando();
    }

    /**
     * A cada vez que esse método é chamado, ele usa o primeiro comando armazenado
     * no ArrayList
     * e o eliminado do ArrayList, para que a ordem de execução de comandos seja
     * respeitada.
     * Este método tenta interpretar o
     * comando de duas palavras. Ele retorna o comando como um objeto da classe
     * Comando.
     * 
     * @return O próximo comando do usuario
     */
    public Comando pegarComando(String comando) {

        // o primeiro comando do ArrayList é usado e removido do ArrayList

        // guardará até duas palavras usadas no comando
        String palavra1 = null;
        String palavra2 = null;

        // quebra o comando do usuário em várias palavras, usando espaços em branco como
        // separadores.
        // Exemplo: se ele digitar "ir norte", o comando vai gerar um vetor com as duas
        // palavras ["ir", "norte"].
        String[] palavras = comando.trim().split("\\s+");

        // guarda a primeira e a segunda palavras digitadas pelo usuário, se houverem.
        if (palavras.length >= 1) {
            palavra1 = palavras[0];
        }
        if (palavras.length >= 2) {
            palavra2 = palavras[1];
        }

        // Agora verifica se esta palavra é conhecida. Se for, cria um comando com ela.
        // Se não, cria um comando "null" (para comando desconhecido)
        if (palavrasDeComando.ehComando(palavra1)) {
            return new Comando(palavra1, palavra2);
        } else {
            return new Comando(null, palavra2);
        }
    }

    /**
     * Retorna os comandos válidos do jogo
     * 
     * @return Uma lista de strings que representam os comandos válidos do jogo
     */
    public ArrayList<String> getComandosValidos() {
        return palavrasDeComando.getComandosValidos();
    }
}
