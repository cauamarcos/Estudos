import java.util.ArrayList;

/**
 * Esta classe é parte da aplicação "A Jornada de guidolf".
 * 
 * Essa classe guarda uma enumeração de todos os comandos conhecidos do
 * jogo. Ela é usada no reconhecimento de comandos quando eles são digitados.
 *
 * @author Lucas de Castro Nizio
 */

public class PalavrasComando {
    // um vetor constante que guarda todas as palavras de comandos válidas
    private static final String[] comandosValidos = {
            "ir", "ajuda", "lutar", "pocao"
    };

    /**
     * Verifica se uma dada String é uma palavra de comando válida.
     * 
     * @return true se a string dada é um comando valido, false se não é.
     */
    public boolean ehComando(String umaString) {
        for (int i = 0; i < comandosValidos.length; i++) {
            if (comandosValidos[i].equals(umaString))
                return true;
        }
        // se chegamos aqui, a string não foi encontrada nos comandos.
        return false;
    }

    /**
     * Retorna os comandos válidos do jogo
     * 
     * @return Uma lista de strings que representam os comandos válidos do jogo
     */
    public ArrayList<String> getComandosValidos() {
        ArrayList<String> comandos = new ArrayList<>();
        for (String comando : comandosValidos) {
            comandos.add(comando);
        }
        return comandos;
    }
}
